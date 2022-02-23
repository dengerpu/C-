#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void left_move(char* str, int k) {
	int len = strlen(str);
	for (int i = 0; i < k; i++) {
		char tmp = *str;
		for (int j = 0; j < len - 1; j++) {
			*(str + j) = *(str + j + 1);
		}
		*(str + len - 1) = tmp;
	}
}
int main(){
	char arr[] = "abcdef";
	left_move(arr, 2);
	printf("%s\n", arr);

	return 0;
}