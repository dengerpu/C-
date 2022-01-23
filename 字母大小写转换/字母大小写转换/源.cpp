#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//实现键盘字母大小写转换
int main() {
	//char a[20],ch;
	//scanf("%s", a);  //不能获取空格。回车
	//for (int i = 0; i < strlen(a); i++) {
	//	if (a[i] >= 65 && a[i] <= 91) {
	//		a[i] += 32;
	//	}
	//	else if (a[i] >= 97 && a[i] <= 123) {
	//		a[i] -= 32;
	//	}
	//}
	//printf("%s\n", a);

	char ch;
	while ((ch = getchar()) != EOF) {
		if (ch >= 65 && ch <= 91) {
			ch += 32;
			printf("%c", ch);
		}
		else if (ch >= 97 && ch <= 123) {
			ch -= 32;
			printf("%c", ch);
		}
	}


	return 0;
}