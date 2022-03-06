#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct people {
	char name[20];
	char sex[10];
	int age;
};
int main() {
	char ch = 0;
	//这里可以是相对路径，也可以是绝对路径
	//FILE* fp = fopen("C:\\Users\\Administrator.SC-201902031211\\Desktop\\data.txt","r");
	//FILE* fp = fopen("C:\\Users\\Administrator.SC-201902031211\\Desktop\\data.txt", "w");
	//读写，没有文件时报错
	FILE* fp = fopen("C:\\Users\\Administrator.SC-201902031211\\Desktop\\data.txt", "r+");
	if (fp == NULL) {
		//printf("%s\n", strerror(errno));
		printf("文件打开失败\n");
	}
	//fgetc这个函数读取完，会将文件指针移动到下一个字符
	//ch = fgetc(fp);
	//printf("%c\n",ch);
	// ch = fgetc(fp);
	// printf("%c\n", ch);
	// ch = fgetc(fp);
	// printf("%c\n", ch);

	//while (EOF != (ch = fgetc(fp))) {
	//	printf("%c",ch);
	//}

	//fgets读取一行   fgets这个函数读取完会将文件指针移动到下一个字符
	//char str[200];  //这里不能用指针来接收，因为指针只能接受4个字节
	//fgets(str, 200, fp);
	//printf("%s\n", str);
	//fgets(str, 200, fp);
	//printf("%s\n", str);
	//fgets(str, 200, fp);
	//printf("%s\n", str);

	//fgets读取结束后，返回值为NULL
	//while (fgets(str, 200, fp)) {
	//	printf("%s", str);
	//}


	//fread ,返回实际读取的大小
	//char str[200];
	//fread(str, 1, 20, fp);//这样会出现烫烫烫
	//解决办法1 
	//char str[200] = { 0 };
	//解决办法2
	//char str[200];
	//memset(str, 0, 200);
	//fread(str, 1, 20, fp);
	//printf("%s", str);

	//解决办法3
	//char str[200];
	//int n = fread(str, 1, 20, fp);
	//str[n] = '\0';
	//printf("%s", str);

	//char str[200] = { 0 };
	//while (fread(str, 1, 200, fp)) {
	//	printf("%s", str);
	//}



	//写入一个字符  w  清空写 
	//fputc('A', fp);
	//fputc('B', fp);
	//fputc('c', fp);

	//const char* str = "abcdefg";
	//char str[20] = "abcd";
	//char str[20] = { 'a','b' };  
	//fputs(str, fp);

	//fwrite函数
	//int num = 123456;
	//fwrite(&num,  sizeof(num),1, fp);

	//fseek(fp, 0, SEEK_SET);
	//
	//int num2;
	//fread(&num2, sizeof(num2),1, fp);
	//printf("%d\n", num2);

	/*struct people p = { "张三","男",20 };
	fwrite(&p, sizeof(p), 1, fp);
	fwrite(&p, sizeof(p), 1, fp);
	fwrite(&p, sizeof(p), 1, fp);*/

	//读取最后一行数据
	//fseek(fp, -1, SEEK_END);
	//int length = 0;
	//while (fread(&ch, 1, 1, fp)) {
	//	if (ch == '\n')
	//		break;
	//	fseek(fp, -2, SEEK_CUR);  //往前退两个，表示移动到当前读取字符的前一个
	//	length++;
	//}
	//fseek(fp, -length, SEEK_END);   //移动到最后一行的首地址
	//char* buff = (char*)malloc(sizeof(char) * length);
	//fread(buff,length, 1, fp);
	//printf("%s\n", buff);

	rewind(fp);  //重置文件指针到文件开头
	fseek(fp, 0, SEEK_END);
	int  size = ftell(fp);
	printf("文件的大小：%d\n", size);


	fclose(fp);//释放内存
	fp = NULL;

	return 0;
}