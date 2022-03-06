#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
	char name[20];  //����
	char num[10];	//ѧ��
	int age;		//����
	char tel[20];	//�绰
	char addr[20];	//��ַ
};

struct Node {
	struct student data;
	struct Node* next;
};

//�˵�
void menu();
//��������
struct Node* createList();
//�������
struct Node* createNode(struct student  data);
//ͷ�巨��������
void insertNoByHead(struct Node* listHeadNode, struct student data);
//��ӡ����
void printList(struct Node* listHeadNode);
//ɾ������
void deleteNodeByStudent_Name(struct Node* listHeadNode, char* name);
//����ѧ�Ų���ѧ����Ϣ
struct Node* searchNodeBynum(struct Node* listHeadNode, char* num);
//��ӡ���
void printNode(struct Node* newNode);
//����ѧ���޸�ѧ����Ϣ
void modifyNodeBynum(struct Node* listHeadNode, char* num);
//��ȡ�ļ��е���Ϣ
void readInfofromfile(const char* filename, struct Node* listHeadNode);
//���浽�ļ���
void saveInfoToFile(const char* filename, struct Node* listHeadNode);