#define _CRT_SECURE_NO_WARNINGS
#include "option.h"
#include<stdlib.h>

//����Ա����
void adminOption(struct Accounts* userList, struct Node* list) {
	int input = 0;
	do {
		adminMenu();
		scanf("%d", &input);
		switch(input) {
			case ADDUSER:addUser(userList); break;
			case MODIFYUSER:modifyUserByUsername(userList); break;
			case DELETEUSER:deleteUserByUsername(userList,NULL); break;
			case QUERYUSER:queryUserByUsername(userList); break;
			case ADDSTUDENT:addStudent(userList,list); break;
			case MODIFYSTUDENT:modifyStudentBySid(list); break;
			case DELETESTUDENT:deleteStudentBySid(userList,list); break;
			case QUERYSTUDENT:queryStudentBynameOrsid(list); break;
			case PRINTUSER:queryAllUser(userList); break;
			case PRINTSTUDENT:queryAllStudent(list); break;
			case SORT:sort(list); break;
			case EXIT:printf("�˳�ģ��"); destory(userList, list); exit(0); break;
			default:printf("������������������"); break;
		}
		system("pause");
		system("cls");

	} while (input);

}
//ϵͳ����Ա����
void systemOperationOption(struct Accounts* userList,struct Node* list) {
	int input = 0;
	do {
		SystemoptionMenu();
		scanf("%d", &input);
		switch (input) {
		case 1:addStudent(userList, list); break;
		case 2:modifyStudentBySid(list); break;
		case 3:deleteStudentBySid(userList, list); break;
		case 4:queryStudentBynameOrsid(list); break;
		case 5:queryAllStudent(list); break;
		case 6:sort(list); break;
		case 0:printf("�˳�ģ��"); destory(userList, list); exit(0); break;
		default:printf("������������������"); break;
		}
		system("pause");
		system("cls");

	} while (input);

}
//ѧ������
void studentOption(struct Node* list,char* sid) {
	int input = 0;
	do {
		StudentMenu();
		scanf("%d", &input);
		switch (input) {
		case 1:printSingleStudent(list,sid); break;
		case 0:printf("�˳�ģ��"); destory(NULL, list); exit(0); break;
		default:printf("������������������"); break;
		}
		system("pause");
		system("cls");

	} while (input);
}

//�����û�
int findUserByUsername(struct Accounts* userList, char* username) {
	struct Accounts* node = userList->next;
	if (node == NULL) {
		return 0;
	}
	else {
		while (node != NULL) {
			if (strcmp(node->account.account, username) == 0) {
				return 1;
			}
			node = node->next;
		}
		return 0;
	}
}

//����û�
void addUser(struct Accounts* userList) {
	struct Account account;
	printf("������Ҫ��ӵ�ϵͳ����Ա�˺ţ�");
	scanf("%s", &account.account);
	int exist  = findUserByUsername(userList, account.account);
	while (exist == 1) {
		printf("���û��Ѵ���,���������룺");
		scanf("%s", &account.account);
		exist = findUserByUsername(userList, account.account);
	}
	strcpy(account.password, account.account);
	account.type = 2;
	insertUserNodeNyHead(userList, account);
	//���浽�ļ���
	//�����û���Ϣ���ļ�
	saveUserInfoToFile("data1.txt", userList);
}
//�޸��û�
int modifyUserByUsername(struct Accounts* userList) {
	char username[10] = { 0 };
	struct Accounts* node = userList->next;
	if (node == NULL) {
		printf("��Ϊ��\n");
		return 0;
	}
	else {
		printf("������Ҫ�޸ĵ��û���:��");
		scanf("%s", username);
		while (node != NULL) {
			if (strcmp(node->account.account, username) == 0) {
				printf("������Ҫ�޸ĵ����룺");
				scanf("%s", node->account.password);
				printf("������Ҫ�޸ĵ����ͣ�1.����Ա��2ϵͳ����Ա��3.ѧ������");
				scanf("%d", &(node->account.type));
				//���浽�ļ���
				saveUserInfoToFile("data1.txt", userList);
				return 1;
				
			}
			node = node->next;
		}
		printf("�޸��û�\n");
		return 0;

	}	
}
//ɾ���û�
int deleteUserByUsername(struct Accounts* userList,char* sid) {
	char  username[10] = { 0 };
	if (sid == NULL) {
		printf("������Ҫɾ�����û����ƣ�");
		scanf("%s", username);
	}
	else {
		strcpy(username, sid);
	}
	struct Accounts* posFrontNode = userList;  //Ҫɾ������ǰһ�����
	struct Accounts* posNode = userList->next; //Ҫɾ���Ľ��
	if (posNode == NULL) {
		printf("��Ϊ�գ��޷�ɾ��\n");
		return 0;
	}
	else {
		while (posNode != NULL) {
			if (strcmp(posNode->account.account, username) == 0) {
				posFrontNode->next = posNode->next;
				printf("ɾ��ѧ���û��ɹ�\n");
				saveUserInfoToFile("data1.txt", userList);
				return 1;
			}
			posFrontNode = posNode;
			posNode = posNode->next;
		}
		printf("�޸��û�\n");
		return 0;
	}
}
//�����û�
int queryUserByUsername(struct Accounts* userList) {
	char  username[10] = { 0 };
	printf("������Ҫ��ѯ���û����ƣ�");
	scanf("%s", username);
	struct Accounts* posNode = userList->next; //Ҫɾ���Ľ��
	if (posNode == NULL) {
		printf("��Ϊ��\n");
		return 0;
	}
	else {
		while (posNode != NULL) {
			if (strcmp(posNode->account.account, username) == 0) {
				//printf("��ʾ��1.����Ա  2.ϵͳ����Ա  3.ѧ��\n");
				printf("�û�����%s  ���룺%s  ���ͣ�%d\n", posNode->account.account, posNode->account.password, posNode->account.type);
				return 1;
			}
			posNode = posNode->next;
		}
		printf("�޸��û�\n");
		return 0;
	}
}
//���������û�
void queryAllUser(struct Accounts* userList) {
	struct Accounts* node = userList->next;
	if (node == NULL) {
		printf("��Ϊ��\n");
		return;
	}
	else {
		printf("%-8s\t%-8s\t%s\n","�˺�","����","����");
		while (node != NULL) {
			printf("%-8s\t%-8s\t%d\n", node->account.account, node->account.password, node->account.type);
			node = node->next;
		}
	}
}

//����ѧ���û���ֱ�ӷ��ظ�ѧ����Ϣ���ϸ��û���ͬ��ģ�����鷳�ˣ�
struct Node* findStudentBySid(struct Node* list, char* sid) {
	struct Node* node = list->next;
	if (node == NULL) {
		return NULL;
	}
	else {
		while (node != NULL) {
			if (strcmp(node->data.stu_id, sid) == 0) {
				return node;
			}
			node = node->next;
		}
		return NULL;
	}
}
//�жϸ��Կ����Ƿ���ϱ�׼������ֵΪѧԺ����
int JudgeSid(char* sid) {
	if (strlen(sid) != 9) {
		printf("���Կ���λ������\n");
		return 0;
	}
	int year = getSidYear(sid);
	int college = getSidCollege(sid);
	int random = getSidNum(sid);
	if (year != 2021) {
		printf("���Կ�����ݴ���\n");
		return 0;
	}
	else if (college < 1 || college>12) {
		printf("���Կ���ѧԺ���Ŵ���\n");
		return 0;
	}
	else if (random < 0 || random>999) {
		printf("���Կ��ź���λ����\n");
		return 0;
	}
	else {
		return college;
	}
}


//���ѧ���ɼ�
void addStudent(struct Accounts* userList,struct Node* list) {
	struct Account account;
	struct student tempData;
	printf("������Ҫ��ӵ�ѧ������Ϣ��\n");
	printf("�����븴��ѧ�ţ�");   //��Ҫ�ж��Ƿ����
	scanf("%s", tempData.stu_id);
	while (JudgeSid(tempData.stu_id) == 0) {
		printf("���������븴��ѧ�ţ�");
		scanf("%s", tempData.stu_id);
	}
	getCollege(JudgeSid(tempData.stu_id), tempData.colleage);
	printf("������������");
	scanf("%s", tempData.name);
	printf("�����뱨�����");
	scanf("%s", tempData.type);
	while (strcmp(tempData.type, "ѧ˶") != 0 && strcmp(tempData.type, "ר˶") != 0 && strcmp(tempData.type, "��ȫ����") != 0) {
		printf("�������������������룺");
		scanf("%s", tempData.type);
	}
	printf("������1�ɼ���");
	scanf("%s", tempData.course1);
	while (atof(tempData.course1) < 0 || atof(tempData.course1) > 100) {
		printf("��������,�������룺");
		scanf("%s", tempData.course1);
	}
	printf("������2�ɼ���");
	scanf("%s", tempData.course2);
	while (atof(tempData.course2) < 0 || atof(tempData.course2) > 100) {
		printf("��������,�������룺");
		scanf("%s", tempData.course2);
	}
	printf("רҵ��1�ɼ���");
	scanf("%s", tempData.course3);
	while (atof(tempData.course3) < 0 || atof(tempData.course3) > 150) {
		printf("��������,�������룺");
		scanf("%s", tempData.course3);
	}
	printf("רҵ��2�ɼ���");
	scanf("%s", tempData.course4);
	while (atof(tempData.course4) < 0 || atof(tempData.course4) > 150) {
		printf("��������,�������룺");
		scanf("%s", tempData.course4);
	}
	double total = atof(tempData.course1) + atof(tempData.course2) + atof(tempData.course3) + atof(tempData.course4);
	_gcvt(total, 6, tempData.ptest);
	printf("���Գɼ���");
	scanf("%s", tempData.retest);
	while (atof(tempData.retest) < 0 || atof(tempData.retest) > 200) {
		printf("��������,�������룺");
		scanf("%s", tempData.retest);
	}
	printf("����ɼ���");
	scanf("%s", tempData.olanguage);
	while (atof(tempData.olanguage) < 0 || atof(tempData.olanguage) > 20) {
		printf("��������,�������룺");
		scanf("%s", tempData.olanguage);
	}
	float totalGrade = atof(tempData.ptest) * 0.6 + atof(tempData.retest) * 0.3 + atof(tempData.olanguage) * 0.1;
	_gcvt(totalGrade, 6, tempData.comprehensive);
	insertNodeNyHead(list, tempData);
	/*printf("%-5s\t%-5s\t%s\t%s %s %s %s %s %s %s %s %s\n", "����ѧ��", "����", "����ѧԺ", "�������", "������1", "������2", "רҵ��1", "רҵ��2", "���Գɼ�", "���Գɼ�", "����ɼ�", "�ۺϳɼ�");
	printf("%-5s\t%-5s\t%s\t%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t\n", tempData.stu_id, tempData.name, tempData.colleage, tempData.type, tempData.course1, tempData.course2, tempData.course3, tempData.course4, tempData.ptest, tempData.retest, tempData.olanguage, tempData.comprehensive);*/
	//����ɼ����ļ���
	saveStudentInfoToFile("data2.txt", list);

	//�Զ�����ѧ���˺�
	strcpy(account.account, tempData.stu_id);
	strcpy(account.password, account.account);
	account.type = 3;
	insertUserNodeNyHead(userList, account);
	////�����û���Ϣ���ļ�
	saveUserInfoToFile("data1.txt", userList);
}
//�޸��û�
void modifyStudentBySid(struct Node* list) {
	char sid[10] = { 0 };
	printf("������Ҫ�޸ĵĿ����ţ�");
	scanf("%s", sid);
	struct Node* modifyNode = findStudentBySid(list, sid);
	if (modifyNode == NULL) {
		printf("�޴�����Ϣ\n");
	}
	else {
		printf("������������");
		scanf("%s", modifyNode->data.name);
		printf("�����뱨�����");
		scanf("%s", modifyNode->data.type);
		while (strcmp(modifyNode->data.type, "ѧ˶") != 0 && strcmp(modifyNode->data.type, "ר˶") != 0 && strcmp(modifyNode->data.type, "��ȫ����") != 0) {
			printf("�������������������룺");
			scanf("%s", modifyNode->data.type);
		}
		printf("������1�ɼ���");
		scanf("%s", modifyNode->data.course1);
		while (atof(modifyNode->data.course1) < 0 || atof(modifyNode->data.course1) > 100) {
			printf("��������,�������룺");
			scanf("%s", modifyNode->data.course1);
		}
		printf("������2�ɼ���");
		scanf("%s", modifyNode->data.course2);
		while (atof(modifyNode->data.course2) < 0 || atof(modifyNode->data.course2) > 100) {
			printf("��������,�������룺");
			scanf("%s", modifyNode->data.course2);
		}
		printf("רҵ��1�ɼ���");
		scanf("%s", modifyNode->data.course3);
		while (atof(modifyNode->data.course3) < 0 || atof(modifyNode->data.course3) > 150) {
			printf("��������,�������룺");
			scanf("%s", modifyNode->data.course3);
		}
		printf("רҵ��2�ɼ���");
		scanf("%s", modifyNode->data.course4);
		while (atof(modifyNode->data.course4) < 0 || atof(modifyNode->data.course4) > 150) {
			printf("��������,�������룺");
			scanf("%s", modifyNode->data.course4);
		}
		int total = atof(modifyNode->data.course1) + atof(modifyNode->data.course2) + atof(modifyNode->data.course3) + atof(modifyNode->data.course4);
		_gcvt(total, 3, modifyNode->data.ptest);   //��Ϊ���õ��Ǹ���������������100����100. ����㣬���ԾͰ������ȥ��
		if ((modifyNode->data.ptest)[strlen(modifyNode->data.ptest) - 1] == '.') {
			(modifyNode->data.ptest)[strlen(modifyNode->data.ptest) - 1] == '\0';
		}
		printf("���Գɼ���");
		scanf("%s", modifyNode->data.retest);
		while (atof(modifyNode->data.retest) < 0 || atof(modifyNode->data.retest) > 200) {
			printf("��������,�������룺");
			scanf("%s", modifyNode->data.retest);
		}
		printf("����ɼ���");
		scanf("%s", modifyNode->data.olanguage);
		while (atof(modifyNode->data.olanguage) < 0 || atof(modifyNode->data.olanguage) > 20) {
			printf("��������,�������룺");
			scanf("%s", modifyNode->data.olanguage);
		}
		float totalGrade = atof(modifyNode->data.ptest) * 0.6 + atof(modifyNode->data.retest) * 0.3 + atof(modifyNode->data.olanguage) * 0.1;
		_gcvt(totalGrade, 5, modifyNode->data.comprehensive);
		//insertNodeNyHead(list, modifyNode->data);
		/*printf("%-5s\t%-5s\t%s\t%s %s %s %s %s %s %s %s %s\n", "����ѧ��", "����", "����ѧԺ", "�������", "������1", "������2", "רҵ��1", "רҵ��2", "���Գɼ�", "���Գɼ�", "����ɼ�", "�ۺϳɼ�");
		printf("%-5s\t%-5s\t%s\t%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t\n", tempData.stu_id, tempData.name, tempData.colleage, tempData.type, tempData.course1, tempData.course2, tempData.course3, tempData.course4, tempData.ptest, tempData.retest, tempData.olanguage, tempData.comprehensive);*/
		//����ɼ����ļ���
		saveStudentInfoToFile("data2.txt", list);
	}
}

//ɾ��ѧ���˻���ͬʱɾ���û�
int deleteStudentBySid(struct Accounts* userList,struct Node* list) {
	char  sid[10] = { 0 };
	printf("������Ҫɾ���ĸ��Կ��ţ�");//ɾ��ѧ��ͬʱҲҪɾ��ѧ����Ӧ���˻�
	scanf("%s", sid);
	struct Node* posFrontNode = list;  //Ҫɾ������ǰһ�����
	struct Node* posNode = list->next; //Ҫɾ���Ľ��
	if (posNode == NULL) {
		printf("��Ϊ�գ��޷�ɾ��\n");
		return 0;
	}
	else {
		while (posNode != NULL) {
			if (strcmp(posNode->data.stu_id, sid) == 0) {
				posFrontNode->next = posNode->next;
				printf("ɾ��ѧ����Ϣ�ɹ�\n");
				saveStudentInfoToFile("data2.txt", list);
				deleteUserByUsername(userList, sid);
				return 1;
			}
			posFrontNode = posNode;
			posNode = posNode->next;
		}
		printf("�޸��û�\n");
		return 0;
	}
}
//ͨ��ѧ���������߲���
int queryStudentBynameOrsid(struct Node* list) {
	char  query[20] = { 0 };
	printf("������Ҫ��ѯ�ĸ��Կ��Ż���������");
	scanf("%s", query);
	struct Node* posNode = list->next; 
	if (posNode == NULL) {
		printf("��Ϊ��\n");
		return 0;
	}
	else {
		while (posNode != NULL) {
			if (strcmp(posNode->data.stu_id, query) == 0|| strcmp(posNode->data.name, query) == 0) {
				printf("%-5s\t%-5s\t%s\t%-8s\t%s %s %s %s %s %s %s %s\n", "����ѧ��", "����", "����ѧԺ", "�������", "������1", "������2", "רҵ��1", "רҵ��2", "���Գɼ�", "���Գɼ�", "����ɼ�", "�ۺϳɼ�");
				printf("%-5s\t%-5s\t%s\t%-8s\t %s\t %s\t %s\t %s\t %s\t %s\t   %s\t   %s\t\n", posNode->data.stu_id, posNode->data.name, posNode->data.colleage, posNode->data.type, posNode->data.course1, posNode->data.course2, posNode->data.course3, posNode->data.course4, posNode->data.ptest, posNode->data.retest, posNode->data.olanguage, posNode->data.comprehensive);
				return 1;
			}
			posNode = posNode->next;
		}
		printf("�޸��û�\n");
		return 0;
	}
}
//����ѧ���ɼ�
void queryAllStudent(struct Node* list) {
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
//ͨ���ۺϳɼ�����
int cmp_by_comprehensive(const void* e1, const void* e2) {
	//return (strcmp(((struct student*)e1)->comprehensive ,((struct student*)e2)->comprehensive));
	
	//printf("%s\n", ((struct Node*)e1)->data.comprehensive);
//	printf("%s\n", ((struct Node*)e2)->data.comprehensive);
	double a = atof(((struct Node*)e1)->data.comprehensive);
	double b = atof(((struct Node*)e2)->data.comprehensive);
	//printf("a:%lf\n", a);
	//printf("b:%lf\n", b);
	if (a > b) {
		return 1;
	}
	else if (a < b) {
		return -1;
	}
	else {
		return 0;
	}
}
//����
void sort(struct Node* list) {
	struct Node* list1;//ѧ˶��
	struct Node* list2;//ר˶��
	struct Node* list3;//��ȫ����
	list1 = createList();
	list2 = createList();
	list3 = createList();
	struct Node* posNode = list->next;
	if (posNode == NULL) {
		printf("��Ϊ��\n");
		return;
	}
	else {
		while (posNode != NULL) {
			if (strcmp(posNode->data.type, "ѧ˶") == 0) {
				insertNodeNyHead(list1, posNode->data);
				//printf("%s\n", posNode->data.comprehensive);
			}else if (strcmp(posNode->data.type, "ר˶") == 0) {
				insertNodeNyHead(list2, posNode->data);
			}else if (strcmp(posNode->data.type, "��ȫ����") == 0) {
				insertNodeNyHead(list3, posNode->data);
			}
			posNode = posNode->next;
		}
		//�����������������
		qsort(list1,getStudentLenth(list1),sizeof(list1),cmp_by_comprehensive);
		qsort(list2, getStudentLenth(list2), sizeof(list2), cmp_by_comprehensive);
		qsort(list3, getStudentLenth(list3), sizeof(list3), cmp_by_comprehensive);

		//queryAllStudent(list1);
		//���浽�ļ���ȥ
		saveSortStudentInfoToFile("data3.txt", list1);
		saveSortStudentInfoToFile("data4.txt", list2);
		saveSortStudentInfoToFile("data5.txt", list3);
		printf("����ɹ�\n");
	}
	free(list1);
	free(list2);
	free(list3);
}
//�ͷ��ڴ�
void destory(struct Accounts* userList, struct Node* list) {
	if (userList != NULL) {
		free(userList);
	}
	if (list != NULL) {
		free(list);
	}
}
//��ӡѧ���ɼ�
void printSingleStudent(struct Node*list ,char *sid) {
	struct Node* posNode = findStudentBySid(list, sid);
	if (posNode == NULL) {
		printf("���޳ɼ�\n");
		return;
	}
	printf("%-5s\t%-5s\t%s\t%-8s\t%s %s %s %s %s %s %s %s\n", "����ѧ��", "����", "����ѧԺ", "�������", "������1", "������2", "רҵ��1", "רҵ��2", "���Գɼ�", "���Գɼ�", "����ɼ�", "�ۺϳɼ�");
	printf("%-5s\t%-5s\t%s\t%-8s\t %s\t %s\t %s\t %s\t %s\t %s\t   %s\t   %s\t\n", posNode->data.stu_id, posNode->data.name, posNode->data.colleage, posNode->data.type, posNode->data.course1, posNode->data.course2, posNode->data.course3, posNode->data.course4, posNode->data.ptest, posNode->data.retest, posNode->data.olanguage, posNode->data.comprehensive);
}