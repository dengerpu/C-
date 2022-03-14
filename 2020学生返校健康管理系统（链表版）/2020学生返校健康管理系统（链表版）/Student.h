#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"

enum option {
	EXIT,
	ADD,
	MODIFY,
	QUERY,
	STATISTICS,
	ADVICE,
	PRINT
};

struct student {
	char stu_id[10];	//ѧ��
	char name[20];		//����
	char colleage[20];	//ѧԺ
	char temperate[5];	//����
	char isCough;		//�Ƿ����
	char status;		//����״̬
	char time[10];			//ͳ��ʱ��
	char date[10];			//����
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
//����������
int getLenth(struct Node* listHeadNode);
//��ӡ����
void printList(struct Node* listHeadNode);
//��ӡ���
void printNode(struct Node* node);
//��ȡ�ļ���Ϣ
void readInfoFromFile(const char* filename, struct Node* listHeadNode);
//������Ϣ���ļ�
void saveInfoToFile(const char* filename, struct Node* listHeadNode);