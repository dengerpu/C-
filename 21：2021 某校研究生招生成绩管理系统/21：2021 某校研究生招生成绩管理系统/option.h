#pragma once
#include"System.h"
#include"utils.h"

//管理员操作
void adminOption(struct Accounts* userList, struct Node* list);

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


