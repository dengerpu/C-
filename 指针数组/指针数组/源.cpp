#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//ָ������ �����飬�������ָ���
//
//int main()
//{
//	int arr[10] = {0};//��������
//	char ch[5] = { 0 };//�ַ�����
//	int* parr[4];//�������ָ������� - ָ������
//	char* pch[5];//����ַ�ָ������� - ָ������
//
//	return 0;
//}
//
//int main() {
//	int arr[10] = { 0 };
//	printf("arr = %p\n", arr);  //������Ԫ�صĵ�ַ
//	printf("&arr = %p\n", &arr);//����ĵ�ַ
//	printf("arr+1 = %p\n", arr+1);
//	printf("&arr+1 = %p\n", &arr+1);
//
//	return 0;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int d = 40;
//	int* arr[4] = {&a, &b, &c, &d};  //ָ������
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d ", *(arr[i]));
//	}
//	return 0;
//}

//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[] = { 2, 3, 4, 5, 6 };
//	int arr3[] = { 3, 4, 5, 6, 7 };
//	
//	int* p[3] = { arr1,arr2,arr3 };
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			printf("%d ", *(p[i] + j));
//		}
//		printf("\n");
//
//	}
//	return 0;
//}

//
//����ָ��- ָ��
//
//
//int main()
//{
//	//int *p = NULL; //p������ָ�� - ָ�����ε�ָ�� - ���Դ�����εĵ�ַ
//	//char* pc = NULL;//pc���ַ�ָ�� - ָ���ַ���ָ�� - ���Դ���ַ��ĵ�ַ
//	               //����ָ�� - ָ�������ָ�� - �������ĵ�ַ
//	//int arr[10] = {0};
//	//arr- ��Ԫ�ص�ַ
//	//&arr[0] -��Ԫ�صĵ�ַ
//	//&arr - ����ĵ�ַ
//
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int (*p)[10] = &arr;//����ĵ�ַҪ������
//	//�����p��������ָ��
//
//	return 0;
//}

//int main()
//{
//	char* arr[5];
//	char* (*pa)[5] = &arr;//
//
//	int arr2[10] = { 0 };
//	int (*pa2)[10] = &arr2;
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int *p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	int (*pa)[10] = &arr;
//	 i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(*pa + i));//*pa == arr
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", (*pa)[i]);
//	}
//	
//	return 0;
//}


//�������������ʽ
void print1(int arr[3][5], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//������ָ�����ʽ
void print2(int(*p)[5], int x, int y)
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j < y; j++)
		{
			printf("%d ", p[i][j]);
			//printf("%d ", *(p[i] + j));
			//printf("%d ", *(*(p + i) + j));
			//printf("%d ", (*(p + i))[j]);
		}
		printf("\n");
	}
}


int main()
{
	int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };

	//print1(arr, 3, 5);//arr - ������ - ������������Ԫ�ص�ַ
	print2(arr, 3, 5);//
	//int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	//int i = 0;
	//int* p = arr;
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d ", p[i]);
	//	printf("%d ", *(p + i));
	//	printf("%d ", *(arr + i));
	//	printf("%d ", arr[i]);//arr[i] == *(arr+i) == *(p+i) == p[i]
	//}
	return 0;
}