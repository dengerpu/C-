#define _CRT_SECURE_NO_WARNINGS
#include "ToSchool.h"

int main() {
	int input = 0;
	students p;  //����ѧ����Ϣ��
	Login();
	Init(&p);
	do {
		menu();
		printf("����������Ҫ�Ĳ�������5�����������\n");
		scanf("%d", &input);
		switch (input) {
		case ADD:AddStudent(&p); break;
		case SEARCH:break;
		case MODIFY:break;
		case SORT:break;
		case SHOW:ShowStudent(&p); break;
		case EXIT:printf("�˳�ϵͳ\n"); break;
		default:printf("������������������\n");
		}
	} while (input);

	return 0;
}