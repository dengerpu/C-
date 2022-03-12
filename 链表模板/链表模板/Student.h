#define _CRT_SECURE_NO_WARNINGS
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
struct Node* createNode(struct Node data);
//ͷ�巨������ڵ�
void insertNodeNyHead(struct Node* listHeadNode, struct student data);
//β�巨������ڵ�
void insertNodeByTail(struct Node* listHeadNode, struct student data);
//ɾ������
void deleteNodeByquery(struct Node* listHeadNode, char* query);
//���ҽ��
struct Node* findNodeByquery(struct Node* listHeadNode, char* query);
//��ӡ����
void printList(struct Node* listHeadNode);
//��ӡ���
void printNode(struct Node* node);
//��ȡ�ļ���Ϣ
void readInfoFromFile(const char* filename, struct Node* listHeadNode);
//������Ϣ���ļ�
void saveInfoToFile(const char* filename, struct Node* listHeadNode);