#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int i;//ȫ�ֱ�������ʼ����Ĭ��Ϊ0
int main() {
	i--;
	//-1
	//Դ�룺10000000 00000000 00000000 00000001
	//���룺11111111 11111111 11111111 11111110
	//���룺11111111 11111111 11111111 11111111
	//printf("%d", sizeof(i));  4
	if (i > sizeof(i)) {//sizeof() -�������/������ռ�ڴ�Ĵ�С >=0 �޷�����
		printf(">\n");
	}
	else {
		printf("<\n");
	}

	return 0;
}