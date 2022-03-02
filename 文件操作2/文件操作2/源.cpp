#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<errno.h>
//
//int main() {
//	FILE * pf = fopen("test.txt","r");
//	if (pf == NULL) {
//		printf("%s\n", strerror(errno));
//	}
//	//1. 文本文件读取是否结束，判断返回值是否为 EOF （ fgetc ），或者 NULL （ fgets ）
//	//	例如：
//	//	fgetc 判断是否为 EOF .
//	//	fgets 判断返回值是否为 NULL .
//	//	2. 二进制文件的读取结束判断，判断返回值是否小于实际要读的个数。
//	//	例如：
//	//	fread判断返回值是否小于实际要读的个数。
//	//读取文件
//	int ch = 0;
//	while ((ch = fgetc(pf)) != EOF) {
//		putchar(ch);
//	}
//	//判断是什么原因结束的
//	if (ferror(pf)) {
//		printf("I/O error when reading\n");
//	}
//	else if (feof(pf)) {
//		//printf("%d", feof(pf));
//		printf("End of file reached successfully\n");
//	}
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main() {
//	FILE * pf = fopen("test.txt", "r");
//	if (pf == NULL) {
//		return 0;
//	}
//	//1.定位文件指针
//	//fseek(pf, -2, SEEK_END);  //从后往前偏移2各单位   abcdefg  得到f
//	//fseek(pf, 1, SEEK_CUR);  //从当前往后偏移2各单位 abcdefg c
//	fseek(pf, 2, SEEK_SET);   //从开始到后
//	
//	//读取文件
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

int main() {
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		printf("%s\n", strerror(errno));
		return 0;
	}
	//定位文件指针
	fseek(pf, -2, SEEK_END);
	
	//读取文件
	int ch = fgetc(pf);
	printf("%c\n", ch);
	int pos = ftell(pf);   //返回文件指针相对于起始位置的偏移量
	printf("%d\n", pos);
	rewind(pf);
	ch = fgetc(pf); //让文件指针回到文件的起始位置
	printf("%c\n", ch);


	fclose(pf);
	pf = NULL;
	return 0;
}