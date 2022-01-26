#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void bubble_sort(int a[],int sz) {
	int i, j;
	int flag = 1;
	for (i = 1; i < sz; i++) {//ÌËÊý  n-1ÌË
		for (j = 0; j < sz - i; j++) {
			if (a[j] > a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				flag = 0;
			}
		}
		//printf("%d\n", i);
		if (flag) {
			break;  //
		}
	}
}
int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(a) / sizeof(a[0]);
	bubble_sort(a, sz);
	for (int i = 0; i < sz; i++) {
		printf("%d ", a[i]);
	}



	return 0;
}