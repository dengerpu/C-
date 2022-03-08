#define _CRT_SECURE_NO_WARNINGS
#include "Toschool.h"

//��ʼ��ѧ����Ϣ
void InitStudent(Students* p) {
	memset(p->data, 0, sizeof(p->data));
	p->size = 0;
}

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

int Check_stu_num(char str[8]) {
	char year[8] = { 0 };
	char major[8] = { 0 };
	char s[8] = { 0 };
	my_substr(str, 1, 4, year);
	my_substr(str, 5, 2, major);
	my_substr(str, 7, 3, s);
	int int_year = atoi(year);   //atoi���ַ���ת��Ϊ����
	int int_major = atoi(major);
	int int_s = atoi(s);
	//printf("major:%d\n", int_major);
	//int int_major = atoi()
	if (int_year < 2016 || int_year>2019) {
		printf("ѧ�����������Ч������������\n");
		return 0;
	}
	
	if (int_major < 1 || int_major>12) {
		printf("ѧ��ѧԺ����������Ч������������\n");
		return 0;
	}
	if (int_s < 0 || int_s>999) {
		printf("ѧ�ź���λ������Ч������������\n");
		return 0;
	}
	return int_major;
}
char status(char temperate[4], char isCough) {
	float temp = (float)atof(temperate);
	if (temp >= 37.3 && isCough == '1') {
		return '1';
	}
	else {
		return '0';
	}
}
void getCollege(int id, enum college,char* string_college) {
	//ͨ��ѧԺ = 1,    //01	
	//	�����ѧԺ,  //02
	//	���ѧԺ,	 //03
	//	�Զ���ѧԺ, //04
	//	����ѧԺ,    //05
	//	�о���Ժ,    //06
	//	����ѧԺ,    //07
	//	����ѧԺ,     //08
	//	����ѧԺ,     //09
	//	��ýѧԺ,     //10
	//	�Ƚ�����ѧԺ, //11
	//	���˼����ѧԺ,//12
	switch(id) {
	case ͨ��ѧԺ:strcpy(string_college, "ͨ��ѧԺ"); break;
	case �����ѧԺ:strcpy(string_college, "�����ѧԺ"); break;
	case ���ѧԺ:strcpy(string_college, "���ѧԺ"); break;
	case �Զ���ѧԺ:strcpy(string_college, "�Զ���ѧԺ"); break;
	case ����ѧԺ:strcpy(string_college, "����ѧԺ"); break;
	case �о���Ժ:strcpy(string_college, "�о���Ժ"); break;
	case ����ѧԺ:strcpy(string_college, "����ѧԺ"); break;
	case ����ѧԺ:strcpy(string_college, "����ѧԺ"); break;
	case ����ѧԺ:strcpy(string_college, "����ѧԺ"); break;
	case ��ýѧԺ:strcpy(string_college, "��ýѧԺ"); break;
	case �Ƚ�����ѧԺ:strcpy(string_college, "�Ƚ�����ѧԺ"); break;
	case ���˼����ѧԺ:strcpy(string_college, "���˼����ѧԺ"); break;
	};
}

//���ѧ����Ϣ
void addStudent(Students* p) {
	printf("������ѧ���ĸ�����Ϣ\n");
	Student tempData;
	//getchar();
	//char stu_num[8];//ѧ��
	//char name[15];  //����
	//char college[20];//ѧԺ
	//char temperate[4];//�¶�
	//char isCough;     ///�Ƿ����
	//char status;      //����״̬
	//char time[5];     //ʱ��
	//char data[8];    //����
	printf("ѧ��ѧ�ţ�");
	scanf("%s", tempData.stu_num);
	while (!Check_stu_num(tempData.stu_num)) {
		printf("ѧ��ѧ�ţ�");
		scanf("%s", tempData.stu_num);
	}
	getCollege(Check_stu_num(tempData.stu_num), enum_college, tempData.college);
	printf("ѧ��������");
	scanf("%s", tempData.name);
	printf("ѧ�����£�>");
	scanf("%s", tempData.temperate);
	getchar();
	printf("�Ƿ���ԣ�");
	scanf("%c", &(tempData.isCough));
	tempData.status = status(tempData.temperate, tempData.isCough);
	printf("ʱ�䣺");
	scanf("%s", tempData.time);
	printf("���ڣ�");
	scanf("%s", tempData.date);
}
//��ӡѧ����Ϣ
void printStudent(Students* p);