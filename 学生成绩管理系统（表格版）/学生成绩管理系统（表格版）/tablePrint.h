#pragma once


#define WIN_WIDTH 160 // 窗口宽度
#define WIN_HEIGHT 60 // 窗口高度
#define TABLE_WIDTH 148 //表格宽度
#define MENU_WIDTH  40 //菜单宽度
#define COL_LEN_MAX 64 //最大列数

//打印表头（适用于打印菜单 ┌──────────┐）
void printMenuHead(int tableWidth);
//打印表格中间的信息（│ 菜单内容│）（适用于输出数据）
void printMenuMidInfo(int tableWidth, const char* str);
//打印表尾（适用于打印菜单 └──────────┘）
void printMenuTail(int tableWidth);

//打印表格标题格式（ ┌───┬───┬───┐标题栏）（适用于输出数据）
void printTableHead(int tableWidth, int cols);
//打印表头数据     （│ 标题1│ 标题2│ 标题3│标题或内容）（适用于输出数据）
void printTableRow(int tableWidth, char cols[][COL_LEN_MAX], int n);
//打印表格中间分割线（├───┼─ ─┼───┤）（适用于输出数据）
void printTableMidLine(int tableWidth, int cols);

//打印表格表尾（      └───┴───┴───┘）（适用于打印数据）
void printTableTail(int tableWidth, int cols);


//居中打印
void printMidInfo(const char* str);

