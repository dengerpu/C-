#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int i;//全局变量不初始化，默认为0
int main() {
	i--;
	//-1
	//源码：10000000 00000000 00000000 00000001
	//反码：11111111 11111111 11111111 11111110
	//补码：11111111 11111111 11111111 11111111
	//printf("%d", sizeof(i));  4
	if (i > sizeof(i)) {//sizeof() -计算变量/类型所占内存的大小 >=0 无符号数
		printf(">\n");
	}
	else {
		printf("<\n");
	}

	return 0;
}