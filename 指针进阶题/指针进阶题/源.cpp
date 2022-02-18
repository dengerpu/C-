#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main() {

	//数组名是首元素的地址
	//1. sizeof(数组名) - 数组名表示整个数组
	//2. &数组名 - 数组名表示整个数组
	//
	//一维数组，
	int a[] = { 1, 2, 3, 4 };//4*4 = 16
	printf("%d\n", sizeof(a));//sizeof(数组名)-计算的是数组总大小-单位是字节- 16
	printf("%d\n", sizeof(a + 0));//4/8 - 数组名这里表示收元素的值，a+0 还是首元素地址，地址的大小就是4/8个字节
	printf("%d\n", sizeof(*a));   //4 - 数组名表示首元素地址，*a就是首元素，sizeof(*a)就是4
	printf("%d\n", sizeof(a + 1));//4/8 - 数组名这里表示收元素的值，a+1 第2个元素的地址，地址的大小就是4/8个字节
	printf("%d\n", sizeof(a[1])); //4 - 第2个元素的大小
	printf("%d\n", sizeof(&a));   //4/8 &a取出的是数组的地址，但是数组的地址那也是地址，地址的大小就是4/8个字节
	printf("%d\n", sizeof(*&a));  //16 - &a数组的地址，数组的地址解引用访问的数组，sizeof计算的就是数组的大小单位是字节
	printf("%d\n", sizeof(&a + 1));//4/8   &a是数组的地址，&a+1虽然地址跳过整个数组，但还是地址，所以是4/8个字节
	printf("%d\n", sizeof(&a[0]));//4/8 &a[0]是第一个元素的地址
	printf("%d\n", sizeof(&a[0] + 1));//4/8  &a[0]+1 是第二个元素的地址

	//字符数组
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };

	printf("%d\n", strlen(arr));//随机值
	printf("%d\n", strlen(arr + 0));//随机值
	//printf("%d\n", strlen(*arr));//err
	//printf("%d\n", strlen(arr[1]));//err

	printf("%d\n", strlen( &arr));//随机值
	printf("%d\n", strlen( &arr + 1));//随机值-6
	printf("%d\n", strlen(&arr[0] + 1));//随机值-1

	printf("%d\n", sizeof(arr));//sizeof计算机的是数组大小，6*1 = 6字节
	printf("%d\n", sizeof(arr + 0));//4/8 arr是首元素的地址，arr+0还是首元素的地址 地址的大小是4/8字节
	printf("%d\n", sizeof(*arr));   //1   arr是首元素的地址，*arr就是首元素，首元素是字符大小是一个字节
	printf("%d\n", sizeof(arr[1])); //1
	printf("%d\n", sizeof(&arr));   //4/8 &arr 虽然是数组的地址，但还是地址，地址大小是4/8个字节
	printf("%d\n", sizeof(&arr + 1));//4/8 &arr+1 是跳过整个数组后的地址，地址大小是4/8个字节
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 第二个元素的地址



	return 0;
}