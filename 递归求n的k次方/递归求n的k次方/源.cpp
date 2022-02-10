#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
double pow(int n, int k) {
	if (k < 0) {
		return 1 / pow(n, -k);
	}
	else if (k == 0)
		return 1;
	else
		return n * pow(n, k - 1);
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%lf\n", pow(n, k));

	return 0;
}