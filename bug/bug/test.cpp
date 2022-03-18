#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DEFAULT_SZ 10
struct student {
	char stu_id[10];	//����ѧ��
	char name[20];		//����
	char colleage[20];	//����ѧԺ
	char type[10];      //�������
	char course1[6];	//������1
	char course2[6];	//������2
	char course3[6];	//רҵ��1
	char course4[6];	//רҵ��2
	char ptest[10];		//���Գɼ�
	char retest[10];		//���Գɼ�
	char olanguage[6];  //����ɼ�
	char comprehensive[10];//�ۺϳɼ�
};

struct students {
	struct student* data;   //�洢ѧ�����ݵ�����
	int size;				//���鳤��
	int capicity;			//��ǰ����
};
struct Node {    //ѧ���ɼ�����
	struct student data;
	struct Node* next;
};

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
		struct student* p = (struct student*)realloc(stu->data, sizeof(struct student) * (DEFAULT_SZ+stu->capicity));
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
	while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", tempData.stu_id, tempData.name, tempData.colleage, tempData.type, tempData.course1, tempData.course2, tempData.course3, tempData.course4, tempData.ptest, tempData.retest, tempData.olanguage, tempData.comprehensive) != EOF) {
		insertNodeNyHead(listHeadNode, tempData);
		memset(&tempData, 0, sizeof(tempData));
	}
	fclose(fp);
	fp = NULL;
}
//����ѧ���ɼ�
void queryAllStudentByArray(struct student* list, int length) {
	if (length == 0) {
		printf("��Ϊ��\n");
		return;
	}
	else {
		printf("%-5s\t%-5s\t%s\t%-8s\t%s %s %s %s %s %s %s %s\n", "����ѧ��", "����", "����ѧԺ", "�������", "������1", "������2", "רҵ��1", "רҵ��2", "���Գɼ�", "���Գɼ�", "����ɼ�", "�ۺϳɼ�");
		for (int i = 0; i < length; i++) {
			printf("%-5s\t%-5s\t%s\t%-8s\t %s\t %s\t %s\t %s\t %s\t %s\t   %s\t   %s\t\n", list[i].stu_id, list[i].name, list[i].colleage, list[i].type, list[i].course1, list[i].course2, list[i].course3, list[i].course4, list[i].ptest, list[i].retest, list[i].olanguage, list[i].comprehensive);
		}
	}
}
//��ӡ����
void printList(struct Node* list) {
	struct Node* posNode = list->next;
	if (posNode == NULL) {
		printf("��Ϊ��\n");
		return;
	}
	else {
		printf("%-5s\t%-5s\t%s\t%-8s\t%s %s %s %s %s %s %s %s\n", "����ѧ��", "����", "����ѧԺ", "�������", "������1", "������2", "רҵ��1", "רҵ��2", "���Գɼ�", "���Գɼ�", "����ɼ�", "�ۺϳɼ�");
		while (posNode != NULL) {
			printf("%-5s\t%-5s\t%s\t%-8s\t %s\t %s\t %s\t %s\t %s\t %s\t   %s\t   %s\t\n", posNode->data.stu_id, posNode->data.name, posNode->data.colleage, posNode->data.type, posNode->data.course1, posNode->data.course2, posNode->data.course3, posNode->data.course4, posNode->data.ptest, posNode->data.retest, posNode->data.olanguage, posNode->data.comprehensive);
			posNode = posNode->next;
		}
	}
}
void sort(struct Node* list) {
	//struct student list1[STUDENT_MAX] ;//ѧ˶��
	//struct student list2[STUDENT_MAX];//ר˶��
	//struct student list3[STUDENT_MAX];//��ȫ����
	struct students p1;
	struct students p2;
	struct students p3;
	InitStudents(&p1);
	InitStudents(&p2);
	InitStudents(&p3);
	//printList(list);
	struct Node* posNode = list->next;
	if (posNode == NULL) {
		printf("��Ϊ��\n");
		return;
	}
	else {
		while (posNode != NULL) {
			if (strcmp(posNode->data.type, "ѧ˶") == 0) {
				p1.data[p1.size] = posNode->data;
				p1.size++;
				CheckCapacity(&p1);
			}
			else if (strcmp(posNode->data.type, "ר˶") == 0) {
				p2.data[p2.size] = posNode->data;
				p2.size++;
				CheckCapacity(&p2);
			}
			else if (strcmp(posNode->data.type, "��ȫ����") == 0) {
				p3.data[p3.size] = posNode->data;
				p3.size++;
				CheckCapacity(&p3);
			}
			posNode = posNode->next;
		}
		//��ӡ�ɼ�
		queryAllStudentByArray(p1.data, p1.size);
		//�����������������
		//qsort(p1.data, p1.size, sizeof(p1.data[0]), cmp_by_comprehensive);

		printf("����ɹ�\n");
	}
	free(p1.data);
	p1.data = NULL;
	free(p2.data);
	p2.data = NULL;
	free(p3.data);
	p3.data = NULL;
}
int main() {
	struct Node* list = NULL;		//ѧ���ɼ�����
	list = createList();
	readStudentInfoFromFile("data2.txt", list);
	sort(list);
}