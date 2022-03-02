#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<errno.h>
#define DEBUG_PRINT printf("file:%s  line:%d  date:%s  time:%s\n", __FILE__, __LINE__, __DATE__, __TIME__)

// __FILE__      //进行编译的源文件
// __LINE__     //文件当前的行号
//__DATE__    //文件被编译的日期
//__TIME__    //文件被编译的时间
//__STDC__    //如果编译器遵循ANSI C，其值为1，否则未定义
int main() {
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		printf("%s\n", strerror(errno));
		return 0;
	}
	//printf("file:%s  line:%d  date:%s  time:%s\n", __FILE__, __LINE__, __DATE__, __TIME__);
	DEBUG_PRINT;
	return 0;
}