#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个只出现一次的数字，编程实现。
//将数组中所有数异或
//异或的结果就是两个单独出现的数异或的结果
//异或的本质是相同为0，相异为1
//这个数对应二进制位为1就是其不同的位
//可以把第一个为1的为进行标记，把为1的疑惑道一起，为0的异或到一起
void find(int arr[], int sz) {
	int num1 = 0;
	int num2 = 0;
	int end_num = 0;
	int flag = 0;
	for (int i = 0; i < sz; i++) {
		end_num ^= arr[i];   //最终结果是两个不同的数异或的结果
	}
	while (!(end_num & 1)) {
		flag++;     
		end_num >>= 1;//找到二进制位第一个1
	}
	for (int i = 0; i < sz; i++) {
		int tmp = arr[i] >> flag;
		//printf("%d\n", tmp);
		if (tmp & 1) {
			num1 ^= arr[i];
			//printf("%d\n", num1);
		}
		else {
			num2 ^= arr[i];
			//printf("%d\n", num2);
		}
	}
	printf("%d  %d\n", num1, num2);

}

int main() {
	int arr[] = { 1,1,2,2,3,3,4 ,5};
	int sz = sizeof(arr) / sizeof(arr[0]);
	find(arr, sz);
	
	return 0;
}