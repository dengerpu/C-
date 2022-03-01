#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>

//int main() {
//	//r只读，为了输入数据，打开一个已经存在的文本文件
//	FILE* pf = fopen("text.txt", "w");
//	if (pf == NULL) {
//		printf("%s\n", strerror(errno));
//	}else {
//		printf("打开文件成功\n");
//	}
//	
//	return 0;
//}

//int main() {
//	//没有文件会创建文件，文件的内容会被覆盖
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL) {
//		printf("%s\n", strerror(errno));
//	}
//	else {
//		fputs("heelo world1", pf);
//		//关闭文件
//		fclose(pf);
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1, pf);//二进制的形式写到文件中
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main() {
//	FILE* pfwrite = fopen("test.txt", "w");
//	if (pfwrite == NULL) {
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//文件打开成功
//
//		fputc('b', pfwrite);
//		fputc('i', pfwrite);
//		fputc('t', pfwrite);
//
//		fclose(pfwrite);
//		pfwrite = NULL;
//	
//
//	return 0;
//}

//int main(){
//	FILE* pfRead = fopen("test.txt", "r");
//	if (pfRead == NULL) {
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	printf("%c", fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//
//	fclose(pfRead);
//	pfRead = NULL;
//	return 0;
//}

//从键盘输入
//输出到屏幕.
//键盘&屏幕都是外部设备
//
//键盘-标准输入设备- stdin
//屏幕-标准输出设备- stdout
//是一个程序默认打开的两个流设备

//int main() {
//	int ch = fgetc(stdin);
//	fputc(ch,stdout);
//	return 0;
//}

//int main() {
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL) {
//		return 0;
//	}
//	//读取文件
//	fgets(buf, 1024, pf);
//	puts(buf);
//	fgets(buf, 1024, pf);
//	puts(buf);
//
//	fclose(pf);
//	pf = NULL;
//}
//
//int main() {
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL) {
//		return 0;
//	}
//	//写文件
//	fputs("heelo\n", pf);
//	fputs("word2\n", pf);
//
//	fclose(pf);
//	pf = NULL;
//}

//int main() {
//	//从键盘读取一行文本信息
//	char buff[1024] = { 0 };
//	fgets(buff, 1024, stdin);//从标准输入流获取
//	fputs(buff, stdout);  //输出到标准输出流
//
//	return 0;
//}

//struct S {
//	int n;
//	float score;
//	char arr[10];
//};
//int main(){
//	struct S s = { 1,3.14,"heelo" };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL) {
//		return 0;
//	}
//	//格式化的形式写文件
//	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main() {
//	struct S s = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL) {
//		return 0;
//	}
//	//格式化的输入数据
//	fscanf(pf, "%d %f %s", &(s.n), &(s.score), s.arr);
//	printf("%d %.2f %s\n", s.n, s.score, s.arr);
//
//	fclose(pf);
//	pf == NULL;
//	return 0;
//}
//int main() {
//	struct S s = { 0 };
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr);
//	fprintf(stdout, "%d %.2f %s", s.n, s.score, s.arr);
//}

//int main() {
//	struct S s = { 100,3.14f,"abcdef" };
//	struct S tmp = { 0 };
//	char buf[1024] = { 0 };
//
//	//把格式化的数据转换成字符串存储到buf
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
//	printf("buf:%s\n", buf);
//	//从buf中读取格式化的数据到tmp中
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), &(tmp.arr));
//
//	printf("tmp:%d %f %s\n", tmp.n, tmp.score, tmp.arr);
//
//	return 0;
//}

struct  S {
	char name[20];
	int age;
	double score;
};
//int main() {
//	struct S s = { "张三",20,55.6 };
//
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL) {
//		return 0;
//	}
//	//二进制的形式写文件
//	fwrite(&s, sizeof(struct S), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//	
//}

int main()
{
	//struct S s = { "张三", 20, 55.6 };
	struct S tmp = { 0 };

	FILE* pf = fopen("test.txt", "rb");
	if (pf == NULL)
	{
		return 0;
	}
	//二进制的形式都文件
	fread(&tmp, sizeof(struct S), 1, pf);
	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);

	fclose(pf);
	pf = NULL;
	return 0;
}