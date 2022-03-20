#pragma once
#include "utils.h"
#include "list.h"

//初始化系统
void init();
//登陆
int login();
//菜单
void menu();
//打印学生信息
void printStudent(struct Node* list);

//添加学生信息
void addStudent(struct Node* list);
//根据学生学号或姓名或身份证号
struct Node* searchStudent(struct Node* list);
//排序
void sortStudent(struct Node* list);
//修改学生信息
void modifyStudent();
