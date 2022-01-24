#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void MulipicationformatTable(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d * %d = %-2d  ", i, j, i * j);
		}
		printf("\n");
	}
}
int main() {
	int n;
	scanf("%d", &n);
	MulipicationformatTable(n);
	return 0;
}