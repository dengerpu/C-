#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//��һ���ַ����������Ϊ:"student a am i",
//���㽫��������ݸ�Ϊ"i am a student".
//Ҫ��
//����ʹ�ÿ⺯����
//ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
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
	int len = sizeof(arr) / sizeof(arr[0]);  //�����\0
	reverse(arr, len-1);
	printf("%s\n", arr);
	return 0;
}