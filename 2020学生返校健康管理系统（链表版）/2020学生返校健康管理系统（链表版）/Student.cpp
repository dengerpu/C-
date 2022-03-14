#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include "utils.h"



//�˵�
void menu() {
	printf("----------------ѧ������ϵͳ----------------\n");
	printf("\t\t0.�˳�����ϵͳ\n");
	printf("\t\t1.���ѧ����Ϣ\n");
	printf("\t\t2.�޸�ѧ����Ϣ\n");
	printf("\t\t3.����ѧ����Ϣ\n");
	printf("\t\t4.ͳ��ѧ����Ϣ\n");
	printf("\t\t5.�쳣״̬Ԥ��\n");
	printf("\t\t6.��ӡѧ����Ϣ\n");
	printf("--------------------------------------------\n");
	printf("��ѡ�����:>");
}

//��������
struct Node* createList() {
	//����ռ�
	struct Node* listHead = (struct Node*)malloc(sizeof(struct Node));
	listHead->next = NULL;
	return listHead;
}

//�������
struct Node* createNode(struct student data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//ͷ�巨������ڵ�
void insertNodeNyHead(struct Node* listHeadNode, struct student data) {
	struct Node* newNode = createNode(data);//����һ���½��
	newNode->next = listHeadNode->next;
	listHeadNode->next = newNode;
}

//β�巨������ڵ�
void insertNodeByTail(struct Node* listHeadNode, struct student data) {
	struct Node* newNode = createNode(data);//����һ���½��
	listHeadNode->next = newNode;
	listHeadNode = newNode;
}

//ɾ������
void deleteNodeByquery(struct Node* listHeadNode, char* query) {
	struct Node* posFrontNode = listHeadNode;  //Ҫɾ������ǰһ�����
	struct Node* posNode = listHeadNode->next; //Ҫɾ���Ľ��
	if (posNode == NULL) {
		printf("��Ϊ�գ��޷�ɾ��\n");
		return;
	}
	else {
		/*while (�������ѯ����) {
			posFrontNode->next = posNode;
			posNode = posNode->next;
			if (posNode == NULL) {
				printf("���Ҳ���,�޷�ɾ��\n");
				return;
			}
		}
		���ҵ�������ɾ��
		posFrontNode->next = posNode->next;*/
	}
}
//���ҽ��
struct Node* findNodeByquery(struct Node* listHeadNode, char* query) {
	struct Node* searchNode = listHeadNode->next;
	if (searchNode == NULL) {
		return NULL;
	}
	else {
		/*while (����������) {
			searchNode = searchNode->next;
			if (searchNode == NULL) {
				return NULL;
			}
		}
		return searchNode;*/
	}
}
//����������
int getLenth(struct Node* listHeadNode) {
	int length = 0;
	struct Node* node = listHeadNode->next;
	if (node == NULL) {
		return 0;
	}
	else {
		while (node != NULL) {
			node = node->next;
			length++;
		}
		return length;
	}
}

//��ӡ����
void printList(struct Node* listHeadNode) {
	struct Node* pMove = listHeadNode->next;
	//char stu_id[10];	//ѧ��
	//char name[20];		//����
	//char colleage[20];	//ѧԺ
	//char temperate[5];	//����
	//char isCough;		//�Ƿ����
	//char status;		//����״̬
	//char time[10];			//ͳ��ʱ��
	//char date[10];			//����
	printf("%-10s\t%s\t%-10s\t%-5s\t%s\t%s\t%s\t%s\t\n","ѧ��","����","ѧԺ","����","�Ƿ����","����״̬","ͳ��ʱ��","����");
	while (pMove != NULL) {
		printf("%-10s\t%s\t%-10s\t%-5s\t%c\t\t%c\t\t%s\t\t%s\t\n", pMove->data.stu_id, pMove->data.name, pMove->data.colleage, pMove->data.temperate, pMove->data.isCough, pMove->data.status, pMove->data.time, pMove->data.date);
		pMove = pMove->next;
	}
}
//��ӡ���
void printNode(struct Node* node) {
	printf("��ӡ�����Ϣ\n");
}
//��ȡ�ļ���Ϣ
void readInfoFromFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w");  //����ļ������ڣ��ʹ����ļ�
	}
	struct student tempData;
	while (fscanf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\t\n", tempData.stu_id, tempData.name, tempData.colleage, tempData.temperate, &(tempData.isCough), &(tempData.status), tempData.time, tempData.date) != EOF) {
		insertNodeNyHead(listHeadNode, tempData);
		memset(&tempData, 0, sizeof(tempData));
	}
	fclose(fp);
	fp = NULL;
}

//������Ϣ���ļ�
void saveInfoToFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Node* pMove = listHeadNode->next;
	while (pMove) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\t\n", pMove->data.stu_id, pMove->data.name, pMove->data.colleage, pMove->data.temperate, pMove->data.isCough, pMove->data.status, pMove->data.time, pMove->data.date);
		pMove = pMove->next;
	}
	fclose(fp);
	fp = NULL;
}