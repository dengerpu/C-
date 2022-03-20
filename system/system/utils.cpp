#define _CRT_SECURE_NO_WARNINGS
#include "utils.h"

//��ӡ��ͷ�����������������������������ڴ�ӡ�˵���
void printMenuHead(int tableWidth) {
	int margin = (WIN_WIDTH - tableWidth) / 2;  //�����ڿ��-�˵���ȣ�/2
	for (int i = 0; i < margin; i++) printf(" "); //����
	printf("��");
	for (int i = 0; i < tableWidth - 2; i++)printf("��");
	printf("��\n");
}
//��ӡ����м����Ϣ����    �˵�����   �����������ڴ�ӡ�˵���
void printMenuMidInfo(int tableWidth, const char* str) {
	int margin = (WIN_WIDTH - tableWidth) / 2;
	for (int i = 0; i < margin; i++) printf(" ");//����
	printf("��");
	//-2�Ǽ�ȥ���� |��ռ�Ŀռ�
	int len1 = (tableWidth - 2 - strlen(str)) / 2;//���ݾ���
	for (int i = 0; i < len1; i++) printf(" ");

	printf("%s", str);

	int len2 = tableWidth - 2 - len1 - strlen(str);
	for (int i = 0; i < len2; i++) printf(" ");

	printf("��\n");
}
//��ӡ��β�������ڴ�ӡ�˵� ��������������������������
void printMenuTail(int tableWidth) {
	int margin = (WIN_WIDTH - tableWidth) / 2;
	for (int i = 0; i < margin; i++) printf(" ");  //����
	printf("��");
	for (int i = 0; i < tableWidth - 2; i++)printf("��");
	printf("��\n");
}


//��ӡ�������ʽ�� ���������Щ������Щ�����������������������������ݣ�
void printTableHead(int tableWidth, int cols) {
	int margin = (WIN_WIDTH - tableWidth) / 2;
	int spanLen = (tableWidth - (cols + 1)) / cols;//��ӡcols����Ҫcols+1��|
	for (int i = 0; i < margin; i++) printf(" ");//����

	printf("��");
	for (int i = 0; i < cols; i++) {//��ӡÿһ��
		for (int j = 0; j < spanLen; j++) {
			printf("��");
		}

		if (i < cols - 1) {
			printf("��");
		}
		else {
			printf("��");
		}
	}
	printf("\n");
}
//��ӡ��ͷ����     ���� ����1�� ����2�� ����3����������ݣ���������������ݣ�
void printTableRow(int tableWidth, char cols[][COL_LEN_MAX], int n) {
	int margin = (WIN_WIDTH - tableWidth) / 2;
	for (int i = 0; i < margin; i++) printf(" ");//����

	int colWidth = (tableWidth - (n + 1)) / n;

	for (int i = 0; i < n; i++) {
		printf("��");

		int leftSpan = (colWidth - strlen(cols[i])) / 2;//��߿ո���
		int rightSpan = colWidth - leftSpan - strlen(cols[i]);//�ұ߿ո���

		for (int j = 0; j < leftSpan; j++) printf(" ");
		printf("%s", cols[i]);
		for (int j = 0; j < rightSpan; j++) printf(" ");
	}

	printf("��\n");
}

//��ӡ����м�ָ��ߣ����������੤ ���੤�����ȣ���������������ݣ�
void printTableMidLine(int tableWidth, int cols) {
	int margin = (WIN_WIDTH - tableWidth) / 2;
	int spanLen = (tableWidth - (cols + 1)) / cols;
	for (int i = 0; i < margin; i++) printf(" ");

	printf("��");
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < spanLen; j++) {
			printf("��");
		}

		if (i < cols - 1) {
			printf("��");
		}
		else {
			printf("��");
		}
	}
	printf("\n");
}
//��ӡ����β��      ���������ة������ة����������������ڴ�ӡ���ݣ�
void printTableTail(int tableWidth, int cols) {
	int margin = (WIN_WIDTH - tableWidth) / 2;
	int spanLen = (tableWidth - (cols + 1)) / cols;
	for (int i = 0; i < margin; i++) printf(" ");

	//�����ة���
	printf("��");
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < spanLen; j++) {
			printf("��");
		}

		if (i < cols - 1) {
			printf("��");
		}
		else {
			printf("��");
		}
	}
	printf("\n");
}


//���д�ӡ
void printMidInfo(const char* str) {
	int margin = (WIN_WIDTH - strlen(str)) / 2;
	for (int i = 0; i < margin; i++) printf(" ");
	printf("%s", str);
}

//��ȡ�ַ���
int my_substr(char* res, int pos, int len, char* substr) {//��pos��ʼȡlen���ַ���substr
	char* p = res;
	int i = 0;
	if (pos > strlen(res)) {
		return 0;
	}
	pos--;
	while (i < len) {
		substr[i++] = res[pos++];
		if (pos > strlen(res)) {
			substr[i] = '\0';
		}
	}
	substr[i] = '\0';
	return 1;
}


//��ȡѧ�����
int getSidYear(char* id) {
	char year[5] = { 0 };
	if (id == NULL) {
		return 0;
	}
	else {
		my_substr(id, 1, 4, year);
		return atoi(year);
	}
}
//��ȡѧ��ѧԺ����
int getSidCollege(char* id) {
	char college[3] = { 0 };
	if (id == NULL) {
		return 0;
	}
	else {
		my_substr(id, 5, 2, college);
		return atoi(college);
	}
}
//��ȡѧ�������
int getSidNum(char* id) {
	char random_num[4] = { 0 };
	if (id == NULL) {
		return 0;
	}
	else {
		my_substr(id, 7, 3, random_num);
		return atoi(random_num);
	}

}


//��ȡ���
int getYear(char* date) {
	char year[5] = { 0 };
	if (date == NULL) {
		return 0;
	}
	else {
		my_substr(date, 1, 4, year);
		return atoi(year);
	}
}
//��ȡ��
int getMonth(char* date) {
	char month[3] = { 0 };
	if (date == NULL) {
		return 0;
	}
	else {
		my_substr(date, 5, 2, month);
		return atoi(month);
	}
}
//��ȡ��
int getDay(char* date) {
	char day[3] = { 0 };
	if (date == NULL) {
		return 0;
	}
	else {
		my_substr(date, 7, 2, day);
		return atoi(day);
	}
}

//��ȡѧԺ
void getCollege(int num, char* college) {
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
