#include<stdio.h>
int main() {
	int a = 5,b=2,c=3;
	int t;
	if (a < b) {
		t = a;
		a = b;
		b = t;
	}
	if (a < c) {
		t = a;
		a = c;
		c = t;
	}
	if (b < c) {
		t = b;
		b = c;
		c = t;

	}
	printf("%d ,%d ,%d\n", a, b, c);

	return 0;
}