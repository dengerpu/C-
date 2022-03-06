#define _CRT_SECURE_NO_WARNINGS
#include "student.h"

//�˵�
void menu() {
	printf("----------------ѧ������ϵͳ----------------\n");
	printf("\t\t0.�˳�ϵͳ\n");
	printf("\t\t1.������Ϣ\n");
	printf("\t\t2.�����Ϣ\n");
	printf("\t\t3.ɾ����Ϣ\n");
	printf("\t\t4.�޸���Ϣ\n");
	printf("\t\t5.������Ϣ\n");
	printf("--------------------------------------------\n");
	printf("��ѡ�����:>");
}

//��������
struct Node* createList() {
	//����ռ�
	struct Node* listHeadNode = (struct Node*)malloc(sizeof(struct Node));
	//listHeadNode->data = NULL;
	listHeadNode->next = NULL;
	return listHeadNode;

}
//�������
struct Node* createNode(struct student data) {
	//����ռ�
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//ͷ�巨��������
void insertNoByHead(struct Node* listHeadNode, struct student data) {
	struct Node* newNode = createNode(data);
	//����ͷ�巨����ڵ�
	newNode->next = listHeadNode->next;
	listHeadNode->next = newNode;
}
//ɾ������
void deleteNodeByStudent_Name(struct Node* listHeadNode, char *name) {
	struct Node* posFrontNode = listHeadNode;  //Ҫɾ�����Ķ�ǰһ�����
	struct Node* posNode = listHeadNode->next;	//Ҫɾ���Ľڵ�
	if (posNode == NULL) {
		printf("��Ϊ�գ��޷�ɾ��\n");
		return;
	}
	else {
		while (strcmp(name,posNode->data.name)) {
			posFrontNode = posNode;
			posNode = posNode->next;
			if (posNode == NULL) {
				printf("���Ҳ������޷�ɾ��\n");
				return;
			}
		}
		//���ҵ�,����ɾ��
		posFrontNode->next = posNode->next;
	}
}
//����ѧ�Ų���ѧ������Ϣ
struct Node* searchNodeBynum(struct Node* listHeadNode, char* num) {
	struct Node* searchNode = listHeadNode->next;
	if (searchNode == NULL) {
		return NULL;
	}
	else {
		while (strcmp(num, searchNode->data.num)) {
			searchNode = searchNode->next;
			if (searchNode == NULL) {
				return NULL;
			}
		}
		return searchNode;
	}

}
//��ӡ���
void printNode(struct Node* newNode) {
	printf("%-20s\t%-10s\t%s\t%-20s\t%-20s\t\n", "����", "ѧ��", "����", "�绰", "��ַ");
	printf("%-20s\t%-10s\t%d\t%-20s\t%-20s\t\n", newNode->data.name, newNode->data.num, newNode->data.age, newNode->data.tel, newNode->data.addr);
}
//����ѧ���޸�ѧ����Ϣ
//void modifyNodeBynum(struct Node* listHeadNode, char* num) {
//	struct Node* newNode = searchNodeBynum(listHeadNode, num);
//	
//}

//��ӡ����
void printList(struct Node* listHeadNode) {
	///��Ϊ��һ������û�д洢��Ϣ
	//char name[20];  //����
	//char num[10];	//ѧ��
	//int age;		//����
	//char tel[20];	//�绰
	//char addr[20];	//��ַ
	struct Node* pMove = listHeadNode->next;
	printf("%-20s\t%-10s\t%s\t%-20s\t%-20s\t\n","����","ѧ��","����","�绰","��ַ");
	while (pMove) {
		printf("%-20s\t%-10s\t%d\t%-20s\t%-20s\t\n", pMove->data.name, pMove->data.num, pMove->data.age, pMove->data.tel, pMove->data.addr);
		pMove = pMove->next;
	}
}

//��ȡ�ļ���Ϣ
void readInfofromfile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w");//���û�оʹ���
	}
	struct student tempData;
	while (fscanf(fp, "%s%s%d%s%s", tempData.name, tempData.num, &tempData.age, tempData.tel, tempData.addr) != EOF) {
		insertNoByHead(listHeadNode, tempData);
		memset(&tempData, 0, sizeof(tempData));
	}
}
//���浽�ļ���
void saveInfoToFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Node* pMove = listHeadNode->next;
	
	while (pMove) {
		fprintf(fp,"%-20s\t%-10s\t%d\t%-20s\t%-20s\t\n", pMove->data.name, pMove->data.num, pMove->data.age, pMove->data.tel, pMove->data.addr);
		pMove = pMove->next;
	}
}