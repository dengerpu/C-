#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//2.
////���Ͼ���
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//
//���飺
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
		printf("�����ǣ���%d�У���%d��\n",x+1,y+1);
	}
}