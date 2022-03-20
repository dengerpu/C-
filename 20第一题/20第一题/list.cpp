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
	while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", tempData.stu_id, tempData.name, tempData.sid, tempData.college, tempData.type, tempData.major, tempData.route, tempData.traffic, tempData.isClose, tempData.temperate, tempData.history, tempData.isCough, tempData.time) != EOF) {
		insertNodeNyHead(listHeadNode, tempData);
		memset(&tempData, 0, sizeof(tempData));
	}
	fclose(fp);
	fp = NULL;
}
//����ѧ����Ϣ���ļ�
void saveStudentInfoToFile(struct Node* listHeadNode) {
	const char* collegeArr[] = {
		"ͨ��ѧԺ",
		"�����ѧԺ",
		"�Զ���ѧԺ",
		"�Ƚ�����ѧԺ",
		"���ѧԺ",
		"���ѧԺ",
		"��ѧԺ",
		"����ѧԺ",
		"��ýѧԺ",
		"����ѧԺ",
		"����ѧԺ",
		"����ѧԺ"
	};
	int count = sizeof(collegeArr) / sizeof(collegeArr[0]);
	FILE* fp = NULL;
	struct Node* pMove = listHeadNode->next;
	while (pMove) {
		for (int i = 0; i < count; i++) {
			if (strcmp(collegeArr[i], pMove->data.college) == 0) {
				char newfilename[20] = { 0 };
				strcpy(newfilename, collegeArr[i]);
				strcat(newfilename, ".txt");
				fp = fopen(newfilename, "a+");
				fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", pMove->data.stu_id, pMove->data.name, pMove->data.sid, pMove->data.college, pMove->data.type, pMove->data.major, pMove->data.route, pMove->data.traffic, pMove->data.isClose, pMove->data.temperate, pMove->data.history, pMove->data.isCough, pMove->data.time);
			}
		}

		pMove = pMove->next;
	}
	fclose(fp);
	fp = NULL;
}
//����������������Ϣ���ļ���
void saveStudentArrInfoToFile(const char* filename, struct student* arr,int length) {
	FILE* fp = NULL;
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("���ļ�ʧ��\n");
		return;
	}
	else {
		for (int i = 0; i < length; i++) {
			fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", arr[i].stu_id, arr[i].name, arr[i].sid, arr[i].college, arr[i].type, arr[i].major, arr[i].route, arr[i].traffic, arr[i].isClose, arr[i].temperate, arr[i].history, arr[i].isCough, arr[i].time);
		}
	}	
	fclose(fp);
	fp = NULL;
}
//��������ѧ����Ϣ���ļ�
void saveALLStudentInfoToFile(const char* filename, struct Node* listHeadNode){
	FILE* fp = fopen(filename,"w");
	struct Node* pMove = listHeadNode->next;
	while (pMove) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", pMove->data.stu_id, pMove->data.name, pMove->data.sid, pMove->data.college, pMove->data.type, pMove->data.major, pMove->data.route, pMove->data.traffic, pMove->data.isClose, pMove->data.temperate, pMove->data.history, pMove->data.isCough, pMove->data.time);
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

