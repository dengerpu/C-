#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
////
//int main()
//{
//	//向内存申请10个整形的空间
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		//打印错误原因的一个方式
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//正常使用空间
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//当动态申请的空间不再使用的时候
//	//就应该还给操作系统
//	free(p);
//	p = NULL;//
//
//	return 0;
//}
//int main() {
//	int* p = (int*)malloc(5 * sizeof(int));
//	int i = 0;
//	if (p != NULL) {
//		for (i = 0; i < 5; i++) {
//			*(p + i) = i;
//		}
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//	
//	int* pr = (int *)calloc(5, sizeof(int));  //不用自己计算
//	if (pr != NULL) {
//		for (i = 0; i < 5; i++) {
//			*(pr + i) = i;
//		}
//	}
//	for (i = 0; i < 5; i++)
//				{
//					printf("%d ", *(pr + i));
//				}
//	printf("\n");
//	
//	free(p);
//	printf("%p", p);
//	p = NULL;
//	free(pr);	//释放空间
////	//free函数是用来释放动态开辟的空间的
//	printf("%p", pr);
//	pr = NULL;
//
//
//	return 0;
//}


//int main() {
//	int* p = (int*)calloc(5, sizeof(int));   //会初始化为0
//	for (int i = 0; i < 5; i++) {
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}


//realloc
//调整动态开辟内存空间的大小
//realloc使用的注意事项：
//1. 如果p指向的空间之后有足够的内存空间可以追加，则直接追加，后返回p
///2. 如果p指向的空间之后没有足够的内存空间可以追加，则realloc函数会重新找一个新的内存区域
///  开辟一块满足需求的空间，并且把原来内存中的数据拷贝回来，释放旧的内存空间
//  最后返回新开辟的内存空间地址
//3. 得用一个新的变量来接受realloc函数的返回值
//int main() {
//	int* p = (int*)malloc(5 * sizeof(int));
//	if (p != NULL) {
//		for (int i = 0; i < 5; i++) {
//			*(p + i) = i;
//			}
//	}
//	else {
//		printf("%s\n", strerror(errno));
//	}
//
//	//再分配5个空间
//	int* pr = (int*)realloc(p, 5 * sizeof(int));
//	if (pr != NULL) {
//		p = pr;
//		for (int i = 5; i < 10; i++) {
//			*(p + i) = i;
//		}
//		for (int i = 0; i < 10; i++) {
//			printf("%d ", *(p + i));
//		}
//	}
//	else {
//		printf("%s\n", strerror(errno)); //打印错误信息
//	}
//	free(p);
//	p = NULL;
//		
//
//	return 0;
//}


//
//int main().
//{
//	int *p = (int*)malloc(20);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			*(p + i) = i;
//		}
//	}
//	//就是在使用malloc开辟的20个字节空间
//	//假设这里，20个自字节不能满足我们的使用了
//	//希望我们能够有40个字节的空间
//	//这里就可以使用realloc来调整动态开辟的内存
//	//
//	//realloc使用的注意事项：
//	//1. 如果p指向的空间之后有足够的内存空间可以追加，则直接追加，后返回p
//	//2. 如果p指向的空间之后没有足够的内存空间可以追加，则realloc函数会重新找一个新的内存区域
//	//  开辟一块满足需求的空间，并且把原来内存中的数据拷贝回来，释放旧的内存空间
//	//  最后返回新开辟的内存空间地址
//	//3. 得用一个新的变量来接受realloc函数的返回值
//	//
//	int*ptr =(int *) realloc(p, 20);
//
//	if (ptr != NULL)
//	{
//		p = ptr;
//		int i = 0;
//		for (i = 5; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//
//	//释放内存
//	free(p);
//	p = NULL;
//
//	return 0;
//}
//int main()
//{
//	//1. 对NULL进行解引用操作
//	//int *p = (int*)malloc(40);
//	////万一malloc失败了，p就被赋值为NULL
//	//*p = 0;//err
//
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	*(p + i) = i;//err
//	//}
//	//free(p);
//	//p = NULL;
//	//2. 对动态开辟的内存的越界访问
//	//int *p = (int*)malloc(5 * sizeof(int));
//	//if (p == NULL)
//	//{
//	//	return 0;
//	//}
//	//else
//	//{
//	//	int i = 0;
//	//	for (i = 0; i < 10; i++)
//	//	{
//	//		*(p + i) = i;
//	//	}
//	//}
//	////
//	//free(p);
//	//p = NULL;
//
//
//	int a = 10;
//	int* p = &a;
//	*p = 20;
//	//3. 对非动态开辟内存的free
//	free(p);
//	p = NULL;
//
//	return 0;
//}

#include <windows.h>
//
//int main()
//{
//	//1. 对NULL指针解引用操作
//	int *p = (int *)malloc(40);
//	//p进行相关的判断
//	*p = 10;//malloc开辟空间失败-对NULL指针解引用
//
//	//2.对动态开辟内存的越界访问
//	int *p = (int*)malloc(40);//10个int 0-9
//	if (p == NULL)
//	{
//		return 0;
//	}
//	int i = 0;
//	//越界
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;
//	}
//
//	free(p);
//	p = NULL;
//
//	//3. 对非动态开辟内存使用free释放
//	int a = 10;
//	int *p = &a;
//	//...
//	//对非动态开辟内存使用free释放
//	free(p);
//	p = NULL;
//
////	4. 使用free释放动态开辟内存的一部分
//	int*p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		*p++ = i;  //p已经指向第6个元素的首地址了
//	}
//	//回收空间
//	// 使用free释放动态开辟内存的一部分
//	free(p);
//	p =NULL;
//
//	//5.对同一块动态内存的多次释放
//	int *p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	//使用
//	//释放
//	free(p);
//	p = NULL;
//
//	free(p);
//
//	//6.动态开辟内存忘记释放（内存泄漏）
//	while (1)
//	{
//		malloc(1);
//	}
//
//
//	return 0;
//}

//
//void GetMemory(char *p)//形参只是临时拷贝一份
//{
//	p = (char *)malloc(100);
//}
//
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(str);  //传递值过去，所以不会地址不会被传过来
//	strcpy(str, "hello world");
//	printf(str);  //非法访问内存
//}
//
//int main()
//{
//	Test();
//
//	//char*str = "abcdef";
//	//printf("%s\n", str);
//	//printf(str);
//	//printf("abcdef");
//
//	return 0;
//}

//改正1
//void GetMemory(char **p)
//{
//	*p = (char *)malloc(100);
//}
//
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str);  //地址传过去
//	strcpy(str, "hello world");
//	printf(str);
//
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

////改正2
//char * GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);  //地址传过去
//	strcpy(str, "hello world");
//	printf(str);
//
//	free(str);
//	str = NULL;
//}

//int main()
//{
//	Test();
//	return 0;
//}

//char *GetMemory(void)
//{
//	char p[] = "hello world";  //局部变量使用完，（栈区）
//								//内存会被释放掉
//	return p;
//}
//
//void Test(void)
//{
//	char *str = NULL;
//	str = GetMemory();
//	printf(str);  //非法访问内存，随机值
//}
//
//int main()
//{
//	Test();
//	return 0;
//}
//
//int* test()
//{
//	//static int a = 10;//静态区  这样内存不会被释放
//	int a = 10;//栈区 
//	return &a;
//}
//
//int main()
//{
//	int*p = test();
//	*p = 20;//
//	printf("%d\n", *p);
//	return 0;
//}

//int* test()
//{
//	int *ptr = malloc(100);//堆区  堆区调用完不会自己释放
//	return ptr;
//}
//
//int main()
//{
//	int *p = test();
//
//	return 0;
//}

//void GetMemory(char **p, int num)
//{
//	*p = (char *)malloc(num);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	//改
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//
//void Test(void)
//{
//	char *str = (char *)malloc(100);
//	strcpy(str, "hello");
//	free(str);//free释放str指向的空间后，并不会把str置为NULL
//	//str = NULL;
//
//	if (str != NULL)
//	{
//		strcpy(str, "world"); //这里非法访问了
//		printf(str);
//	}
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}
