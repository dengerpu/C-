#define _CRT_SECURE_NO_WARNINGS
#include "System.h"
#include"option.h"

int main() {
	int input = 0;
	struct Accounts* userList = NULL;  //�û�����
	struct Node* list = NULL;		//ѧ���ɼ�����
	userList = createUserList();
	list = createList();
	//��ȡ�û��ļ����û���Ϣ
	readUserInfoFromFile("data1.txt", userList);
	readStudentInfoFromFile("data2.txt", list);
	int type = login(userList);
	system("pause");
	system("cls");
	switch (type)
	{
	case 1:adminOption(userList,list); break;
	case 2:SystemoptionMenu(); break;
	case 3:StudentMenu(); break;
	default:printf("�˳�ϵͳ\n"); EXIT(0); break;
	}
}