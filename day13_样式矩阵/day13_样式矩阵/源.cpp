#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//2.
////杨氏矩阵
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//数组：
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
int FindNum(int arr[][3], int k, int *px, int *py) {
	int x = 0;
	int y = *py - 1;
	while (x <= *px - 1 && y >= 0) {
		if (arr[x][y] > k) {
			y--;
		}
		else if (arr[x][y] < k) {
			x++;
		}
		else {
			*px = x;
			*py = y;
			return 1;
		}
	}
}
int main() {
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 4;
	int x = 3, y = 3;
	int ret = FindNum(arr, k, &x, &y);
	if(ret){
		printf("坐标是：第%d行，第%d列\n",x+1,y+1);
	}
}