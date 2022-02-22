#define _CRT_SECURE_NO_WARNINGS
//1.调整数组使奇数全部都位于偶数前面。
//
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。

#include<stdio.h>
void order(int arr[], int sz) {
	int left = 0,right = sz-1;
	//从左边偶数
	while (left < right) {
		while (left < right && arr[left] % 2 == 1) {
			left++;
		}
		//从右边找奇数
		while (left < right && arr[right] % 2 == 0) {
			right--;
		}
		if (left < right) {
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
	}
	
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	order(arr, sz);
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}