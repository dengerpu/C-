#include<stdio.h>
#include<math.h>
int main() {
	int i, j,k;
	for (i = 100; i <=200; i++) {
		k = sqrt(i);
		for (j = 2; j < k; j++) {
			if (i % j == 0) {
				break;  //如果有除了1和本身，还有其他能被自身整除的就说明不是素数
			}
		}
		if (j == k) {
			printf("%d ", i);
		}
	}
	return 0;
}