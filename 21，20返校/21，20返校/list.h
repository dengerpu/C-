#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DEFAULT_SZ 10
struct student {
	char stu_id[10];	//ѧ��
	char name[20];		//����
	char colleage[20];	//ѧԺ
	char temperate[5];  //�¶�
	char isCough;       //�Ƿ����
	char status;        //����״̬
	char time[10];      //ͳ��ʱ��
	char date[10];      //����
};

struct students {
	struct student* data;   //�洢ѧ�����ݵ�����
	int size;				//���鳤��
	int capicity;			//��ǰ����
};

struct Node {
	struct student data;
	struct Node* next;
};

//����ѧ���ɼ�����
struct Node* createList();
//����ѧ���ɼ����
struct Node* createNode(struct student data);
//ѧ���ɼ� ͷ�巨������ڵ�
void insertNodeNyHead(struct Node* listHeadNode, struct student data);
//����ѧ���ɼ�������
int getStudentLenth(struct Node* listHeadNode);
//��ȡ�ļ���ѧ���ɼ���Ϣ
void readStudentInfoFromFile(const char* filename, struct Node* listHeadNode);
//����ѧ����Ϣ���ļ�
void saveStudentInfoToFile(const char* filename, struct Node* listHeadNode);

//��ʼ��students
void InitStudents(struct students* stu);
//��������Ƿ���
void CheckCapacity(struct students* stu);
//���bug��ȥ��  .
void removedot(char* arr, int length);
