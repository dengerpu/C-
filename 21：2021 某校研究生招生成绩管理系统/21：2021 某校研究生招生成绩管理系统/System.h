#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum adminOption {
	EXIT,
	ADDUSER,
	MODIFYUSER,
	DELETEUSER,
	QUERYUSER,
	ADDSTUDENT,
	MODIFYSTUDENT,
	DELETESTUDENT,
	QUERYSTUDENT,
	PRINTUSER,
	PRINTSTUDENT,
	SORT
};


struct Account {
	char account[10];  //�˺�
	char password[10]; //����
	int type;         //�û����ͣ�1.����Ա 2.ϵͳ����Ա 3.ѧ���û�
};

struct Accounts {
	struct Account account;
	struct Accounts* next;
};

struct student {
	char stu_id[10];	//����ѧ��
	char name[20];		//����
	char colleage[20];	//����ѧԺ
	char type[10];      //�������
	char course1[6];	//������1
	char course2[6];	//������2
	char course3[6];	//רҵ��1
	char course4[6];	//רҵ��2
	char ptest[10];		//���Գɼ�
	char retest[10];		//���Գɼ�
	char olanguage[6];  //����ɼ�
	char comprehensive[10];//�ۺϳɼ�
};

struct Node {
	struct student data;
	struct Node* next;
};

//��½
int login(struct Accounts* userList,char* user);
//����Ա�˵�
void adminMenu();
//ϵͳ����Ա�˵�
 void SystemoptionMenu();
//ѧ���˵�
void StudentMenu();
//��ȡ�ļ����û���Ϣ
void readUserInfoFromFile(const char* filename, struct Accounts* listHeadNode);
//�����û���Ϣ���ļ�
void saveUserInfoToFile(const char* filename, struct Accounts* listHeadNode);
//�����û�����
struct Accounts* createUserList();
//�����û����
struct Accounts* createUserNode(struct Account account);
//�û� ͷ�巨������ڵ�
void insertUserNodeNyHead(struct Accounts* listHeadNode, struct Account account);
//�����û�,���ؽ��Ϊ�û����ͣ�����Ҳ�����Ϊ�գ�����Ϊ0
int findUser(struct Accounts* listHeadNode,char* user, char* pwd);
//����������
int getUserLenth(struct Accounts* listHeadNode);
//�����û��޸�����
void AdviceModifyPwd(struct Accounts* userList, char* user, char* pwd);

//����ѧ���ɼ�����
struct Node* createList();
//����ѧ���ɼ����
struct Node* createNode(struct Node data);
//ѧ���ɼ� ͷ�巨������ڵ�
void insertNodeNyHead(struct Node* listHeadNode, struct student data);
//����ѧ���ɼ�������
int getStudentLenth(struct Node* listHeadNode);
//��ȡ�ļ���ѧ���ɼ���Ϣ
void readStudentInfoFromFile(const char* filename, struct Node* listHeadNode);
//����ѧ����Ϣ���ļ�
void saveStudentInfoToFile(const char* filename, struct Node* listHeadNode);
//����������ѧ����Ϣ���ļ�
void saveSortStudentInfoToFile(const char* filename, struct Node* listHeadNode);
