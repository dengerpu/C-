#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int binary_search(int arr[],int k,int sz) {
	//���������������鳤�ȣ���Ϊ���������ǵ�ַ
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
	printf("������Ҫ���ҵ�����\n");
	scanf("%d", &n);
	//�����鳤��
	sz = sizeof(arr) / sizeof(arr[0]);
	k = binary_search(arr, n, sz);

	if (k != -1) {
		printf("�������е�%d��λ��", k);
	}
	else {
		printf("�Ҳ���\n");
	}

	return 0;
}