#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"





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
struct Node* insertNodeByTail(struct Node* listHeadNode, struct student data) {
	//struct Node* L = listHeadNode;
	//struct Node* newNode = createNode(data);//����һ���½��
	//L->next = newNode;
	//L = newNode;
	//return listHeadNode;
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
		while (strcmp(posNode->data.name,query)) {
			posFrontNode->next = posNode;
			posNode = posNode->next;
			if (posNode == NULL) {
				printf("���Ҳ���,�޷�ɾ��\n");
				return;
			}
		}
		//���ҵ�������ɾ��
		posFrontNode->next = posNode->next;
	}
}
//�޸�������Ϣ
void modifyNodeByquery(struct Node* listHeadNode, char* query) {
	//struct Node* modifyNode = findNodeByquery(listHeadNode, query);

}
//���ҽ��
struct Node* findNodeByquery(struct Node* listHeadNode, char* query) {
	struct Node* searchNode = listHeadNode->next;
	if (searchNode == NULL) {
		return NULL;
	}
	else {
		while (strcmp(searchNode->data.name,query)) {
			searchNode = searchNode->next;
			if (searchNode == NULL) {
				return NULL;
			}
		}
		return searchNode;
	}
}


//��ӡ����
void printList(struct Node* listHeadNode) {
	struct Node* pMove = listHeadNode->next;
	if (pMove == NULL) {
		printf("��Ϊ��\n");
	}
	else {
		printf("%-20s\t%-10s\t%s\t%-20s\t%-20s\t\n", "����", "ѧ��", "����", "�绰", "��ַ");
		while (pMove != NULL) {
			printf("%-20s\t%-10s\t%d\t%-20s\t%-20s\t\n", pMove->data.name, pMove->data.num, pMove->data.age, pMove->data.tel, pMove->data.addr);
			pMove = pMove->next;
		}
	}
}
//��ӡ���
void printNode(struct Node* node) {
	if (node == NULL) {
		printf("��Ϊ��\n");
	}
	else {
		printf("%-20s\t%-10s\t%s\t%-20s\t%-20s\t\n", "����", "ѧ��", "����", "�绰", "��ַ");
		printf("%-20s\t%-10s\t%d\t%-20s\t%-20s\t\n", node->data.name, node->data.num, node->data.age, node->data.tel, node->data.addr);
	}
	
}
//��ȡ�ļ���Ϣ
void readInfoFromFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w");  //����ļ������ڣ��ʹ����ļ�
	}
	struct student tempData;
	while (fscanf(fp, "%s%s%d%s%s", tempData.name, tempData.num, &(tempData.age), tempData.tel, tempData.addr) != EOF) {
		insertNodeNyHead(listHeadNode, tempData);
		memset(&tempData, 0, sizeof(tempData));
	}
}

//������Ϣ���ļ�
void saveInfoToFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Node* pMove = listHeadNode->next;
	while (pMove) {
		fprintf(fp,"%-20s\t%-10s\t%d\t%-20s\t%-20s\t\n", pMove->data.name, pMove->data.num, pMove->data.age, pMove->data.tel, pMove->data.addr);
		pMove = pMove->next;
	}
}