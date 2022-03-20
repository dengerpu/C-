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
	printMenuMidInfo(MENU_WIDTH, "ѧ����Ϣ����ϵͳ");
	printMenuMidInfo(MENU_WIDTH, "");
	const char* subMenus[] = {
		"1.�˵�1",
		"2.�˵�2",
		"3.�˵�3",
		"4.�˵�4",
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
//����������
char head[][COL_LEN_MAX] = { "����1","����2","����3","����4","����5","����6" };
int length = 1;
//�Ա����ʽ��ӡ����
void printInfoByTable() {
	if (length == 0) {
		printf("��û��ѧ����Ϣ��\n");
		return;
	}
	int cols = sizeof(head) / sizeof(head[0]);
	char row[6][COL_LEN_MAX];
	//system("cls");
	printTableHead(TABLE_WIDTH, cols);
	printTableRow(TABLE_WIDTH, head, cols);
	printTableMidLine(TABLE_WIDTH, cols);
	for (int i = 0; i < length; i++) {
		sprintf(row[0], "%s","����1");
		sprintf(row[1], "%s", "����2");
		sprintf(row[2], "%s", "���˼����ѧԺ");
		sprintf(row[3], "%s", "����4");
		sprintf(row[4], "%s", "����5");
		sprintf(row[5], "%s", "����6");
		printTableRow(TABLE_WIDTH, row, cols);
		if (i < length-1) {
			printTableMidLine(TABLE_WIDTH, cols);
		}
		else {
			printTableTail(TABLE_WIDTH, cols);
		}
	}
	char buff[64];
	sprintf(buff, "��%d������\n",length);
	printMidInfo(buff);
}
//��ӡѧ������
void printStudentList(struct Node* list) {
	struct Node* pMove = list->next;
	if (pMove == NULL) {
		printf("��Ϊ��\n");
		return;
	}
	//printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", "ѧ��", "����", "���֤��", "ѧԺ", "ѧ������", "רҵ", "��У·��", "��ͨ����", "���нӴ�", "�¶�", "��ȥ14�첡ʷ", "�Ƿ���", "��Уʱ��");
	//while (pMove) {
	//	printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", pMove->data.stu_id, pMove->data.name, pMove->data.sid, pMove->data.college, pMove->data.type, pMove->data.major, pMove->data.route, pMove->data.traffic, pMove->data.isClose, pMove->data.temperate, pMove->data.history, pMove->data.isCough, pMove->data.time);
	//	pMove = pMove->next;
	//}
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
//����ѧ����Ϣ
struct student inputStudent() {
	struct student tempData;
	memset(&tempData, 0, sizeof(tempData));
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
	int total = atof(tempData.course1) + atof(tempData.course2) + atof(tempData.course3) + atof(tempData.course4);
	_gcvt(total, 5, tempData.ptest);   //��Ϊ���õ��Ǹ���������������100����100. ����㣬���ԾͰ������ȥ��
	removedot(tempData.ptest, strlen(tempData.ptest));
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
	_gcvt(totalGrade, 5, tempData.comprehensive);
	removedot(tempData.comprehensive, strlen(tempData.comprehensive));
	return tempData;
}
//ͨ���ۺϳɼ�����
int cmp_by_comprehensive(const void* e1, const void* e2) {
	return (strcmp(((struct student*)e1)->comprehensive ,((struct student*)e2)->comprehensive));
}
//����
void sort() {
	struct students p1;
	InitStudents(&p1);
	//��������
	qsort(p1.data, p1.size, sizeof(p1.data[0]), cmp_by_comprehensive);
	free(p1.data);
	p1.data = NULL;
}
//�ͷ��ڴ�
//�ͷ��ڴ�
void destory(struct Node* list) {
	free(list);
	list = NULL;
}