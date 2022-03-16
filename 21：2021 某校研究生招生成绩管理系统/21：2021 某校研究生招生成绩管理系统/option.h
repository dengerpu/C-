#pragma once
#include"System.h"
#include"utils.h"

//管理员操作
void adminOption(struct Accounts* userList, struct Node* list);
//系统操作员操作
void systemOperationOption(struct Accounts* userList, struct Node* list);
//学生操作
void studentOption(struct Node* list,char* sid);

//添加用户
void addUser(struct Accounts* userList);
//查找用户
int findUserByUsername(struct Accounts* userList, char* username);
//修改用户
int modifyUserByUsername(struct Accounts* userList);
//删除用户
int deleteUserByUsername(struct Accounts* userList,char* sid);
//查找用户
int queryUserByUsername(struct Accounts* userList);
//查找所用用户
void queryAllUser(struct Accounts* userList);

//添加学生成绩
void addStudent(struct Accounts* userList, struct Node* list);
//修改用户
void modifyStudentBySid(struct Node* list);
//删除学生账户，同时删除用户
int deleteStudentBySid(struct Accounts* userList, struct Node* list);
//通过学生姓名或者查找
int queryStudentBynameOrsid(struct Node* list);
//查找学生成绩
void queryAllStudent(struct Node* list);
//排序
void sort(struct Node* list);

//释放内存
void destory(struct Accounts* userList, struct Node* list);

//查找学生用户（直接返回该学生信息，上个用户相同的模块做麻烦了）
struct Node* findStudentBySid(struct Node* list, char* sid);
//打印学生成绩
void printSingleStudent(struct Node* list, char* sid);

