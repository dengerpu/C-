#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
////
//int main()
//{
//	//���ڴ�����10�����εĿռ�
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		//��ӡ����ԭ���һ����ʽ
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//����ʹ�ÿռ�
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//����̬����Ŀռ䲻��ʹ�õ�ʱ��
//	//��Ӧ�û�������ϵͳ
//	free(p);
//	p = NULL;//
//
//	return 0;
//}
//int main() {
//	int* p = (int*)malloc(5 * sizeof(int));
//	int i = 0;
//	if (p != NULL) {
//		for (i = 0; i < 5; i++) {
//			*(p + i) = i;
//		}
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//	
//	int* pr = (int *)calloc(5, sizeof(int));  //�����Լ�����
//	if (pr != NULL) {
//		for (i = 0; i < 5; i++) {
//			*(pr + i) = i;
//		}
//	}
//	for (i = 0; i < 5; i++)
//				{
//					printf("%d ", *(pr + i));
//				}
//	printf("\n");
//	
//	free(p);
//	printf("%p", p);
//	p = NULL;
//	free(pr);	//�ͷſռ�
////	//free�����������ͷŶ�̬���ٵĿռ��
//	printf("%p", pr);
//	pr = NULL;
//
//
//	return 0;
//}


//int main() {
//	int* p = (int*)calloc(5, sizeof(int));   //���ʼ��Ϊ0
//	for (int i = 0; i < 5; i++) {
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}


//realloc
//������̬�����ڴ�ռ�Ĵ�С
//reallocʹ�õ�ע�����
//1. ���pָ��Ŀռ�֮�����㹻���ڴ�ռ����׷�ӣ���ֱ��׷�ӣ��󷵻�p
///2. ���pָ��Ŀռ�֮��û���㹻���ڴ�ռ����׷�ӣ���realloc������������һ���µ��ڴ�����
///  ����һ����������Ŀռ䣬���Ұ�ԭ���ڴ��е����ݿ����������ͷžɵ��ڴ�ռ�
//  ��󷵻��¿��ٵ��ڴ�ռ��ַ
//3. ����һ���µı���������realloc�����ķ���ֵ
//int main() {
//	int* p = (int*)malloc(5 * sizeof(int));
//	if (p != NULL) {
//		for (int i = 0; i < 5; i++) {
//			*(p + i) = i;
//			}
//	}
//	else {
//		printf("%s\n", strerror(errno));
//	}
//
//	//�ٷ���5���ռ�
//	int* pr = (int*)realloc(p, 5 * sizeof(int));
//	if (pr != NULL) {
//		p = pr;
//		for (int i = 5; i < 10; i++) {
//			*(p + i) = i;
//		}
//		for (int i = 0; i < 10; i++) {
//			printf("%d ", *(p + i));
//		}
//	}
//	else {
//		printf("%s\n", strerror(errno)); //��ӡ������Ϣ
//	}
//	free(p);
//	p = NULL;
//		
//
//	return 0;
//}


//
//int main().
//{
//	int *p = (int*)malloc(20);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			*(p + i) = i;
//		}
//	}
//	//������ʹ��malloc���ٵ�20���ֽڿռ�
//	//�������20�����ֽڲ����������ǵ�ʹ����
//	//ϣ�������ܹ���40���ֽڵĿռ�
//	//����Ϳ���ʹ��realloc��������̬���ٵ��ڴ�
//	//
//	//reallocʹ�õ�ע�����
//	//1. ���pָ��Ŀռ�֮�����㹻���ڴ�ռ����׷�ӣ���ֱ��׷�ӣ��󷵻�p
//	//2. ���pָ��Ŀռ�֮��û���㹻���ڴ�ռ����׷�ӣ���realloc������������һ���µ��ڴ�����
//	//  ����һ����������Ŀռ䣬���Ұ�ԭ���ڴ��е����ݿ����������ͷžɵ��ڴ�ռ�
//	//  ��󷵻��¿��ٵ��ڴ�ռ��ַ
//	//3. ����һ���µı���������realloc�����ķ���ֵ
//	//
//	int*ptr =(int *) realloc(p, 20);
//
//	if (ptr != NULL)
//	{
//		p = ptr;
//		int i = 0;
//		for (i = 5; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//
//	//�ͷ��ڴ�
//	free(p);
//	p = NULL;
//
//	return 0;
//}
//int main()
//{
//	//1. ��NULL���н����ò���
//	//int *p = (int*)malloc(40);
//	////��һmallocʧ���ˣ�p�ͱ���ֵΪNULL
//	//*p = 0;//err
//
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	*(p + i) = i;//err
//	//}
//	//free(p);
//	//p = NULL;
//	//2. �Զ�̬���ٵ��ڴ��Խ�����
//	//int *p = (int*)malloc(5 * sizeof(int));
//	//if (p == NULL)
//	//{
//	//	return 0;
//	//}
//	//else
//	//{
//	//	int i = 0;
//	//	for (i = 0; i < 10; i++)
//	//	{
//	//		*(p + i) = i;
//	//	}
//	//}
//	////
//	//free(p);
//	//p = NULL;
//
//
//	int a = 10;
//	int* p = &a;
//	*p = 20;
//	//3. �ԷǶ�̬�����ڴ��free
//	free(p);
//	p = NULL;
//
//	return 0;
//}

#include <windows.h>
//
//int main()
//{
//	//1. ��NULLָ������ò���
//	int *p = (int *)malloc(40);
//	//p������ص��ж�
//	*p = 10;//malloc���ٿռ�ʧ��-��NULLָ�������
//
//	//2.�Զ�̬�����ڴ��Խ�����
//	int *p = (int*)malloc(40);//10��int 0-9
//	if (p == NULL)
//	{
//		return 0;
//	}
//	int i = 0;
//	//Խ��
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;
//	}
//
//	free(p);
//	p = NULL;
//
//	//3. �ԷǶ�̬�����ڴ�ʹ��free�ͷ�
//	int a = 10;
//	int *p = &a;
//	//...
//	//�ԷǶ�̬�����ڴ�ʹ��free�ͷ�
//	free(p);
//	p = NULL;
//
////	4. ʹ��free�ͷŶ�̬�����ڴ��һ����
//	int*p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		*p++ = i;  //p�Ѿ�ָ���6��Ԫ�ص��׵�ַ��
//	}
//	//���տռ�
//	// ʹ��free�ͷŶ�̬�����ڴ��һ����
//	free(p);
//	p =NULL;
//
//	//5.��ͬһ�鶯̬�ڴ�Ķ���ͷ�
//	int *p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	//ʹ��
//	//�ͷ�
//	free(p);
//	p = NULL;
//
//	free(p);
//
//	//6.��̬�����ڴ������ͷţ��ڴ�й©��
//	while (1)
//	{
//		malloc(1);
//	}
//
//
//	return 0;
//}

//
//void GetMemory(char *p)//�β�ֻ����ʱ����һ��
//{
//	p = (char *)malloc(100);
//}
//
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(str);  //����ֵ��ȥ�����Բ����ַ���ᱻ������
//	strcpy(str, "hello world");
//	printf(str);  //�Ƿ������ڴ�
//}
//
//int main()
//{
//	Test();
//
//	//char*str = "abcdef";
//	//printf("%s\n", str);
//	//printf(str);
//	//printf("abcdef");
//
//	return 0;
//}

//����1
//void GetMemory(char **p)
//{
//	*p = (char *)malloc(100);
//}
//
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str);  //��ַ����ȥ
//	strcpy(str, "hello world");
//	printf(str);
//
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

////����2
//char * GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);  //��ַ����ȥ
//	strcpy(str, "hello world");
//	printf(str);
//
//	free(str);
//	str = NULL;
//}

//int main()
//{
//	Test();
//	return 0;
//}

//char *GetMemory(void)
//{
//	char p[] = "hello world";  //�ֲ�����ʹ���꣬��ջ����
//								//�ڴ�ᱻ�ͷŵ�
//	return p;
//}
//
//void Test(void)
//{
//	char *str = NULL;
//	str = GetMemory();
//	printf(str);  //�Ƿ������ڴ棬���ֵ
//}
//
//int main()
//{
//	Test();
//	return 0;
//}
//
//int* test()
//{
//	//static int a = 10;//��̬��  �����ڴ治�ᱻ�ͷ�
//	int a = 10;//ջ�� 
//	return &a;
//}
//
//int main()
//{
//	int*p = test();
//	*p = 20;//
//	printf("%d\n", *p);
//	return 0;
//}

//int* test()
//{
//	int *ptr = malloc(100);//����  ���������겻���Լ��ͷ�
//	return ptr;
//}
//
//int main()
//{
//	int *p = test();
//
//	return 0;
//}

//void GetMemory(char **p, int num)
//{
//	*p = (char *)malloc(num);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	//��
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//
//void Test(void)
//{
//	char *str = (char *)malloc(100);
//	strcpy(str, "hello");
//	free(str);//free�ͷ�strָ��Ŀռ�󣬲������str��ΪNULL
//	//str = NULL;
//
//	if (str != NULL)
//	{
//		strcpy(str, "world"); //����Ƿ�������
//		printf(str);
//	}
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}
