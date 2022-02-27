#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"


//��ʼ��ͨѶ¼
void InitContact(struct Contact* p) {
	memset(p->data, 0, sizeof(p->data));
	p->size= 0;
}
//����û�
void AddContact(struct Contact* p) {
	if (p->size == MAX) {
		printf("ͨѶ¼����");
	}
	else {
		printf("����������: > ");
		scanf("%s", p->data[p->size].name);
		//printf("%s\n", p->data[p->size].name);
		printf("����������: > ");
		scanf("%d", &(p->data[p->size].age));  //ע������Ҫȡ��ַ
		//printf("%d\n", p->data[p->size].age);
		printf("�������Ա�: > ");
		scanf("%s", p->data[p->size].sex);
		//printf("%s\n", p->data[p->size].sex);
		printf("������绰: > ");
		scanf("%s", p->data[p->size].tele);
		//printf("%s\n", p->data[p->size].tele);
		printf("�������ַ: > ");
		scanf("%s", p->data[p->size].addr);
		//printf("%s\n", p->data[p->size].addr);
		p->size++;
		printf("��ӳɹ�\n");
	}
}
//չʾ�û�
void ShowContact(const struct Contact* p) {
	if (p->size == 0) {
		printf("ͨѶ¼Ϊ��\n");
	}
	else {
		int i = 0;
		printf("%-20s\t%-5s\t%-5s\t%-11s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (i = 0; i < p->size; i++) {
			printf("%-20s\t%-5d\t%-5s\t%-11s\t%-30s\n", 
					p->data[i].name,
					p->data[i].age,
					p->data[i].sex,
					p->data[i].tele,
					p->data[i].addr
				);
		}
	}
}
static int FindByName(const struct Contact* p,char name[NAME_MAX]) {
	if (p->size == 0) {
		printf("ͨѶ¼Ϊ��\n");
	}
	else {
		for (int i = 0; i < p->size; i++) {
			if (0 == strcmp(p->data[i].name, name)) {
				return i;
			}
		}
		return -1;  //�Ҳ���
	}
}
//ɾ���û�
void DelContact(struct Contact* p) {
	char name[NAME_MAX];
	printf("������Ҫɾ��������:>");
	scanf("%s", name);
	int ret = FindByName(p, name);
	if (-1 == ret) {
		printf("���Ҳ���\n");
	}
	else {
		for (int i = ret; i < p->size - 1; i++) {
			p->data[i] = p->data[i + 1];
		}
		p->size--;
		printf("ɾ���ɹ�\n");
	}
}

//�����û�
void SearchContact(const struct Contact* p) {
	char name[NAME_MAX];
	printf("������Ҫ���ҵ�����:>");
	scanf("%s", name);
	int ret = FindByName(p, name);
	if (-1 == ret) {
		printf("���Ҳ���\n");
	}
	else {
		printf("%-20s\t%-5s\t%-5s\t%-11s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-5d\t%-5s\t%-11s\t%-30s\n",
			p->data[ret].name,
			p->data[ret].age,
			p->data[ret].sex,
			p->data[ret].tele,
			p->data[ret].addr
		);
	}
}

//�޸��û�
void ModifyContact(struct Contact* p) {
	char name[NAME_MAX];
	printf("������Ҫ�޸��û�������:>");
	scanf("%s", name);
	int ret = FindByName(p, name);
	if (-1 == ret) {
		printf("���Ҳ���\n");
	}else {
		printf("����������:>");
		scanf("%s", p->data[ret].name);
		printf("����������:>");
		scanf("%d", &(p->data[ret].age));
		printf("�������Ա�:>");
		scanf("%s", p->data[ret].sex);
		printf("������绰:>");
		scanf("%s", p->data[ret].tele);
		printf("�������ַ:>");
		scanf("%s", p->data[ret].addr);

		printf("�޸����\n");
	}

}
//void qsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*))
//
//����
//base-- ָ��Ҫ���������ĵ�һ��Ԫ�ص�ָ�롣
//nitems-- �� base ָ���������Ԫ�صĸ�����
//size-- ������ÿ��Ԫ�صĴ�С�����ֽ�Ϊ��λ��
//compar-- �����Ƚ�����Ԫ�صĺ�����������ָ�루�ص�������
//����
//������������
int cmpByName (const void* e1, const void* e2) {
	return strcmp((*(struct PeoInfo*)e1).name, (*(struct PeoInfo*)e2).name);
}
//������������
int cmpByAge(const void* e1, const void* e2) {
	return ( ((struct PeoInfo*)e1)->age- ((struct PeoInfo*)e2)->age);
}
void SortContact(struct Contact* p) {
	printf("����������ʽ��0������  1�����䣨Ĭ��Ϊ0��\n");
	int input = 0;
	scanf("%d", &input);
	if (input == 1) {
		qsort(p->data, p->size, sizeof(p->data[0]), cmpByAge);
	}
	else {
		qsort(p->data, p->size, sizeof(p->data[0]), cmpByName);
	}
	ShowContact(p);
}