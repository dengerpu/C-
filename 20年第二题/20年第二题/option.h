#pragma once
#include "utils.h"
#include "list.h"

//初始化系统
void init();
//菜单
void menu();
//登陆
int login();

//添加信息
void addCountry(struct Node* list);


//以表格形式打印数据
void printInfoByTable();
//打印学生链表
void printStudentList(struct Node* list);
//打印学生数组
void printStudentArr(struct student* arr, int length);
//排序
void sort();

