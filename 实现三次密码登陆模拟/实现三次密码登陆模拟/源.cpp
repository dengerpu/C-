#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//strcpy(arr,arr1); //字符串拷贝，将arr1的字符拷贝到arr


int main() {
	char s[20];
	int i = 1;
	printf("请输入密码:\n");
	while (i <= 3) {
		scanf("%s", s);
		if (strcmp(s, "123456")==0) {
			printf("%s", s);
			printf("登陆成功\n");
			break;
		}
		else {
			if(i<=2)
			printf("密码错误，请重新输入\n");	
		}
		i++;
	}
	if (i > 3) {
		printf("错误次数已经超过三次\n");
	}

	return 0;
}