#define _CRT_SECURE_NO_WARNINGS
//struct S
//{
//	int n;
//	int arr[10];
//};
//
//struct S
//{
//	int n;
//	int arr[];//δ֪��С��  //Ӧ�÷��������
//};    //��С��4���ֽ�
#include<stdlib.h>
#include<stdio.h>
//struct S
//{
//	int n;
//	int arr[0];//δ֪��С��-���������Ա-����Ĵ�С�ǿ��Ե�����
//};
//int main() {
//	struct S* s = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	s->n = 100;
//	for (int i = 0; i < 5; i++)
//	{
//		s->arr[i] = i;//0 1 2 3 4
//	}
//	struct S* ptr = (struct S*)realloc(s, 44);
//	if (ptr != NULL) {
//		s = ptr;
//	}
//	for (int i = 5; i < 10; i++) {
//		s->arr[i] = i;
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", s->arr[i]);
//	}
//}

struct S {
	int n;
	int* arr;
};   //��С8���ֽ�
int main() {
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	ps->arr = (int*)malloc(sizeof(int) * 5);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
	//������С
	int* ptr = (int *)realloc(ps->arr, sizeof(int) * 5);
	if (ptr != NULL) {
		ps->arr = ptr;
	}
	for (i = 5; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	//�ͷ��ڴ�
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
}