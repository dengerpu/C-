#define _CRT_SECURE_NO_WARNINGS
#include "utils.h"

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

//截取字符串
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


//获取学号年份
int getSidYear(char* id) {
	char year[5] = { 0 };
	if (id == NULL) {
		return 0;
	}
	else {
		my_substr(id, 1, 4, year);
		return atoi(year);
	}
}
//获取学号学院代号
int getSidCollege(char* id) {
	char college[3] = { 0 };
	if (id == NULL) {
		return 0;
	}
	else {
		my_substr(id, 5, 2, college);
		return atoi(college);
	}
}
//获取学号随机数
int getSidNum(char* id) {
	char random_num[4] = { 0 };
	if (id == NULL) {
		return 0;
	}
	else {
		my_substr(id, 7, 3, random_num);
		return atoi(random_num);
	}

}


//获取年份
int getYear(char* date) {
	char year[5] = { 0 };
	if (date == NULL) {
		return 0;
	}
	else {
		my_substr(date, 1, 4, year);
		return atoi(year);
	}
}
//获取月
int getMonth(char* date) {
	char month[3] = { 0 };
	if (date == NULL) {
		return 0;
	}
	else {
		my_substr(date, 5, 2, month);
		return atoi(month);
	}
}
//获取日
int getDay(char* date) {
	char day[3] = { 0 };
	if (date == NULL) {
		return 0;
	}
	else {
		my_substr(date, 7, 2, day);
		return atoi(day);
	}
}

//获取学院
void getCollege(int num, char* college) {
	switch (num) {
	case 通信学院:strcpy(college, "通信学院"); break;
	case 计算机学院:strcpy(college, "计算机学院"); break;
	case 光电学院:strcpy(college, "光电学院"); break;
	case 自动化学院:strcpy(college, "自动化学院"); break;
	case 经管学院:strcpy(college, "经管学院"); break;
	case 研究生院:strcpy(college, "研究生院"); break;
	case 外语学院:strcpy(college, "外语学院"); break;
	case 安法学院:strcpy(college, "安法学院"); break;
	case 体育学院:strcpy(college, "体育学院"); break;
	case 传媒学院:strcpy(college, "传媒学院"); break;
	case 先进制造学院:strcpy(college, "先进制造学院"); break;
	case 马克思主义学院:strcpy(college, "马克思主义学院"); break;
	default:strcpy(college, "无"); break;
	};
}
