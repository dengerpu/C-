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
struct Node* createNode(struct country data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//ѧ���ɼ����� ͷ�巨������ڵ�
void insertNodeNyHead(struct Node* listHeadNode, struct country data) {
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
	struct country tempData;
	//while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", tempData.stu_id, tempData.name, tempData.colleage, tempData.type, tempData.course1, tempData.course2, tempData.course3, tempData.course4, tempData.ptest, tempData.retest, tempData.olanguage, tempData.comprehensive) != EOF) {
	//	insertNodeNyHead(listHeadNode, tempData);
	//	memset(&tempData, 0, sizeof(tempData));
	//}
	fclose(fp);
	fp = NULL;
}
//����ѧ����Ϣ���ļ�
void saveStudentInfoToFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Node* pMove = listHeadNode->next;
	//while (pMove) {
	//	fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", pMove->data.stu_id, pMove->data.name, pMove->data.colleage, pMove->data.type, pMove->data.course1, pMove->data.course2, pMove->data.course3, pMove->data.course4, pMove->data.ptest, pMove->data.retest, pMove->data.olanguage, pMove->data.comprehensive);
	//	pMove = pMove->next;
	//}
	fclose(fp);
	fp = NULL;
}

//��ʼ��students
void InitStudents(struct courties* stu) {
	//����DEFAULT_SZ����С
	stu->data = (struct country*)malloc(sizeof(struct country) * DEFAULT_SZ);
	if (stu->data == NULL) {  //����ʧ��
		printf("%s\n", strerror(errno));
		return;
	}
	stu->size = 0;
	stu->capicity = DEFAULT_SZ;
}
//��������Ƿ���
void CheckCapacity(struct courties* stu) {
	if (stu->size == stu->capicity) {  //���������ã��ٴη�������
		struct country* p = (struct country*)realloc(stu->data, sizeof(struct country) * (DEFAULT_SZ + stu->capicity));
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

