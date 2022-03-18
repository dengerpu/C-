#define _CRT_SECURE_NO_WARNINGS
#include "tablePrint.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COUNT 100
#define DEFAULT_PAGE_NUM 10
struct student {
	int num;   //学号
	char name[16];  //姓名
	int cLang;   //c语言
	int algo;    //算法
	int database; //数据库
	int sum;	//总成绩
};
struct student stu[MAX_COUNT];
int currentCount = 0;

void init() {
	char cmd[128];
	sprintf(cmd, "mode con lines=%d cols=%d", WIN_HEIGHT, WIN_WIDTH); //改变窗口大小
	system(cmd);
	//system("color 1f");  //改变颜色，1是窗口背景颜色，f是字体颜色
	memset(stu, 0, sizeof(stu));
	FILE* fp = fopen("data.txt", "rb");
	if (fp == NULL) {
		fopen("data.txt", "w");//文件不存在就不要
		currentCount = 0;
	}
	int i = 0;
	while (!feof(fp)) {
		int ret = fread(&stu[i], sizeof(struct student), 1, fp);
		if (ret == 1) {
			i++;
		}
	}
	currentCount = i;

}
//根据学号查找学生
int searchStu(int id) {
	for (int i = 0; i < currentCount; i++) { 
		if (stu[i].num == id)
		{ 
			return i;
		} 
	}
	return -1;
}
bool save() {
	FILE* fp = fopen("data.txt", "wb");
	if (fp == NULL) {
		fclose(fp);
		return false;
	}
	for (int i = 0; i < currentCount; i++) {
		if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1) {
			fclose(fp);
			return false;
		}
	}
	fclose(fp);
	return true;
}
char head[][COL_LEN_MAX] = { "学号","姓名","C语言","算法","数据库","总分","学号","姓名","C语言","算法","数据库","总分" };
void showPage(int startIndex, int endIndex) {
	if (endIndex >= currentCount) {
		endIndex = currentCount - 1;
	}
	if (endIndex - startIndex + 1 > DEFAULT_PAGE_NUM) {
		endIndex = startIndex + DEFAULT_PAGE_NUM - 1;
	}
	char row[12][COL_LEN_MAX];
	//system("cls");
	printTableHead(TABLE_WIDTH, 12);
	printTableRow(TABLE_WIDTH, head, sizeof(head) / sizeof(head[0]));
	printTableMidLine(TABLE_WIDTH, 12);
	for (int i = startIndex; i <= endIndex; i++) {
		sprintf(row[0], "%d", stu[i].num); 
		sprintf(row[1], "%s", stu[i].name);
		sprintf(row[2], "%d", stu[i].cLang);
		sprintf(row[3], "%d", stu[i].algo); 
		sprintf(row[4], "%d", stu[i].database); 
		sprintf(row[5], "%d", stu[i].sum);
		sprintf(row[6], "%d", stu[i].num);
		sprintf(row[7], "%s", stu[i].name);
		sprintf(row[8], "%d", stu[i].cLang);
		sprintf(row[9], "%d", stu[i].algo);
		sprintf(row[10], "%d", stu[i].database);
		sprintf(row[11], "%d", stu[i].sum);
		printTableRow(TABLE_WIDTH, row, 12);
		if (i < endIndex) {
			printTableMidLine(TABLE_WIDTH, 12);
		}
		else {
			printTableTail(TABLE_WIDTH, 12);
		}
	}
	
}
void show() {
	if (currentCount == 0) {
		printf("还没有学生信息！\n");
		return;
	}
	int pageCount = (currentCount + DEFAULT_PAGE_NUM - 1) / DEFAULT_PAGE_NUM;//计算总页数
	char buff[64];
	for (int i = 0; i < pageCount; i++) {
		showPage(i * DEFAULT_PAGE_NUM, (i + 1) * DEFAULT_PAGE_NUM);
		sprintf(buff, "共%d页 第[%d]页\n", pageCount, i + 1);
		printMidInfo(buff);
	}
}
//输入学生信息
struct student inputInfo() {
		struct student s;
		printf("学号:"); scanf("%d", &s.num);
		printf("姓名:"); scanf("%s", s.name); 
		printf("C 语言:"); scanf("%d", &s.cLang); 
		printf("算法:"); scanf("%d", &s.algo); 
		printf("数据库:"); scanf("%d", &s.database); 
		s.sum = s.cLang + s.algo + s.database;
		return s;
}
//添加学生信息
void input() {
	char str[16];
	struct student s;
	while (1) {
		printMidInfo("输入学生信息：y/n");
		scanf("%s", str);
		if (strcmp("Y", str) != 0 && strcmp("y", str) != 0) {
			break;
		}
		s = inputInfo();
		if (searchStu(s.num) >= 0) {
			printf("学号[%d]已经存在！\n",s.num);
			continue;
		}
		stu[currentCount++] = s;
		if (!save()) {
			printf("保存失败！\n");
		}
		else {
			printf("保存成功！\n");
		}
	}
}
void search() {
	int snum = 0; 
	system("cls"); 
	printf("请输入学号:");
	scanf("%d", &snum); 
	int i = searchStu(snum);
	if (i < 0) { 
		printf("没有找到这名学生！\n"); 
		return; 
	}
	char row[6][COL_LEN_MAX];
	char head[][COL_LEN_MAX] = { "学号", "姓名", "C 语言", "算法", "数据库", "总分" }; 
	printTableHead(TABLE_WIDTH, 6);
	printTableRow(TABLE_WIDTH, head, sizeof(head) / sizeof(head[0]));
	printTableMidLine(TABLE_WIDTH, 6); 
	sprintf(row[0], "%d", stu[i].num); 
	sprintf(row[1], "%s", stu[i].name);
	sprintf(row[2], "%d", stu[i].cLang);
	sprintf(row[3], "%d", stu[i].algo); 
	sprintf(row[4], "%d", stu[i].database); 
	sprintf(row[5], "%d", stu[i].sum); 
	printTableRow(TABLE_WIDTH, row, 6); 
	printTableTail(TABLE_WIDTH, 6);
}

 
void menu() {
	printMenuHead(MENU_WIDTH);
	printMenuMidInfo(MENU_WIDTH, "学生信息管理系统");
	printMenuMidInfo(MENU_WIDTH, "");
	const char* subMenus[] = {
		"1.输入学生信息",
		"2.查找学生信息",
		"3.删除学生信息",
		"4.修改学生信息",
		"5.插入学生信息",
		"6.学生成绩排名",
		"7.统计学生总数",
		"8.显示所有信息",
		"0.退出系统    "
	};
	int count = sizeof(subMenus) / sizeof(subMenus[0]);
	for (int i = 0; i < count; i++) {
		printMenuMidInfo(MENU_WIDTH, subMenus[i]);
	}
	printMenuMidInfo(MENU_WIDTH, "");
	printMenuTail(MENU_WIDTH);
	printMidInfo("请选择（0-8）");
}

int main() {
	init();
	int n = 0;
	do {
		menu();
		scanf("%d", &n);
		switch (n) {
		case 1: input();break;
		case 2: search();break;
		case 3:  break; 
		case 4:  break; 
		case 5:  break; 
		case 6:  break; 
		case 7:  break; 
		case 8: show(); break; 
		case 0:printf("退出\n"); exit(0); break;
		default:printMidInfo("输入有误，请重新输入\n"); break;
		}
		system("pause");
		system("cls");
	} while (n);
	return 0;
}