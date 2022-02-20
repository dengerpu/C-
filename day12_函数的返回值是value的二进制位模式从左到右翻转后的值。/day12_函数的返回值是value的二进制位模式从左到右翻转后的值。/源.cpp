#define _CRT_SECURE_NO_WARNINGS
//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值是value的二进制位模式从左到右翻转后的值。
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
#include<stdio.h>
#include<math.h>
//unsigned int reverse_bit(unsigned int value) {
//	int ret = 0;
//	int bit = 0;
//	int i;
//	for (i = 0; i < 32; i++) {
//		//ret =0
//		ret = ret << 1;  //左移一位，保存前一位
//		bit = value & 1; // 取出最后一位
//		value = value >> 1; //值右移，取下一位
//		ret = bit | ret;  //最后一位赋给ret
//	}
//	return ret;
//}
/*
循环拿出二进制的每一位（右移按位与1得到）
*/
//unsigned int reverse_bit(unsigned int value) {
//	int i = 0;
//	unsigned int ret = 0;
//	for (i = 0; i < 32; i++) {
//		//ret += ((value >> i) & 1) * pow(2, 31 - i);  这样计算量太大
//		ret += ((value >> i) & 1) << (31 - i); 
//	}
//	return ret;
//}
unsigned int reverse_bit(unsigned int value) {
	unsigned int sum = 0;
	int arr[32], a = 0;
	int count1 = 0, i = 0;
	for (i = 0; i < 32; i++) {
		a = (value>>i) & 1;  //得到二进制形式的每一位
		arr[i] = a;
	}
	printf("输入值的二进制序列为：\n");
	for (i = 31; i >= 0; i--) {   //逆序输出
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