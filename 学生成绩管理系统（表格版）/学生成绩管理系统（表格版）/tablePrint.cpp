#include <stdio.h>
#include <string.h>
#include "tablePrint.h"

//打印表头（┌───────┐）（适用于打印菜单）
void printMenuHead(int tableWidth) {
	int margin = (WIN_WIDTH - tableWidth) / 2;  //（窗口宽度-菜单宽度）/2
	for (int i = 0; i < margin; i++) printf(" "); //居中
	printf("┌");
	for (int i = 0; i < tableWidth - 2; i++)printf("─");
	printf("┐\n");
}
//打印表格中间的信息（│    菜单内容   │）（适用于打印菜单）
void printMenuMidInfo(int tableWidth, const char* str) {
	int margin = (WIN_WIDTH - tableWidth) / 2;
	for (int i = 0; i < margin; i++) printf(" ");//居中
	printf("│");
	//-2是减去左右 |所占的空间
	int len1 = (tableWidth - 2 - strlen(str)) / 2;//内容居中
	for (int i = 0; i < len1; i++) printf(" ");

	printf("%s", str);

	int len2 = tableWidth - 2 - len1 - strlen(str);
	for (int i = 0; i < len2; i++) printf(" ");

	printf("│\n");
}
//打印表尾（适用于打印菜单 └──────────┘）
void printMenuTail(int tableWidth) {
	int margin = (WIN_WIDTH - tableWidth) / 2;
	for (int i = 0; i < margin; i++) printf(" ");  //居中
	printf("└");
	for (int i = 0; i < tableWidth - 2; i++)printf("─");
	printf("┘\n");
}


//打印表格标题格式（ ┌───┬───┬───┐标题栏）（适用于输出数据）
void printTableHead(int tableWidth, int cols) {
	int margin = (WIN_WIDTH - tableWidth) / 2;
	int spanLen = (tableWidth - (cols + 1)) / cols;//打印cols列需要cols+1个|
	for (int i = 0; i < margin; i++) printf(" ");//居中

	printf("┌");
	for (int i = 0; i < cols; i++) {//打印每一列
		for (int j = 0; j < spanLen; j++) {
			printf("─");
		}

		if (i < cols - 1) {
			printf("┬");
		}
		else {
			printf("┐");
		}
	}
	printf("\n");
}
//打印表头数据     （│ 标题1│ 标题2│ 标题3│标题或内容）（适用于输出数据）
void printTableRow(int tableWidth, char cols[][COL_LEN_MAX], int n) {
	int margin = (WIN_WIDTH - tableWidth) / 2;
	for (int i = 0; i < margin; i++) printf(" ");//居中

	int colWidth = (tableWidth - (n + 1)) / n;

	for (int i = 0; i < n; i++) {
		printf("│");

		int leftSpan = (colWidth - strlen(cols[i])) / 2;//左边空格数
		int rightSpan = colWidth - leftSpan - strlen(cols[i]);//右边空格数

		for (int j = 0; j < leftSpan; j++) printf(" ");
		printf("%s", cols[i]);
		for (int j = 0; j < rightSpan; j++) printf(" ");
	}

	printf("│\n");
}

//打印表格中间分割线（├───┼─ ─┼───┤）（适用于输出数据）
void printTableMidLine(int tableWidth, int cols) {
	int margin = (WIN_WIDTH - tableWidth) / 2;
	int spanLen = (tableWidth - (cols + 1)) / cols;
	for (int i = 0; i < margin; i++) printf(" ");

	printf("├");
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < spanLen; j++) {
			printf("─");
		}

		if (i < cols - 1) {
			printf("┼");
		}
		else {
			printf("┤");
		}
	}
	printf("\n");
}
//打印表格表尾（      └───┴───┴───┘）（适用于打印数据）
void printTableTail(int tableWidth, int cols) {
	int margin = (WIN_WIDTH - tableWidth) / 2;
	int spanLen = (tableWidth - (cols + 1)) / cols;
	for (int i = 0; i < margin; i++) printf(" ");

	//└─┴─┘
	printf("└");
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < spanLen; j++) {
			printf("─");
		}

		if (i < cols - 1) {
			printf("┴");
		}
		else {
			printf("┘");
		}
	}
	printf("\n");
}


//居中打印
void printMidInfo(const char* str) {
	int margin = (WIN_WIDTH - strlen(str)) / 2;
	for (int i = 0; i < margin; i++) printf(" ");
	printf("%s", str);
}


