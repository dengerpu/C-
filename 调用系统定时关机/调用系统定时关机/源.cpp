#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>

int main() {

	char input[20];
	system("shutdown -s -t 60");//60���ػ�

	again:	printf("���Խ���60���������������\n");
			scanf("%s", input);
			if (strcmp(input, "������")==0) {
				system("shutdown -a");
				}
			else {
				goto again;
			}


	return 0;
}