#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"



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


//��ӡ����
void printList(struct Node* listHeadNode) {
	struct Node* pMove = listHeadNode->next;
	while (pMove != NULL) {
		printf("%d\n", pMove->data);
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
	/*while (fscanf(fp, "%d\n", &(tempData.data)) != EOF) {
		insertNodeNyHead(listHeadNode, tempData);
		memset(&tempData, 0, sizeof(tempData));
	}*/
}

//������Ϣ���ļ�
void saveInfoToFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Node* pMove = listHeadNode->next;
	/*while (pMove) {
		fprintf(fp, "%d", pMove->data.data);
		pMove = pMove->next;
	}*/
}