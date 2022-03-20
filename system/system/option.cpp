#define _CRT_SECURE_NO_WARNINGS
#include "option.h"
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
void showPage(int startIndex, int endIndex) {
	if (endIndex >= length) {
		endIndex = length - 1;
	}
	if (endIndex - startIndex + 1 > DEFAULT_PAGE_NUM) {
		endIndex = startIndex + DEFAULT_PAGE_NUM - 1;
	}
	char row[6][COL_LEN_MAX];
	//system("cls");
	printTableHead(TABLE_WIDTH, 6);
	printTableRow(TABLE_WIDTH, head, sizeof(head) / sizeof(head[0]));
	printTableMidLine(TABLE_WIDTH, 6);
	for (int i = startIndex; i <= endIndex; i++) {
		sprintf(row[0], "%s","����1");
		sprintf(row[1], "%s", "����2");
		sprintf(row[2], "%s", "���˼����ѧԺ");
		sprintf(row[3], "%s", "����4");
		sprintf(row[4], "%s", "����5");
		sprintf(row[5], "%s", "����6");
		printTableRow(TABLE_WIDTH, row, 6);
		if (i < endIndex) {
			printTableMidLine(TABLE_WIDTH, 6);
		}
		else {
			printTableTail(TABLE_WIDTH, 6);
		}
	}

}
//��ӡ
void printTable() {
	if (length == 0) {
		printf("��û��ѧ����Ϣ��\n");
		return;
	}
	int pageCount = (length + DEFAULT_PAGE_NUM - 1) / DEFAULT_PAGE_NUM;//������ҳ��
	char buff[64];
	for (int i = 0; i < pageCount; i++) {
		showPage(i * DEFAULT_PAGE_NUM, (i + 1) * DEFAULT_PAGE_NUM);
		sprintf(buff, "��%dҳ ��[%d]ҳ\n", pageCount, i + 1);
		printMidInfo(buff);
	}
}