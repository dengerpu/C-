#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int binary_search(int arr[],int k,int sz) {
	//不能在这里求数组长度，因为传过来的是地址
	int low = 0, high = sz - 1,mid;
	while (low <= high) {
		 mid = (low + high) / 2;
		 if (arr[mid] > k) {
			 high = mid - 1;
		 }
		 else if (arr[mid] < k) {
			 low = mid + 1;
		 }
		 else {
			 return mid;
		 }
	}
	return -1;
}


int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int n,k,sz;
	printf("请输入要查找的数字\n");
	scanf("%d", &n);
	//求数组长度
	sz = sizeof(arr) / sizeof(arr[0]);
	k = binary_search(arr, n, sz);

	if (k != -1) {
		printf("在数组中第%d个位置", k);
	}
	else {
		printf("找不到\n");
	}

	return 0;
}