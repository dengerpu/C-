#pragma once
#include "utils.h"
#include "list.h"

//��ʼ��ϵͳ
void init();
//�˵�
void menu();
//�Ա�����ʽ��ӡ����
void printInfoByTable();
//��ӡѧ������
void printStudentList(struct Node* list);
//��ӡѧ������
void printStudentArr(struct student* arr, int length);
//����
void sort();
//