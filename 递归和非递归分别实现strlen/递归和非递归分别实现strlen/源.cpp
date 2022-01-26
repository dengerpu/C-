#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int f_strlen(char* a) {
	if (*a == '\0') return 0;
	else return 1 + f_strlen(a+1);  //这里填a++是错误的因为a++还是a本身

}
int fun_strlen(char* a) {
	int count = 0;
	while (*a != '\0') {
		count++;
		a++;
	}
	return count;
}

int main() {
	char a[20] = "abcdefg";
	printf("%d\n", strlen(a));
	printf("%d\n", f_strlen(a));
	printf("%d\n", fun_strlen(a));
	return 0;
}