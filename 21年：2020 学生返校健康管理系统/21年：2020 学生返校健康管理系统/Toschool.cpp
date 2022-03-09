#define _CRT_SECURE_NO_WARNINGS
#include "Toschool.h"
#include "utils.h"

enum college {
	ͨ��ѧԺ = 1,    //01	
	�����ѧԺ,  //02
	���ѧԺ,	 //03
	�Զ���ѧԺ, //04
	����ѧԺ,    //05
	�о���Ժ,    //06
	����ѧԺ,    //07
	����ѧԺ,     //08
	����ѧԺ,     //09
	��ýѧԺ,     //10
	�Ƚ�����ѧԺ, //11
	���˼����ѧԺ,//12
}enum_college;

//����ѧ����Ϣ
void loadStudent(const char* filename, Students* p) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w");
	}
	Student tempData;
	while ((fscanf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\n",
		tempData.stu_num,
		tempData.name,
		tempData.college,
		tempData.temperate,
		&(tempData.isCough),
		&(tempData.status),
		tempData.time,
		tempData.date)) != EOF) {
		p->data[p->size++] = tempData;
	}
}

//��ʼ��ѧ����Ϣ
void InitStudent(Students* p) {
	memset(p->data, 0, sizeof(p->data));
	p->size = 0;
	loadStudent("data1.txt", p);
}


int Check_stu_num(char str[10]) {
	char year[8] = { 0 };
	char major[8] = { 0 };
	char s[8] = { 0 };
	my_substr(str, 1, 4, year);
	my_substr(str, 5, 2, major);
	my_substr(str, 7, 3, s);
	int int_year = atoi(year);   //atoi���ַ���ת��Ϊ����
	int int_major = atoi(major);
	int int_s = atoi(s);
	if (strlen(str) != 9) {
		printf("ѧ��λ�����ԣ�����������\n");
		return 0;
	}
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
		return '0';
	}
	else {
		return '1';
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
	//printf("���£�%s\n", tempData.temperate);
	getchar();
	printf("�Ƿ���ԣ�");
	scanf("%c", &(tempData.isCough));
	//printf("�Ƿ���ԣ�%c\n", tempData.isCough);
	tempData.status = status(tempData.temperate, tempData.isCough);
	//printf("����״̬��%c\n", tempData.status);
	printf("ʱ�䣺");
	scanf("%s", tempData.time);
	//printf("ʱ�䣺%s\n", tempData.time);
	printf("���ڣ�");
	scanf("%s", tempData.date);
	//printf("���ڣ�%s\n", tempData.date);
	p->data[p->size++] = tempData;
	memset(&tempData, 0, sizeof(tempData));
}
//��ӡѧ����Ϣ
void printStudent(const Students* p) {
	if (p->size == 0) {
		printf("ѧ����ϢΪ��\n");
		return ;
	}
	printf("%-8s\t%-6s\t%-10s\t%s\t%s\t%s\t%s\t%s\t\n", "ѧ��", "����", "ѧԺ", "�¶�", "�Ƿ����", "����״̬", "ʱ��", "����");
	for (int i = 0; i < p->size; i++) {
		//printf("%s\n", p->data[i].temperate);
		printf("%-8s\t%-6s\t%-10s\t%s\t%c\t\t%c\t\t%s\t%s\t\n",
			p->data[i].stu_num,
			p->data[i].name,
			p->data[i].college,
			p->data[i].temperate,
			p->data[i].isCough,
			p->data[i].status,
			p->data[i].time,
			p->data[i].date);
	}
}
//ͨ��ѧ�Ż���������ѯѧ��
int findStudentByIdOrName(const char* query,Students *p) {
	int i = 0;
	if (query==NULL) {
		printf("����Ҫ���ҵĹؼ���Ϊ��\n");
	}
	if (query != NULL) {
		for (i = 0; i < p->size; i++) {
			if ((0 == strcmp(query, p->data[i].stu_num))||(0 == strcmp(query, p->data[i].name))) {
				return i;
			}
		}
		return -1;
	}
}
//�޸�ѧ����Ϣ
void modifyStudent(Students* p) {
	char query[20] = {0};
	char modify[20] = { 0 };
	char isCough = 0;
	char modify_value[20] = { 0 };
	printf("��������Ҫ�޸���Ϣ��ѧ��ѧ�Ż���������");
	scanf("%s", query);
	int pos = findStudentByIdOrName(query, p);
	if (-1 == pos) {
		printf("���Ҳ���������Ϣ\n");
	}
	else {
		printf("��������Ҫ�޸ĵ���:\n");
		scanf("%s", modify);
		if (0 == strcmp(modify, "ѧ��")) {
			printf("������ѧ��");
			scanf("%s", modify_value);
			strcpy(p->data[pos].stu_num, modify_value);
		}else if (0 == strcmp(modify, "����")) {
			printf("����������");
			scanf("%s", modify_value);
			strcpy(p->data[pos].name, modify_value);
		}
		else if (0 == strcmp(modify, "����")) {
			printf("����������");
			scanf("%s", modify_value);
			strcpy(p->data[pos].temperate, modify_value);
		}
		else if (0 == strcmp(modify, "�Ƿ����")) {
			printf("�������Ƿ����:");
			getchar();
			isCough =getchar();
			//scanf("%c", isCough);
			p->data[pos].isCough = isCough;
		}
		else if (0 == strcmp(modify, "ʱ��")) {
			printf("������ʱ��");
			scanf("%s", modify_value);
			strcpy(p->data[pos].time, modify_value);
		}
		else if (0 == strcmp(modify, "����")) {
			printf("����������");
			scanf("%s", modify_value);
			strcpy(p->data[pos].date, modify_value);
		}
		else{
			printf("û�и��޸���\n");
			printf("��ʾ�����޸ĵ����У�ѧ�ţ����������£��Ƿ���ԣ��¼�������\n");
			return;
		}
		getCollege(Check_stu_num(p->data[pos].stu_num), enum_college, p->data[pos].college);
		p->data[pos].status = status(p->data[pos].temperate, p->data[pos].isCough);
		printf("�޸ĳɹ�\n");
	}
	
}
//��ӡ����ѧ������Ϣ
void printSingleStundet(Student* p) {
	printf("%-8s\t%-6s\t%-10s\t%s\t%c\t\t%c\t\t%s\t%s\t\n",
		p->stu_num,
		p->name,
		p->college,
		p->temperate,
		p->isCough,
		p->status,
		p->time,
		p->date);

}

//��ѯѧ����Ϣ�����浽�ļ���
void findStudentAndSave(char* query,char *date, const char* filename, Students* p) {
	if (query == NULL) {
		printf("��ѯ��ѧ�Ż�������Ϊ��\n");
	}else {
		FILE* fp = fopen(filename, "w");
		if (fp == NULL) {
			printf("%s\n", strerror(errno));
			return;
		}
		int flag = 0;
		int print_flag = 1;
		for (int i = 0; i < p->size; i++) {
			if ((0 == strcmp(query, p->data[i].stu_num)) || (0 == strcmp(query, p->data[i].name))) {
				if (strcmp(p->data[i].date, date) <= 0) {
					flag = 1;
					//printf("%s\n", p->data[i].date);
					fprintf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\n",
					p->data[i].stu_num,
					p->data[i].name,
					p->data[i].college,
					p->data[i].temperate,
					p->data[i].isCough,
					p->data[i].status,
					p->data[i].time,
					p->data[i].date);
					if (print_flag) {
						printf("��ֹ��%d��%d��%d�ո����Ľ���������ϢΪ:\n",getYear(date),getMonth(date),getDay(date));
						printf("%-8s\t%-6s\t%-10s\t%s\t%s\t%s\t%s\t%s\t\n", "ѧ��", "����", "ѧԺ", "�¶�", "�Ƿ����", "����״̬", "ʱ��", "����");
						print_flag = 0;
					}
					printSingleStundet(&(p->data[i]));
				}
				
			}
		}
		if (flag == 0) {
			printf("�޷����������Ϣ\n");
		}
	}
}
void searchStudent(Students* p) {
	char query[20] = { 0 };
	char date[20] = { 0 };
	printf("������ѧ��ѧ�Ż�������");
	scanf("%s", query);
	printf("���������ֹ���ڣ�");
	scanf("%s", date);
	findStudentAndSave(query, date, "data2.txt", p);
}

//�������ݵ��ļ�
void saveStudent(const char* filename, const Students * p) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("%s\n", strerror(errno));
	}
	for (int i = 0; i < p->size; i++) {
		//printf("%s\n", p->data[i].temperate);
		fprintf(fp,"%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\n",
			p->data[i].stu_num,
			p->data[i].name,
			p->data[i].college,
			p->data[i].temperate,
			p->data[i].isCough,
			p->data[i].status,
			p->data[i].time,
			p->data[i].date);
	}
	fclose(fp);
	fp = NULL;
}