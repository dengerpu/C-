#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int day;
	scanf("%d", &day);

	//switch (day) {
	//case 1: printf("����һ\n"); break;
	//case 2: printf("���ڶ�\n"); break;
	//case 3: printf("������\n"); break;
	//case 4: printf("������\n"); break;
	//case 5: printf("������\n"); break;
	//case 6: printf("������\n"); break;
	//case 7: printf("������\n"); break;
	//}

	switch (day){
	default:printf("�������\n"); break;
	case 1: if (day == 1) printf("111");
	case 2:
	case 3:
	case 4:
	case 5: printf("������\n"); break;
	case 6:
	case 7:printf("��Ϣ��\n"); break;
	}

	return 0;
}