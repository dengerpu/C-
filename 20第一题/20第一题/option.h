#pragma once
#include "utils.h"
#include "list.h"

//��ʼ��ϵͳ
void init();
//��½
int login();
//�˵�
void menu();
//��ӡѧ����Ϣ
void printStudent(struct Node* list);

//���ѧ����Ϣ
void addStudent(struct Node* list);
//����ѧ��ѧ�Ż����������֤��
struct Node* searchStudent(struct Node* list);
//����
void sortStudent(struct Node* list);
//�޸�ѧ����Ϣ
void modifyStudent();
