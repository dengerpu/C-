#define _CRT_SECURE_NO_WARNINGS
#include "System.h"

//��ȡ�ļ����û���Ϣ
void readUserInfoFromFile(const char* filename, struct Accounts* listHeadNode) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w");  //����ļ������ڣ��ʹ����ļ�
	}
	struct Account account;
	while (fscanf(fp, "%s\t%s\t%d\t\n", account.account,account.password,&(account.type)) != EOF) {
		insertUserNodeNyHead(listHeadNode, account);
		memset(&account, 0, sizeof(account));
	}
	//printf("%d\n", getUserLenth(listHeadNode));
	//���Ϊ�գ���˵����һ��ʹ��ϵͳ��
	//��һ������������Զ����ɹ���Ա�˺ź�����
	if (getUserLenth(listHeadNode)==0) {
		strcpy(account.account, "admin");
		strcpy(account.password, "admin");
		account.type = 1;
		fprintf(fp, "%s\t%s\t%d\t\n", account.account, account.password, account.type);
	}
	fclose(fp);
	fp = NULL;
}
//�����û���Ϣ���ļ�
void saveUserInfoToFile(const char* filename, struct Accounts* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Accounts* pMove = listHeadNode->next;
	while (pMove) {
		fprintf(fp, "%s\t%s\t%d\t\n", pMove->account.account, pMove->account.password, pMove->account.type);
		pMove = pMove->next;
	}
	fclose(fp);
	fp = NULL;
}
//�����û�,���ؽ��Ϊ�û����ͣ�����Ҳ�����Ϊ�գ�����Ϊ0
int findUser(struct Accounts* listHeadNode, char* user, char* pwd) {
	struct Accounts* node = listHeadNode->next;
	if (node == NULL) {
		return 0;
	}
	else {
		while (node != NULL) {
			if (strcmp(node->account.account, user) == 0 && strcmp(node->account.password,pwd) == 0) {
				//printf("%s\n", node->account.account);
				//printf("%s\n", node->account.password);
				//printf("%d\n", node->account.type);
				return node->account.type;
			}
			node = node->next;
		}
		return 0; //���Ҳ���
	}
}
//�����û��޸�����
void AdviceModifyPwd(struct Accounts* userList, char* user, char* pwd) {
	char newpwd[10] = { 0 };
	struct Accounts* node = userList->next;
	strcpy(newpwd, pwd);
	while (strcmp(user, newpwd) == 0) {
		printf("���޸����룺");
		scanf("%s", newpwd);
	}
	while (node != NULL) {
		if (strcmp(node->account.password, user) == 0) {
			strcpy(node->account.password ,newpwd);
			printf("�޸�����ɹ����´ε�¼��Ч\n");
			saveUserInfoToFile("data1.txt", userList);
		}
		node = node->next;
	}
}

//��½
int login(struct Accounts* userList,char* user) {
	char account[10] = { 0 };
	char password[10] = { 0 };
	int i = 3;
	while (i--) {
		printf("---------�о��������ɼ�����ϵͳ--------\n");
		printf("\t\t�˺�:");
		scanf("%s", account);
		printf("\t\t����:");
		scanf("%s", password);
		int type = findUser(userList, account, password);
		if (type == 1) {
			printf("��ӭ����Ա��¼\n");
			AdviceModifyPwd(userList, account, password);
			return 1;
		}else if(type==2){
			printf("��ӭϵͳ����Ա��½\n");
			AdviceModifyPwd(userList, account, password);
			return 2;
		}
		else if (type ==3 ) {
			printf("��ӭѧ����¼\n");
			AdviceModifyPwd(userList, account, password);
			strcpy(user, account);//��user���ݻ�ȥ��ѧ��
			return 3;
		}
		else {
			printf("�˺Ż������������������\n");
			printf("�㻹��%d�λ���\n", i);
			system("pause");
			system("cls");
		}
	}
	return 0;
}

//����Ա�˵�
void adminMenu() {
	printf("---------�о��������ɼ�����ϵͳ--------\n");
	printf("\t\t0.�˳��ɼ�����ϵͳ\n");
	printf("\t\t1.����û���Ϣ\n");
	printf("\t\t2.�޸��û���Ϣ\n");
	printf("\t\t3.ɾ���û���Ϣ\n");
	printf("\t\t4.��ѯ�û���Ϣ\n");
	printf("\t\t5.���ѧ���ɼ���Ϣ\n");
	printf("\t\t6.�޸�ѧ���ɼ���Ϣ\n");
	printf("\t\t7.ɾ��ѧ���ɼ���Ϣ\n");
	printf("\t\t8.��ѯѧ���ɼ���Ϣ\n");
	printf("\t\t9.��ӡ�û���Ϣ\n");
	printf("\t\t10.��ӡѧ���ɼ���Ϣ\n");
	printf("\t\t11.����\n");
	printf("----------------------------------------\n");
	printf("��ѡ�����:>");
}
//ϵͳ����Ա�˵�
void SystemoptionMenu() {
	printf("---------�о��������ɼ�����ϵͳ--------\n");
	printf("\t\t0.�˳��ɼ�����ϵͳ\n");
	printf("\t\t1.���ѧ���ɼ���Ϣ\n");
	printf("\t\t2.�޸�ѧ���ɼ���Ϣ\n");
	printf("\t\t3.ɾ��ѧ���ɼ���Ϣ\n");
	printf("\t\t4.��ѯѧ���ɼ���Ϣ\n");
	printf("\t\t5.��ӡѧ���ɼ���Ϣ\n");
	printf("\t\t6.����\n");
	printf("---------------------------------------\n");
	printf("��ѡ�����:>");
}
//ѧ���˵�
void StudentMenu() {
	printf("---------�о��������ɼ�����ϵͳ--------\n");
	printf("\t\t0.�˳�ϵͳ\n");
	printf("\t\t1.�鿴�ɼ�\n");
	printf("---------------------------------------\n");
	printf("��ѡ�����:>");
}

//�����û�����
struct Accounts* createUserList() {
	//����ռ�
	struct Accounts* listHead = (struct Accounts*)malloc(sizeof(struct Accounts));
	listHead->next = NULL;
	return listHead;
}
//�����û����
struct Accounts* createUserNode(struct Account account) {
	struct Accounts* newNode = (struct Accounts*)malloc(sizeof(struct Accounts));
	newNode->account = account;
	newNode->next = NULL;
	return newNode;
}
//�û�ͷ�巨������ڵ�
void insertUserNodeNyHead(struct Accounts* listHeadNode, struct Account account) {
	struct Accounts* newNode = createUserNode(account);//����һ���½��
	newNode->next = listHeadNode->next;
	listHeadNode->next = newNode;
}

//�����û�������
int getUserLenth(struct Accounts* listHeadNode) {
	int length = 0;
	struct Accounts* node = listHeadNode->next;
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
	while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", tempData.stu_id, tempData.name, tempData.colleage, tempData.type, tempData.course1, tempData.course2, tempData.course3, tempData.course4, tempData.ptest, tempData.retest, tempData.olanguage, tempData.comprehensive) != EOF) {
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
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", pMove->data.stu_id, pMove->data.name, pMove->data.colleage, pMove->data.type, pMove->data.course1, pMove->data.course2, pMove->data.course3, pMove->data.course4, pMove->data.ptest, pMove->data.retest, pMove->data.olanguage, pMove->data.comprehensive);
		pMove = pMove->next;
	}
	fclose(fp);
	fp = NULL;
}

//����������ѧ����Ϣ���ļ�
void saveSortStudentInfoToFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Node* pMove = listHeadNode->next;
	int i = 0;
	while (pMove) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", pMove->data.stu_id, pMove->data.name, pMove->data.colleage, pMove->data.type, pMove->data.course1, pMove->data.course2, pMove->data.course3, pMove->data.course4, pMove->data.ptest, pMove->data.retest, pMove->data.olanguage, pMove->data.comprehensive);
		i++;
		if (i % 10 == 0) {   //ÿ��10����Ϣ��һ�����и���
			fprintf(fp, "\n");
		}
		pMove = pMove->next;
	}
	fclose(fp);
	fp = NULL;
}

