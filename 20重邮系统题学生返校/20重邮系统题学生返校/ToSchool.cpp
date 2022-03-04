#define _CRT_SECURE_NO_WARNINGS
#include "ToSchool.h"


void Login() {
	char password[20] = { 0 };
	int i = 5;
	printf("\n\n");
	printf("====================学生返校信息管理系统====================\n");
	while (i > 0) {
		printf("请输入登录密码:>");
		scanf("%s", &password);
		if (strcmp(password, "123456") != 0) {
			i--;
			printf("密码输入错误，请重新输入,您还有%d次机会\n", i);
		}
		else {
			printf("密码输入正确\n");
			break;
		}
		if (i == 0) { exit(0); }
	}
}

//菜单
void menu() {
	printf("====================学生返校信息管理系统====================\n");
	printf("=                                                          =\n");
	printf("=                   ***功能介绍***                         =\n");
	printf("=                                                          =\n");
	printf("=                   1.录入学生信息                         =\n");
	printf("=                   2.查找学生信息                         =\n");
	printf("=                   3.修改学生信息                         =\n");
	printf("=                   4.按顺序输出某学院学生信息             =\n");
	printf("=                   5.显示学生信息                         =\n");
	printf("=                   0.退出系统                             =\n");
	printf("=                                                          =\n");
	printf("=                                                          =\n");
	printf("============================================================\n");
}

//初始化
void Init(students* p) {
	//memset(p->data, 0, sizeof(p->data));
	p->data = MALLOC(Student, DEFAULT_SZ);
	if (p->data == NULL) {
		printf("%s\n", strerror(errno));  //打印错误信息
		return;
	}
	p->capicty = DEFAULT_SZ;
	p->size = 0;
	//加载文件中学生信息
	//LoadStudent(students * p);
}
//检查容量是够
void CheckCapacity(students* p) {
	Student* pr = NULL;
	if (p->size == p->capicty) {
		pr = (Student*)realloc(p->data, sizeof(Student) * DEFAULT_SZ);
		if (pr != NULL) {
			p->data = pr;
			p->capicty += DEFAULT_SZ;
			printf("增容成功\n");
		}
		else {
			printf("增容失败\n");
			printf("%s\n", strerror(errno));
			return;
		}
	}
}

//添加学生信息
void AddStudent(students* p) {  
	CheckCapacity(p);
	//char file[50] = { 0 };
	//FILE* fp = NULL;
	printf("请按照下列提示完成信息录入：>\n");
	printf("请输入学号：>");
	scanf("%s",p->data[p->size].stu_num);   //vs高版本认为gets不安全，可能会因为读取的字符串太长而导致缓冲区溢出甚至程序崩溃
	printf("请输入姓名：>");
	scanf("%s", p->data[p->size].name);
	printf("请输入身份证号码：>");
	scanf("%s", p->data[p->size].stu_id);
	getchar();
	printf("请输入学生类型（本科生：1/硕士生：2/博士生：3/本科生）：>");
	scanf("%c", &(p->data[p->size].stu_type));
	printf("%d\n", p->data[p->size].stu_type);
	printf("请输入所在学院：>");
	scanf("%s", p->data[p->size].college);
	printf("请输入所在专业：>");
	scanf("%s", p->data[p->size].major);
	printf("请输入返校所经城市：>");
	scanf("%s", p->data[p->size].route);
	printf("请输入交通工具：>");
	scanf("%s", p->data[p->size].trafficTools);
	getchar();
	printf("过去14天是否密切接触确诊人员（是：1/否：0）：>");
	scanf("%c", &(p->data[p->size].isCloseContact));
	printf("请输入入校时的温度：>");
	//getchar();
	scanf("%s", p->data[p->size].temperature);
	printf("是否发烧（是：1/否：0）：>");
	getchar();
	scanf("%c", &(p->data[p->size].isFever));
	printf("是否咳嗽（是：1/否：0）：>");
	getchar();
	scanf("%c", &(p->data[p->size].isCough));
	printf("请输入入校时间：>");
	scanf("%s", p->data[p->size].time);
	p->size++;

	//strcat(file, p->data[p->size].college);
	//strcat(file, ".txt");

	//fp = fopen(file, "a");//用“a”的方式打开文件，向文件末尾继续添加新的数据（不删除原有数据）
	//if (fp == NULL) {
	//	printf("%s\n", strerror(errno));
	//	exit(0);
	//}
	//if (fwrite(p->data, sizeof(Student), 1, fp) != 1) {
	//	printf("无法录入\n");
	//}
	//fclose(fp);
}

//展示学生信息
void ShowStudent(const students* p) {
	if (p->size == 0) {
		printf("学生信息为空\n");
	}
	else {
		int i = 0;
		//printf("%-15s\t%-15s\t%-20s\t%-50s\t%s\t%-50s\t%-100s\t%-100s\t%s\t%-10s\t%s\t%s\t%-20s\n", "学号", "姓名", "身份证号", "学院", "学生类型", "专业", "返校路线", "交通工具", "近14天是否有密切接触", "体温", "是否发烧", "是否咳嗽", "进校时间");
		for (i = 0; i < p->size; i++) {
			printf("学号：%-15s\t姓名：%-15s\t身份证号：%-20s\t\n学院：%-20s\t学生类型：%c\t专业：%-20s\t\n返校路线：%-20s\t交通工具：%-20s\t\n近14天是否有密切接触：%c\t体温：%-10s\t是否发烧：%c\t是否咳嗽：%c\t进校时间：%-20s\n",
				p->data[i].stu_num,
				p->data[i].name,
				p->data[i].stu_id,
				p->data[i].college,
				p->data[i].stu_type,
				p->data[i].major,
				p->data[i].route,
				p->data[i].trafficTools,
				p->data[i].isCloseContact,
				p->data[i].temperature,
				p->data[i].isFever,
				p->data[i].isCough,
				p->data[i].time
			);
		}
	}
}
void Print(const students* p,int i) {
	printf("学号：%-15s\t姓名：%-15s\t身份证号：%-20s\t\n学院：%-20s\t学生类型：%c\t专业：%-20s\t\n返校路线：%-20s\t交通工具：%-20s\t\n近14天是否有密切接触：%c\t体温：%-10s\t是否发烧：%c\t是否咳嗽：%c\t进校时间：%-20s\n",
		p->data[i].stu_num,
		p->data[i].name,
		p->data[i].stu_id,
		p->data[i].college,
		p->data[i].stu_type,
		p->data[i].major,
		p->data[i].route,
		p->data[i].trafficTools,
		p->data[i].isCloseContact,
		p->data[i].temperature,
		p->data[i].isFever,
		p->data[i].isCough,
		p->data[i].time);
}
//根据姓名查找
void FindByName(const students* p, char name[15]) {
	if (p->size == 0) {
		printf("学生信息表为空\n");
	}
	else {
		for (int i = 0; i < p->size; i++) {
			if (0 == strcmp(name, p->data[i].name)) {
				Print(p, i);
			}
		}
	}
}
//根据学院查找
void FindByCollege(const students* p, char college[30]) {
	if (p->size == 0) {
		printf("学生信息表为空\n");
	}
	else {
		for (int i = 0; i < p->size; i++) {
			if (0 == strcmp(college, p->data[i].college)) {
				Print(p, i);
			}
		}
	}
}

//搜索信息
void SearchStudent(const students* p){
	int s = 0;
	char info[50];
	printf("请选择：>(1.名字 2.学院)");
	scanf("%d", &s);
	if (s == 2) {
		printf("请输入要查找的学院：>");
		scanf("%s", info);
		FindByCollege(p, info);
	}
	else{
		printf("请输入要查找的名字：>");
		scanf("%s", info);
		FindByName(p, info);
	}
}

int FindByNameID(const students* p, char name[15]) {
	if (p->size == 0) {
		printf("学生信息表为空\n");
	}
	else {
		for (int i = 0; i < p->size; i++) {
			if (0 == strcmp(name, p->data[i].name)) {
				return i;
			}
		}
	}
}
void MOdifyStudent(students* p) {
	char name[15];
	int ret = 0;
	printf("请输入要修改的名字\n");
	scanf("%s", name);
	ret = FindByNameID(p, name);
	//模拟修改
	strcpy(p->data->name, "修改");
}

int  cmp_bynum(const void *e1,const void *e2) {
	return strcmp(((Student*)e1)->stu_num, ((Student*)e2)->stu_num);
}

//排序
void SortStudent(students* p) {
	printf("请输入排序方式：0：学号  1：姓名（默认为0）\n");
	int input = 0;
	scanf("%d", &input);
	if (input == 1) {
		qsort(p->data, p->size, sizeof(p->data[0]), cmp_bynum);
		ShowStudent(p);
	}
	else {
	
	}
}