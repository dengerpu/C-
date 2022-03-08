#define _CRT_SECURE_NO_WARNINGS
#include "Toschool.h"

//初始化学生信息
void InitStudent(Students* p) {
	memset(p->data, 0, sizeof(p->data));
	p->size = 0;
}

int my_substr(char* res, int pos, int len, char* substr) {//从pos开始取len个字符到substr
	char* p = res;
	int i = 0;
	if (pos > strlen(res)) {
		return 0;
	}
	pos--;
	while (i < len) {
		substr[i++] = res[pos++];
		if (pos > strlen(res)) {
			substr[i] = '\0';
		}
	}
	substr[i] = '\0';
	return 1;
}

int Check_stu_num(char str[8]) {
	char year[8] = { 0 };
	char major[8] = { 0 };
	char s[8] = { 0 };
	my_substr(str, 1, 4, year);
	my_substr(str, 5, 2, major);
	my_substr(str, 7, 3, s);
	int int_year = atoi(year);   //atoi将字符串转换为整形
	int int_major = atoi(major);
	int int_s = atoi(s);
	//printf("major:%d\n", int_major);
	//int int_major = atoi()
	if (int_year < 2016 || int_year>2019) {
		printf("学号年份输入有效，请重新输入\n");
		return 0;
	}
	
	if (int_major < 1 || int_major>12) {
		printf("学号学院代码输入有效，请重新输入\n");
		return 0;
	}
	if (int_s < 0 || int_s>999) {
		printf("学号后三位输入有效，请重新输入\n");
		return 0;
	}
	return int_major;
}
char status(char temperate[4], char isCough) {
	float temp = (float)atof(temperate);
	if (temp >= 37.3 && isCough == '1') {
		return '1';
	}
	else {
		return '0';
	}
}
void getCollege(int id, enum college,char* string_college) {
	//通信学院 = 1,    //01	
	//	计算机学院,  //02
	//	光电学院,	 //03
	//	自动化学院, //04
	//	经管学院,    //05
	//	研究生院,    //06
	//	外语学院,    //07
	//	安法学院,     //08
	//	体育学院,     //09
	//	传媒学院,     //10
	//	先进制造学院, //11
	//	马克思主义学院,//12
	switch(id) {
	case 通信学院:strcpy(string_college, "通信学院"); break;
	case 计算机学院:strcpy(string_college, "计算机学院"); break;
	case 光电学院:strcpy(string_college, "光电学院"); break;
	case 自动化学院:strcpy(string_college, "自动化学院"); break;
	case 经管学院:strcpy(string_college, "经管学院"); break;
	case 研究生院:strcpy(string_college, "研究生院"); break;
	case 外语学院:strcpy(string_college, "外语学院"); break;
	case 安法学院:strcpy(string_college, "安法学院"); break;
	case 体育学院:strcpy(string_college, "体育学院"); break;
	case 传媒学院:strcpy(string_college, "传媒学院"); break;
	case 先进制造学院:strcpy(string_college, "先进制造学院"); break;
	case 马克思主义学院:strcpy(string_college, "马克思主义学院"); break;
	};
}

//添加学生信息
void addStudent(Students* p) {
	printf("请输入学生的各项信息\n");
	Student tempData;
	//getchar();
	//char stu_num[8];//学号
	//char name[15];  //姓名
	//char college[20];//学院
	//char temperate[4];//温度
	//char isCough;     ///是否咳嗽
	//char status;      //健康状态
	//char time[5];     //时间
	//char data[8];    //日期
	printf("学生学号：");
	scanf("%s", tempData.stu_num);
	while (!Check_stu_num(tempData.stu_num)) {
		printf("学生学号：");
		scanf("%s", tempData.stu_num);
	}
	getCollege(Check_stu_num(tempData.stu_num), enum_college, tempData.college);
	printf("学生姓名：");
	scanf("%s", tempData.name);
	printf("学生体温：>");
	scanf("%s", tempData.temperate);
	getchar();
	printf("是否咳嗽：");
	scanf("%c", &(tempData.isCough));
	tempData.status = status(tempData.temperate, tempData.isCough);
	printf("时间：");
	scanf("%s", tempData.time);
	printf("日期：");
	scanf("%s", tempData.date);
}
//打印学生信息
void printStudent(Students* p);