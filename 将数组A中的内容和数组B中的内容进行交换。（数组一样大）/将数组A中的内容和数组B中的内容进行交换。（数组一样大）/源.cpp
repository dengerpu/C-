#include<stdio.h>
int main() {
	int arr1[] = { 1,2,3,4 };
	int arr2[] = { 5,6,7,8 };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);

	for (int i = 0; i < sz1; i++) {
		int t = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = t;
	}

	for (int i = 0; i < sz1; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");


	for (int i = 0; i < sz1; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");
	
	return 0;
}