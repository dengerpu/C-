#include <stdio.h>
int main() {//不创建零时变量交换

		int a = 1;
		int b = 3;
		a = a + b;
		b = a - b;
		a = a - b;



		//a ^= b;
		//b ^= a;
		//a ^= b;
		printf("a=%d,b=%d", a, b);
	return 0;
}