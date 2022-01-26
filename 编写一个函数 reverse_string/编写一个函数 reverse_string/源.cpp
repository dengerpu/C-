#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void reverse_string(char* string) {
	if (*string == '\0') {
		printf("%c", *string);
	}
	else {
		reverse_string(++string);//输出下一个字符
		printf("%c", *(--string));//因为string已经执行完++，所以要输出当前字符
	}
}
void Reverse_string(char* ch) {
	ch++;
	if (*ch != '\0') {
		Reverse_string(ch);
	}
	ch--;
	printf("%c", *ch);
}
int main() {
	char a[20];
	scanf("%s", &a);
	reverse_string(a);
	printf("\n");
	Reverse_string(a);
	return 0;
}