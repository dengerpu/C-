#define _CRT_SECURE_NO_WARNINGS
//2.不使用（a+b）/2这种方式，求两个数的平均值。
#include<stdio.h>
//可以避免栈溢出
//double average(int a, int b) {
//	return a + (b - a) / 2.0;
//	
//}
//int average(int a, int b) {
//	//用a和b相同的部分加上a和b不同的地方，
//	//a和b相同的部分为（a& b），
//	//a和b不同的部分为（a^ b），
//	//不同的部分除以二就是（a^ b >> 1）
//	return ((a & b) + (a ^ b) >> 1);
//}

//一个数右移一位相当于除以2
//int average(int a, int b) {
//	//return (a + b) >> 1;
//	return (a + ((b - a) >> 1));
//}
//&的作用：找出相同的位
//^的作用：找出不同的位
int average(int a, int b) {
	return (a & b) + ((a ^ b) >> 1);
}
int main() {
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	printf("%d\n", average(a, b));
	return 0;
}