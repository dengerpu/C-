#define _CRT_SECURE_NO_WARNINGS
#include "Toschool.h"

void menu(){

	printf("--------ѧ����У��������ϵͳ--------\n");
	printf("------------1.���ѧ����Ϣ----------\n");
	printf("------------2.�޸�ѧ����Ϣ----------\n");
	printf("------------3.��������ѧ���쳣��Ϣ--\n");
	printf("------------4.��ѯѧ����Ϣ----------\n");
	printf("------------5.�쳣��Ϣ�鿴----------\n");
	printf("------------6.��ӡѧ����Ϣ----------\n");
	printf("---------------0.�˳�---------------\n");

}

int main() {
	int input = 0;
	struct students p;
	InitStudent(&p);
	loadStudent("data1.txt", &p);
	do {
		menu();
		printf("������Ҫѡ��Ĳ�����>");
		scanf("%d", &input);
		switch (input) {
			case ADD:addStudent(&p); saveStudent("data1.txt",&p); break;
			case MODIFY:modifyStudent(&p); saveStudent("data1.txt", &p); break;
			case ADVICE:abnormaladvice("data4.txt",&p); break;
			case SEARCH:searchStudent(&p); break;
			case ABNORMAL:abnormalStudent("data3.txt" ,&p); break;
			case PRINT: printStudent(&p); break;
			case EXIT:destory(&p); exit(0); break;
			default:printf("������������������\n"); break;
		}
		system("pause");
		system("cls");
	} while (input);
	return 0;
}