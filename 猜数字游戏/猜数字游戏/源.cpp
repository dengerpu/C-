#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>


void menu() {  //�˵�
	printf("*********************\n");
	printf("*****��������Ϸ******\n");
	printf("****1.play  0.exit***\n");
	printf("*********************\n");
}
void game() {
	int input = 0;
	int ret = rand()%100+1;
	printf("������Ҫ�µ�����\n", ret);
	scanf("%d", &input);
	while (input != ret) {
		if (input < ret) {
			printf("��С��\n");
			printf("������Ҫ�µ�����\n", ret);
			scanf("%d", &input);
		}
		else if (input > ret) {
			printf("�´���\n");
			printf("������Ҫ�µ�����\n", ret);
			scanf("%d", &input);
		}
	}
	if(input == ret)
		printf("��ϲ��¶���\n");

}

int main() {
	int num = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		scanf("%d", &num);
		if (num == 1) {
			game();
		}
		else if (num == 0) {
			break;
		}
		else {
			printf("����Ƿ�,����������\n");
		}
	
	} while (num == 1);
	

	return 0;
}