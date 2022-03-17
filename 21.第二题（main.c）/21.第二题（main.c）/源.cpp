#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ADMIN 0     // ϵͳ����Ա
#define OPERATOR 1  // ϵͳ����Ա
#define USER 2      // ѧ���û�

#define MAX 100  // ����˻�����

// �����˻���Ϣ�ṹ
typedef struct {
    char username[32];
    char password[32];
    bool password_changed;
    int type;
} account_info_t;

account_info_t accounts[MAX];
int accounts_len = 0;

// ѧ����Ϣ�ṹ
typedef struct student_info_t {
    char id[10];              // ���Կ���
    char name[64];            // ����
    char school[64];          // ����ѧԺ
    char type[32];            // �������
    double intro_courses[2];  // �����γɼ�
    double spec_courses[2];   // רҵ�γɼ�
    double first_score;       // �����ܷ�
    double second_score;      //���Գɼ�
    double speaking_score;    // ����ɼ�
    double overall_score;     // �ۺϳɼ�
    struct student_info_t *next;
} student_info_t;

student_info_t *student_info_list = NULL;       // ����ѧ������
student_info_t *taught_student_list = NULL;     // ѧ˶
student_info_t *spec_student_list = NULL;       // ר˶
student_info_t *part_time_student_list = NULL;  // ��ȫ����

// ѧԺ��Ϣ��ű�
typedef struct {
    char id[8];       //���
    char school[64];  // ѧԺ
} school_info_t;

school_info_t school_info[] = {
    {"01", "ͨ��ѧԺ"},
    {"02", "�����ѧԺ"},
    {"03", "���ѧԺ"},
    {"04", "�Զ���ѧԺ"},
    {"05", "����ѧԺ"},
    {"06", "�о���Ժ"},
    {"07", "����ѧԺ"},
    {"08", "����ѧԺ"},
    {"09", "����ѧԺ"},
    {"10", "��ýѧԺ"},
    {"11", "�Ƚ�����ѧԺ"},
    {"12", "���˼����ѧԺ"},
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
 *      �û�����ģ��      *
 *************************/

// ���ļ���ȡ�˻���Ϣ
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

// ��������
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

// �ж��Ƿ�Ϊ�Ϸ��˻�
bool is_valid_account(const char *username, const char *password) {
    int i = 0;
    for (i = 0; i < accounts_len; i++) {
        if (strcmp(username, accounts[i].username) == 0 && strcmp(password, accounts[i].password) == 0) {
            return true;
        }
    }
    return false;
}

// �ж��Ƿ�Ϊϵͳ����Ա
bool is_admin(const char *username) {
    int i = 0;
    for (i = 0; i < accounts_len; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            return accounts[i].type == ADMIN;
        }
    }
    return false;
}

// �ж��Ƿ�Ϊϵͳ����Ա
bool is_operator(const char *username) {
    int i = 0;
    for (i = 0; i < accounts_len; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            return accounts[i].type == OPERATOR;
        }
    }
    return false;
}

// �ж��Ƿ�Ϊ�״ε�½
bool is_first_login(const char *username) {
    int i = 0;
    for (i = 0; i < accounts_len; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            return !accounts[i].password_changed;
        }
    }
    return true;
}

// ��¼����
int login() {
    char username[32] = {0};
    char password[32] = {0};

    while (1) {
        printf("����¼���˺ţ�");
        scanf("%s", username);
        printf("����¼�����룺");
        scanf("%s", password);

        if (is_valid_account(username, password)) {
            break;
        }

        printf("����¼ʧ�ܡ�\n");
    }

    if (is_first_login(username)) {
        printf("�״ε�¼�޸����룺");
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
    printf("����Ӳ���Ա���˺ţ�");
    scanf("%s", accounts[accounts_len].username);
    if (has_account_exist(accounts[accounts_len].username)) {
        printf("�������˺��Ѵ���\n\n\n");
        return;
    }
    printf("����Ӳ���Ա�����룺");
    scanf("%s", accounts[accounts_len].password);
    accounts[accounts_len].password_changed = false;
    accounts[accounts_len].type = OPERATOR;
    accounts_len++;
    update_account_info();
    printf("\n\n");
}

// ϵͳ����Ա�˵�
void admin_menu() {
    int choice = 0;

    while (1) {
        printf("��ϵͳ����Ա�˵���\n");
        printf("1. ��������\n");
        printf("2. ɾ������\n");
        printf("3. �޸�����\n");
        printf("4. ��ѯ����\n");
        printf("5. �鿴��������\n");
        printf("6. ��Ӳ���Ա\n");
        printf("0. �˳�\n");
        printf("ѡ�� << ");
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

// ϵͳ����Ա�˵�
void operator_menu() {
    int choice = 0;

    while (1) {
        printf("��ϵͳ����Ա�˵���\n");
        printf("1. ��������\n");
        printf("2. ��ѯ����\n");
        printf("3. �鿴��������\n");
        printf("0. �˳�\n");
        printf("ѡ�� << ");
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

// ѧ���˵�
void student_menu() {
    int choice = 0;

    while (1) {
        printf("��ѧ���˵���\n");
        printf("1. ��ѯ����\n");
        printf("0. �˳�\n");
        printf("ѡ�� << ");
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
 *    ѧ��������Ϣ����    *
 *************************/

// ���ļ���ȡѧ����Ϣ
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

// ɾ��ȫ��ѧ��
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

// ���ݸ��Կ���ʶ���ӦԺУ
const char *get_school_by_id(char *id) {
    int school_info_len = sizeof(school_info) / sizeof(school_info[0]);

    // �����Ƿ�Ϊ9λ
    if (strlen(id) != 9) {
        return NULL;
    }

    int year = 0;
    char school_id[8] = {0};
    char idx[4] = {0};
    sscanf(id, "%4d%2s%3s", &year, school_id, idx);

    // ĩβ3λ�����Ƿ�Ϊ001-999
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

// �ж��Ƿ�Ϊ�Ϸ��������
bool is_valid_type(const char *type) {
    return strcmp(type, "ѧ˶") == 0 || strcmp(type, "ר˶") == 0 || strcmp(type, "��ȫ����") == 0;
}

/*************************
 *    ѧ��������ɾ��      *
 *************************/

// ���ݸ��Կ��Ų�ѯѧ��
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

// ���ѧ����Ϣ
void add_student_info() {
    student_info_t *student = (student_info_t *)malloc(sizeof(student_info_t));
    student->next = NULL;

    while (1) {
        printf("�����ѧ����Ϣ�����Կ��ţ�");
        scanf("%s", student->id);
        student_info_t *s = get_student_by_id(student->id);
        if (s) {
            printf("�����󡿸��Կ����Ѵ���\n");
            continue;
        }
        const char *school = get_school_by_id(student->id);
        if (school) {
            strcpy(student->school, school);
            break;
        }
        printf("�����󡿸��Կ���Ӧ��Ϊ9λ��4λ���+2λѧԺ��ţ�01-12��+3λ���֣�001-999��\n");
    }

    printf("�����ѧ����Ϣ��������");
    scanf("%s", student->name);

    while (1) {
        printf("�����ѧ����Ϣ���������");
        scanf("%s", student->type);
        if (is_valid_type(student->type)) {
            break;
        }
        printf("�����󡿱���������ѧ˶��ר˶����ȫ����\n");
    }

    student->first_score = 0;
    int i = 0;
    for (i = 0; i < 2; i++) {
        while (1) {
            printf("�����ѧ����Ϣ��������%d�ɼ���", i + 1);
            scanf("%lf", &student->intro_courses[i]);
            if (student->intro_courses[i] >= 0 && student->intro_courses[i] <= 100) {
                student->first_score += student->intro_courses[i];
                break;
            }
            printf("�����󡿻����γɼ�����Ϊ100��\n");
        }
    }

    for (i = 0; i < 2; i++) {
        while (1) {
            printf("�����ѧ����Ϣ��רҵ��%d�ɼ���", i + 1);
            scanf("%lf", &student->spec_courses[i]);
            if (student->spec_courses[i] >= 0 && student->spec_courses[i] <= 150) {
                student->first_score += student->spec_courses[i];
                break;
            }
            printf("������רҵ�γɼ�����Ϊ150��\n");
        }
    }

    printf("�����ѧ����Ϣ�����Գɼ���");
    scanf("%lf", &student->second_score);

    printf("�����ѧ����Ϣ������ɼ���");
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
    printf("\n����ӳɹ���\n\n");
}

// ɾ��ѧ����Ϣ
void remove_student_info() {
    char id[10] = {0};
    printf("��ɾ��ѧ����Ϣ�����Կ��ţ�");
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
            printf("\n��ɾ���ɹ���\n\n");
            return;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("������δ�ҵ��ÿ���\n\n");
    }
}

// �޸�ѧ����Ϣ
void modify_student_info() {
    char id[10] = {0};
    printf("���޸�ѧ����Ϣ�����Կ��ţ�");
    scanf("%s", id);
    student_info_t *student = get_student_by_id(id);
    if (!student) {
        printf("������δ�ҵ��ÿ���\n\n");
        return;
    }

    printf("���޸�ѧ����Ϣ��������");
    scanf("%s", student->name);

    while (1) {
        printf("���޸�ѧ����Ϣ���������");
        scanf("%s", student->type);
        if (is_valid_type(student->type)) {
            break;
        }
        printf("�����󡿱���������ѧ˶��ר˶����ȫ����\n");
    }

    student->first_score = 0;
    int i = 0;
    for (i = 0; i < 2; i++) {
        while (1) {
            printf("���޸�ѧ����Ϣ��������%d�ɼ���", i + 1);
            scanf("%lf", &student->intro_courses[i]);
            if (student->intro_courses[i] >= 0 && student->intro_courses[i] <= 100) {
                student->first_score += student->intro_courses[i];
                break;
            }
            printf("�����󡿻����γɼ�����Ϊ100��\n");
        }
    }

    for (i = 0; i < 2; i++) {
        while (1) {
            printf("���޸�ѧ����Ϣ��רҵ��%d�ɼ���", i + 1);
            scanf("%lf", &student->spec_courses[i]);
            if (student->spec_courses[i] >= 0 && student->spec_courses[i] <= 150) {
                student->first_score += student->spec_courses[i];
                break;
            }
            printf("������רҵ�γɼ�����Ϊ150��\n");
        }
    }

    printf("���޸�ѧ����Ϣ�����Գɼ���");
    scanf("%lf", &student->second_score);

    printf("���޸�ѧ����Ϣ������ɼ���");
    scanf("%lf", &student->speaking_score);

    student->overall_score = student->first_score * 0.6 + student->second_score * 0.3 + student->speaking_score * 0.1;

    update_account_info();
    printf("\n���޸ĳɹ���\n\n");
}

// ��ѯѧ����Ϣ
void search_student_info() {
    char id[10] = {0};
    printf("����ѯѧ����Ϣ�����Կ��ţ�");
    scanf("%s", id);
    student_info_t *student = get_student_by_id(id);
    if (!student) {
        printf("������δ�ҵ��ÿ���\n\n");
        return;
    }

    printf("\n");
    printf("***** ������Ϣ *****\n");
    printf("���Կ��ţ�%s\n", student->id);
    printf("��    ����%s\n", student->name);
    printf("������ 1��%.2f\n", student->intro_courses[0]);
    printf("������ 2��%.2f\n", student->intro_courses[1]);
    printf("רҵ�� 1��%.2f\n", student->spec_courses[0]);
    printf("רҵ�� 2��%.2f\n", student->spec_courses[1]);
    printf("���Գɼ���%.2f\n", student->first_score);
    printf("���Գɼ���%.2f\n", student->second_score);
    printf("����ɼ���%.2f\n", student->speaking_score);
    printf("�ۺϳɼ���%.2f\n", student->overall_score);
    printf("\n\n");
}

/*************************
 *      ѧ������ͳ��      *
 *************************/

// ������������
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

        if (strcmp(student->type, "ѧ˶") == 0) {
            student->next = taught_student_list->next;
            taught_student_list->next = student;
        } else if (strcmp(student->type, "ר˶") == 0) {
            student->next = spec_student_list->next;
            spec_student_list->next = student;
        } else {
            student->next = part_time_student_list->next;
            part_time_student_list->next = student;
        }
    }
}

// �����ۺϳɼ�����
void sort_student_by_overall_score(student_info_t *list) {
    student_info_t *temp1 = NULL;
    student_info_t *temp2 = NULL;
	//   char id[10];              // ���Կ���
    //char name[64];            // ����
   // char school[64];          // ����ѧԺ
   // char type[32];            // �������
   // double intro_courses[2];  // �����γɼ�
  //  double spec_courses[2];   // רҵ�γɼ�
   // double first_score;       // �����ܷ�
   // double second_score;      //���Գɼ�
  //  double speaking_score;    // ����ɼ�
  //  double overall_score;     // �ۺϳɼ�

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

// ������Ϣ���ļ�
void export_student_info_to_file(const char *filename, student_info_t *list) {
    FILE *fp = fopen(filename, "w");
    student_info_t *temp = list;
    while (temp && temp->next) {
        temp = temp->next;
        fprintf(fp, "%s %s %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", temp->id, temp->name, temp->school, temp->type, temp->intro_courses[0], temp->intro_courses[1], temp->spec_courses[0], temp->spec_courses[1], temp->first_score, temp->second_score, temp->speaking_score, temp->overall_score);
    }
    fclose(fp);
}

// ��ѧ���ۺϳɼ��������ʽ
void sort_student_by_score() {
    sort_student_by_overall_score(taught_student_list);
    sort_student_by_overall_score(spec_student_list);
    sort_student_by_overall_score(part_time_student_list);
}

// ��ȡѧ��ͳ����Ϣ
void get_student_statistic() {
    category_student_by_type();
    sort_student_by_score();
    export_student_info_to_file("data3.txt", taught_student_list);
    export_student_info_to_file("data4.txt", spec_student_list);
    export_student_info_to_file("data5.txt", part_time_student_list);
}

void display_student_info(student_info_t *student) {
    printf("***** ������Ϣ *****\n");
    printf("���Կ��ţ�%s\n", student->id);
    printf("��    ����%s\n", student->name);
    printf("������ 1��%.2f\n", student->intro_courses[0]);
    printf("������ 2��%.2f\n", student->intro_courses[1]);
    printf("רҵ�� 1��%.2f\n", student->spec_courses[0]);
    printf("רҵ�� 2��%.2f\n", student->spec_courses[1]);
    printf("���Գɼ���%.2f\n", student->first_score);
    printf("���Գɼ���%.2f\n", student->second_score);
    printf("����ɼ���%.2f\n", student->speaking_score);
    printf("�ۺϳɼ���%.2f\n", student->overall_score);
}

void display_all_students_info() {
    student_info_t *temp = student_info_list;
    while (temp && temp->next) {
        temp = temp->next;
        display_student_info(temp);
        printf("\n\n");
    }
}