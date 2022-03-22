#define _CRT_SECURE_NO_WARNINGS

#include"singleList.h"

/***************ѧ��������Ϣ����****************/
Node* list;

/***************ѧ����ѯ��ͳ������****************/
Node* list2;

/***************�����쳣ͳ������****************/
Node* list3;

/***************����״��Ԥ������****************/
Node* list4;

/*****��������*********/
//////////////////////////////////////////////////////
// ��ҵ��
//////////////////////////////////////////////////////
//	���ӣ�
void  addStudent();
//	ɾ����
void deleteStudent();
//	���ң�
void queryStudent();
//	�޸ģ�
void updateStudnt();
//	��ӡ������Ϣ: 
void printAll();
//	ͳ��ѧ����Ϣ��
void stats();
//	ͳ���쳣��Ϣ
void exceptionStats();
//	�����쳣��Ϣ
void handleExceptions();
/////////////////////////////////////////////
//����ҵ��
/////////////////////////////////////////////
//	ѧԺ��ȡ
void getAcademy(char* stuID, char* academy);
//	����״̬��ȡ
int getState(int temperature, int cough);
//	��ȡѧ��
void getStuID(char* stuID);
//	��ȡʱ��
void getTime(char* time);
//	��ȡ����
void getDate(char* date);
//	���˵���
void mainMenu();

int main() {


	list = createList();
	list2 = createList();
	list3 = createList();
	list4 = createList();
	
	readFile("data1.txt", list);
	readFile("data2.txt", list2);

	exceptionStats();
	handleExceptions();
	
	sortByDate(list);
	sortByDate(list2);
	sortByDate(list3);
	sortByDate(list4);

	mainMenu();


	getchar();
	return 0;
}


/****************��������*****************/
//////////////////////////////////////////

/*
 �������ܣ�ѭ����ʾ���˵����ṩѡ������ʾ
		  ��������ѡ���������ҵ���� 
 ��������
 ����ֵ����
*/
void mainMenu() {
	int select = 0;
	printf("|--------------------------------------|\n");
	printf("|---  ��ӭʹ��ѧ����У��������ϵͳ  ---|\n");
	printf("|--------------------------------------|\n");
	printf("\n");
	while (1) {
		printf("|------------------------------|\n");
		printf("|       1. ����ѧ����Ϣ        |\n");
		printf("|       2. ɾ��ѧ����Ϣ        |\n");
		printf("|       3. �޸�ѧ����Ϣ        |\n");
		printf("|       4. ����ѧ����Ϣ        |\n");
		printf("|       5. ��ӡȫ����Ϣ        |\n");
		printf("|       6. ͳ��ѧ����Ϣ        |\n");
		printf("|       7. ͳ���쳣��Ϣ        |\n");
		printf("|       8. �����쳣��Ϣ        |\n");
		printf("|       0. �˳�ϵͳ            |\n");
		printf("|------------------------------|\n");
		printf("��ѡ��ҵ��");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			addStudent();
			break;
		case 2:
			deleteStudent();
			break;
		case 3:
			updateStudnt();
			break;
		case 4:
			queryStudent();
			break;
		case 5:
			printAll();
			break;
		case 6:
			stats();
			break;
		case 7:
			printList(list3);
			break;
		case 8:
			printList(list4);
			break;
		case 0:
			exit(0);
		default:
			printf("����ѡ������������ѡ��\n");
		}
	}

}

/*
 �������ܣ����ѧ����Ϣ
 ��������
 ����ֵ����
*/
void addStudent() {
	int loop = 1;
	int select = 0;
	student stu;
	while (loop) {
		printf("----------  ����ѧ����Ϣ  ----------\n");
		printf("������");
		scanf("%s", stu.name);

		getStuID(stu.stuID);//ѧ��
		
		printf("���£�");
		scanf("%f", &stu.temperature);

		printf("�Ƿ����(1�� 0��)��");
		scanf("%d", &stu.cough);

		getTime(stu.time);//ʱ��

		getDate(stu.date);//����

		getAcademy(stu.stuID, stu.academy);//ѧԺ
		stu.state = getState(stu.temperature, stu.cough);//����״̬
		stu.day = 0;

		insertNode(list, stu);//��������
		writeFile("data1.txt", list);//���浽������Ϣ�ļ���
		printf("�Ƿ������ӣ�1�� 0��");
		while (1) {
			scanf("%d", &select);
			if (select == 1) {
				break;
			}
			else if (select == 0) {
				loop = 0;
				break;
			}
			else {
				printf("������������������(1��0)��");
				continue;
			}
		}
		
	}
	
}

/*
�������ܣ�ɾ��ѧ����Ϣ����ѧ��״̬��stateΪ0 
��������
����ֵ�� �� 
*/
void deleteStudent() {
	int loop = 1;
	int select = 0;
	char stuID[20];
	printf("----------  ɾ��ѧ����Ϣ  ----------\n");
	while (loop) {
		printf("��������Ҫɾ����ѧ��ѧ�ţ�");
		scanf("%s", stuID);
		deleteNode(list, stuID);
		writeFile("data1.txt", list);//���浽�ļ�
		printf("�Ƿ����ɾ����1�� 0��");
		while (1) {
			scanf("%d", &select);
			if (select == 1) {
				break;
			}
			else if (select == 0) {
				loop = 0;
				break;
			}
			else {
				printf("������������������(1��0)��");
				continue;
			}
		}
	}
	
}

/*
�������ܣ��޸�ѧ����Ϣ���ȸ���ѧ�Ų���
		  �ҵ�����������ѧ�����ݣ�Ȼ��
		  ��д�ļ�
��������
����ֵ�� ��
*/
void updateStudnt() {
	int loop = 1;
	int select = 0;
	Node* node;
	char* date[20] = { "" };
	char* stuID[20] = {""};
	printf("----------  �޸�ѧ����Ϣ  ----------\n");
	while (loop) {
		getStuID(stuID);
		getDate(date);

		node = searchNodeByID(list, stuID,date);

		if (node == NULL) {
			printf("û���ҵ�ѧ����Ϣ!");
			continue;
		}

		printf("������");
		scanf("%s", node->data.name);

		getStuID(stuID);

		printf("���£�");
		scanf("%f", &node->data.temperature);

		printf("�Ƿ����(1�� 0��)��");
		scanf("%d", &node->data.cough);

		getTime(node->data.time);//ʱ��

		getDate(node->data.date);//����

		getAcademy(node->data.stuID, node->data.academy);//ѧԺʶ��
		
		node->data.state = getState(node->data.temperature, node->data.cough);//״̬ʶ��
		writeFile("data1.txt", list);//���浽�ļ�

		printf("�Ƿ�����޸ģ�1�� 0��");

		while (1) {
			scanf("%d", &select);
			if (select == 1) {
				break;
			}
			else if (select == 0) {
				loop = 0;
				break;
			}
			else {
				printf("������������������(1��0)��");
				continue;
			}
		}
	}
	
}

/*
�������ܣ���ѯѧ����Ϣ�����Ը���ѧ��
		  ��������ѯ
��������
����ֵ�� ��
*/
void queryStudent() {
	Node* newNode = NULL;
	int loop = 1;
	int select = 0;
	char* date[20] = { "" };
	char* stuID[20] = {""};
	printf("----------  ��ѯѧ����Ϣ  ----------\n");
	while (loop) {
		getStuID(stuID);
		getDate(date);
		newNode = searchNode(list, stuID, date);
		if (newNode == NULL) {
			printf("δ�ҵ������Ϣ��");
		}else{
			printCurNode(newNode);
		}
		
		printf("�Ƿ������ѯ��1�� 0��");

		while (1) {
			scanf("%d", &select);
			if (select == 1) {
				break;
			}
			else if (select == 0) {
				loop = 0;
				break;
			}
			else {
				printf("������������������(1��0)��");
				continue;
			}
		}
	}
}

/*
�������ܣ����ȫ��ѧ����Ϣ
��������
����ֵ�� ��
*/
void printAll() {
	printf("----------  ���ȫ����Ϣ  ----------\n");
	printList(list);
}

/*
�������ܣ��ֱ�ѧ�š�����������ʽ��ѧ����Ϣͳ��
��������
����ֵ����
*/
void stats() {
	if (list->next == NULL) {
		return;
	}
	Node* newNode = NULL;//list�����в�ѯ���Ľ��
	Node* newNode2 = NULL;//list2�����в�ѯ���Ľ��
	Node* pNode = list;//list�������ָ��
	Node* pNode2 = list2;//list2�������ָ��
	int mode = 0;//ͳ�Ʒ�ʽ
	int loop = 1;//��ѭ������
	int select = 0;//�Ƿ�������ѡ��
	char* date[20];
	char* name[20];
	char* stuID[20];
	printf("----------  ͳ��ѧ����Ϣ  ----------\n");
	while (loop) {
		printf("������ͳ�Ʒ�ʽ 1��ѧ�� 0��������");
		scanf("%d", &mode);
		switch (mode) {
		case 0://����������
			printf("������ѧ��������");
			scanf("%s", name);
			getDate(date);
			while ((newNode = searchNodeByName(pNode, name)) != NULL) {
				pNode2 = list2;
				if (list2->next == NULL) {
					insertNode(list2, newNode->data);
					writeFile("data2.txt", list2);
				}
				else {
					while ((newNode2 = searchNodeByName(pNode2, name)) != NULL) {
						if (strcmp(newNode2->data.date, newNode->data.date) == NULL) {
							break;
						}
						pNode2 = newNode2;
					}
					if (newNode2 == NULL) {
						insertNode(list2, newNode->data);
						writeFile("data2.txt", list2);
					}
				}
				pNode = newNode;//�������²�ѯ
			}
			
			printList(list2);
			break;
		case 1://��ѧ�Ų�ѯ
			getStuID(stuID);
			getDate(date);
			while ((newNode = searchNodeByID(pNode, stuID)) != NULL) {
				pNode2 = list2;
				if (list2->next == NULL) {//����Ϊ��
					insertNode(list2, newNode->data);
					writeFile("data2.txt", list2);
				}
				else{
					while ((newNode2 = searchNodeByID(pNode2, stuID)) != NULL) {
						if (strcmp(newNode2->data.date, newNode->data.date) == NULL) {
							break;
						}
						pNode2 = newNode2;
					}
					if (newNode2 == NULL) {
						insertNode(list2, newNode->data);
						writeFile("data2.txt", list2);
					}
				}
				pNode = newNode;//�������²�ѯ
			}
			printList(list2);
			break;
		default:
			printf("������������������ͳ�Ʒ�ʽ��");
			break;
		}

		//printCurNode(searchNode(list, stuID));

		printf("�Ƿ������ѯ��1�� 0��");
		while (1) {
			scanf("%d", &select);
			if (select == 1) {
				break;
			}
			else if (select == 0) {
				loop = 0;
				break;
			}
			else {
				printf("�������������������Ƿ������ѯ��1�� 0��");
				continue;
			}
		}
	}
}

/*
�������ܣ�ͳ��ÿ�콡��״̬Ϊ�쳣��ѧ����Ϣ
		  ���ں����ص�۲��뽡������
��������
����ֵ����
*/
void exceptionStats() {
	if (list->next == NULL) {
		return;
	}
	Node* pNode = list->next;
	//printf("----------  ͳ���쳣��Ϣ  ----------\n");
	while (pNode) {
		if (pNode->data.state == 0) {
			insertNode(list3, pNode->data);
			writeFile("data3.txt", list3);
		}
		pNode = pNode->next;
	}
}

/*
�������ܣ�����״��Ԥ������ĳѧ������״���������켰����
		  Ϊ������ʱ������������ʾ
��������
����ֵ����
*/
void handleExceptions() {
	if (list3->next == NULL) {
		return;
	}
	Node* pNode3 = list3->next;
	Node* pNode4 = list4;
	Node* newNode = NULL;
	//printf("----------  �����쳣��Ϣ  ----------\n");
	while (pNode3) {
		pNode4 = list4;
		if (list4->next == NULL) {//����Ϊ��
				insertNode(list4, pNode3->data);
				writeFile("data4.txt", list4);
			}
		else {
			while ((newNode = searchNodeByID(pNode4, pNode3->data.stuID)) != NULL) {
				if (strcmp(newNode->data.date, pNode3->data.date) == NULL) {
					break;
				}
				pNode4 = newNode;
			}
			if (newNode == NULL) {
				insertNode(list4, pNode3->data);
				writeFile("data4.txt", list4);
			}
		}
	pNode3 = pNode3->next;
	}
}

/*
�������ܣ�����ѧ�ŵĵ�5��6λʶ��ѧԺ����
������ѧ��ѧ�š���Ҫʶ���ԺУ
����ֵ����
*/
void getAcademy(char* stuID,char* academy) {
	char* num[4] = {""};
	strncpy(num, stuID + 4, 2);
	num[3] = '\0';
	switch (atol(num)) {
		case 1:
			strcpy(academy, "ͨ��ѧԺ");
			break;
		case 2:
			strcpy(academy, "�����ѧԺ");
			break;
		case 3:
			strcpy(academy, "���ѧԺ");
			break;
		case 4:
			strcpy(academy, "�Զ���ѧԺ");
			break;
		case 5:
			strcpy(academy, "����ѧԺ");
			break;
		case 6:
			strcpy(academy, "�о���Ժ");
			break;
		case 7:
			strcpy(academy, "����ѧԺ");
			break;
		case 8:
			strcpy(academy, "����ѧԺ");
			break;
		case 9:
			strcpy(academy, "����ѧԺ");
			break;
		case 10:
			strcpy(academy, "��ýѧԺ");
			break;
		case 11:
			strcpy(academy, "�Ƚ�����ѧԺ");
			break;
		case 12:
			strcpy(academy, "���˼����ѧԺ");
			break;
	}
}

/*
�������ܣ���ȡѧ���Ľ���״̬����ѧ������>=37��
		  ���ߴ��ڿ�������ʱ������״̬Ϊ�쳣
		  ������������
������ѧ������temperature������״̬cough
����ֵ������״̬
*/
int getState(float temperature, int cough) {
	if (temperature <= 37.3 && cough == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void getStuID(char* stuID) {
	char num1[10] = {""};
	char num2[5] = { "" };
	char num3[10] = { "" };
	printf("ѧ�ţ�");
	while (1) {
		scanf("%s", stuID);
		strncpy(num1, stuID, 4);
		num1[4] = '\0';
		strncpy(num2, stuID + 4, 2);
		num2[2] = '\0';
		strncpy(num3, stuID + 6, 3);
		num3[3] = '\0';
		if (strlen(stuID) != 9) {
			printf("ѧ�Ÿ�ʽ��������������!");
			continue;
		}
		if (atol(num1) < 2016 || atol(num1) > 2019 ||
			atol(num2) < 1 || atol(num2) > 12 ||
			atol(num3) < 1 || atol(num3) > 999) {
			printf("ѧ�Ÿ�ʽ�������������룡");
			continue;
		}
		else {
			break;
		}
	}
}


/*
�������ܣ���ȡʱ�䣬��ʽΪxx��xx
������ʱ��
����ֵ����
*/
void getTime(char* time) {
	char num1[5] = { "" };
	char num2[5] = { "" };
	char num3[5] = { "" };
	printf("ʱ�䣺");
	while (1) {
		scanf("%s", time);
		strncpy(num1, time, 2);
		num1[2] = '\0';
		strncpy(num2, time + 2, 1);
		num2[1] = '\0';
		strncpy(num3, time + 3, 2);
		num3[2] = '\0';
		if (strlen(time) != 5) {
			printf("ʱ���ʽ��������������!");
			continue;
		}
		if (atol(num1) < 0 || atol(num1) > 24 ||
			strcmp(num2,":") != 0 ||
			atol(num3) < 0 || atol(num3) > 59) {
			printf("ʱ���ʽ�������������룡");
			continue;
		}
		else {
			break;
		}
	}
}

/*
�������ܣ���ȡ���ڣ���ʽΪ��λ���+��λ�·�+��λ����
		  ͳ��ʱ��Ϊ2022��4��29��2022��5��12��
������ʱ��
����ֵ����
*/
void getDate(char* date) {
	char num1[10] = { "" };
	char num2[5] = { "" };
	char num3[5] = { "" };
	printf("���ڣ�");
	while (1) {
		scanf("%s", date);
		strncpy(num1, date, 4);
		num1[4] = '\0';
		strncpy(num2, date + 4, 2);
		num2[2] = '\0';
		strncpy(num3, date + 6, 2);
		num3[2] = '\0';
		if (strlen(date) != 8) {
			printf("���ڸ�ʽ��������������!");
			continue;
		}
		if (strcmp(num1,"2022") != 0 ) {
			printf("���ڸ�ʽ�������������룡");
			continue;
			
		}
		if (strcmp(num2, "04") != 0 && strcmp(num2, "05") != 0) {
			printf("���ڸ�ʽ�������������룡");
			continue;
		}
		if (strcmp(num2, "04") == 0) {
			if (atol(num3) < 29 || atol(num3) > 30) {
				printf("���ڸ�ʽ�������������룡");
				continue;
			}
			else {
				break;
			}
		}
		if (strcmp(num2, "05") == 0) {
			if (atol(num3) < 1 || atol(num3) > 12) {
				printf("���ڸ�ʽ�������������룡");
				continue;
			}
			else {
				break;
			}
		}
		
	}
}