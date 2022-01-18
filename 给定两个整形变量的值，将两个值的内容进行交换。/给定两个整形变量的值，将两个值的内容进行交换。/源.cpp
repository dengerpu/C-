#include<stdio.h>
void swap(int *a, int *b) {
	int* c;
	c = a;
	a = b;
	b = c;
	printf("%d %d", *a, *b);
}
int main() {
	int a = 3;
	int b = 5;
	//swap(&a, &b);

	//a = a + b;
	//b = a - b;
	///a = a - b;

	a ^= b;
	b ^= a;
	a ^= b;


	printf("a=%d,b=%d\n", a, b);
	return 0;
}