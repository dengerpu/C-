#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//������������ˮ��1��Ǯ������һƿ��ˮ��������ƿ���Ի�һƿ��ˮ��
//�ʣ���20����ܺȶ���ƿ��ˮ
int main() {
	int money = 0, total = 0, empty = 0;
	scanf("%d", &money);
	total = money/1;
	empty = total;
	while (empty >= 2) {
		total += empty / 2;
		empty = empty / 2+empty%2;
	} 
	printf("%d \n", total);
	
}