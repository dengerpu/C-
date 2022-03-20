#define _CRT_SECURE_NO_WARNINGS
#include "option.h"
//初始化系统
void init() {
	char cmd[128];
	sprintf(cmd, "mode con lines=%d cols=%d", WIN_HEIGHT, WIN_WIDTH); //改变窗口大小
	system(cmd);
	//初始化链表，加载文件数据等操作
}
//菜单
void menu() {
	printMenuHead(MENU_WIDTH);
	printMenuMidInfo(MENU_WIDTH, "学生信息管理系统");
	printMenuMidInfo(MENU_WIDTH, "");
	const char* subMenus[] = {
		"1.菜单1",
		"2.菜单2",
		"3.菜单3",
		"4.菜单4",
		"5.菜单5",
		"6.菜单6",
		"0.退出系统"
	};
	int count = sizeof(subMenus) / sizeof(subMenus[0]);
	for (int i = 0; i < count; i++) {
		printMenuMidInfo(MENU_WIDTH, subMenus[i]);
	}
	printMenuMidInfo(MENU_WIDTH, "");
	printMenuTail(MENU_WIDTH);
	printMidInfo("请选择（0-6）");
}
//标题栏数据
char head[][COL_LEN_MAX] = { "标题1","标题2","标题3","标题4","标题5","标题6" };
int length = 1;
void showPage(int startIndex, int endIndex) {
	if (endIndex >= length) {
		endIndex = length - 1;
	}
	if (endIndex - startIndex + 1 > DEFAULT_PAGE_NUM) {
		endIndex = startIndex + DEFAULT_PAGE_NUM - 1;
	}
	char row[6][COL_LEN_MAX];
	//system("cls");
	printTableHead(TABLE_WIDTH, 6);
	printTableRow(TABLE_WIDTH, head, sizeof(head) / sizeof(head[0]));
	printTableMidLine(TABLE_WIDTH, 6);
	for (int i = startIndex; i <= endIndex; i++) {
		sprintf(row[0], "%s","内容1");
		sprintf(row[1], "%s", "内容2");
		sprintf(row[2], "%s", "马克思主义学院");
		sprintf(row[3], "%s", "内容4");
		sprintf(row[4], "%s", "内容5");
		sprintf(row[5], "%s", "内容6");
		printTableRow(TABLE_WIDTH, row, 6);
		if (i < endIndex) {
			printTableMidLine(TABLE_WIDTH, 6);
		}
		else {
			printTableTail(TABLE_WIDTH, 6);
		}
	}

}
//打印
void printTable() {
	if (length == 0) {
		printf("还没有学生信息！\n");
		return;
	}
	int pageCount = (length + DEFAULT_PAGE_NUM - 1) / DEFAULT_PAGE_NUM;//计算总页数
	char buff[64];
	for (int i = 0; i < pageCount; i++) {
		showPage(i * DEFAULT_PAGE_NUM, (i + 1) * DEFAULT_PAGE_NUM);
		sprintf(buff, "共%d页 第[%d]页\n", pageCount, i + 1);
		printMidInfo(buff);
	}
}