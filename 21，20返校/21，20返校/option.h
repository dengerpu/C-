#pragma once
#include "utils.h"
#include "list.h"

//初始化系统
void init();
//菜单
void menu();
//添加学生信息
void addStudent(struct Node* list);
//修改学生信息
void modifyStudent(struct Node* list);
//以表格形式打印数据
void printInfoByTable(struct Node* list);
//打印学生数组
void printStudentArr(struct student* arr, int length);
//排序
void sort();
//释放内存
void destory(struct Node* list);
