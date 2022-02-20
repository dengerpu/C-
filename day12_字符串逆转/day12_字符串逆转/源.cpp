#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//有一个字符数组的内容为:"student a am i",
//请你将数组的内容改为"i am a student".
//要求：
//不能使用库函数。
//只能开辟有限个空间（空间个数和字符串的长度无关）。
//
//student a am i
//i ma a tneduts
//i am a student
#include<stdlib.h>
void reverse(char* str, int len) {
	int left = 0, right = len - 1;
	while (left <= right) {
		char tmp = *(str + left);
		*(str + left) = *(str + right);
		*(str + right) = tmp;
		left++;
		right--;
	}
}
int main() {
	char arr[] = "student a am i";
	//gets(arr);
	int len = sizeof(arr) / sizeof(arr[0]);  //会计算\0
	reverse(arr, len-1);
	printf("%s\n", arr);
	return 0;
}