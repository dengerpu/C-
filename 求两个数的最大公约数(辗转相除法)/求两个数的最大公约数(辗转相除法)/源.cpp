#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    int a, b;
    int t;
    scanf("%d %d", &a, &b);
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
        printf("a=%d b=%d t=%d\n", a, b, t);
    }
    printf("���Լ����%d\n", a);
    return 0;
}