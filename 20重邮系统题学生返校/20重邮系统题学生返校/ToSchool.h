#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define DEFAULT_SZ 10  //����Ĭ�ϵĴ����������������̬����ͬ����С��
#define MALLOC(type,num) (type*)malloc(num*sizeof(type))  //����һ����

enum OPTION {
	EXIT,
	ADD,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
};

typedef struct studentInfo {   //ѧ����Ϣ
	char stu_num[15];      //ѧ��
	char name[15];         //����
	char stu_id[20];       //���֤��
	char college[50];      //ѧԺ
	char stu_type;         //ѧ������
	char major[50];        //רҵ
	char route[100];       //��У·��
	char trafficTools[100];//��ͨ����
	char isCloseContact;   //��14���Ƿ������нӴ�ȷ����Ա
	char temperature[10];  //��Уʱ�¶�
	char isFever;		   //�Ƿ���
	char isCough;		   //�Ƿ����
	char time[20];		  //��Уʱ��


}Student;
struct students {
	Student* data;
	int size;
	int capicty;
};
//��½
void Login();
//�˵�
void menu();
//����ѧ����Ϣ
void LoadStudent(students* p);
//��ʼ��
void Init(students* p);
//��������Ƿ���
void CheckCapacity(students* p);
//���ѧ����Ϣ
void AddStudent(students* p);
//չʾѧ����Ϣ
void ShowStudent(const students* p);
//������Ϣ
void SearchStudent(const students* p);
//�޸���Ϣ
void MOdifyStudent(students* p);
//����
void SortStudent(students* p);

