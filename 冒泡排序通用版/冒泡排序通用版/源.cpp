#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void qsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*))
//
//参数
//base-- 指向要排序的数组的第一个元素的指针。
//nitems-- 由 base 指向的数组中元素的个数。
//size-- 数组中每个元素的大小，以字节为单位。
//compar-- 用来比较两个元素的函数，即函数指针（回调函数）
//回调函数：
//
//回调函数就是一个通过函数指针调用的函数。如果把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，就说这是回调函数。[2]
//
//compar参数
//
//compar参数指向一个比较两个元素的函数。比较函数的原型应该像下面这样。注意两个形参必须是const void* 型，同时在调用compar 函数（compar实质为函数指针，这里称它所指向的函数也为compar）时，传入的实参也必须转换成const void* 型。在compar函数内部会将const void* 型转换成实际类型。
//
//int compar(const void* p1, const void* p2);
//
//如果compar返回值小于0（ < 0），那么p1所指向元素会被排在p2所指向元素的左面；
//	如果compar返回值等于0（ = 0），那么p1所指向元素与p2所指向元素的顺序不确定；
//	如果compar返回值大于0（> 0），那么p1所指向元素会被排在p2所指向元素的右面。[2]
//
//	功能
//	使用排序例程进行排序。
//
//	说明
//	该函数不返回任何值。
struct Stu {
	char name[20];
	int age;
}*p;
int cmp_int(const void* e1, const void* e2) {
	return *(int *)e1 - *(int *)e2;
}
void test1() {
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);

	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int cmp_float(const void* e1, const void* e2) {
	/*if (*(float*)e1 > *(float*)e2) {
		return 1;
	}
	else if (*(float*)e1 == *(float*)e2) {
		return 0;
	}
	else {
		return -1;
	}*/

	return (int)(*(float*)e1 - *(float*)e2);
}
void test2() {
	float arr[] = { 9.0,8.0,7.0,6.0,5.0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_float);

	for (int i = 0; i < sz; i++) {
		printf("%f ", arr[i]);
	}
	printf("\n");
}
int cmp_stu_by_age(const void *e1,const void *e2){
	return ( (*(Stu *)e1).age  -  ((Stu *)e2)->age );
}
int cmp_stu_by_name(const void* e1, const void* e2) {
	//	//比较名字就是比较字符串
//	//字符串比较不能直接用><=来比较，应该用strcmp函数
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void test3() {
	struct Stu s[3] = { { "zhangsan", 20 }, { "lisi", 30 }, { "wangwu", 10 } };
	int sz = sizeof(s) / sizeof(s[0]);
	//qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);

}

//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//	//第一个参数：待排序数组的首元素地址
//	//第二个参数：待排序数组的元素个数
//	//第三个参数：待排序数组的每个元素的大小-单位是字节
//	//第四个参数：是函数指针，比较两个元素的所用函数的地址-这个函数使用者自己实现
//	//           函数指针的两个参数是：待比较的两个元素的地址
//	//
//}
//
////void qsort(void* base, 
////	       size_t num, 
////		   size_t width, 
////		   int( *cmp)(const void *e1, const void *e2)
////		   );
//
////实现bubble_sort函数的程序员，他是否知道未来排序的数据类型-不知道
////那程序员也不知道，待比较的两个元素的类型

void swap( char* e1,  char* e2,int width) {
	for (int i = 0; i < width; i++) {
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
	
}

void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2)) {
	int i = 0, j = 0;
	for (i = 0; i < sz - 1; i++) {  //一共进行sz-1趟
		for (j = 0; j < sz - 1 - i; j++) {
			//两个元素比较
			if (    cmp((char*)base+j*width,(char*)base+(j+1)*width)  >0   ) {
				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
			}
		}
	}
}
void test4()
{
	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//使用bubble_sort的程序员一定知道自己排序的是什么数据
	//就应该知道如何比较待排序数组中的元素
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test5() {
	struct Stu s[3] = { { "zhangsan", 20 }, { "lisi", 30 }, { "wangwu", 10 } };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	//bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}
int main() {
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}