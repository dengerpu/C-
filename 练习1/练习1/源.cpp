#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include"add.h"  //�Լ�д��ͷ�ļ�
void add(int *p) {
	(*p)++;
}

//int main() {
//
//	int num = 0;
//	add(&num);
//	printf("%d\n", num);
//
//	return 0;
//}

//int main() {
//	
//	int len = 0;
//	len = strlen("abc");
//	printf("%d\n",len);
// 
//
//	printf("%d\n", strlen("abc"));
//	return 0;
//}


//int main() {
//
//	//printf�������ص��Ǵ�ӡ�ַ��ĸ���
//	printf("%d\n", printf("%d\n", printf("43\n")));
//
//	return 0;
//}

int main() {
	int a, b,z;
	scanf("%d%d", &a, &b);
	z = add(a, b);
	printf("%d+%d=%d", a, b, z);
	return 0;
}