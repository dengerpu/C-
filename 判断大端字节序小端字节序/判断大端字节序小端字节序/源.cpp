#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int check_sys() {
	int a = 1;  //0x005CFABC  01 00 00 00
	char* p = (char*)&a;  //char*����ֻȡһ���ֽ�  ������01  ������С��
	//����1С�ˣ�����0���
	return *p;
}

int check_sys2() {
	union {
		int i;
		char c;
	}un;
	un.i = 1;
	return un.c;
}

int main() {
	int ret = check_sys2();
	if (ret == 1) {
		printf("С��\n");
	}
	else
		printf("���\n");

	int a = 0x11223344;
/*	int* p = &a;
	*p = 0; */  //0x005CF7DC  00 00 00 00  
	char* p = (char *)&a;
	*p = 0;

	//0x012FFE84  00 33 22 11 

	return 0;
}