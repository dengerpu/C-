#define _CRT_SECURE_NO_WARNINGS
#include "option.h"
//��ʼ��ϵͳ
void init() {
	char cmd[128];
	sprintf(cmd, "mode con lines=%d cols=%d", WIN_HEIGHT, WIN_WIDTH); //�ı䴰�ڴ�С
	system(cmd);
	//��ʼ�����������ļ����ݵȲ���
}
//��½
int login() {
	char user[20] = { 0 };
	char pwd[20] = { 0 };
	int i = 3;
	char buff[64] = { 0 };
	while (i--) {
		printMenuHead(MENU_WIDTH);
		printMenuMidInfo(MENU_WIDTH, "��½ϵͳ");
		printMenuTail(MENU_WIDTH);
		printMidInfo("�˺ţ�");
		scanf("%s", user);
		printMidInfo("���룺");
		scanf("%s", pwd);
		if (strcmp(user, "admin") == 0 && strcmp(pwd, "admin")==0) {
			printMidInfo("��½�ɹ�\n");
			return 1;
		}
		else {
			if (i != 0) {
				sprintf(buff, "�㻹��%d�λ���\n", i);
				printMidInfo(buff);
			}	
		}
		system("pause");
		system("cls");
	}
	return 0;
}
//�˵�
void menu() {
	printMenuHead(MENU_WIDTH);
	printMenuMidInfo(MENU_WIDTH, "��У��Ϣ����ϵͳ");
	printMenuMidInfo(MENU_WIDTH, "");
	const char* subMenus[] = {
		"1.���ѧ����Ϣ",
		"2.����ѧԺ����",
		"3.�˵�3",
		"4.����ѧ����Ϣ",
		"5.�޸�ѧ����Ϣ",
		"6.��ӡѧ����Ϣ",
		"0.�˳�ϵͳ"
	};
	int count = sizeof(subMenus) / sizeof(subMenus[0]);
	for (int i = 0; i < count; i++) {
		printMenuMidInfo(MENU_WIDTH, subMenus[i]);
	}
	printMenuMidInfo(MENU_WIDTH, "");
	printMenuTail(MENU_WIDTH);
	printMidInfo("��ѡ��0-6��");
}

////����������
//char head[][COL_LEN_MAX] = { "ѧ��","����","���֤��","ѧԺ","ѧ������","רҵ","��У·��","��ͨ����","���нӴ�","�¶�","��ȥ14�첡ʷ","�Ƿ���","��Уʱ��" };
////��ӡѧ����Ϣ
//void printStudent(struct Node* list) {
//	struct Node* pMove = list->next;
//	if (pMove == NULL) {
//		printMidInfo("��Ϊ��\n");
//		return;
//	}
//	int col = sizeof(head) / sizeof(head[0]);
//	char row[13][COL_LEN_MAX];
//	int i = 0;
//	//system("cls");
//	printTableHead(TABLE_WIDTH, col);
//	printTableRow(TABLE_WIDTH, head, col);
//	printTableMidLine(TABLE_WIDTH, col);
//	while (pMove) {
//		sprintf(row[0], "%s", pMove->data.stu_id);
//		sprintf(row[1], "%s", pMove->data.name);
//		sprintf(row[2], "%s", pMove->data.sid);
//		sprintf(row[3], "%s", pMove->data.college);
//		sprintf(row[4], "%s", pMove->data.type);
//		sprintf(row[5], "%s", pMove->data.major);
//		sprintf(row[6], "%s", pMove->data.route);
//		sprintf(row[7], "%s", pMove->data.traffic);
//		sprintf(row[8], "%s", pMove->data.isClose);
//		sprintf(row[9], "%s", pMove->data.temperate);
//		sprintf(row[10], "%s", pMove->data.history);
//		sprintf(row[11], "%s", pMove->data.isCough);
//		sprintf(row[12], "%s", pMove->data.time);
//		printTableRow(TABLE_WIDTH, row, col);
//		if (pMove->next != NULL) {
//			printTableMidLine(TABLE_WIDTH, col);
//		}
//		else {
//			printTableTail(TABLE_WIDTH, col);
//		}
//		pMove = pMove->next;
//		i++;
//	}
//	char buff[64];
//	sprintf(buff, "��%d�� \n" ,i);
//	printMidInfo(buff);
//}
void printStudent(struct Node* list) {
	struct Node* pMove = list->next;
	if (pMove == NULL) {
		printf("��Ϊ��\n");
		return;
	}
	printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", "ѧ��", "����", "���֤��", "ѧԺ", "ѧ������", "רҵ", "��У·��", "��ͨ����", "���нӴ�", "�¶�", "��ȥ14�첡ʷ", "�Ƿ���", "��Уʱ��");
	while (pMove) {
		printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", pMove->data.stu_id, pMove->data.name, pMove->data.sid, pMove->data.college, pMove->data.type, pMove->data.major, pMove->data.route, pMove->data.traffic, pMove->data.isClose, pMove->data.temperate, pMove->data.history, pMove->data.isCough, pMove->data.time);
		pMove = pMove->next;
	}
}
//��ӡ����
void printStudentArr(struct student* arr, int length) {
	if (arr == NULL) {
		printf("��Ϊ��\n");
		return;
	}
	printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", "ѧ��", "����", "���֤��", "ѧԺ", "ѧ������", "רҵ", "��У·��", "��ͨ����", "���нӴ�", "�¶�", "��ȥ14�첡ʷ", "�Ƿ���", "��Уʱ��");
	for (int i = 0; i < length; i++) {
		printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", arr[i].stu_id, arr[i].name, arr[i].sid, arr[i].college, arr[i].type, arr[i].major, arr[i].route, arr[i].traffic, arr[i].isClose, arr[i].temperate, arr[i].history, arr[i].isCough, arr[i].time);
	}
}
//����ѧ����Ϣ
struct student inputStudent() {
	struct student tempData;
	memset(&tempData, 0, sizeof(tempData));
	printf("������ѧ��:");
	scanf("%s", tempData.stu_id);
	printf("����������:");
	scanf("%s", tempData.name);
	printf("���������֤��:");
	scanf("%s", tempData.sid);
	printf("������ѧԺ:");
	scanf("%s", tempData.college);
	printf("����������:");
	scanf("%s", tempData.type);
	printf("������רҵ:");
	scanf("%s", tempData.major);
	printf("�����뷵У·��:");
	scanf("%s", tempData.route);
	printf("�����뽻ͨ����:");
	scanf("%s", tempData.traffic);
	printf("�������Ƿ����нӴ�:");
	scanf("%s", tempData.isClose);
	printf("�������¶�:");
	scanf("%s", tempData.temperate);
	printf("�������ȥ14�첡ʷ:");
	scanf("%s", tempData.history);
	printf("�������Ƿ��տ���:");
	scanf("%s", tempData.isCough);
	printf("�������Уʱ��:");
	scanf("%s", tempData.time);
	return tempData;
}

//���ѧ����Ϣ
void addStudent(struct Node* list) {
	struct student tempData = inputStudent();
	//����������
	insertNodeNyHead(list, tempData);
	//�����ļ�
	saveStudentInfoToFile(list);
	//��������ѧ�����ļ���ȥ
	saveALLStudentInfoToFile("data.txt", list);
}
//����ѧ��ѧ�Ż����������֤��
struct Node* searchStudent(struct Node* list) {
	struct Node *newList = createList();
	struct Node* pMove = list->next;
	if (pMove == NULL) {
		printf("��Ϊ��\n");
		return NULL;
	}
	char query[20] = { 0 };
	printf("������Ҫ�����Ĺؼ��֣�ѧ���������֤�ž��ɣ�ѧ�����֤��Ϊ���ؼ��֣���:");
	int flag = 1;
	scanf("%s", query);
	while (pMove != NULL) {
		if (strcmp(query, pMove->data.stu_id) == 0 || strcmp(query, pMove->data.sid) == 0 || strcmp(query, pMove->data.name) == 0) {
			if (flag) {
				printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", "ѧ��", "����", "���֤��", "ѧԺ", "ѧ������", "רҵ", "��У·��", "��ͨ����", "���нӴ�", "�¶�", "��ȥ14�첡ʷ", "�Ƿ���", "��Уʱ��");
				
				flag = 0;
			}
			insertNodeNyHead(newList, pMove->data);
			printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", pMove->data.stu_id, pMove->data.name, pMove->data.sid, pMove->data.college, pMove->data.type, pMove->data.major, pMove->data.route, pMove->data.traffic, pMove->data.isClose, pMove->data.temperate, pMove->data.history, pMove->data.isCough, pMove->data.time);
		}
		pMove = pMove->next;
	}
	if (flag) {
		printf("���޴���\n");
		return NULL;
	}
	return newList;

}
int cmp_by_college(const void* e1, const void* e2) {
	
	if (strcmp(((struct student*)e1)->type, ((struct student*)e2)->type) > 0) {//�Ȱ�ѧ��������
		return 1;
	}else if (strcmp(((struct student*)e1)->type, ((struct student*)e2)->type) < 0) {
		return -1;
	}
	else if (strcmp(((struct student*)e1)->type, ((struct student*)e2)->type) == 0) {
		if (strcmp(((struct student*)e1)->major, ((struct student*)e2)->major) > 0) {
			return 1;
		}
		else if (strcmp(((struct student*)e1)->major, ((struct student*)e2)->major) < 0) {
			return -1;
		}
		else if (strcmp(((struct student*)e1)->major, ((struct student*)e2)->major) == 0) {
			if (strcmp(((struct student*)e1)->stu_id, ((struct student*)e2)->stu_id) > 0) {//�Ȱ�ѧ��������
				return 1;
			}
			else if (strcmp(((struct student*)e1)->stu_id, ((struct student*)e2)->stu_id) < 0) {
				return -1;
			}
			else {
				return 0;
			}
		}
	}
}
//����
void sortStudent(struct Node* list) {
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
	char college[20] = { 0 };
	char filename[20] = { 0 };
	int flag = 1;
	struct students arr;
	InitStudents(&arr);
	while (flag) {
		printf("������ѧԺ��:");
		scanf("%s", college);
		for (int i = 0; i < count; i++) {
			if (strcmp(college, collegeArr[i]) == 0) {
				flag = 0;
			}
		}
	}
	strcpy(filename, college);
	char newfilename[20] = { 0 };
	strcpy(newfilename, filename);
	strcat(filename, ".txt");
	FILE* fp = fopen(filename, "r+");
	if (fp == NULL) {
		printf("�޸�ѧԺ��Ϣ\n");
	}
	else {
		struct student tempData;
		while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", tempData.stu_id, tempData.name, tempData.sid, tempData.college, tempData.type, tempData.major, tempData.route, tempData.traffic, tempData.isClose, tempData.temperate, tempData.history, tempData.isCough, tempData.time) != EOF) {
			arr.data[arr.size++] = tempData;
			CheckCapacity(&arr);
			memset(&tempData, 0, sizeof(tempData));
		}
	}
	if (arr.size == 0) {
		printf("��ѧԺ��ѧ����Ϣ\n");
	}
	else {
		qsort(arr.data, arr.size, sizeof(arr.data[0]), cmp_by_college);
		printStudentArr(arr.data, arr.size);
		strcat(newfilename, "����.txt");
		saveStudentArrInfoToFile(newfilename, arr.data, arr.size);
	}
	fclose(fp);
	fp = NULL;
	free(arr.data);
	arr.data = NULL;
}
void modifyStudent() {
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
	char college[20] = { 0 };
	char filename[20] = { 0 };
	int flag = 1;
	struct Node* newList = createList();
	while (flag) {
		printf("������ѧԺ��:");
		scanf("%s", college);
		for (int i = 0; i < count; i++) {
			if (strcmp(college, collegeArr[i]) == 0) {
				flag = 0;
			}
		}
	}
	strcpy(filename, college);
	char newfilename[20] = { 0 };
	strcpy(newfilename, filename);
	strcat(newfilename, "����.txt");
	FILE* fp = fopen(newfilename, "r+");
	if (fp == NULL) {
		printf("�޸�ѧԺ��Ϣ\n");
	}
	else {
		struct student tempData;
		while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", tempData.stu_id, tempData.name, tempData.sid, tempData.college, tempData.type, tempData.major, tempData.route, tempData.traffic, tempData.isClose, tempData.temperate, tempData.history, tempData.isCough, tempData.time) != EOF) {
			insertNodeNyHead(newList, tempData);
			memset(&tempData, 0, sizeof(tempData));
		}
	}
	if (newList->next == 0) {
		printf("��ѧԺ��ѧ����Ϣ\n");
	}
	else {
		char query[20] = { 0 };
		printf("������Ҫ�޸ĵ�ѧ��ѧ��:");
		scanf("%s", query);
		struct Node* pMove = newList->next;
		int findFlag = 1;
		while (pMove) {
			if (strcmp(query, pMove->data.stu_id) == 0) {
				struct student modifyStudent = inputStudent();
				findFlag = 0;
				pMove->data = modifyStudent;
			}
			pMove = pMove->next;
		}
		if (findFlag == 1) {
			printf("�޴���\n");
		}
		else {
			saveALLStudentInfoToFile(newfilename, newList);
		}

	}
	fclose(fp);
	fp = NULL;

}