#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ������
	//���磺2+22+222+2222+22222
	int a, sum=0,n,sum2=0,b;
	scanf("%d", &a);
	n = a;
	for (int i = 1; i <= 5; i++) {
		a = n;
		if (i != 1) {
			for (int j = 1; j < i; j++) {
				a = a * 10 + n;
				//printf("%d ", a);
			}
			printf("+%d", a);
			sum += a;
		}
		else {
			printf("sum=%d", a);
			sum += a;
		}	
	}
	printf("\n%d\n", sum);

	//����
	b = 0;
	for (int i = 0; i < 5; i++) {
		b = b * 10 + n;
		printf("%d ", b);
		sum2 += b;
	}
	printf("\n%d\n", sum2);
	return 0;
}