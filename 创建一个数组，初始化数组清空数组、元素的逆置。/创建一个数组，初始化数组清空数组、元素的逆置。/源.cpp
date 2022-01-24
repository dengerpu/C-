#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void print(int arr[], int sz);
void init(int arr[],int sz) {
	printf("请初始化数组\n");
	for (int i = 0; i < sz; i++) {
		scanf("%d", &arr[i]);
	}
	print(arr, sz);
}
void empty(int arr[], int sz) {
	printf("清空数组\n");
	for (int i = 0; i < sz; i++) {
		arr[i] = 0;
	}
	print(arr, sz);
}
void reverse(int arr[], int sz) {
	printf("逆转数组\n");
	for (int i = 0; i < sz / 2; i++) {
		int t = arr[i];
		arr[i] = arr[sz - 1 - i];
		arr[sz - 1 - i] = t;
	}
	print(arr, sz);
}
void print(int arr[], int sz) {
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int n;
	printf("请输入元素个数\n");
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	init(arr, n);
	reverse(arr, n);
	empty(arr, n);

	return 0;
}