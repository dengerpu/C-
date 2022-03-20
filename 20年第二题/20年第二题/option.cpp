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
//��½
int login() {
	char user[20] = { 0 };
	char pwd[20] = { 0 };
	int i = 3;
	while (i--) {
		printMenuHead(MENU_WIDTH);
		printMenuMidInfo(MENU_WIDTH, "ȫ���¹��������ϵͳ");
		printMenuMidInfo(MENU_WIDTH, "");
		printMenuTail(MENU_WIDTH);
		printMidInfo("�˺�:");
		scanf("%s", user);
		printMidInfo("����:");
		scanf("%s", pwd);
		if (strcmp(user, "admin") == 0 && strcmp(pwd, "admin") == 0) {
			printMidInfo("��½�ɹ�\n");
			system("pause");
			system("cls");
			return 1;
		}
		if (i != 0) {
			char buff[32];
			sprintf(buff, "�㻹��%d�λ���\n", i);
			printMidInfo(buff);
		}
		system("pause");
		system("cls");
	}
	return 0;
	
}

//����������
char head[][COL_LEN_MAX] = { "����", "��", "�˿�����", "�������", "���������", "�ܶ�", "����ȷ��", "�ۼ�ȷ��", "�ۼ�����", "�ۼ�����", "������", "������", "����ָ��" };
int length = 1;
//�Ա����ʽ��ӡ����
void printInfoByTable() {
	if (length == 0) {
		printf("��û��ѧ����Ϣ��\n");
		return;
	}
	int cols = sizeof(head) / sizeof(head[0]);
	char row[13][COL_LEN_MAX];
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
	//printf("%-10s  %-10s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "����", "��", "�˿�����", "�������", "���������", "�ܶ�", "����ȷ��", "�ۼ�ȷ��", "�ۼ�����", "�ۼ�����", "������", "������", "����ָ��");
	//while (pMove) {
	//	printf("%-10s  %-10s\t%d\t%.0lf\t%.0lf\t%.0lf\t%d\t%d\t%d\t%d\t%.2lf\t%.2lf\t%.2lf\n", pMove->data.country_name, pMove->data.continent, pMove->data.total_peoples, pMove->data.country_area, pMove->data.builder_area, pMove->data.people_density, pMove->data.add, pMove->data.total, pMove->data.death, pMove->data.cure, pMove->data.mortality, pMove->data.cure_rate, pMove->data.severity_index);
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
struct country inputStudent() {
	struct country tempData;
	memset(&tempData, 0, sizeof(tempData));
	printf("��������ң�");
	scanf("%s", tempData.country_name);
	printf("�����������ޣ�");
	scanf("%s", tempData.continent);
	printf("�������˿�������");
	scanf("%d", &(tempData.total_peoples));
	printf("%d\n", tempData.total_peoples);
	printf("��������������");
	scanf("%lf", &(tempData.country_area));
	printf("%.0lf\n", tempData.country_area);
	printf("�����뽨���������");
	scanf("%lf", &(tempData.builder_area));
	printf("%.0lf\n", tempData.builder_area);
	printf("����������ȷ�");
	scanf("%d", &(tempData.add));
	printf("%d\n", tempData.add);
	printf("�������ۼ�ȷ�");
	scanf("%d", &(tempData.total));
	printf("%d\n", tempData.total);
	printf("�������ۼ�������");
	scanf("%d", &(tempData.death));
	printf("%d\n", tempData.death);
	printf("�������ۼ�������");
	scanf("%d", &(tempData.cure));
	printf("%d\n", tempData.cure);
	//�ִ�ȷ����=�ۼ�ȷ��-�ۼ�����-�ۼ�����
	int current = tempData.total - tempData.death - tempData.cure;
	//�ִ�ȷ����
	double current_r = current / tempData.total;
	//�ִ�ȷ���˿�ռ�� = �ִ�ȷ���������� / �˿���������
	double current_rate = current / tempData.total_peoples;
	//�ִ�ȷ���˿��ܶ�=�ִ�ȷ����������/���ҽ��������ƽ�������
	double current_density = current / tempData.country_area;
	//Ȩ��1 + Ȩ��2 = 1��
	double a ; double b;
	//Ȩ��2 / Ȩ��1 = ȫ��ǽ����˿��ܶȣ�
	//ȫ��ǽ����˿��ܶ�=ȫ���˿���/ȫ��ǽ������
	double all_density = 76 / 45;
	b = 1 / (all_density - 1);
	a = 1 - b;
	//����ָ�� = ��Ȩ��1 * �ִ�ȷ���˿��ܶ� + Ȩ��2 * �ִ�ȷ���ʣ� * SQRT���ִ�ȷ�� * 1000000 / ȫ���ִ�ȷ� * 10000��
	tempData.severity_index = (a * current_density + b * current_r) * (current * 10000000 / 4020878) * 10000;
	//double mortality;		//������
	tempData.mortality = tempData.death / tempData.total;
	printf("%.0lf\n", tempData.mortality);
	//double cure_rate;  //������
	tempData.cure_rate = tempData.cure/ tempData.total;
	printf("%.0lf\n", tempData.cure_rate);
	return tempData;
}
//�����Ϣ
void addCountry(struct Node* list) {
	struct country tempData = inputStudent();
	
	//��������
	insertNodeNyHead(list,tempData);
}
//ͨ���ۺϳɼ�����
int cmp_by_comprehensive(const void* e1, const void* e2) {
	//return (strcmp(((struct student*)e1)->comprehensive ,((struct student*)e2)->comprehensive));
	return 1;
}
//����
void sort() {
	//struct students p1;
	//InitStudents(&p1);
	////��������
	//qsort(p1.data, p1.size, sizeof(p1.data[0]), cmp_by_comprehensive);
	//free(p1.data);
	//p1.data = NULL;
}
//�ͷ��ڴ�
//�ͷ��ڴ�
void destory(struct Node* list) {
	free(list);
	list = NULL;
}