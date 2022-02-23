#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC
char* left_move(char* str, int k) {
	int len = strlen(str);
	for (int i = 0; i < k; i++) {
		char tmp = *str;
		for (int j = 0; j < len - 1; j++) {
			*(str + j) = *(str + j + 1);
		}
		*(str + len - 1) = tmp;
	}
	return str;
}
//int is_left_move(char *src,char *move) {
//	int k = strlen(src);
//	for (int i = 0; i < k; i++) {
//		char* str = left_move(src, i);
//		printf("%s\n", str);
//		if (strcmp(str, move)==0) {
//			return 1;
//		}
//	}
//	return 0;
//}
int is_left_move(char* src, char* move) {
	int len1 = strlen(src);
	int len2 = strlen(move);
	if (len1 != len2) {
		return 0;
	}

	int k = strlen(src);
	//strcat(src, src);//这是错误的  在src后面追加一个src的字符串
	strncat(src, src, k);
	//判断move指向的字符串是否是src指向的字符串的子串
	char* ret = strstr(src, move);//查找子串
	if (ret == NULL) {
		return 0;
	}
	else {
		return 1;
	}
		

	return 0;
}
int main() {
	char arr[20] = "AABCD";
	char arr2[] = "ABCDA";
	int ret = is_left_move(arr, arr2);
	if (ret == 1) {
		printf("是\n");
	}
	else {
		printf("不是\n");
	}
}