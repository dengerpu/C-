#define _CRT_SECURE_NO_WARNINGS
//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）

//异或相同为0，相异为1
//与0异或还是本身
#include<stdio.h>
//只有一个数不同
//int main() {
//	int arr[] = { 1,1,2,2,3,3,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int num = 0;
//	for (int i = 0; i < sz; i++) {
//		num^= arr[i];
//	}
//	printf("%d\n", num);
//	return 0;
//}

//将数组中的所有数异或，
//异或的结果就是两个单独出现的数异或的结果
//异或的本质是相同为0，相异为1，所以这个数（两个不同数异或的结果）
//这个数对应二进制位为1就是其不同的位
//可以把第一个为1的位进行标记，把为1的异或到一起，为0的异或到一起
void find_num(int* arr, int size) {
	int num1 = 0;
	int num2 = 0;
	int end_num = 0;
	int flag = 0;
	for (int i = 0; i < size; i++) {
		end_num ^= *(arr + i);
	}
	while (!(end_num & 1)) { //找到第一个1
		flag++;
		end_num >>= 1;
	}
	for (int i = 0; i < size; i++) {
		int tmp = arr[i] >> flag;
		if (tmp & 1) {  //二进制对应位为1
			num1 ^= arr[i];
		}
		else {
			num2 ^= arr[i];
		}
	}
	printf("num1=%d,num2=%d\n", num1, num2);
}
int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 3, 6, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	find_num(arr, size);
	return 0;
}
