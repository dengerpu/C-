#define _CRT_SECURE_NO_WARNINGS
#include "Toschool.h"
#include "utils.h"

enum college {
	通信学院 = 1,    //01	
	计算机学院,  //02
	光电学院,	 //03
	自动化学院, //04
	经管学院,    //05
	研究生院,    //06
	外语学院,    //07
	安法学院,     //08
	体育学院,     //09
	传媒学院,     //10
	先进制造学院, //11
	马克思主义学院,//12
}enum_college;

//加载学生信息
void loadStudent(const char* filename, Students* p) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w");
	}
	Student tempData;
	while ((fscanf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\n",
		tempData.stu_num,
		tempData.name,
		tempData.college,
		tempData.temperate,
		&(tempData.isCough),
		&(tempData.status),
		tempData.time,
		tempData.date)) != EOF) {
		p->data[p->size++] = tempData;
	}
}

//初始化学生信息
void InitStudent(Students* p) {
	memset(p->data, 0, sizeof(p->data));
	p->size = 0;
	loadStudent("data1.txt", p);
}


int Check_stu_num(char str[10]) {
	char year[8] = { 0 };
	char major[8] = { 0 };
	char s[8] = { 0 };
	my_substr(str, 1, 4, year);
	my_substr(str, 5, 2, major);
	my_substr(str, 7, 3, s);
	int int_year = atoi(year);   //atoi将字符串转换为整形
	int int_major = atoi(major);
	int int_s = atoi(s);
	if (strlen(str) != 9) {
		printf("学号位数不对，请重新输入\n");
		return 0;
	}
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
		return '0';
	}
	else {
		return '1';
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
	//printf("体温：%s\n", tempData.temperate);
	getchar();
	printf("是否咳嗽：");
	scanf("%c", &(tempData.isCough));
	//printf("是否咳嗽：%c\n", tempData.isCough);
	tempData.status = status(tempData.temperate, tempData.isCough);
	//printf("健康状态：%c\n", tempData.status);
	printf("时间：");
	scanf("%s", tempData.time);
	//printf("时间：%s\n", tempData.time);
	printf("日期：");
	scanf("%s", tempData.date);
	//printf("日期：%s\n", tempData.date);
	p->data[p->size++] = tempData;
	memset(&tempData, 0, sizeof(tempData));
}
//打印学生信息
void printStudent(const Students* p) {
	if (p->size == 0) {
		printf("学生信息为空\n");
		return ;
	}
	printf("%-8s\t%-6s\t%-10s\t%s\t%s\t%s\t%s\t%s\t\n", "学号", "姓名", "学院", "温度", "是否咳嗽", "健康状态", "时间", "日期");
	for (int i = 0; i < p->size; i++) {
		//printf("%s\n", p->data[i].temperate);
		printf("%-8s\t%-6s\t%-10s\t%s\t%c\t\t%c\t\t%s\t%s\t\n",
			p->data[i].stu_num,
			p->data[i].name,
			p->data[i].college,
			p->data[i].temperate,
			p->data[i].isCough,
			p->data[i].status,
			p->data[i].time,
			p->data[i].date);
	}
}
//通过学号或者姓名查询学生
int findStudentByIdOrName(const char* query,Students *p) {
	int i = 0;
	if (query==NULL) {
		printf("输入要查找的关键词为空\n");
	}
	if (query != NULL) {
		for (i = 0; i < p->size; i++) {
			if ((0 == strcmp(query, p->data[i].stu_num))||(0 == strcmp(query, p->data[i].name))) {
				return i;
			}
		}
		return -1;
	}
}
//修改学生信息
void modifyStudent(Students* p) {
	char query[20] = {0};
	char modify[20] = { 0 };
	char isCough = 0;
	char modify_value[20] = { 0 };
	printf("请输入需要修改信息的学生学号或者姓名：");
	scanf("%s", query);
	int pos = findStudentByIdOrName(query, p);
	if (-1 == pos) {
		printf("查找不到此人信息\n");
	}
	else {
		printf("请输入如要修改的项:\n");
		scanf("%s", modify);
		if (0 == strcmp(modify, "学号")) {
			printf("请输入学号");
			scanf("%s", modify_value);
			strcpy(p->data[pos].stu_num, modify_value);
		}else if (0 == strcmp(modify, "姓名")) {
			printf("请输入姓名");
			scanf("%s", modify_value);
			strcpy(p->data[pos].name, modify_value);
		}
		else if (0 == strcmp(modify, "体温")) {
			printf("请输入体温");
			scanf("%s", modify_value);
			strcpy(p->data[pos].temperate, modify_value);
		}
		else if (0 == strcmp(modify, "是否咳嗽")) {
			printf("请输入是否咳嗽:");
			getchar();
			isCough =getchar();
			//scanf("%c", isCough);
			p->data[pos].isCough = isCough;
		}
		else if (0 == strcmp(modify, "时间")) {
			printf("请输入时间");
			scanf("%s", modify_value);
			strcpy(p->data[pos].time, modify_value);
		}
		else if (0 == strcmp(modify, "日期")) {
			printf("请输入日期");
			scanf("%s", modify_value);
			strcpy(p->data[pos].date, modify_value);
		}
		else{
			printf("没有该修改项\n");
			printf("提示：可修改的项有：学号，姓名，体温，是否咳嗽，事件，日期\n");
			return;
		}
		getCollege(Check_stu_num(p->data[pos].stu_num), enum_college, p->data[pos].college);
		p->data[pos].status = status(p->data[pos].temperate, p->data[pos].isCough);
		printf("修改成功\n");
	}
	
}
//打印单个学生的信息
void printSingleStundet(Student* p) {
	printf("%-8s\t%-6s\t%-10s\t%s\t%c\t\t%c\t\t%s\t%s\t\n",
		p->stu_num,
		p->name,
		p->college,
		p->temperate,
		p->isCough,
		p->status,
		p->time,
		p->date);

}

//查询学生信息并保存到文件中
void findStudentAndSave(char* query,char *date, const char* filename, Students* p) {
	if (query == NULL) {
		printf("查询的学号或者姓名为空\n");
	}else {
		FILE* fp = fopen(filename, "w");
		if (fp == NULL) {
			printf("%s\n", strerror(errno));
			return;
		}
		int flag = 0;
		int print_flag = 1;
		for (int i = 0; i < p->size; i++) {
			if ((0 == strcmp(query, p->data[i].stu_num)) || (0 == strcmp(query, p->data[i].name))) {
				if (strcmp(p->data[i].date, date) <= 0) {
					flag = 1;
					//printf("%s\n", p->data[i].date);
					fprintf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\n",
					p->data[i].stu_num,
					p->data[i].name,
					p->data[i].college,
					p->data[i].temperate,
					p->data[i].isCough,
					p->data[i].status,
					p->data[i].time,
					p->data[i].date);
					if (print_flag) {
						printf("截止到%d年%d月%d日该生的健康管理信息为:\n",getYear(date),getMonth(date),getDay(date));
						printf("%-8s\t%-6s\t%-10s\t%s\t%s\t%s\t%s\t%s\t\n", "学号", "姓名", "学院", "温度", "是否咳嗽", "健康状态", "时间", "日期");
						print_flag = 0;
					}
					printSingleStundet(&(p->data[i]));
				}
				
			}
		}
		if (flag == 0) {
			printf("无符合满足的信息\n");
		}
	}
}
void searchStudent(Students* p) {
	char query[20] = { 0 };
	char date[20] = { 0 };
	printf("请输入学生学号或姓名：");
	scanf("%s", query);
	printf("请输入如截止日期：");
	scanf("%s", date);
	findStudentAndSave(query, date, "data2.txt", p);
}

//保存数据到文件
void saveStudent(const char* filename, const Students * p) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("%s\n", strerror(errno));
	}
	for (int i = 0; i < p->size; i++) {
		//printf("%s\n", p->data[i].temperate);
		fprintf(fp,"%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\n",
			p->data[i].stu_num,
			p->data[i].name,
			p->data[i].college,
			p->data[i].temperate,
			p->data[i].isCough,
			p->data[i].status,
			p->data[i].time,
			p->data[i].date);
	}
	fclose(fp);
	fp = NULL;
}