#define _CRT_SECURE_NO_WARNINGS
#include "ToSchool.h"

int main() {
	int input = 0;
	students p;  //����ѧ����Ϣ��
	Login();
	Init(&p);
	do {
		menu();
		printf("����������Ҫ�Ĳ�����\n");
		scanf("%d", &input);
		switch (input) {
		case ADD:AddStudent(&p); break;
		case SEARCH:SearchStudent(&p); break;
		case MODIFY: ModifyStudent(&p); break;
		case SORT:SortStudent(&p); break;
		case SHOW:ShowStudent(&p); break;
		case SAVE:SaveStudent(&p); break;
		case EXIT:printf("�˳�ϵͳ\n"); SaveStudent(&p); DsetoryStudent(&p); break;
		default:printf("������������������\n");
		}
	} while (input);

	return 0;
}