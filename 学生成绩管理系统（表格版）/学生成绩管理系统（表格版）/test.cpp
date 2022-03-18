#define _CRT_SECURE_NO_WARNINGS
#include "tablePrint.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COUNT 100
#define DEFAULT_PAGE_NUM 10
struct student {
	int num;   //ѧ��
	char name[16];  //����
	int cLang;   //c����
	int algo;    //�㷨
	int database; //���ݿ�
	int sum;	//�ܳɼ�
};
struct student stu[MAX_COUNT];
int currentCount = 0;

void init() {
	char cmd[128];
	sprintf(cmd, "mode con lines=%d cols=%d", WIN_HEIGHT, WIN_WIDTH); //�ı䴰�ڴ�С
	system(cmd);
	//system("color 1f");  //�ı���ɫ��1�Ǵ��ڱ�����ɫ��f��������ɫ
	memset(stu, 0, sizeof(stu));
	FILE* fp = fopen("data.txt", "rb");
	if (fp == NULL) {
		fopen("data.txt", "w");//�ļ������ھͲ�Ҫ
		currentCount = 0;
	}
	int i = 0;
	while (!feof(fp)) {
		int ret = fread(&stu[i], sizeof(struct student), 1, fp);
		if (ret == 1) {
			i++;
		}
	}
	currentCount = i;

}
//����ѧ�Ų���ѧ��
int searchStu(int id) {
	for (int i = 0; i < currentCount; i++) { 
		if (stu[i].num == id)
		{ 
			return i;
		} 
	}
	return -1;
}
bool save() {
	FILE* fp = fopen("data.txt", "wb");
	if (fp == NULL) {
		fclose(fp);
		return false;
	}
	for (int i = 0; i < currentCount; i++) {
		if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1) {
			fclose(fp);
			return false;
		}
	}
	fclose(fp);
	return true;
}
char head[][COL_LEN_MAX] = { "ѧ��","����","C����","�㷨","���ݿ�","�ܷ�","ѧ��","����","C����","�㷨","���ݿ�","�ܷ�" };
void showPage(int startIndex, int endIndex) {
	if (endIndex >= currentCount) {
		endIndex = currentCount - 1;
	}
	if (endIndex - startIndex + 1 > DEFAULT_PAGE_NUM) {
		endIndex = startIndex + DEFAULT_PAGE_NUM - 1;
	}
	char row[12][COL_LEN_MAX];
	//system("cls");
	printTableHead(TABLE_WIDTH, 12);
	printTableRow(TABLE_WIDTH, head, sizeof(head) / sizeof(head[0]));
	printTableMidLine(TABLE_WIDTH, 12);
	for (int i = startIndex; i <= endIndex; i++) {
		sprintf(row[0], "%d", stu[i].num); 
		sprintf(row[1], "%s", stu[i].name);
		sprintf(row[2], "%d", stu[i].cLang);
		sprintf(row[3], "%d", stu[i].algo); 
		sprintf(row[4], "%d", stu[i].database); 
		sprintf(row[5], "%d", stu[i].sum);
		sprintf(row[6], "%d", stu[i].num);
		sprintf(row[7], "%s", stu[i].name);
		sprintf(row[8], "%d", stu[i].cLang);
		sprintf(row[9], "%d", stu[i].algo);
		sprintf(row[10], "%d", stu[i].database);
		sprintf(row[11], "%d", stu[i].sum);
		printTableRow(TABLE_WIDTH, row, 12);
		if (i < endIndex) {
			printTableMidLine(TABLE_WIDTH, 12);
		}
		else {
			printTableTail(TABLE_WIDTH, 12);
		}
	}
	
}
void show() {
	if (currentCount == 0) {
		printf("��û��ѧ����Ϣ��\n");
		return;
	}
	int pageCount = (currentCount + DEFAULT_PAGE_NUM - 1) / DEFAULT_PAGE_NUM;//������ҳ��
	char buff[64];
	for (int i = 0; i < pageCount; i++) {
		showPage(i * DEFAULT_PAGE_NUM, (i + 1) * DEFAULT_PAGE_NUM);
		sprintf(buff, "��%dҳ ��[%d]ҳ\n", pageCount, i + 1);
		printMidInfo(buff);
	}
}
//����ѧ����Ϣ
struct student inputInfo() {
		struct student s;
		printf("ѧ��:"); scanf("%d", &s.num);
		printf("����:"); scanf("%s", s.name); 
		printf("C ����:"); scanf("%d", &s.cLang); 
		printf("�㷨:"); scanf("%d", &s.algo); 
		printf("���ݿ�:"); scanf("%d", &s.database); 
		s.sum = s.cLang + s.algo + s.database;
		return s;
}
//���ѧ����Ϣ
void input() {
	char str[16];
	struct student s;
	while (1) {
		printMidInfo("����ѧ����Ϣ��y/n");
		scanf("%s", str);
		if (strcmp("Y", str) != 0 && strcmp("y", str) != 0) {
			break;
		}
		s = inputInfo();
		if (searchStu(s.num) >= 0) {
			printf("ѧ��[%d]�Ѿ����ڣ�\n",s.num);
			continue;
		}
		stu[currentCount++] = s;
		if (!save()) {
			printf("����ʧ�ܣ�\n");
		}
		else {
			printf("����ɹ���\n");
		}
	}
}
void search() {
	int snum = 0; 
	system("cls"); 
	printf("������ѧ��:");
	scanf("%d", &snum); 
	int i = searchStu(snum);
	if (i < 0) { 
		printf("û���ҵ�����ѧ����\n"); 
		return; 
	}
	char row[6][COL_LEN_MAX];
	char head[][COL_LEN_MAX] = { "ѧ��", "����", "C ����", "�㷨", "���ݿ�", "�ܷ�" }; 
	printTableHead(TABLE_WIDTH, 6);
	printTableRow(TABLE_WIDTH, head, sizeof(head) / sizeof(head[0]));
	printTableMidLine(TABLE_WIDTH, 6); 
	sprintf(row[0], "%d", stu[i].num); 
	sprintf(row[1], "%s", stu[i].name);
	sprintf(row[2], "%d", stu[i].cLang);
	sprintf(row[3], "%d", stu[i].algo); 
	sprintf(row[4], "%d", stu[i].database); 
	sprintf(row[5], "%d", stu[i].sum); 
	printTableRow(TABLE_WIDTH, row, 6); 
	printTableTail(TABLE_WIDTH, 6);
}

 
void menu() {
	printMenuHead(MENU_WIDTH);
	printMenuMidInfo(MENU_WIDTH, "ѧ����Ϣ����ϵͳ");
	printMenuMidInfo(MENU_WIDTH, "");
	const char* subMenus[] = {
		"1.����ѧ����Ϣ",
		"2.����ѧ����Ϣ",
		"3.ɾ��ѧ����Ϣ",
		"4.�޸�ѧ����Ϣ",
		"5.����ѧ����Ϣ",
		"6.ѧ���ɼ�����",
		"7.ͳ��ѧ������",
		"8.��ʾ������Ϣ",
		"0.�˳�ϵͳ    "
	};
	int count = sizeof(subMenus) / sizeof(subMenus[0]);
	for (int i = 0; i < count; i++) {
		printMenuMidInfo(MENU_WIDTH, subMenus[i]);
	}
	printMenuMidInfo(MENU_WIDTH, "");
	printMenuTail(MENU_WIDTH);
	printMidInfo("��ѡ��0-8��");
}

int main() {
	init();
	int n = 0;
	do {
		menu();
		scanf("%d", &n);
		switch (n) {
		case 1: input();break;
		case 2: search();break;
		case 3:  break; 
		case 4:  break; 
		case 5:  break; 
		case 6:  break; 
		case 7:  break; 
		case 8: show(); break; 
		case 0:printf("�˳�\n"); exit(0); break;
		default:printMidInfo("������������������\n"); break;
		}
		system("pause");
		system("cls");
	} while (n);
	return 0;
}