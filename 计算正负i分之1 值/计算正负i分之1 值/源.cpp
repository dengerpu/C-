#include<stdio.h>
int main() {

	double sum = 0;
	int flag = 1;
	for (int i = 1; i <= 100; i++) {
		sum += flag * (1.0 / i);
		flag = -flag;
	}

	printf("1/1-1/2+1/3+.....-1/99+1/100µÄÖµÎª£º%lf\n", sum);

	return 0;
}