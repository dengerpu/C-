#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>
struct people {
	char name[50];
	char sex[10];
	int age;
	float money;
};
struct peoples {
	struct people data[50];
	int size;
};
int main() {
	int n;
	FILE* fp = fopen("C:\\Users\\Administrator.SC-201902031211\\Desktop\\data.txt", "w");
	if (fp == NULL) {
		printf("%s\n", strerror(errno));
	}
	struct peoples ps;
	memset(ps.data,0,sizeof(ps.data));
	printf("���������");
	scanf("%d", &n);
	ps.size = n;
	for (int i = 0; i < n; i++) {
		printf("������������>");
		scanf("%s", ps.data[i].name);
		printf("�������Ա�>");
		scanf("%s", ps.data[i].sex);
		printf("���������䣺>");
		scanf("%d", &(ps.data[i].age));
		printf("�������>");
		scanf("%f",&( ps.data[i].money));
		//printf("%f\n", ps.data[i].money);
	}
	fprintf(fp, "%s\t%s\t%s%\t%s\t\n", "����", "�Ա�", "����", "���");
	for (int i = 0; i < ps.size; i++) {
		//char name[50];
		//char sex[10];
		//int age;
		//double money;
		fprintf(fp, "%s\t%s\t%d\t%f\t\n", ps.data[i].name, ps.data[i].sex, ps.data[i].age, ps.data[i].money);
	}
	return 0;
}