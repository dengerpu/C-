#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main() {
//	//�ַ�ָ��
//	char ch = 'w';
//	char* p = &ch;
//	const char* p2 = "abcdef";
//	//ָ������-����-���ָ�������
//	int* arr[10];
//	char* ch[5];
//	//����ָ��  -ָ������
//	int* p3; //����ָ��  - ָ�����ε�ָ��
//	char* p4;  //�ַ�ָ�� -ָ���ַ���
//	int arr2[5];  //����
//	int(*pa)[5] = &arr2; //ȡ������ĵ�ַ��pa����һ������֯��
//
//	int(*paa[10])[5];
//
//	return 0;

//
//void test(int arr[3][5])
//{}
//void test1(int arr[][5])
//{}
//void test2(int arr[3][])//err
//{}
//
//void test3(int* arr) //err
//{}
//
//void test4(int **arr) //err
//{}
//
//void test5(int (*arr)[5])
//{}
//
//int main()
//{
//	int arr[3][5] = { 0 };
//
//	//test(arr);//��ά���鴫��
//	//test1(arr);
//	//test2(arr);
//	test3(arr);
//	test4(arr);
//	test5(arr);
//
//	return 0;
//}

//void test1(int* p)
//{
//}
//
//void test2(char*p)
//{}
//
//int main()
//{
//	int a = 10;
//	int* p1 = &a;
//	test1(&a);//ok
//	test1(p1);//ok
//
//	char ch = 'w';
//	char* pc = &ch;
//	test2(&ch);//ok
//	test2(pc);//ok
//	return 0;
//}

//void test(int **p)
//{}
//
//int main()
//{
//	int *ptr;
//	int** pp = &ptr;
//	test(&ptr);
//	test(pp);
//	int* arr[10];//
//	test(arr);//ָ������Ҳ����
//
//	return 0;
//}
//����ָ�� - ��ָ�������ָ��
//����ָ�� - ��ָ������ָ�� - ��ź�����ַ��һ��ָ��
//

//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	//int arr[10] = { 0 };
//	//int (*p)[10] = &arr;
//
//	//arr;
//	//printf("%d\n", Add(a, b));
//
//	//&������ �� ������ ���Ǻ����ĵ�ַ
//	/*
//	printf("%p\n", &Add);
//	printf("%p\n", Add);
//	*/
//
//	int (*p)(int, int) = Add;
//	printf("%d", p(2, 3));
//	printf("%d", (*p)(2, 3));
//
//	return 0;
//}

//void Print(const char *str){
//	printf("%s\n", str);
//}
//int main() {
//	void (*p)(const char*) = Print;
//	(*p)("hello bit");
//	p("hello");
//	return 0;
//}

//signal��һ����������
//signal�����Ĳ�����2������һ����int��
// �ڶ����Ǻ���ָ�룬�ú���ָ��ָ��ĺ����Ĳ�����int,����������void
//signal�����ķ�������Ҳ��һ������ָ�룺�ú���ָ��ָ��ĺ����Ĳ�����int,����������void
// 
//
void(* signal(int, void(*)(int)))(int);

typedef void(*pfun_t)(int) ;
pfun_t signal(int, pfun_t);

//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	int(*pa)(int, int) = Add;
//	printf("%d\n", pa(2, 3));
//	printf("%d\n", Add(2, 3));
//
//	//printf("%d\n", *pa(2, 3));//err
//
//	printf("%d\n", (*pa)(2, 3));
//
//	return 0;
//}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}

int main()
{
	//ָ������
	//int* arr[5];//
	//��Ҫһ�����飬���������Դ��4�������ĵ�ַ - ����ָ�������
	int (*pa)(int, int) = Add;//Sub/Mul/Div

	int(*parr[4])(int, int) = {Add, Sub, Mul, Div};//����ָ�������
	
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", parr[i](2, 3));//5 -1 6 0
	}

	return 0;
}