#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int check() {
	//int a = 1;
	//	//返回1，表示小端
	//	//返回0，表示大端
	//	return *(char*)&a;
	union un {
		int i;
		char a;
	}u;
	u.i = 1;
	//返回1，表示小端
//	//返回0，表示大端
	return u.a;
}
int main(){
		int a = 1;
	int ret = check();

	if (1 == ret)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}

	//int a = 0x11223344;
	
	/*低地址-------------------->高地址
	....[][][][][11][22][33][44][][][][][][][]...  大端字节序存储模式
	....[][][][][44][33][22][11][][][][][][][]...  小端字节序存储模式
	讨论一个数据，放在内存中的存放的字节顺序
	大小端字节序问题
	*/
	return 0;
}