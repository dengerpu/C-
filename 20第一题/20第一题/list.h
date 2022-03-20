#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DEFAULT_SZ 10

struct student {
	char stu_id[12];//ѧ��
	char name[20];	//����
	char sid[20];	//���֤��
	char college[20];//ѧԺ
	char type[20];	//ѧ������
	char major[20];	//רҵ
	char route[20];	//��У·��
	char traffic[20];//��ͨ����
	char isClose[10];//���нӴ�
	char temperate[10];//�¶�
	char history[20]; //��ȥ14�첡ʷ
	char isCough[5];//�Ƿ���
	char time[20];  //��Уʱ��
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
void saveStudentInfoToFile(struct Node* listHeadNode);
//��������ѧ����Ϣ���ļ�
void saveALLStudentInfoToFile(const char* filename, struct Node* listHeadNode);
//����������������Ϣ���ļ���
void saveStudentArrInfoToFile(const char* filename, struct student* arr, int length);

//��ʼ��students
void InitStudents(struct students* stu);
//��������Ƿ���
void CheckCapacity(struct students* stu);
