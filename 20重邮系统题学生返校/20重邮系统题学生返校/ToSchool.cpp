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
	printf("=                   5.��ʾѧ����Ϣ                         =\n");
	printf("=                   0.�˳�ϵͳ                             =\n");
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
	Student* pr = NULL;
	if (p->size == p->capicty) {
		pr = (Student*)realloc(p->data, sizeof(Student) * DEFAULT_SZ);
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
	printf("�밴��������ʾ�����Ϣ¼�룺>\n");
	printf("������ѧ�ţ�>");
	scanf("%s",p->data[p->size].stu_num);   //vs�߰汾��Ϊgets����ȫ�����ܻ���Ϊ��ȡ���ַ���̫�������»�������������������
	printf("������������>");
	scanf("%s", p->data[p->size].name);
	printf("���������֤���룺>");
	scanf("%s", p->data[p->size].stu_id);
	getchar();
	printf("������ѧ�����ͣ���������1/˶ʿ����2/��ʿ����3/����������>");
	scanf("%c", &(p->data[p->size].stu_type));
	printf("%d\n", p->data[p->size].stu_type);
	printf("����������ѧԺ��>");
	scanf("%s", p->data[p->size].college);
	printf("����������רҵ��>");
	scanf("%s", p->data[p->size].major);
	printf("�����뷵У�������У�>");
	scanf("%s", p->data[p->size].route);
	printf("�����뽻ͨ���ߣ�>");
	scanf("%s", p->data[p->size].trafficTools);
	getchar();
	printf("��ȥ14���Ƿ����нӴ�ȷ����Ա���ǣ�1/��0����>");
	scanf("%c", &(p->data[p->size].isCloseContact));
	printf("��������Уʱ���¶ȣ�>");
	//getchar();
	scanf("%s", p->data[p->size].temperature);
	printf("�Ƿ��գ��ǣ�1/��0����>");
	getchar();
	scanf("%c", &(p->data[p->size].isFever));
	printf("�Ƿ���ԣ��ǣ�1/��0����>");
	getchar();
	scanf("%c", &(p->data[p->size].isCough));
	printf("��������Уʱ�䣺>");
	scanf("%s", p->data[p->size].time);
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
void ShowStudent(const students* p) {
	if (p->size == 0) {
		printf("ѧ����ϢΪ��\n");
	}
	else {
		int i = 0;
		//printf("%-15s\t%-15s\t%-20s\t%-50s\t%s\t%-50s\t%-100s\t%-100s\t%s\t%-10s\t%s\t%s\t%-20s\n", "ѧ��", "����", "���֤��", "ѧԺ", "ѧ������", "רҵ", "��У·��", "��ͨ����", "��14���Ƿ������нӴ�", "����", "�Ƿ���", "�Ƿ����", "��Уʱ��");
		for (i = 0; i < p->size; i++) {
			printf("ѧ�ţ�%-15s\t������%-15s\t���֤�ţ�%-20s\t\nѧԺ��%-20s\tѧ�����ͣ�%c\tרҵ��%-20s\t\n��У·�ߣ�%-20s\t��ͨ���ߣ�%-20s\t\n��14���Ƿ������нӴ���%c\t���£�%-10s\t�Ƿ��գ�%c\t�Ƿ���ԣ�%c\t��Уʱ�䣺%-20s\n",
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
void Print(const students* p,int i) {
	printf("ѧ�ţ�%-15s\t������%-15s\t���֤�ţ�%-20s\t\nѧԺ��%-20s\tѧ�����ͣ�%c\tרҵ��%-20s\t\n��У·�ߣ�%-20s\t��ͨ���ߣ�%-20s\t\n��14���Ƿ������нӴ���%c\t���£�%-10s\t�Ƿ��գ�%c\t�Ƿ���ԣ�%c\t��Уʱ�䣺%-20s\n",
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
		p->data[i].time);
}
//������������
void FindByName(const students* p, char name[15]) {
	if (p->size == 0) {
		printf("ѧ����Ϣ��Ϊ��\n");
	}
	else {
		for (int i = 0; i < p->size; i++) {
			if (0 == strcmp(name, p->data[i].name)) {
				Print(p, i);
			}
		}
	}
}
//����ѧԺ����
void FindByCollege(const students* p, char college[30]) {
	if (p->size == 0) {
		printf("ѧ����Ϣ��Ϊ��\n");
	}
	else {
		for (int i = 0; i < p->size; i++) {
			if (0 == strcmp(college, p->data[i].college)) {
				Print(p, i);
			}
		}
	}
}

//������Ϣ
void SearchStudent(const students* p){
	int s = 0;
	char info[50];
	printf("��ѡ��>(1.���� 2.ѧԺ)");
	scanf("%d", &s);
	if (s == 2) {
		printf("������Ҫ���ҵ�ѧԺ��>");
		scanf("%s", info);
		FindByCollege(p, info);
	}
	else{
		printf("������Ҫ���ҵ����֣�>");
		scanf("%s", info);
		FindByName(p, info);
	}
}

int FindByNameID(const students* p, char name[15]) {
	if (p->size == 0) {
		printf("ѧ����Ϣ��Ϊ��\n");
	}
	else {
		for (int i = 0; i < p->size; i++) {
			if (0 == strcmp(name, p->data[i].name)) {
				return i;
			}
		}
	}
}
void MOdifyStudent(students* p) {
	char name[15];
	int ret = 0;
	printf("������Ҫ�޸ĵ�����\n");
	scanf("%s", name);
	ret = FindByNameID(p, name);
	//ģ���޸�
	strcpy(p->data->name, "�޸�");
}

int  cmp_bynum(const void *e1,const void *e2) {
	return strcmp(((Student*)e1)->stu_num, ((Student*)e2)->stu_num);
}

//����
void SortStudent(students* p) {
	printf("����������ʽ��0��ѧ��  1��������Ĭ��Ϊ0��\n");
	int input = 0;
	scanf("%d", &input);
	if (input == 1) {
		qsort(p->data, p->size, sizeof(p->data[0]), cmp_bynum);
		ShowStudent(p);
	}
	else {
	
	}
}