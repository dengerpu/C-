#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
����ѧ��������Ϣ���ݽṹ
*/
typedef struct student {
	char name[20];
	char stuID[20];
	char academy[20];
	float temperature;
	int cough;
	int state;
	char time[10];
	char date[20];
	int day;
}student;

/***********����ѧ�����ͽ��*************/
typedef struct Node {
	student data;
	struct Node* next;
}Node;

/*
�������ܣ�������ͷ���ĵ�����
��������
����ֵ������ͷָ��
*/
Node* createList() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	return head;
}


/*
�������ܣ�������
����������ͷָ�룬ѧ����Ϣ
����ֵ������������ͷָ��
*/
insertNode(Node* list, student data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = list->next;
	list->next = newNode;
	newNode->data = data;
}

/*
�������ܣ�ͨ��ѧ�ź����ڲ��ҽ����
����������ͷָ�룬ѧ������������
����ֵ�����ҵ��Ľ��
*/
Node* searchNode(Node* list, char* stuID,char* date) {
	Node* node = list->next;
	while (node != NULL && strcmp(node->data.stuID, stuID) != 0 && strcmp(node->data.stuID, date) != 0) {
		node = node->next;
	}
	return node;
}


/*
�������ܣ�ͨ���������ҽ����
����������ͷָ�룬ѧ������
����ֵ�����ҵ��Ľ��
*/
Node* searchNodeByName(Node* list,char* name) {
	Node* node = list->next;
	while (node != NULL && strcmp(node->data.name, name) != 0) {
		node = node->next;
	}
	return node;
}

/*
 �������ܣ�ͨ��ѧ�Ų��ҽ����
 ����������ͷָ�룬ѧ��ѧ��
 ����ֵ�����ҵ��Ľ��
*/
Node* searchNodeByID(Node* list, char* stuID) {
	Node* node = list->next;
	while (node != NULL && strcmp(node->data.stuID, stuID) != 0 ) {
		node = node->next;
	}
	return node;
}

/*
�������ܣ�ɾ�����
����������ͷָ�룬ѧ��ѧ��
����ֵ����
*/
void deleteNode(Node* list, char* stuID) {
	Node* pre = list;//��Ҫɾ������ǰ��
	Node* p = list->next;//��Ҫɾ���Ľ��
	if (p == NULL) {
		printf("û�������Ϣ��\n");
		return;
	}
	else {
		while (strcmp(p->data.stuID, stuID)) {
			pre = p;
			p = p->next;
			if (p == NULL) {
				printf("û�������Ϣ!\n");
				return;
			}
		}
		pre->next = p->next;//ɾ�����
		free(p);
	}
}

/*
�������ܣ����������Ϣ
����������ͷָ��
����ֵ����
*/
printList(Node* list) {
	if (list->next == NULL) {
		printf("�޿ɲ�ѯ��Ϣ��\n");
		return;
	}
	Node* p = list->next;
	printf("|------------------------------------------------------------------------------------|\n");
	printf("|%-10s|%-10s|%-15s|%-8s|%-8s|%-8s|%-8s|%-10s|\n", "ѧ��", "����", "ѧԺ", "����",
		"�Ƿ����", "����״̬", "ʱ��", "����");
	printf("|----------+----------+---------------+--------+--------+--------+--------+----------|\n");
	while (p != NULL) {
		printf("|%-10s|%-10s|%-15s|%-8.1f|%-8d|%-8d|%-8s|%-10s|\n", p->data.stuID, p->data.name, p->data.academy, p->data.temperature,
			p->data.cough, p->data.state,p->data.time, p->data.date);

		p = p->next;
		if (p)
		{
			printf("|----------+----------+---------------+--------+--------+--------+--------+----------|\n");
		}
		else
		{
			printf("|------------------------------------------------------------------------------------|\n");
		}
	}
}

/*
�������ܣ������ǰ��������ѧ����Ϣ
���������ָ��
����ֵ����
*/
void printCurNode(Node* node) {
	Node* newNode = node;
	printf("|------------------------------------------------------------------------------------|\n");
	printf("|%-10s|%-10s|%-15s|%-8s|%-8s|%-8s|%-8s|%-10s|\n", "ѧ��", "����", "ѧԺ", "����",
		"�Ƿ����", "����״̬", "ʱ��", "����");
	printf("|----------+----------+---------------+--------+--------+--------+--------+----------|\n");
	printf("|%-10s|%-10s|%-15s|%-8.1f|%-8d|%-8d|%-8s|%-10s|\n", newNode->data.stuID, newNode->data.name, newNode->data.academy, 
		newNode->data.temperature,newNode->data.cough, newNode->data.state, newNode->data.time, newNode->data.date);
	printf("|------------------------------------------------------------------------------------|\n");
}

/*
�������ܣ����ı��ж�ȡ��Ϣ��������
�������ļ���������
����ֵ����
*/
void readFile(char* fileName, Node* list) {
	student stu;
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {//�ļ������ڣ��򴴽��ļ�
		fp = fopen(fileName, "w");
	}
	while ((fscanf(fp, "%s\t%s\t%s\t%f\t%d\t%d\t%s\t%s\n", stu.stuID, stu.name, stu.academy, &stu.temperature,
		&stu.cough, &stu.state, stu.time, stu.date)) != EOF) {
		insertNode(list, stu);
	}
	fclose(fp);
}

/*
�������ܣ�����������д���ļ���
�������ļ���������
����ֵ����
*/
void writeFile(char* fileName, Node* list) {
	Node* p = list->next;//����ָ��
	FILE* fp = fopen(fileName, "w");
	while (p) {
		fprintf(fp, "%s\t%s\t%s\t%.1f\t%d\t%d\t%s\t%s\n", p->data.stuID, p->data.name, p->data.academy, p->data.temperature,
			p->data.cough, p->data.state, p->data.time, p->data.date);
		p = p->next;
	}
	fclose(fp);
}

void swap(char* cur, char* curN) {
	char* temp[20] = { "" };
	strcpy(temp, cur);
	strcpy(cur, curN);
	strcpy(curN, temp);
}

/*
�������ܣ�ͨ�����ڰ��Ⱥ��������
����������������
����ֵ����
*/
void sortByDate(Node* list) {
	if (list->next == NULL) {
		return;
	}
	if (list->next->next == NULL) {
		return;
	}
	Node* tail = NULL;
	Node* cur = list->next;
	while (cur->next != tail) {
		int flag = 0;
		while (cur->next != tail) {
			if (strcmp(cur->data.date, cur->next->data.date) > 0) {
				swap(cur->data.date, cur->next->data.date);
				flag = 1;
			}
			cur = cur->next;
		}
		if (!flag) {
			break;
		}
		tail = cur;
		cur = list->next;
	}
}