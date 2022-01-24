#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void swap1(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;

}
void swap2(int* a, int* b) {
	*a = *a + *b;
	*b = *a - *b;  //b变成原来的a
	*a = *a - *b;
}
void swap3(int* a, int* b) {
	 *a = (*a) ^ (*b);
	 *b = (*a) ^ (*b);
	 *a = (*a) ^ (*b);
}
int main() {
	int a = 5, b = 3;
	//swap1(&a, &b);
	//swap2(&a, &b);
	swap3(&a, &b);
	printf("a=%d,b=%d\n",a,b);
	return 0;
}