#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//1.һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ�������ֻ����һ�ε����֣����ʵ�֡�
//�����������������
//���Ľ�����������������ֵ������Ľ��
//���ı�������ͬΪ0������Ϊ1
//�������Ӧ������λΪ1�����䲻ͬ��λ
//���԰ѵ�һ��Ϊ1��Ϊ���б�ǣ���Ϊ1���ɻ��һ��Ϊ0�����һ��
void find(int arr[], int sz) {
	int num1 = 0;
	int num2 = 0;
	int end_num = 0;
	int flag = 0;
	for (int i = 0; i < sz; i++) {
		end_num ^= arr[i];   //���ս����������ͬ�������Ľ��
	}
	while (!(end_num & 1)) {
		flag++;     
		end_num >>= 1;//�ҵ�������λ��һ��1
	}
	for (int i = 0; i < sz; i++) {
		int tmp = arr[i] >> flag;
		//printf("%d\n", tmp);
		if (tmp & 1) {
			num1 ^= arr[i];
			//printf("%d\n", num1);
		}
		else {
			num2 ^= arr[i];
			//printf("%d\n", num2);
		}
	}
	printf("%d  %d\n", num1, num2);

}

int main() {
	int arr[] = { 1,1,2,2,3,3,4 ,5};
	int sz = sizeof(arr) / sizeof(arr[0]);
	find(arr, sz);
	
	return 0;
}