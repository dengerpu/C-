#define _CRT_SECURE_NO_WARNINGS
#include "Toschool.h"

void menu(){

	printf("--------ѧ����У��������ϵͳ--------\n");
	printf("------------1.���ѧ����Ϣ----------\n");
	printf("------------2.�޸�ѧ����Ϣ----------\n");
	printf("------------3.ɾ��ѧ����Ϣ----------\n");
	printf("------------4.��ѯѧ����Ϣ----------\n");
	printf("------------5.�쳣��Ϣ�鿴----------\n");
	printf("---------------0.�˳�---------------\n");

}

int main() {
	int input = 0;
	struct students p;
	InitStudent(&p);
	do {
		menu();
		printf("������Ҫѡ��Ĳ�����>");
		scanf("%d", &input);
		switch (input) {
		case ADD:addStudent(&p); break;
		case MODIFY:printf("�޸�ѧ��ģ��\n"); break;
		case DELETE:printf("ɾ��ѧ��ģ��\n"); break;
		case SEARCH:printf("����ѧ����Ϣģ��\n"); break;
		case ABNORMAL:printf("�쳣��Ϣģ��\n"); break;
		case EXIT:exit(0); printf("�˳�\n"); break;
		}
		system("pause");
		system("cls");
	} while (input);
	return 0;
}