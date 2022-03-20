#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DEFAULT_SZ 10
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
