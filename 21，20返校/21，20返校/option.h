#pragma once
#include "utils.h"
#include "list.h"

//��ʼ��ϵͳ
void init();
//�˵�
void menu();
//���ѧ����Ϣ
void addStudent(struct Node* list);
//�޸�ѧ����Ϣ
void modifyStudent(struct Node* list);
//��ѯ��ͳ��ѧ����Ϣ
void searchStudent(struct Node* list);
//�쳣ѧ����Ϣͳ��
void abnormalStudent(struct Node* list);
//����Ԥ��
void adviceStudent(struct Node* list);
//�Ա����ʽ��ӡ����
void printInfoByTable(struct Node* list);
//��ӡѧ������
void printStudentArr(struct student* arr, int length);
//����
void sort();
//�ͷ��ڴ�
void destory(struct Node* list);
