#include<stdio.h>
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int max = arr[0];
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 1; i < sz; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	printf("��СֵΪ:%d\n", max);

	return 0;
}