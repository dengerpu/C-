#define _CRT_SECURE_NO_WARNINGS
#include "ToSchool.h"


void Login() {
	char password[20] = { 0 };
	int i = 5;
	printf("\n\n");
	printf("====================ѧ����У��Ϣ����ϵͳ====================\n");
	while (i > 0) {
		printf("�������¼����:>");
		scanf("%s", &password);
		if (strcmp(password, "123456") != 0) {
			i--;
			printf("���������������������,������%d�λ���\n", i);
		}
		else {
			printf("����������ȷ\n");
			break;
		}
		if (i == 0) { exit(0); }
	}
}

//�˵�
void menu() {
	printf("====================ѧ����У��Ϣ����ϵͳ====================\n");
	printf("=                                                          =\n");
	printf("=                   ***���ܽ���***                         =\n");
	printf("=                                                          =\n");
	printf("=                   1.¼��ѧ����Ϣ                         =\n");
	printf("=                   2.����ѧ����Ϣ                         =\n");
	printf("=                   3.�޸�ѧ����Ϣ                         =\n");
	printf("=                   4.��˳�����ĳѧԺѧ����Ϣ             =\n");
	printf("=                   5.�������                             =\n");
	printf("=                   6.�˳�ϵͳ                             =\n");
	printf("=                                                          =\n");
	printf("=                                                          =\n");
	printf("============================================================\n");
}

//��ʼ��
void Init(students* p) {
	//memset(p->data, 0, sizeof(p->data));
	p->data = MALLOC(Student, DEFAULT_SZ);
	if (p->data == NULL) {
		printf("%s\n", strerror(errno));  //��ӡ������Ϣ
		return;
	}
	p->capicty = DEFAULT_SZ;
	p->size = 0;
	//�����ļ���ѧ����Ϣ
	//LoadStudent(students * p);
}
//��������ǹ�
void CheckCapacity(students* p) {
	Student * pr = NULL;
	if (p->size == p->capicty) {
		pr = (Student *)realloc(p->data, sizeof(Student) * DEFAULT_SZ);
		if (pr != NULL) {
			p->data = pr;
			p->capicty += DEFAULT_SZ;
			printf("���ݳɹ�\n");
		}
		else {
			printf("����ʧ��\n");
			printf("%s\n", strerror(errno));
			return;
		}
	}
}

//���ѧ����Ϣ
void AddStudent(students* p) {
	CheckCapacity(p);
	//char file[50] = { 0 };
	//FILE* fp = NULL;
	printf("�밴��������ʾ�����Ϣ¼�룺\n");
	printf("������ѧ�ţ�\n");
	gets_s(p->data[p->size].stu_id);   //vs�߰汾��Ϊgets����ȫ�����ܻ���Ϊ��ȡ���ַ���̫�������»�������������������
	printf("������������\n");
	gets_s(p->data[p->size].name);
	printf("���������֤���룺\n");
	gets_s(p->data[p->size].stu_id);
	printf("������ѧ�����ͣ���������1/˶ʿ����2/��ʿ����3����\n");
	p->data[p->size].stu_type = getchar();
	printf("����������ѧԺ��\n");
	gets_s(p->data[p->size].college);
	printf("����������רҵ��\n");
	gets_s(p->data[p->size].major);
	printf("�����뷵У�������У�\n");
	gets_s(p->data[p->size].route);
	printf("�����뽻ͨ���ߣ�\n");
	gets_s(p->data[p->size].trafficTools);
	printf("��ȥ14���Ƿ����нӴ�ȷ����Ա���ǣ�1/��0����\n");
	p->data[p->size].isCloseContact = getchar();
	printf("��������Уʱ���¶ȣ�\n");
	//getchar();
	gets_s(p->data[p->size].temperature);
	printf("�Ƿ��գ��ǣ�1/��0����\n");
	p->data[p->size].isFever = getchar();
	printf("�Ƿ���ԣ��ǣ�1/��0����\n");
	p->data[p->size].isCough = getchar();
	printf("��������Уʱ�䣺\n");
	gets_s(p->data[p->size].time);
	p->size++;

	//strcat(file, p->data[p->size].college);
	//strcat(file, ".txt");

	//fp = fopen(file, "a");//�á�a���ķ�ʽ���ļ������ļ�ĩβ��������µ����ݣ���ɾ��ԭ�����ݣ�
	//if (fp == NULL) {
	//	printf("%s\n", strerror(errno));
	//	exit(0);
	//}
	//if (fwrite(p->data, sizeof(Student), 1, fp) != 1) {
	//	printf("�޷�¼��\n");
	//}
	//fclose(fp);
}

//չʾѧ����Ϣ
void ShowStudent(students* p) {
	if (p->size == 0) {
		printf("ѧ����ϢΪ��\n");
	}
	else {
		int i = 0;
		printf("%-15s\t%-15s\t%-20s\t%-50s\t%s\t%-50s\t%-100s\t%-100s\t%s\t%-10s\t%s\t%s\t%-20s\n", "ѧ��", "����", "���֤��", "ѧԺ", "ѧ������", "רҵ", "��У·��", "��ͨ����", "��14���Ƿ������нӴ�", "����", "�Ƿ���", "�Ƿ����", "��Уʱ��");
		for (i = 0; i < p->size; i++) {
			printf("%-15s\t%-15s\t%-20s\t%-50s\t%s\t%-50s\t%-100s\t%-100s\t%s\t%-10s\t%s\t%s\t%-20s\n",
				p->data[i].stu_num,
				p->data[i].name,
				p->data[i].stu_id,
				p->data[i].college,
				p->data[i].stu_type,
				p->data[i].major,
				p->data[i].route,
				p->data[i].trafficTools,
				p->data[i].isCloseContact,
				p->data[i].temperature,
				p->data[i].isFever,
				p->data[i].isCough,
				p->data[i].time
			);
		}
	}
}