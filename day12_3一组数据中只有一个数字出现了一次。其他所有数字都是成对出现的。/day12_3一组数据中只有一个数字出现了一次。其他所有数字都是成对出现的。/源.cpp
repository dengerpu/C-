#define _CRT_SECURE_NO_WARNINGS
//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩

//�����ͬΪ0������Ϊ1
//��0����Ǳ���
#include<stdio.h>
//ֻ��һ������ͬ
//int main() {
//	int arr[] = { 1,1,2,2,3,3,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int num = 0;
//	for (int i = 0; i < sz; i++) {
//		num^= arr[i];
//	}
//	printf("%d\n", num);
//	return 0;
//}

//�������е����������
//���Ľ�����������������ֵ������Ľ��
//���ı�������ͬΪ0������Ϊ1�������������������ͬ�����Ľ����
//�������Ӧ������λΪ1�����䲻ͬ��λ
//���԰ѵ�һ��Ϊ1��λ���б�ǣ���Ϊ1�����һ��Ϊ0�����һ��
void find_num(int* arr, int size) {
	int num1 = 0;
	int num2 = 0;
	int end_num = 0;
	int flag = 0;
	for (int i = 0; i < size; i++) {
		end_num ^= *(arr + i);
	}
	while (!(end_num & 1)) { //�ҵ���һ��1
		flag++;
		end_num >>= 1;
	}
	for (int i = 0; i < size; i++) {
		int tmp = arr[i] >> flag;
		if (tmp & 1) {  //�����ƶ�ӦλΪ1
			num1 ^= arr[i];
		}
		else {
			num2 ^= arr[i];
		}
	}
	printf("num1=%d,num2=%d\n", num1, num2);
}
int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 3, 6, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	find_num(arr, size);
	return 0;
}
