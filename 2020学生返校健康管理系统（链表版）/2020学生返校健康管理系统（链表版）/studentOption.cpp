#pragma once
#include "Student.h"
enum COLLEGE{
	ͨ��ѧԺ=1,		//01
	�����ѧԺ,		//02
	���ѧԺ,		//03
	�Զ���ѧԺ,		//04
	����ѧԺ,		//05
	�о���Ժ,		//06
	����ѧԺ,		//07
	����ѧԺ,		//08
	����ѧԺ,		//09
	��ýѧԺ,		//10
	�Ƚ�����ѧԺ,	//11
	���˼����ѧԺ	//12
};
//��ȡѧԺ
void getCollege(int num,char *college) {
	switch (num) {
	case ͨ��ѧԺ:strcpy(college, "ͨ��ѧԺ"); break;
	case �����ѧԺ:strcpy(college, "�����ѧԺ"); break;
	case ���ѧԺ:strcpy(college, "���ѧԺ"); break;
	case �Զ���ѧԺ:strcpy(college, "�Զ���ѧԺ"); break;
	case ����ѧԺ:strcpy(college, "����ѧԺ"); break;
	case �о���Ժ:strcpy(college, "�о���Ժ"); break;
	case ����ѧԺ:strcpy(college, "����ѧԺ"); break;
	case ����ѧԺ:strcpy(college, "����ѧԺ"); break;
	case ����ѧԺ:strcpy(college, "����ѧԺ"); break;
	case ��ýѧԺ:strcpy(college, "��ýѧԺ"); break;
	case �Ƚ�����ѧԺ:strcpy(college, "�Ƚ�����ѧԺ"); break;
	case ���˼����ѧԺ:strcpy(college, "���˼����ѧԺ"); break;
	default:strcpy(college, "��"); break;
	};
}
//��ȡ����״̬
char  getStatus(char* temperate, char isCough) {
	float temp = (float)atof(temperate);
	if (temp >= 37.3 && isCough == '1') {
		return '0';
	}else {
		return '1';
	}
}

//���ѧ����Ϣ
void addStudent(struct Node* list) {
	struct student tempData;
	int flag = 1;
	memset(&(tempData), 0, sizeof(tempData));
	printf("������ѧ���ĸ�����Ϣ��\n");
	while (flag) {
		printf("ѧ��ѧ�ţ�");
		scanf("%s", tempData.stu_id);
		int year = getSidYear(tempData.stu_id);
		int college = getSidCollege(tempData.stu_id);
		int num = getSidNum(tempData.stu_id);
		if (year < 2016 || year>2019) {
			printf("��ѧ�������Ϣ��Ч�����������룡\n");
		}
		else if (college < 0 || college>12) {
			printf("��ѧ��ѧԺ��Ϣ��Ч�����������룡\n");
		}
		else if (num < 0 || num>999) {
			printf("��ѧ����Ϣ��Ч�����������룡\n");
		}
		else {
			flag = 0;
		}
	}
	printf("ѧ��������");
	scanf("%s", tempData.name);
	printf("ѧ�����£�");
	scanf("%s", tempData.temperate);
	printf("�Ƿ���ԣ�");
	getchar();
	scanf("%c", &(tempData.isCough));
	printf("ʱ�䣺");
	scanf("%s", tempData.time);
	printf("���ڣ�");
	scanf("%s", tempData.date);
	tempData.status = getStatus(tempData.temperate,tempData.isCough);
	int cid = getSidCollege(tempData.stu_id);
	getCollege(cid, tempData.colleage);
	insertNodeNyHead(list, tempData);
}
//����ѧ�Ų���ѧ����Ϣ
struct Node* findBySid(struct Node* list, char* sid) {
	struct Node* searchNode = list->next;
	//printf("%s\n", sid);
	if (searchNode == NULL) {
		printf("��Ϊ��\n");
	}
	else{
		while (searchNode != NULL) {
			if (strcmp(searchNode->data.stu_id, sid) == 0) {
				return searchNode;
			}
			searchNode = searchNode->next;
			if (searchNode == NULL) {
				//printf("���Ҳ���\n");
				return NULL;
			}
		}
	}
}
//�޸�ѧ����Ϣ
void modifyStudent(struct Node* list) {
	//struct Node* modifyNode;
	char modify[20] = { 0 };
	char sid[20] = { 0 };
	printf("��������Ҫ�޸���Ϣ��ѧ��ѧ�ţ�");
	scanf("%s", sid);
	struct Node* modifyNode = findBySid(list, sid);
	if (modifyNode == NULL) {
		printf("���Ҳ���\n");
	}
	else {
		printf("������Ҫ�޸ĵ���(ѧ�š����������¡��Ƿ���ԡ�ʱ�䡢����)��");
		scanf("%s", modify);
		if (strcmp(modify, "ѧ��") == 0) {
			printf("���������޸ĵ�ѧ�ţ�");
			scanf("%s", modifyNode->data.stu_id);
		}else if (strcmp(modify, "����")==0) {
			printf("���������޸ĵ�������");
			scanf("%s", modifyNode->data.name);
		}else if (strcmp(modify, "����")==0) {
			printf("���������޸ĵ����£�");
			scanf("%s", modifyNode->data.temperate);
		}
		else if (strcmp(modify, "�Ƿ����")==0) {
			getchar();
			printf("���������޸ĵ��Ƿ���ԣ�");
			scanf("%c", &(modifyNode->data.isCough));
		}
		else if (strcmp(modify, "ʱ��")==0) {
			printf("���������޸ĵ�ʱ�䣺");
			scanf("%s", modifyNode->data.time);
		}
		else if (strcmp(modify, "����")==0) {
			printf("���������޸ĵ����ڣ�");
			scanf("%s", modifyNode->data.date);
		}
		else {
			printf("�޸�ѡ��\n");
		}
		modifyNode->data.status = getStatus(modifyNode->data.temperate, modifyNode->data.isCough);
		int cid = getSidCollege(modifyNode->data.stu_id);
		getCollege(cid, modifyNode->data.colleage);
		printf("�޸ĳɹ�\n");
	}
}
void deadlineStatics(struct Node* list) {
	char query[20] = { 0 };
	char deadline[20] = { 0 };
	int flag = 1;  //���ڿ��ƽ�ֹ���꼸�¼��ո����Ľ�����Ϣ����ֻ��ӡһ��
	int flag1 = 1; //����ѧ������ѧԺֻ��ӡһ��
	struct Node* findNode = list->next;
	if (findNode == NULL) {
		printf("��Ϊ��\n");
	}
	else {
		FILE* fp = fopen("data2.txt", "w");
		printf("������ѧ��ѧ�Ż���������");
		scanf("%s", query);
		printf("�����뵱ǰ���ڣ�");
		scanf("%s", deadline);
		while (findNode != NULL) {
			if ((strcmp(findNode->data.stu_id, query) == 0) || (strcmp(findNode->data.name, query) == 0)) {
				if (flag) {
					printf("��ֹ%d��%d��%d�ո����Ľ���������ϢΪ��\n", getYear(deadline), getMonth(deadline), getDay(deadline));
					flag = 0;
				}
				if (strcmp(findNode->data.date, deadline) < 0) {
					if (flag1 == 1) {
						printf("ѧ�ţ�%s\n",findNode->data.stu_id);
						printf("������%s\n", findNode->data.name);
						printf("ѧԺ��%s\n", findNode->data.colleage);
						printf("%-5s\t%s\t%s\t%s\t%s\t\n", "����", "�Ƿ����", "����״̬", "ͳ��ʱ��", "����");
						flag1 = 0;
					}
					printf("%-5s\t%c\t\t%c\t\t%s\t\t%s\t\n", findNode->data.temperate, findNode->data.isCough, findNode->data.status, findNode->data.time, findNode->data.date);
					fprintf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\t\n", findNode->data.stu_id, findNode->data.name, findNode->data.colleage, findNode->data.temperate, findNode->data.isCough, findNode->data.status, findNode->data.time, findNode->data.date);
				}
			}
			findNode = findNode->next;
		}
		fclose(fp);  //�ͷ��ڴ�
		fp = NULL;
		if (flag == 1) {
			printf("�޴�����Ϣ\n");
		}
		if (flag1 == 1) {
			printf("����������\n");
		}
	}
}
//ͳ��ÿ�콡��״̬�쳣��ѧ����Ϣ�����浽�ļ�data3.txt
void abnormalStatus(struct Node* list) {
	struct Node* node = list->next;
	FILE* fp = fopen("data3.txt", "w");
	if (node == NULL) {
		printf("��Ϊ��\n");
	}else {
		while (node != NULL) {
			if (node->data.status == '0') {
				fprintf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\t\n", node->data.stu_id, node->data.name, node->data.colleage, node->data.temperate, node->data.isCough, node->data.status, node->data.time, node->data.date);
				printf("%-10s\t%s\t%-10s\t%-5s\t%c\t\t%c\t\t%s\t\t%s\t\n", node->data.stu_id, node->data.name, node->data.colleage, node->data.temperate, node->data.isCough, node->data.status, node->data.time, node->data.date);
			}
			node = node->next;
		}
	}
	fclose(fp);
	fp = NULL;

}
int cmp_stu_by_sid(const void* e1, const void* e2) {
	return (strcmp(((struct Node*)e1)->data.stu_id, ((struct Node*)e2)->data.stu_id));
}

//ͳ���������켰�����Ͻ���״̬Ϊ�쳣��ѧ�����洢��data4.txt
void abnormalAdvice(struct Node* list) {
	struct Node* node = list->next;
	struct Node* node2 = NULL;
	struct Node* node3 = NULL;
	FILE* fp = fopen("data4.txt", "w");
	int length = getLenth(list);
	if (node == NULL) {
		printf("��Ϊ��\n");
	}
	else {
		qsort(list, length, sizeof(list), cmp_stu_by_sid);
		//printList(list);
		while (node != NULL) {
			if (node->next != NULL) {
				node2 = node->next;
			}
			if (node2 != NULL && node2->next != NULL) {
				node3 = node2->next;
			}
			if (node != NULL && node2 != NULL && node3 != NULL) {  //����Ҫ�ж�Node3��Node2Ϊ�գ�3��Ϊ��
				if (node->data.status == '0' && node2->data.status == '0' && node3->data.status == '0' && (strcmp(node->data.stu_id, node2->data.stu_id) == 0) && (strcmp(node3->data.stu_id, node2->data.stu_id) == 0)) {
					fprintf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\t\n", node->data.stu_id, node->data.name, node->data.colleage, node->data.temperate, node->data.isCough, node->data.status, node->data.time, node->data.date);
					printf("%-10s\t%s\t%-10s\t%-5s\t%c\t\t%c\t\t%s\t\t%s\t\n", node->data.stu_id, node->data.name, node->data.colleage, node->data.temperate, node->data.isCough, node->data.status, node->data.time, node->data.date);
				}
			}
			node = node->next;
		}
	}
	fclose(fp);
	fp = NULL;

}
