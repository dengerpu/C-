#define _CRT_SECURE_NO_WARNINGS
//2.��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ��
#include<stdio.h>
//���Ա���ջ���
//double average(int a, int b) {
//	return a + (b - a) / 2.0;
//	
//}
//int average(int a, int b) {
//	//��a��b��ͬ�Ĳ��ּ���a��b��ͬ�ĵط���
//	//a��b��ͬ�Ĳ���Ϊ��a& b����
//	//a��b��ͬ�Ĳ���Ϊ��a^ b����
//	//��ͬ�Ĳ��ֳ��Զ����ǣ�a^ b >> 1��
//	return ((a & b) + (a ^ b) >> 1);
//}

//һ��������һλ�൱�ڳ���2
//int average(int a, int b) {
//	//return (a + b) >> 1;
//	return (a + ((b - a) >> 1));
//}
//&�����ã��ҳ���ͬ��λ
//^�����ã��ҳ���ͬ��λ
int average(int a, int b) {
	return (a & b) + ((a ^ b) >> 1);
}
int main() {
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	printf("%d\n", average(a, b));
	return 0;
}