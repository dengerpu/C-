#define _CRT_SECURE_NO_WARNINGS
//1.��������ʹ����ȫ����λ��ż��ǰ�档
//
//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�

#include<stdio.h>
void order(int arr[], int sz) {
	int left = 0,right = sz-1;
	//�����ż��
	while (left < right) {
		while (left < right && arr[left] % 2 == 1) {
			left++;
		}
		//���ұ�������
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