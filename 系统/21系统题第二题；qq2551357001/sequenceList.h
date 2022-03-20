
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/***********����ѧ���������ݽṹ************/
typedef struct student {
	char stu_id[10];//ѧ��
	char name[20];//����
	char institute[20];//����ѧԺ
	char category[20];//�������
	int basSco_1;//������1�ɼ�
	int basSco_2;//������2�ɼ�
	int speSco_1;//רҵ��1�ɼ�
	int speSco_2;//רҵ��2�ɼ�
	float preExamSco;//�����ܳɼ�
	float reExamSco;//�����Գɼ�
	float orExamSco;//����ɼ�
	float totalSco;//�ܳɼ�
	int state;//ѧ���Ƿ����
}Student;

/***********�����˻��������ݽṹ************/
typedef struct acco{
	char account[20];//�˺�
	char pwd[20];//����
	int state;//�˺��Ƿ����
}Account;

/***************����˳���****************/
typedef struct StuList {
	Student* student;//ѧ������洢�ռ����ַ
	int stuLength;//ѧ�����鵱ǰ����
	int stuSize;//ѧ�����鵱ǰ����Ĵ洢����
}StuList;

typedef struct AccoList {
	Account* account;//�˻�����洢�ռ����ַ
	int accoLength;//�˻����鵱ǰ����
	int accoSize; //�˻����鵱ǰ����Ĵ洢����
}AccoList;

/*
�������ܣ�����һ���յ����Ա�list
���������Ա�
����ֵ����
*/
void initStuList(StuList* list) {
	list->student = (Student*)malloc(sizeof(Student) * 10);
	list->stuLength = 0; //�ձ���Ϊ0
	list->stuSize = 10; //���Դ洢����
}

void initAccoList(AccoList* list) {
	list->account = (Account*)malloc(sizeof(Account) * 10);
	list->accoLength = 0;
	list->accoSize = 10;
}

/*
�������ܣ������Ա�ĩβ��������
���������Ա�ѧ������
����ֵ����
*/
void insertStu(StuList* list, Student stu) {
	if (list->stuLength >= list->stuSize * 0.8) {
		Student* newbase = (Student*)realloc(list->student,
			sizeof(Student) * (list->stuSize * 1.5));
		if (!newbase) {
			printf("�ռ����ʧ�ܣ�");
			return;
		}
		list->student = newbase;
	}
	
	list->student[list->stuLength] = stu;
	++list->stuLength;
	list->stuSize = list->stuSize + list->stuSize * 1.5;
}

void insertAcco(AccoList* list, Account acco) {
	if (list->accoLength >= list->accoSize * 0.8) {
		Account* newbase = (Account*)realloc(list->account,
			sizeof(Account) * (list->accoSize * 1.5));
		if (!newbase) {
			printf("�ռ����ʧ�ܣ�");
			return;
		}
		list->account = newbase;
	}
	list->account[list->accoLength] = acco;
	++list->accoLength;
	list->accoSize = list->accoSize + list->accoSize * 1.5;
}

/*
�������ܣ�ͨ��ѧ�Ų���ѧ��
���������Ա�ѧ��ѧ��
����ֵ����ѧ��ָ��
*/
int locateStu(StuList* list, char* stu_id) {
	if (list->stuLength == 0) {
		printf("��ѧ����Ϣ��\n");
		return -1;
	}
	int i = 0;
	for (i = 0; i < list->stuLength && strcmp(list->student[i].stu_id, stu_id); i++);
	if (i >= list->stuLength) {
		printf("û�и�ѧ����Ϣ��\n");
		return -1;
	}
	if (list->student[i].state == 0) {
		printf("��ѧ���ѱ�ɾ����\n");
		return -1;
	}
	return i;
}

int locateAcco(AccoList* list, char* account) {
	if (list->accoLength == 0) {
		printf("���˺���Ϣ��");
		return -1;
	}
	int i = 0;
	for (i = 0; i < list->accoLength && strcmp(list->account[i].account, account); i++);
	if (i >= list->accoLength) {
		printf("û�и��˺���Ϣ��");
		return -1;
	}
	if (list->account[i].state == 0) {
		printf("���˺��ѱ�ɾ����");
		return -1;
	}
	return i;
}

/*
�������ܣ�ͨ��ѧ��ɾ��ѧ������ɾ��Ϊ�߼�ɾ��
		  state = 0��ʾ�ѱ�ɾ��
���������Ա�ѧ��ѧ��
����ֵ����
*/
void deleteStu(StuList* list, char* stu_id) {
	if (list->stuLength == 0) {
		printf("��ѧ����Ϣ��\n");
		return;
	}
	int index = locateStu(list, stu_id);
	if (index == -1) {
		return;
	}
	list->student[index].state = 0;
	printf("ɾ���ɹ���");
}

void deleteAcco(AccoList* list, char* account) {
	if (list->accoLength == 0) {
		printf("���˺���Ϣ��\n");
		return;
	}
	int index = locateAcco(list, account);
	if (index == -1) {
		return;
	}
	list->account[index].state = 0;
	printf("ɾ���ɹ���");
}

void swapNode(Student* stu1, Student* stu2) {
	Student stu = { "" };
	stu = *stu1;
	*stu1 = *stu2;
	*stu2 = stu;
}

void sorList(StuList* stuList) {
	int flag = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < stuList->stuLength - 1; i++) {
		flag = 0;
		for (j = i; j < stuList->stuLength - 1; j++) {
			if (stuList->student[j].totalSco < stuList->student[j + 1].totalSco) {
				flag = 1;
				swapNode(&stuList->student[j], &stuList->student[j + 1]);
			}
			if (stuList->student[j].totalSco == stuList->student[j + 1].totalSco) {
				if (stuList->student[j].preExamSco < stuList->student[j + 1].preExamSco) {
					flag = 1;
					swapNode(&stuList->student[j], &stuList->student[j + 1]);
				}
				if (stuList->student[j].preExamSco == stuList->student[j + 1].preExamSco) {
					if (stuList->student[j].reExamSco < stuList->student[j + 1].reExamSco) {
						flag = 1;
						swapNode(&stuList->student[j], &stuList->student[j + 1]);
					}
					if (stuList->student[j].reExamSco == stuList->student[j + 1].reExamSco) {
						if (stuList->student[j].speSco_1 < stuList->student[j + 1].speSco_1) {
							flag = 1;
							swapNode(&stuList->student[j], &stuList->student[j + 1]);
						}
						if (stuList->student[j].speSco_1 == stuList->student[j + 1].speSco_1) {
							if (stuList->student[j].speSco_2 < stuList->student[j + 1].speSco_2) {
								flag = 1;
								swapNode(&stuList->student[j], &stuList->student[j + 1]);
							}
						}
					}
				}
			}
		}
		if (flag == 0) {
			return;
		}
	}
}
