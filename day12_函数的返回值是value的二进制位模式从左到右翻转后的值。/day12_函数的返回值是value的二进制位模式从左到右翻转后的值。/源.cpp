#define _CRT_SECURE_NO_WARNINGS
//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵ��value�Ķ�����λģʽ�����ҷ�ת���ֵ��
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
#include<stdio.h>
#include<math.h>
//unsigned int reverse_bit(unsigned int value) {
//	int ret = 0;
//	int bit = 0;
//	int i;
//	for (i = 0; i < 32; i++) {
//		//ret =0
//		ret = ret << 1;  //����һλ������ǰһλ
//		bit = value & 1; // ȡ�����һλ
//		value = value >> 1; //ֵ���ƣ�ȡ��һλ
//		ret = bit | ret;  //���һλ����ret
//	}
//	return ret;
//}
/*
ѭ���ó������Ƶ�ÿһλ�����ư�λ��1�õ���
*/
//unsigned int reverse_bit(unsigned int value) {
//	int i = 0;
//	unsigned int ret = 0;
//	for (i = 0; i < 32; i++) {
//		//ret += ((value >> i) & 1) * pow(2, 31 - i);  ����������̫��
//		ret += ((value >> i) & 1) << (31 - i); 
//	}
//	return ret;
//}
unsigned int reverse_bit(unsigned int value) {
	unsigned int sum = 0;
	int arr[32], a = 0;
	int count1 = 0, i = 0;
	for (i = 0; i < 32; i++) {
		a = (value>>i) & 1;  //�õ���������ʽ��ÿһλ
		arr[i] = a;
	}
	printf("����ֵ�Ķ���������Ϊ��\n");
	for (i = 31; i >= 0; i--) {   //�������
		count1++;
		if (count1 % 9 == 0) {
			count1++;
			printf(" ");
		}
		printf("%d", arr[i]);
	}
	printf("\n");
	int count2 = 0;
	for (i = 0; i < 32; i++) {
		count2++;
		if (count2 % 9 == 0) {
			count2++;
			printf(" ");
		}
		sum += ((value >> i & 1)) * pow(2, 31 - i);
		printf("%d", arr[i]);
	}
	printf("\n");
	return sum;
}
int main() {
	printf("%u\n", reverse_bit(25));
	return 0;
}