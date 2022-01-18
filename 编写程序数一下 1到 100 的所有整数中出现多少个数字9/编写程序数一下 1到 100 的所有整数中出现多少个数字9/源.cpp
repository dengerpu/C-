#include<stdio.h>
int main() {
	int count = 0;
	for (int i = 1; i <= 100; i++) {
		if (i / 10 == 9) {
			printf("%d ", i);
			count++;
		}
		 if (i % 10 == 9) {
			printf("%d ", i);
			count++;
		}
	}
	printf("\n");
	printf("共有%d个数字9\n", count);

	return 0;
}