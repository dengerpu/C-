#pragma once
#pragma once

//#define MAX 1000  //��󴢴��û���

#define DEFAULT_SZ 3    //����Ĭ�ϵ�����

#define NAME_MAX 20  //���ֵ���󳤶�
#define SEX_MAX 5    //�Ա���󳤶�
#define TELE_MAX 11  //�绰������󳤶�
#define ADDR_MAX 30  //��ַ��󳤶�

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
typedef struct PeoInfo {  //�û���Ϣ
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}*PInfo;
struct Contact {
	struct PeoInfo *data;
	int size;
	int capicty;   //��������
};

//��������
//��ʼ��ͨѶ¼
void InitContact(struct Contact* p);
//����û�
void AddContact(struct Contact* p);

//չʾ�û�
void ShowContact(const struct Contact* p);
//�����û�
void SearchContact(const struct Contact* p);
//ɾ���û�
void DelContact(struct Contact* p);

//�޸��û�
void ModifyContact(struct Contact* p);
//����
void SortContact(struct Contact* p);
//�˳����ͷ��ڴ�
void DestroyContact(Contact* ps);