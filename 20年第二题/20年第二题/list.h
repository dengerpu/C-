#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DEFAULT_SZ 10
struct country {
	char country_name[20];	//����
	char continent[20];  	//��
	int total_peoples;	     //�˿�����
	double country_area;     //�������
	double builder_area;	//���������
	double people_density;  //�ܶ�
	int add;	//����ȷ��
	int total ;	//�ۼ�ȷ��
	int death;	//�ۼ�����
	int cure;		//�ۼ�����
	double mortality;		//������
	double cure_rate;  //������
	char severity_index;//����ָ��
};

struct courties {
	struct country* data;   //�洢ѧ�����ݵ�����
	int size;				//���鳤��
	int capicity;			//��ǰ����
};

struct Node {
	struct country data;
	struct Node* next;
};

//����ѧ���ɼ�����
struct Node* createList();
//����ѧ���ɼ����
struct Node* createNode(struct country data);
//ѧ���ɼ� ͷ�巨������ڵ�
void insertNodeNyHead(struct Node* listHeadNode, struct country data);
//����ѧ���ɼ�������
int getStudentLenth(struct Node* listHeadNode);
//��ȡ�ļ���ѧ���ɼ���Ϣ
void readStudentInfoFromFile(const char* filename, struct Node* listHeadNode);
//����ѧ����Ϣ���ļ�
void saveStudentInfoToFile(const char* filename, struct Node* listHeadNode);

//��ʼ��students
void InitStudents(struct countrys* stu);
//��������Ƿ���
void CheckCapacity(struct countrys* stu);
//���bug��ȥ��  .
void removedot(char* arr, int length);
