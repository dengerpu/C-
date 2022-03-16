#define _CRT_SECURE_NO_WARNINGS
#include "System.h"
#include"option.h"

int main() {
	int input = 0;
	char user[10] = { 0 };
	struct Accounts* userList = NULL;  //用户链表
	struct Node* list = NULL;		//学生成绩链表
	userList = createUserList();
	list = createList();
	//读取用户文件中用户信息
	readUserInfoFromFile("data1.txt", userList);
	readStudentInfoFromFile("data2.txt", list);
	int type = login(userList,user);
	system("pause");
	system("cls");
	switch (type)
	{
	case 1:adminOption(userList,list); break;
	case 2:systemOperationOption(userList,list); break;
	case 3:studentOption(list,user); break;
	default:printf("退出系统\n"); EXIT(0); break;
	}
}