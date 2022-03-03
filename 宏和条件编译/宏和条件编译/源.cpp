#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//int  main()
//{
//	printf("%d\n", __STDC__);
//
//	return 0;
//}


//95% - VS
//99% - gcc

//#define MAX 100
//#define STR "hehe"
//
//#define reg register
//#define do_forever for(;;)
//
//int main()
//{
//	for (;;)
//		;
//
//	return 0;
//
//	//reg int a;
//	//register int a;
//	//int max = MAX;
//	//int max = 100;
//	//printf("%d\n", max);
//	//printf("%s\n", STR);
//}
//#define MAX 100
//
//int main()
//{
//	int a = MAX;
//	printf("%d\n", MAX);
//
//	return 0;
//}

//#define SQUARE(x) (x)*(x)
//
//int main() {
//	int ret = SQUARE(5);
//	//等价于int ret = 5*5;
//	printf("ret=%d\n", ret);
//
//	 ret = SQUARE(5 + 1);
//	 //SQUARE(x) x*x  这种情况是5*5+1
//	 //SQUARE(x) (x)*(x)  6*6
//	 printf("%d\n", ret);
//
//	return 0;
//}

//#define MAX 100
//#define DOUBLE(X) ((X)+(X))
//
//int main()
//{
//	int a = 5;
//	int ret = 10 * DOUBLE(MAX);
//	printf("MAX = %d\n", MAX);
//	//int ret = 10* ((a)+(a));
//	//
//	printf("%d\n", ret);
//
//	return 0;
//}

//# ，把一个宏参数变成对应的字符串
#define PRINT(X) printf("the value of " #X " is %d\n", X)

//int main()
//{
//	//printf("hello world\n");
//	//printf("hello " "world\n");
//	printf("hel" "lo " "world\n");
//
//	int a = 10;
//	int b = 20;
//	PRINT(a);
//	//printf("the value of ""a"" is %d\n", a);
//	PRINT(b);
//	//printf("the calue of ""b"" is %d\n", b);
//	return 0;
//}

//## 的作用
//##可以把位于它两边的符号合成一个符号。
//它允许宏定义从分离的文本片段创建标识符。

//#define CAT(X,Y) X##Y
//int main() {
//	int Class84 = 2019;
//	printf("%d\n", CAT(Class,84));
//	//printf("%d\n", Class##84);
//	return 0;
//}


//#define MAX(X, Y)     ((X)>(Y)?(X):(Y))
//
//int main()
//{
//	int a = 10;
//	int b = 11;
//
//	int max = MAX(a++, b++);
//	//int max = ((a++) > (b++) ? (a++) : (b++));
//	//a++=10  a=11  b++=11 b= 12  max=b++=12 b=13
//
//	printf("%d\n", max);//12
//	printf("%d\n", a);//11
//	printf("%d\n", b);//13
//
//	return 0;
//}

//宏-2
//#define MAX(X, Y) ((X)>(Y)?(X):(Y))
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	float c = 3.0f;
//	float d = 4.0f;
//	//函数在调用的时候
//	//会有函数调用和返回的开销
//	//
//	/*float max = Max2(c, d);
//	printf("max = %d\n", max);*/
//	//预处理阶段就完成了替换
//	//没有函数的调用和返回的开销
//	//max = MAX(c, d);
//	max = ((c) > (d) ? (c) : (d));
//	printf("max = %d\n", max);
//	/*int max = Max(a, b);
//	printf("max = %d\n", max);
//	max = MAX(a, b);
//	printf("max = %d\n", max);*/
//
//	return 0;
//}

//#define SIZEOF(type) sizeof(type)
//int main()
//{
//	int ret = SIZEOF(int);
//	//int ret = sizeof(int);
//	printf("%d\n", ret);
//	return 0;
//}

//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	int* p = (int*)malloc(10*sizeof(int));
//	
//	int* p = MALLOC(10, int);
//	//int* p = (int*)malloc(10 * sizeof(int));
//	return 0;
//}

//#define DEBUG

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int i = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = 0;
//#ifdef DEBUG
//		printf("%d ", arr[i]);
//#endif
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int i = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = 0;
//#if 1+1
//		printf("%d ", arr[i]);
//#endif
//	}
//
//	return 0;
//}


//int main()
//{
//#if 1==2
//	printf("haha\n");
//#elif 2==2
//	printf("hehe\n");
//#else
//	printf("嘿嘿\n");
//#endif
//
//	return 0;
//}

//#define DEBUG 0
//
//int main()
//{
//#if defined(DEBUG)
//	printf("hehe\n");
//#endif
//
//#ifdef DEBUG
//	printf("hehe\n");
//#endif
//
//#if !defined(DEBUG)
//	printf("hehe\n");
//#endif
//
//#ifndef DEBUG
//	printf("hehe\n");
//#endif
//	return 0;
//}

//#include<stddef.h>
//struct S
//{
//	char c1;
//	int a;
//	char c2;
//};
//
//#define OFFSETOF(struct_name,number_name) (int)&(((struct_name *)0)->number_name)
//int main()
//{
//	//struct S s;
//	printf("%d\n", OFFSETOF(struct S, c1) );
//	printf("%d\n", OFFSETOF(struct S, a) );
//	printf("%d\n", OFFSETOF(struct S, c2) );
//
//	printf("%d\n", offsetof(struct S, c1));
//	printf("%d\n", offsetof(struct S, a));
//	printf("%d\n", offsetof(struct S, c2));
//
//
//	return 0;
//}
//
//int main()
//{
//	unsigned char puc[4];
//	struct tagPIM
//	{
//		unsigned char ucPim1;
//		unsigned char ucData0 : 1;
//		unsigned char ucData1 : 2;
//		unsigned char ucData2 : 3;
//	}*pstPimData;
//	pstPimData = (struct tagPIM*)puc;
//	memset(puc, 0, 4);
//	pstPimData->ucPim1 = 2;
//	pstPimData->ucData0 = 3;
//	pstPimData->ucData1 = 4;
//	pstPimData->ucData2 = 5;
//	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//	return 0;
//}
//
//#include <stdio.h>
//union Un
//{
//	short s[7];//14  2  
//	int n;//4
//};
//int main()
//{
//	printf("%d\n", sizeof(union Un));  //16
//	return 0;
//}

#include<stdio.h>
int main()
{
	union
	{
		short k;  //2
		char i[2];  //2
	}*s, a;
	s = &a;
	s->i[0] = 0x39;
	s->i[1] = 0x38;
	printf("%x\n", a.k);//3839   小端存储
	return 0;
}