#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC
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
	//strcat(src, src);//���Ǵ����  ��src����׷��һ��src���ַ���
	strncat(src, src, k);
	//�ж�moveָ����ַ����Ƿ���srcָ����ַ������Ӵ�
	char* ret = strstr(src, move);//�����Ӵ�
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
		printf("��\n");
	}
	else {
		printf("����\n");
	}
}