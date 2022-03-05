#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"


//��ʼ��ͨѶ¼
void InitContact(struct Contact* p) {
	//memset(p->data, 0, sizeof(p->data));
	p->data = (PInfo)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (p->data == NULL) {
		printf("%s\n", strerror(errno));
	}
	p->size = 0;
	p->capicty = DEFAULT_SZ;
	//���ļ����Ѿ���ŵ�ͨѶ¼�е���Ϣ���ص�ͨѶ¼��ȥ
	LoadContact(p);
}
//��������Ƿ�
void CheckCapacity(struct Contact* p) {
	if (p->size == p->capicty) {
		//����
		PInfo ptr = (PInfo)realloc(p->data, sizeof(struct PeoInfo) * DEFAULT_SZ);
		if (ptr != NULL) {
			p->data = ptr;
			p->capicty = p->capicty + DEFAULT_SZ;
			printf("���ݳɹ�\n");
		}
		else {
			printf("����ʧ��\n");
			printf("%s\n", strerror(errno));
			return;
		}

	}
}
//�����ļ����ݵ�ͨѶ¼��
void LoadContact(Contact* p) {
	PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("data.txt", "r");
	if (pfRead == NULL) {
		printf("LoadContact:%s\n", strerror(errno));
		return;
	}
	//��ȡ�ļ�����ŵ�ͨѶ¼��
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead)) {
		CheckCapacity(p);
		p->data[p->size] = tmp;
		p->size++;
	}
	fclose(pfRead);
	pfRead = NULL;
}

//����û�
void AddContact(struct Contact* p) {
	//��⵱ǰͨѶ¼������
	//1. ������ˣ������ӿռ�
	//2. ���������ɶ�¶�����
	CheckCapacity(p);
	getchar();
		printf("����������: > ");
		//scanf("%s", p->data[p->size].name);
		//printf("%s\n", p->data[p->size].name);
		gets_s(p->data[p->size].name);
		printf("����������: > ");
		scanf("%d", &(p->data[p->size].age));  //ע������Ҫȡ��ַ
		//printf("%d\n", p->data[p->size].age);
		getchar();
		printf("�������Ա�: > ");
		gets_s(p->data[p->size].sex);
		//scanf("%s", p->data[p->size].sex);
		//printf("%s\n", p->data[p->size].sex);
		printf("������绰: > ");
		gets_s(p->data[p->size].tele);
		//scanf("%s", p->data[p->size].tele);
		//printf("%s\n", p->data[p->size].tele);
		printf("�������ַ: > ");
		gets_s(p->data[p->size].addr);
		//scanf("%s", p->data[p->size].addr);
		//printf("%s\n", p->data[p->size].addr);
		p->size++;
		printf("��ӳɹ�\n");
	
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
static int FindByName(const struct Contact* p, char name[NAME_MAX]) {
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
	}
	else {
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
int cmpByName(const void* e1, const void* e2) {
	return strcmp((*(struct PeoInfo*)e1).name, (*(struct PeoInfo*)e2).name);
}
//������������
int cmpByAge(const void* e1, const void* e2) {
	return (((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age);
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
//�˳���ִ���ͷź���
void DestroyContact(Contact* ps)
{
	free(ps->data);  //�ͷ��ڴ�
	ps->data = NULL;
}

void SaveContact(Contact* p) {
	FILE* pfWrite = fopen("data.txt", "w");
	if (pfWrite == NULL) {
		printf("SaveContact:%s\n", strerror(errno));
		return;
	}
	//ͨѶ¼������д���ļ���ȥ
	int i = 0;
	for (i = 0; i < p->size; i++) {
		fwrite(&(p->data[i]), sizeof(PeoInfo), 1, pfWrite);

	}
	fclose(pfWrite);
	pfWrite = NULL;
}
