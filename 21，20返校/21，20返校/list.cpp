#define _CRT_SECURE_NO_WARNINGS
#include"list.h"

//����ѧ���ɼ�������
int getStudentLenth(struct Node* listHeadNode) {
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


//����ѧ������
struct Node* createList() {
	//����ռ�
	struct Node* listHead = (struct Node*)malloc(sizeof(struct Node));
	listHead->next = NULL;
	return listHead;
}

//����ѧ���ɼ����
struct Node* createNode(struct student data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//ѧ���ɼ����� ͷ�巨������ڵ�
void insertNodeNyHead(struct Node* listHeadNode, struct student data) {
	struct Node* newNode = createNode(data);//����һ���½��
	newNode->next = listHeadNode->next;
	listHeadNode->next = newNode;
}
//��ȡ�ļ���ѧ���ɼ���Ϣ
void readStudentInfoFromFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w");  //����ļ������ڣ��ʹ����ļ�
	}
	struct student tempData;
	while (fscanf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\n", tempData.stu_id, tempData.name, tempData.colleage, tempData.temperate, &(tempData.isCough), &(tempData.status), tempData.time, tempData.date) != EOF) {
		insertNodeNyHead(listHeadNode, tempData);
		memset(&tempData, 0, sizeof(tempData));
	}
	fclose(fp);
	fp = NULL;
}
//����ѧ����Ϣ���ļ�
void saveStudentInfoToFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Node* pMove = listHeadNode->next;
	while (pMove) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\n", pMove->data.stu_id, pMove->data.name, pMove->data.colleage, pMove->data.temperate, pMove->data.isCough, pMove->data.status, pMove->data.time, pMove->data.date);
		pMove = pMove->next;
	}
	fclose(fp);
	fp = NULL;
}

//��ʼ��students
void InitStudents(struct students* stu) {
	//����DEFAULT_SZ����С
	stu->data = (struct student*)malloc(sizeof(struct student) * DEFAULT_SZ);
	if (stu->data == NULL) {  //����ʧ��
		printf("%s\n", strerror(errno));
		return;
	}
	stu->size = 0;
	stu->capicity = DEFAULT_SZ;
}
//��������Ƿ���
void CheckCapacity(struct students* stu) {
	if (stu->size == stu->capicity) {  //���������ã��ٴη�������
		struct student* p = (struct student*)realloc(stu->data, sizeof(struct student) * (DEFAULT_SZ + stu->capicity));
		if (p != NULL) {
			stu->data = p;
			stu->capicity = stu->capicity + DEFAULT_SZ;
		}
		else {
			printf("%s\n", strerror(errno));
			return;
		}
	}
}
//���bug��ȥ��  .
void removedot(char* arr, int length) {
	if (arr[length - 1] == '.') {
		arr[length - 1] = '\0';
	}
}

