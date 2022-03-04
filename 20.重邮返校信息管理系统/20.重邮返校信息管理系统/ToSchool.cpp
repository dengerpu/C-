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
	printf("=                   5.请求帮助                             =\n");
	printf("=                   6.退出系统                             =\n");
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
	Student * pr = NULL;
	if (p->size == p->capicty) {
		pr = (Student *)realloc(p->data, sizeof(Student) * DEFAULT_SZ);
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
	printf("请按照下列提示完成信息录入：\n");
	printf("请输入学号：\n");
	gets_s(p->data[p->size].stu_id);   //vs高版本认为gets不安全，可能会因为读取的字符串太长而导致缓冲区溢出甚至程序崩溃
	printf("请输入姓名：\n");
	gets_s(p->data[p->size].name);
	printf("请输入身份证号码：\n");
	gets_s(p->data[p->size].stu_id);
	printf("请输入学生类型（本科生：1/硕士生：2/博士生：3）：\n");
	p->data[p->size].stu_type = getchar();
	printf("请输入所在学院：\n");
	gets_s(p->data[p->size].college);
	printf("请输入所在专业：\n");
	gets_s(p->data[p->size].major);
	printf("请输入返校所经城市：\n");
	gets_s(p->data[p->size].route);
	printf("请输入交通工具：\n");
	gets_s(p->data[p->size].trafficTools);
	printf("过去14天是否密切接触确诊人员（是：1/否：0）：\n");
	p->data[p->size].isCloseContact = getchar();
	printf("请输入入校时的温度：\n");
	//getchar();
	gets_s(p->data[p->size].temperature);
	printf("是否发烧（是：1/否：0）：\n");
	p->data[p->size].isFever = getchar();
	printf("是否咳嗽（是：1/否：0）：\n");
	p->data[p->size].isCough = getchar();
	printf("请输入入校时间：\n");
	gets_s(p->data[p->size].time);
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
void ShowStudent(students* p) {
	if (p->size == 0) {
		printf("学生信息为空\n");
	}
	else {
		int i = 0;
		printf("%-15s\t%-15s\t%-20s\t%-50s\t%s\t%-50s\t%-100s\t%-100s\t%s\t%-10s\t%s\t%s\t%-20s\n", "学号", "姓名", "身份证号", "学院", "学生类型", "专业", "返校路线", "交通工具", "近14天是否有密切接触", "体温", "是否发烧", "是否咳嗽", "进校时间");
		for (i = 0; i < p->size; i++) {
			printf("%-15s\t%-15s\t%-20s\t%-50s\t%s\t%-50s\t%-100s\t%-100s\t%s\t%-10s\t%s\t%s\t%-20s\n",
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