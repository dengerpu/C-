#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
//����1

//char* leftmove(char* str, int k) {
//	int len = strlen(str);
//	k = k % (len+1);
//	for (int i = 0; i < k; i++) {
//		char tmp = *str;  //�����һ���ַ�
//		for (int j = 0; j < len - 1; j++) {
//			*(str + j) = *(str + j + 1);
//		}
//		*(str + len - 1) = tmp;		
//	}
//	return str;
//}

void reverse( char* left,char * right) {
	assert(left && right);
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
int main() {
	char arr[] = "abcdef";
	assert(arr);
	int k=3;
	int len = strlen(arr);
	reverse(arr, arr + k - 1);  //�������
	reverse(arr+k, arr + len-1);  //�����ұ�
	reverse(arr, arr + len - 1);		//��������
	printf("%s\n", arr);

}