#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//void test(int arr[])
//{
//	int sz = sizeof(arr) / sizeof(arr[0]); //这里算的是指针所占的字节（地址）
//	printf("%d\n", sz); //输出1或者2
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	test(arr);
//
//	return 0;
//}


//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//
//	return 0;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	char* pc = arr;
//	printf("%s\n", arr);
//	printf("%s\n", pc);
//
//	printf("%p\n", arr);  //两个都是首元素的地址
//	printf("%p\n", arr+1);
//	printf("%p\n", pc);
//	printf("%p\n", pc+1);
//
//	return 0;
//}

//int main()
//{
//	 const char* p = "abcdef";//"abcdef" 是一个常量字符串
//	//*p = 'W'; 
//	printf("%s\n", p);  //p指向字符串的首地址
//
//	printf("%c\n", *p);
//	printf("%s\n", p);
//
//	return 0;
//}


//
//www.stackoverflow.com
//Segmentation fault - 段错误
//segmentfault.com  
//
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "acbdef";
//	const char* p1 = "abcdef";
//	const char* p2 = "abcdef";
//
//	if (p1 == p2)
//	{
//		printf("p1和p2相同\n");
//	}
//	else
//	{
//		printf("p1和p2不同\n");
//	}
//
//	if (arr1 == arr2)
//	{
//		printf("arr1和arr2相同\n");
//	}
//	else
//	{
//		printf("arr1和arr2不同\n");
//	}
//
//	return 0;
//}

