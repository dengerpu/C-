#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ADMIN 0     // 系统管理员
#define OPERATOR 1  // 系统操作员
#define USER 2      // 学生用户

#define MAX 100  // 最大账户容量

// 保存账户信息结构
typedef struct {
    char username[32];
    char password[32];
    bool password_changed;
    int type;
} account_info_t;

account_info_t accounts[MAX];
int accounts_len = 0;

// 学生信息结构
typedef struct student_info_t {
    char id[10];              // 复试考号
    char name[64];            // 姓名
    char school[64];          // 报考学院
    char type[32];            // 报考类别
    double intro_courses[2];  // 基础课成绩
    double spec_courses[2];   // 专业课成绩
    double first_score;       // 初试总分
    double second_score;      //复试成绩
    double speaking_score;    // 口语成绩
    double overall_score;     // 综合成绩
    struct student_info_t *next;
} student_info_t;

student_info_t *student_info_list = NULL;       // 所有学生链表
student_info_t *taught_student_list = NULL;     // 学硕
student_info_t *spec_student_list = NULL;       // 专硕
student_info_t *part_time_student_list = NULL;  // 非全日制

// 学院信息编号表
typedef struct {
    char id[8];       //编号
    char school[64];  // 学院
} school_info_t;

school_info_t school_info[] = {
    {"01", "通信学院"},
    {"02", "计算机学院"},
    {"03", "光电学院"},
    {"04", "自动化学院"},
    {"05", "经管学院"},
    {"06", "研究生院"},
    {"07", "外语学院"},
    {"08", "安法学院"},
    {"09", "体育学院"},
    {"10", "传媒学院"},
    {"11", "先进制造学院"},
    {"12", "马克思主义学院"},
};

void get_account_info();
void update_password(const char *username, const char *password);
bool is_valid_account(const char *username, const char *password);
bool is_admin(const char *username);
bool is_operator(const char *username);
bool is_first_login(const char *username);
int login();
bool has_account_exist(const char *username);
void add_operator();
void admin_menu();
void operator_menu();
void student_menu();
void get_student_info();
void free_student_list(student_info_t *list);
const char *get_school_by_id(char *id);
void update_account_info();
bool is_valid_type(const char *type);
student_info_t *get_student_by_id(const char *id);
void add_student_info();
void remove_student_info();
void modify_student_info();
void search_student_info();
void category_student_by_type();
void export_student_info_to_file(const char *filename, student_info_t *list);
void sort_student_by_score();
void get_student_statistic();
void display_all_students_info();

int main() {
    get_account_info();
    get_student_info();

    int user_type = login();

    if (user_type == ADMIN) {
        admin_menu();
    } else if (user_type == OPERATOR) {
        operator_menu();
    } else {
        student_menu();
    }

    get_student_statistic();

    free_student_list(student_info_list);
    free_student_list(taught_student_list);
    free_student_list(spec_student_list);
    free_student_list(part_time_student_list);
    return 0;
}

/*************************
 *      用户管理模块      *
 *************************/

// 从文件读取账户信息
void get_account_info() {
    FILE *fp = fopen("data1.txt", "r");
    if (!fp) {
        fp = fopen("data1.txt", "w");

        const char *admin = "admin";
        const char *user01 = "user01";
        int password_changed = 0;

        fprintf(fp, "%s %s %d %d\n", admin, admin, password_changed, ADMIN);
        fprintf(fp, "%s %s %d %d\n", user01, user01, password_changed, OPERATOR);

        strcpy(accounts[0].username, admin);
        strcpy(accounts[0].password, admin);
        accounts[0].password_changed = false;
        accounts[0].type = ADMIN;
        strcpy(accounts[1].username, user01);
        strcpy(accounts[1].password, user01);
        accounts[1].password_changed = false;
        accounts[1].type = OPERATOR;

        accounts_len = 2;

        fclose(fp);
        return;
    }

    int password_changed = 0;
    while (fscanf(fp, "%s %s %d %d", accounts[accounts_len].username, accounts[accounts_len].password, &password_changed, &accounts[accounts_len].type) != EOF) {
        accounts[accounts_len].password_changed = (bool)password_changed;
        accounts_len++;
    }

    fclose(fp);
}

// 更新密码
void update_password(const char *username, const char *password) {
    FILE *fp = fopen("data1.txt", "w");

    int i = 0;
    for (i = 0; i < accounts_len; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            strcpy(accounts[i].password, password);
            accounts[i].password_changed = true;
        }
        fprintf(fp, "%s %s %d %d\n", accounts[i].username, accounts[i].password, accounts[i].password_changed, accounts[i].type);
    }

    fclose(fp);
}

// 判断是否为合法账户
bool is_valid_account(const char *username, const char *password) {
    int i = 0;
    for (i = 0; i < accounts_len; i++) {
        if (strcmp(username, accounts[i].username) == 0 && strcmp(password, accounts[i].password) == 0) {
            return true;
        }
    }
    return false;
}

// 判断是否为系统管理员
bool is_admin(const char *username) {
    int i = 0;
    for (i = 0; i < accounts_len; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            return accounts[i].type == ADMIN;
        }
    }
    return false;
}

// 判断是否为系统操作员
bool is_operator(const char *username) {
    int i = 0;
    for (i = 0; i < accounts_len; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            return accounts[i].type == OPERATOR;
        }
    }
    return false;
}

// 判断是否为首次登陆
bool is_first_login(const char *username) {
    int i = 0;
    for (i = 0; i < accounts_len; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            return !accounts[i].password_changed;
        }
    }
    return true;
}

// 登录功能
int login() {
    char username[32] = {0};
    char password[32] = {0};

    while (1) {
        printf("【登录】账号：");
        scanf("%s", username);
        printf("【登录】密码：");
        scanf("%s", password);

        if (is_valid_account(username, password)) {
            break;
        }

        printf("【登录失败】\n");
    }

    if (is_first_login(username)) {
        printf("首次登录修改密码：");
        scanf("%s", password);
        update_password(username, password);
    }

    printf("\n");

    if (is_admin(username)) {
        return ADMIN;
    } else if (is_operator(username)) {
        return OPERATOR;
    } else {
        return USER;
    }
}

bool has_account_exist(const char *username) {
    int i = 0;
    for (i = 0; i < accounts_len; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            return true;
        }
    }
    return false;
}

void add_operator() {
    printf("【添加操作员】账号：");
    scanf("%s", accounts[accounts_len].username);
    if (has_account_exist(accounts[accounts_len].username)) {
        printf("【错误】账号已存在\n\n\n");
        return;
    }
    printf("【添加操作员】密码：");
    scanf("%s", accounts[accounts_len].password);
    accounts[accounts_len].password_changed = false;
    accounts[accounts_len].type = OPERATOR;
    accounts_len++;
    update_account_info();
    printf("\n\n");
}

// 系统管理员菜单
void admin_menu() {
    int choice = 0;

    while (1) {
        printf("【系统管理员菜单】\n");
        printf("1. 增加数据\n");
        printf("2. 删除数据\n");
        printf("3. 修改数据\n");
        printf("4. 查询数据\n");
        printf("5. 查看所有数据\n");
        printf("6. 添加操作员\n");
        printf("0. 退出\n");
        printf("选择 << ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1) {
            add_student_info();
        } else if (choice == 2) {
            remove_student_info();
        } else if (choice == 3) {
            modify_student_info();
        } else if (choice == 4) {
            search_student_info();
        } else if (choice == 5) {
            display_all_students_info();
        } else if (choice == 6) {
            add_operator();
        } else if (choice == 0) {
            break;
        }
    }
}

// 系统操作员菜单
void operator_menu() {
    int choice = 0;

    while (1) {
        printf("【系统操作员菜单】\n");
        printf("1. 增加数据\n");
        printf("2. 查询数据\n");
        printf("3. 查看所有数据\n");
        printf("0. 退出\n");
        printf("选择 << ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1) {
            add_student_info();
        } else if (choice == 2) {
            search_student_info();
        } else if (choice == 2) {
            display_all_students_info();
        } else if (choice == 0) {
            break;
        }
    }
}

// 学生菜单
void student_menu() {
    int choice = 0;

    while (1) {
        printf("【学生菜单】\n");
        printf("1. 查询数据\n");
        printf("0. 退出\n");
        printf("选择 << ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1) {
            search_student_info();
        } else if (choice == 0) {
            break;
        }
    }
}

/*************************
 *    学生基本信息管理    *
 *************************/

// 从文件读取学生信息
void get_student_info() {
    if (!student_info_list) {
        student_info_list = (student_info_t *)malloc(sizeof(student_info_t));
        student_info_list->next = NULL;
    }

    FILE *fp = fopen("data2.txt", "r");
    if (!fp) {
        fp = fopen("data2.txt", "w");
    }

    char line[256] = {0};
    while (fgets(line, sizeof(line), fp)) {
        student_info_t *student = (student_info_t *)malloc(sizeof(student_info_t));
        sscanf(line, "%s %s %s %s %lf %lf %lf %lf %lf %lf %lf %lf", student->id, student->name, student->school, student->type, &student->intro_courses[0], &student->intro_courses[1], &student->spec_courses[0], &student->spec_courses[1], &student->first_score, &student->second_score, &student->speaking_score, &student->overall_score);
        student->next = student_info_list->next;
        student_info_list->next = student;
    }

    fclose(fp);
}

// 删除全部学生
void free_student_list(student_info_t *list) {
    student_info_t *temp = list;

    while (temp && temp->next) {
        student_info_t *del = temp->next;
        temp->next = del->next;
        del->next = NULL;
        free(del);
    }

    if (list) {
        free(list);
        list = NULL;
    }
}

// 根据复试考号识别对应院校
const char *get_school_by_id(char *id) {
    int school_info_len = sizeof(school_info) / sizeof(school_info[0]);

    // 长度是否为9位
    if (strlen(id) != 9) {
        return NULL;
    }

    int year = 0;
    char school_id[8] = {0};
    char idx[4] = {0};
    sscanf(id, "%4d%2s%3s", &year, school_id, idx);

    // 末尾3位数字是否为001-999
    if (atoi(idx) < 1 || atoi(idx) > 999) {
        return NULL;
    }

    int i = 0;
    for (i = 0; i < school_info_len; i++) {
        if (strcmp(school_id, school_info[i].id) == 0) {
            return school_info[i].school;
        }
    }

    return NULL;
}

void update_account_info() {
    FILE *fp = fopen("data1.txt", "w");
    int i = 0;
    for (i = 0; i < accounts_len; i++) {
        fprintf(fp, "%s %s %d %d\n", accounts[i].username, accounts[i].password, accounts[i].password_changed, accounts[i].type);
    }
    fclose(fp);

    fp = fopen("data2.txt", "w");
    student_info_t *temp = student_info_list;
    while (temp && temp->next) {
        temp = temp->next;
        fprintf(fp, "%s %s %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", temp->id, temp->name, temp->school, temp->type, temp->intro_courses[0], temp->intro_courses[1], temp->spec_courses[0], temp->spec_courses[1], temp->first_score, temp->second_score, temp->speaking_score, temp->overall_score);
    }
    fclose(fp);
}

// 判断是否为合法报考类别
bool is_valid_type(const char *type) {
    return strcmp(type, "学硕") == 0 || strcmp(type, "专硕") == 0 || strcmp(type, "非全日制") == 0;
}

/*************************
 *    学生数据增删改      *
 *************************/

// 根据复试考号查询学生
student_info_t *get_student_by_id(const char *id) {
    student_info_t *temp = student_info_list;
    while (temp && temp->next) {
        temp = temp->next;
        if (strcmp(temp->id, id) == 0) {
            return temp;
        }
    }
    return NULL;
}

// 添加学生信息
void add_student_info() {
    student_info_t *student = (student_info_t *)malloc(sizeof(student_info_t));
    student->next = NULL;

    while (1) {
        printf("【添加学生信息】复试考号：");
        scanf("%s", student->id);
        student_info_t *s = get_student_by_id(student->id);
        if (s) {
            printf("【错误】复试考号已存在\n");
            continue;
        }
        const char *school = get_school_by_id(student->id);
        if (school) {
            strcpy(student->school, school);
            break;
        }
        printf("【错误】复试考号应该为9位，4位年份+2位学院编号（01-12）+3位数字（001-999）\n");
    }

    printf("【添加学生信息】姓名：");
    scanf("%s", student->name);

    while (1) {
        printf("【添加学生信息】报考类别：");
        scanf("%s", student->type);
        if (is_valid_type(student->type)) {
            break;
        }
        printf("【错误】报考类别包含学硕、专硕、非全日制\n");
    }

    student->first_score = 0;
    int i = 0;
    for (i = 0; i < 2; i++) {
        while (1) {
            printf("【添加学生信息】基础课%d成绩：", i + 1);
            scanf("%lf", &student->intro_courses[i]);
            if (student->intro_courses[i] >= 0 && student->intro_courses[i] <= 100) {
                student->first_score += student->intro_courses[i];
                break;
            }
            printf("【错误】基础课成绩满分为100分\n");
        }
    }

    for (i = 0; i < 2; i++) {
        while (1) {
            printf("【添加学生信息】专业课%d成绩：", i + 1);
            scanf("%lf", &student->spec_courses[i]);
            if (student->spec_courses[i] >= 0 && student->spec_courses[i] <= 150) {
                student->first_score += student->spec_courses[i];
                break;
            }
            printf("【错误】专业课成绩满分为150分\n");
        }
    }

    printf("【添加学生信息】复试成绩：");
    scanf("%lf", &student->second_score);

    printf("【添加学生信息】口语成绩：");
    scanf("%lf", &student->speaking_score);

    student->overall_score = student->first_score * 0.6 + student->second_score * 0.3 + student->speaking_score * 0.1;

    student->next = student_info_list->next;
    student_info_list->next = student;

    strcpy(accounts[accounts_len].username, student->id);
    strcpy(accounts[accounts_len].password, student->id);
    accounts[accounts_len].password_changed = false;
    accounts[accounts_len].type = USER;

    accounts_len++;
    update_account_info();
    printf("\n【添加成功】\n\n");
}

// 删除学生信息
void remove_student_info() {
    char id[10] = {0};
    printf("【删除学生信息】复试考号：");
    scanf("%s", id);

    bool found = false;
    student_info_t *temp = student_info_list;
    while (temp && temp->next) {
        if (strcmp(temp->next->id, id) == 0) {
            student_info_t *del = temp->next;
            temp->next = del->next;
            del->next = NULL;
            free(del);

            int i = 0;
            for (i = 0; i < accounts_len; i++) {
                if (strcmp(accounts[i].username, id) == 0) {
                    accounts[i] = accounts[accounts_len - 1];
                    accounts_len--;
                    break;
                }
            }

            update_account_info();
            printf("\n【删除成功】\n\n");
            return;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("【错误】未找到该考生\n\n");
    }
}

// 修改学生信息
void modify_student_info() {
    char id[10] = {0};
    printf("【修改学生信息】复试考号：");
    scanf("%s", id);
    student_info_t *student = get_student_by_id(id);
    if (!student) {
        printf("【错误】未找到该考生\n\n");
        return;
    }

    printf("【修改学生信息】姓名：");
    scanf("%s", student->name);

    while (1) {
        printf("【修改学生信息】报考类别：");
        scanf("%s", student->type);
        if (is_valid_type(student->type)) {
            break;
        }
        printf("【错误】报考类别包含学硕、专硕、非全日制\n");
    }

    student->first_score = 0;
    int i = 0;
    for (i = 0; i < 2; i++) {
        while (1) {
            printf("【修改学生信息】基础课%d成绩：", i + 1);
            scanf("%lf", &student->intro_courses[i]);
            if (student->intro_courses[i] >= 0 && student->intro_courses[i] <= 100) {
                student->first_score += student->intro_courses[i];
                break;
            }
            printf("【错误】基础课成绩满分为100分\n");
        }
    }

    for (i = 0; i < 2; i++) {
        while (1) {
            printf("【修改学生信息】专业课%d成绩：", i + 1);
            scanf("%lf", &student->spec_courses[i]);
            if (student->spec_courses[i] >= 0 && student->spec_courses[i] <= 150) {
                student->first_score += student->spec_courses[i];
                break;
            }
            printf("【错误】专业课成绩满分为150分\n");
        }
    }

    printf("【修改学生信息】复试成绩：");
    scanf("%lf", &student->second_score);

    printf("【修改学生信息】口语成绩：");
    scanf("%lf", &student->speaking_score);

    student->overall_score = student->first_score * 0.6 + student->second_score * 0.3 + student->speaking_score * 0.1;

    update_account_info();
    printf("\n【修改成功】\n\n");
}

// 查询学生信息
void search_student_info() {
    char id[10] = {0};
    printf("【查询学生信息】复试考号：");
    scanf("%s", id);
    student_info_t *student = get_student_by_id(id);
    if (!student) {
        printf("【错误】未找到该考生\n\n");
        return;
    }

    printf("\n");
    printf("***** 考生信息 *****\n");
    printf("复试考号：%s\n", student->id);
    printf("姓    名：%s\n", student->name);
    printf("基础课 1：%.2f\n", student->intro_courses[0]);
    printf("基础课 2：%.2f\n", student->intro_courses[1]);
    printf("专业课 1：%.2f\n", student->spec_courses[0]);
    printf("专业课 2：%.2f\n", student->spec_courses[1]);
    printf("初试成绩：%.2f\n", student->first_score);
    printf("复试成绩：%.2f\n", student->second_score);
    printf("口语成绩：%.2f\n", student->speaking_score);
    printf("综合成绩：%.2f\n", student->overall_score);
    printf("\n\n");
}

/*************************
 *      学生数据统计      *
 *************************/

// 按报考类别分类
void category_student_by_type() {
    taught_student_list = (student_info_t *)malloc(sizeof(student_info_t));
    spec_student_list = (student_info_t *)malloc(sizeof(student_info_t));
    part_time_student_list = (student_info_t *)malloc(sizeof(student_info_t));
    taught_student_list->next = NULL;
    spec_student_list->next = NULL;
    part_time_student_list->next = NULL;

    student_info_t *temp = student_info_list;
    while (temp && temp->next) {
        temp = temp->next;
        student_info_t *student = (student_info_t *)malloc(sizeof(student_info_t));
        strcpy(student->id, temp->id);
        strcpy(student->name, temp->name);
        strcpy(student->school, temp->school);
        strcpy(student->type, temp->type);
        student->intro_courses[0] = temp->intro_courses[0];
        student->intro_courses[1] = temp->intro_courses[1];
        student->spec_courses[0] = temp->spec_courses[0];
        student->spec_courses[1] = temp->spec_courses[1];
        student->first_score = temp->first_score;
        student->second_score = temp->second_score;
        student->speaking_score = temp->speaking_score;
        student->overall_score = temp->overall_score;

        if (strcmp(student->type, "学硕") == 0) {
            student->next = taught_student_list->next;
            taught_student_list->next = student;
        } else if (strcmp(student->type, "专硕") == 0) {
            student->next = spec_student_list->next;
            spec_student_list->next = student;
        } else {
            student->next = part_time_student_list->next;
            part_time_student_list->next = student;
        }
    }
}

// 根据综合成绩排序
void sort_student_by_overall_score(student_info_t *list) {
    student_info_t *temp1 = NULL;
    student_info_t *temp2 = NULL;
	//   char id[10];              // 复试考号
    //char name[64];            // 姓名
   // char school[64];          // 报考学院
   // char type[32];            // 报考类别
   // double intro_courses[2];  // 基础课成绩
  //  double spec_courses[2];   // 专业课成绩
   // double first_score;       // 初试总分
   // double second_score;      //复试成绩
  //  double speaking_score;    // 口语成绩
  //  double overall_score;     // 综合成绩

    for (temp1 = list->next; temp1; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2; temp2 = temp2->next) {
            if (temp1->overall_score < temp2->overall_score) {
                char str_temp[128] = {0};
                double d_temp = 0;

                strcpy(str_temp, temp1->id);
                strcpy(temp1->id, temp2->id);
                strcpy(temp2->id, str_temp);

                strcpy(str_temp, temp1->name);
                strcpy(temp1->name, temp2->name);
                strcpy(temp2->name, str_temp);

                strcpy(str_temp, temp1->type);
                strcpy(temp1->type, temp2->type);
                strcpy(temp2->type, str_temp);

                strcpy(str_temp, temp1->school);
                strcpy(temp1->school, temp2->school);
                strcpy(temp2->school, str_temp);

                d_temp = temp1->intro_courses[0];
                temp1->intro_courses[0] = temp2->intro_courses[0];
                temp2->intro_courses[0] = d_temp;

                d_temp = temp1->intro_courses[1];
                temp1->intro_courses[1] = temp2->intro_courses[1];
                temp2->intro_courses[1] = d_temp;

                d_temp = temp1->spec_courses[0];
                temp1->spec_courses[0] = temp2->spec_courses[0];
                temp2->spec_courses[0] = d_temp;

                d_temp = temp1->spec_courses[1];
                temp1->spec_courses[1] = temp2->spec_courses[1];
                temp2->spec_courses[1] = d_temp;

                d_temp = temp1->first_score;
                temp1->first_score = temp2->first_score;
                temp2->first_score = d_temp;

                d_temp = temp1->second_score;
                temp1->second_score = temp2->second_score;
                temp2->second_score = d_temp;

                d_temp = temp1->speaking_score;
                temp1->speaking_score = temp2->speaking_score;
                temp2->speaking_score = d_temp;

                d_temp = temp1->overall_score;
                temp1->overall_score = temp2->overall_score;
                temp2->overall_score = d_temp;
            }
        }
    }
}

// 导出信息到文件
void export_student_info_to_file(const char *filename, student_info_t *list) {
    FILE *fp = fopen(filename, "w");
    student_info_t *temp = list;
    while (temp && temp->next) {
        temp = temp->next;
        fprintf(fp, "%s %s %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", temp->id, temp->name, temp->school, temp->type, temp->intro_courses[0], temp->intro_courses[1], temp->spec_courses[0], temp->spec_courses[1], temp->first_score, temp->second_score, temp->speaking_score, temp->overall_score);
    }
    fclose(fp);
}

// 以学生综合成绩降序的形式
void sort_student_by_score() {
    sort_student_by_overall_score(taught_student_list);
    sort_student_by_overall_score(spec_student_list);
    sort_student_by_overall_score(part_time_student_list);
}

// 获取学生统计信息
void get_student_statistic() {
    category_student_by_type();
    sort_student_by_score();
    export_student_info_to_file("data3.txt", taught_student_list);
    export_student_info_to_file("data4.txt", spec_student_list);
    export_student_info_to_file("data5.txt", part_time_student_list);
}

void display_student_info(student_info_t *student) {
    printf("***** 考生信息 *****\n");
    printf("复试考号：%s\n", student->id);
    printf("姓    名：%s\n", student->name);
    printf("基础课 1：%.2f\n", student->intro_courses[0]);
    printf("基础课 2：%.2f\n", student->intro_courses[1]);
    printf("专业课 1：%.2f\n", student->spec_courses[0]);
    printf("专业课 2：%.2f\n", student->spec_courses[1]);
    printf("初试成绩：%.2f\n", student->first_score);
    printf("复试成绩：%.2f\n", student->second_score);
    printf("口语成绩：%.2f\n", student->speaking_score);
    printf("综合成绩：%.2f\n", student->overall_score);
}

void display_all_students_info() {
    student_info_t *temp = student_info_list;
    while (temp && temp->next) {
        temp = temp->next;
        display_student_info(temp);
        printf("\n\n");
    }
}