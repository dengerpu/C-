#include <stdio.h>
int main() {//��������ʱ��������

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