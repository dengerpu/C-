#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>

int main() {

	char input[20];
	system("shutdown -s -t 60");//60秒后关机

	again:	printf("电脑将在60秒后，请输入你是猪\n");
			scanf("%s", input);
			if (strcmp(input, "你是猪")==0) {
				system("shutdown -a");
				}
			else {
				goto again;
			}


	return 0;
}