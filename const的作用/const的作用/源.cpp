#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void test1() {
	int n = 10, m = 20;
	int* p = &n;
	*p = 20;
	p = &m;
}
void test2() {
	int n = 10, m = 20;
	const int* p = &n;
	*p = 20;  //这里是错误的 const如果放在左边修饰的是指针指向的内容
	p = &m;		//指针指向的内容不可以改变，但是指针变量本身的内容可以改变
}
void test3() {
	int n = 10, m = 20;
	 int* const p = &n;
	*p = 20;  
	p = &m;//这里是错误的 const如果放在右边修饰的是指针变量本身，指针变量的内容不可更改
	//但是指针指向的内容可以改
}

void test4() {
	int n = 10, m = 20;
	const int* const p = &n;  //最严格，指针变量本身不可改，指向的内容也不可以改
	*p = 20;
	p = &m;
}

int main() {


	return 0;
}