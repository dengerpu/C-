#define _CRT_SECURE_NO_WARNINGS
#include "option.h"
const char* collegeArr[] = {
	"ͨ��ѧԺ",
	"�����ѧԺ",
	"���ѧԺ",
	"�Զ���ѧԺ",
	"����ѧԺ",
	"�о���Ժ",
	"����ѧԺ",
	"����ѧԺ",
	"����ѧԺ",
	"��ýѧԺ",
	"�Ƚ�����ѧԺ",
	"���˼����ѧԺ"
};
//��ʼ��ϵͳ
void init() {
	char cmd[128];
	sprintf(cmd, "mode con lines=%d cols=%d", WIN_HEIGHT, WIN_WIDTH); //�ı䴰�ڴ�С
	system(cmd);
	//��ʼ�����������ļ����ݵȲ���
}
//�˵�
void menu() {
	printMenuHead(MENU_WIDTH);
	printMenuMidInfo(MENU_WIDTH, "2020ѧ����У��������ϵͳ");
	printMenuMidInfo(MENU_WIDTH, "");
	const char* subMenus[] = {
		"1.���ѧ����Ϣ",
		"2.�޸�ѧ����Ϣ",
		"3. ��ѯ��ͳ�� ",
		"4.�쳣ѧ����Ϣ",
		"5.�˵�5",
		"6.�˵�6",
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

//�ж�ѧ���Ƿ�Ϸ�
int illegal(char* sid) {
	int year = 0, college_id = 0, num = 0;
	if (strlen(sid) < 0 || strlen(sid) > 9) {//ѧ�ų��ȴ���0����С��9���Ϸ�
		return 1;   
	}
	 year = getSidYear(sid);
	if (year < 2016 || year>2019) { //ѧ����ݲ��Ϸ�
		return 1;    
	}
	college_id = getSidCollege(sid);
	if (college_id < 0 || college_id>12) {//ѧԺ���벻�Ϸ�
		return 1;
	}
	num = getSidCollege(sid);
	if (num < 0 || num>999) {  //����λ���Ϸ�
		return 1;
	}
	return 0;
}
//���㽡��״̬
char getStatus( char isCough, char* temperate) {
	if (isCough == '1' && atof(temperate) >= 37.5) {  
		return '0';  //����״̬�쳣
	}
	return '1';	//����״̬����
}
//����ѧ����Ϣ
struct student inputStudent() {
	struct student tempData;
	memset(&tempData, 0, sizeof(tempData));
	printf("������ѧ���ĸ�����Ϣ��\n");
	printf("ѧ��ѧ�ţ�");
	scanf("%s", tempData.stu_id);
	while (illegal(tempData.stu_id)) {
		printf("��ѧ����Ϣ��Ч������������!\n");
		printf("ѧ��ѧ�ţ�");
		scanf("%s", tempData.stu_id);
	}
	printf("ѧ��������");
	scanf("%s", tempData.name);
	printf("ѧ�����£�");
	scanf("%s", tempData.temperate);
	getchar();
	printf("�Ƿ���ԣ�");
	scanf("%c", &(tempData.isCough));
	printf("ʱ�䣺");
	scanf("%s", tempData.time);
	printf("���ڣ�");
	scanf("%s", tempData.date);
	//��ȡ����״̬
	tempData.status = getStatus(tempData.isCough, tempData.temperate);
	//��ȡѧԺ
	int college_id = getSidCollege(tempData.stu_id);
	getCollege(college_id, tempData.colleage);
	return tempData;
}
//���ѧ����Ϣ
void addStudent(struct Node* list) {
	struct student tempData = inputStudent();
	//����������
	insertNodeNyHead(list,tempData);
	//���浽�ļ���
	saveStudentInfoToFile("data1.txt", list);
	
}
//����ѧ�Ų���ѧ����Ϣ
struct Node* findStudentByStuId(struct Node* list,char *sid) {
	struct Node* pMove = list->next;
	if (pMove == NULL) {
		return NULL;
	}
	while (pMove) {
		if (strcmp(pMove->data.stu_id, sid) == 0) {
			return pMove;
		}
		pMove = pMove->next;
	}
	return NULL;
}
//�޸�ѧ����Ϣ
void modifyStudent(struct Node* list) {
	char sid[20] = { 0 };
	char modifyItem[20] = { 0 };
	struct Node* modifyNode = NULL;
	printf("��������Ҫ�޸���Ϣ��ѧ��ѧ�ţ�");
	scanf("%s", sid);
	modifyNode = findStudentByStuId(list, sid);
	if (modifyNode == NULL) {
		printf("��Ϊ�ջ��߸�ѧ����Ϣ������\n");
	}
	else {
		printf("������Ҫ�޸ĵ��");
		scanf("%s", modifyItem);
		if (strcmp(modifyItem, "ѧ��") == 0) {
			printf("������ѧ�ţ�");
			scanf("%s", modifyNode->data.stu_id);
			while (illegal(modifyNode->data.stu_id)) {
				printf("��ѧ����Ϣ��Ч������������!\n");
				printf("ѧ��ѧ�ţ�");
				scanf("%s", modifyNode->data.stu_id);
			}
		}else if (strcmp(modifyItem, "����") == 0) {
			printf("������������");
			scanf("%s", modifyNode->data.name);
		}else if (strcmp(modifyItem, "����") == 0) {
			printf("���������£�");
			scanf("%s", modifyNode->data.temperate);
		}
		else if (strcmp(modifyItem, "�Ƿ����") == 0) {
			printf("�������Ƿ���ԣ�");
			scanf("%c", &(modifyNode->data.isCough));
		}
		else if (strcmp(modifyItem, "ʱ��") == 0) {
			printf("������ʱ�䣺");
			scanf("%s", modifyNode->data.time);
		}
		else if (strcmp(modifyItem, "����") == 0) {
			printf("���������ڣ�");
			scanf("%s", modifyNode->data.date);
		}
		else {
			printf("��������\n");
			return;
		}
		//���»�ȡ����״̬
		modifyNode->data.status = getStatus(modifyNode->data.isCough, modifyNode->data.temperate);
		//���»�ȡѧԺ
		int college_id = getSidCollege(modifyNode->data.stu_id);
		getCollege(college_id, modifyNode->data.colleage);
		//���浽�ļ���
		saveStudentInfoToFile("data1.txt", list);
	}
}
//��ѯ��ͳ��ѧ����Ϣ
void searchStudent(struct Node* list) {
	char sid[20] = { 0 };//ѧ��
	char deadLine[20] = { 0 };//��ֹ����
	struct Node* newList;  //�洢��ѯ��ѧ����Ϣ����
	int flag = 1;
	newList = createList();
	struct Node* pMove = list->next;
	if (pMove == NULL) {
		printMidInfo("��Ϊ��\n");
	}
	else {
		printf("������ѧ��ѧ�ţ�");
		scanf("%s", sid);
		printf("�����뵱ǰ���ڣ�");
		scanf("%s", deadLine);
		while (pMove) {
			if (strcmp(pMove->data.stu_id, sid) == 0 && strcmp(pMove->data.date, deadLine) < 0) {
				insertNodeNyHead(newList, pMove->data);
				if (flag == 1) {
					printf("���� %d �� %d �� %d �ո����Ľ���������ϢΪ��\n", getYear(deadLine), getMonth(deadLine), getDay(deadLine));
					printf("ѧ�ţ�%s\n", pMove->data.stu_id);
					printf("������%s\n", pMove->data.name);
					printf("ѧԺ��%s\n", pMove->data.colleage);
					printf("%s\t%s\t%s\t%s\t%s\t\n", "����", "�Ƿ����", "����״̬", "ʱ��", "����");
					flag = 0;
				}
				printf("%s\t%c\t%c\t%s\t%s\t\n", pMove->data.temperate, pMove->data.isCough, pMove->data.status, pMove->data.time, pMove->data.date);
			}
			pMove = pMove->next;
		}
		saveStudentInfoToFile("data2.txt", newList);
	}
	if (flag == 1) {
		printf("�����ڷ��ϸ�ѧ������Ϣ\n");
	}
	free(newList);
}
//�쳣ѧ����Ϣͳ��
void abnormalStudent(struct Node* list) {
	struct Node* pMove = list->next;
	struct Node* newList;//�洢�쳣ѧ����Ϣ
	newList = createList();
	if (pMove == NULL) {
		printf("��Ϊ��\n");
	}
	else {
		while (pMove) {
			if (pMove->data.status == '0') {
				insertNodeNyHead(newList, pMove->data);
			}
			pMove = pMove->next;
		}
		saveStudentInfoToFile("data3.txt", newList);
	}
	printf("�Ѿ�������data3.txt�ļ���\n");
	free(newList);
}
//ͨ��ѧ�ź���������
int cmp_by_date(const void* e1, const void* e2) {
	//return (strcmp(((struct student*)e1)->comprehensive ,((struct student*)e2)->comprehensive));
	if (strcmp(((struct student*)e1)->stu_id, ((struct student*)e2)->stu_id)>0) {
		return 1;
	}
	else if (strcmp(((struct student*)e1)->stu_id, ((struct student*)e2)->stu_id) < 0) {
		return -1;
	}
	else if (strcmp(((struct student*)e1)->stu_id, ((struct student*)e2)->stu_id) == 0) {
		if (strcmp(((struct student*)e1)->date, ((struct student*)e2)->date) > 0) {
			return 1;
		}
		else if (strcmp(((struct student*)e1)->date, ((struct student*)e2)->date) < 0) {
			return -1;
		}
		else {
			return 0;
		}
	}
}
//����Ԥ��
void adviceStudent(struct Node* list) {
	struct students p1;
	InitStudents(&p1);
	struct Node* newList;
	newList = createList();
	struct Node* pMove = list->next;
	while (pMove) {
		p1.data[p1.size++] = pMove->data;
		CheckCapacity(&p1);
		pMove = pMove->next;
	}
	//��������
	qsort(p1.data, p1.size, sizeof(p1.data[0]), cmp_by_date);
	for (int i = 0; i < p1.size; i++) {
		if (i < p1.size - 2) {
			if (p1.data[i].status == '0' && p1.data[i + 1].status == '0' && p1.data[i + 2].status == '0') { //���������쳣
				if (strcmp(p1.data[i].stu_id, p1.data[i + 1].stu_id) == 0 && strcmp(p1.data[i + 2].stu_id, p1.data[i + 1].stu_id) == 0) {
					insertNodeNyHead(newList, pMove->data);
				}
			}
		}
	}
	saveStudentInfoToFile("data4.txt", newList);
	free(newList);
	free(p1.data);
	p1.data = NULL;
}
//����������
char head[][COL_LEN_MAX] = { "ѧ��","����","ѧԺ","����","�Ƿ����","����״̬","ʱ��","����"};
//�Ա����ʽ��ӡ����
void printInfoByTable(struct Node* list) {
	struct Node* pMove = list->next;
	if (pMove == NULL) {
		printf("��û��ѧ����Ϣ��\n");
		return;
	}
	else {
		int cols = sizeof(head) / sizeof(head[0]);
		char row[8][COL_LEN_MAX];
		//system("cls");
		printTableHead(TABLE_WIDTH, cols);
		printTableRow(TABLE_WIDTH, head, cols);
		printTableMidLine(TABLE_WIDTH, cols);
		while (pMove) {
			sprintf(row[0], "%s", pMove->data.stu_id);
			sprintf(row[1], "%s", pMove->data.name);
			sprintf(row[2], "%s", pMove->data.colleage);
			sprintf(row[3], "%s", pMove->data.temperate);
			sprintf(row[4], "%c", pMove->data.isCough);
			sprintf(row[5], "%c", pMove->data.status);
			sprintf(row[6], "%s", pMove->data.time);
			sprintf(row[7], "%s", pMove->data.date);
			printTableRow(TABLE_WIDTH, row, cols);
			if (pMove->next!=NULL) {   //��û�е����һ��
				printTableMidLine(TABLE_WIDTH, cols);
			}
			else {
				printTableTail(TABLE_WIDTH, cols);
			}
			pMove = pMove->next;
		}
			char buff[64];
			sprintf(buff, "��%d������\n", getStudentLenth(list));
			printMidInfo(buff);
			
		}
}

//��ӡѧ������
void printStudentArr(struct student* arr, int length) {
	if (arr == NULL) {
		printf("��Ϊ��\n");
		return;
	}
	/*printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", "ѧ��", "����", "���֤��", "ѧԺ", "ѧ������", "רҵ", "��У·��", "��ͨ����", "���нӴ�", "�¶�", "��ȥ14�첡ʷ", "�Ƿ���", "��Уʱ��");
	for (int i = 0; i < length; i++) {
		printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", arr[i].stu_id, arr[i].name, arr[i].sid, arr[i].college, arr[i].type, arr[i].major, arr[i].route, arr[i].traffic, arr[i].isClose, arr[i].temperate, arr[i].history, arr[i].isCough, arr[i].time);
	}*/
}

//����
void sort(struct Node* list) {
	
}
//�ͷ��ڴ�
void destory(struct Node* list) {
	free(list);
	list = NULL;
}