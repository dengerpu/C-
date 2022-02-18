#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void qsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*))
//
//����
//base-- ָ��Ҫ���������ĵ�һ��Ԫ�ص�ָ�롣
//nitems-- �� base ָ���������Ԫ�صĸ�����
//size-- ������ÿ��Ԫ�صĴ�С�����ֽ�Ϊ��λ��
//compar-- �����Ƚ�����Ԫ�صĺ�����������ָ�루�ص�������
//�ص�������
//
//�ص���������һ��ͨ������ָ����õĺ���������Ѻ�����ָ�루��ַ����Ϊ�������ݸ���һ�������������ָ�뱻������������ָ��ĺ���ʱ����˵���ǻص�������[2]
//
//compar����
//
//compar����ָ��һ���Ƚ�����Ԫ�صĺ������ȽϺ�����ԭ��Ӧ��������������ע�������βα�����const void* �ͣ�ͬʱ�ڵ���compar ������comparʵ��Ϊ����ָ�룬���������ָ��ĺ���ҲΪcompar��ʱ�������ʵ��Ҳ����ת����const void* �͡���compar�����ڲ��Ὣconst void* ��ת����ʵ�����͡�
//
//int compar(const void* p1, const void* p2);
//
//���compar����ֵС��0�� < 0������ôp1��ָ��Ԫ�ػᱻ����p2��ָ��Ԫ�ص����棻
//	���compar����ֵ����0�� = 0������ôp1��ָ��Ԫ����p2��ָ��Ԫ�ص�˳��ȷ����
//	���compar����ֵ����0��> 0������ôp1��ָ��Ԫ�ػᱻ����p2��ָ��Ԫ�ص����档[2]
//
//	����
//	ʹ���������̽�������
//
//	˵��
//	�ú����������κ�ֵ��
struct Stu {
	char name[20];
	int age;
}*p;
int cmp_int(const void* e1, const void* e2) {
	return *(int *)e1 - *(int *)e2;
}
void test1() {
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);

	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int cmp_float(const void* e1, const void* e2) {
	/*if (*(float*)e1 > *(float*)e2) {
		return 1;
	}
	else if (*(float*)e1 == *(float*)e2) {
		return 0;
	}
	else {
		return -1;
	}*/

	return (int)(*(float*)e1 - *(float*)e2);
}
void test2() {
	float arr[] = { 9.0,8.0,7.0,6.0,5.0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_float);

	for (int i = 0; i < sz; i++) {
		printf("%f ", arr[i]);
	}
	printf("\n");
}
int cmp_stu_by_age(const void *e1,const void *e2){
	return ( (*(Stu *)e1).age  -  ((Stu *)e2)->age );
}
int cmp_stu_by_name(const void* e1, const void* e2) {
	//	//�Ƚ����־��ǱȽ��ַ���
//	//�ַ����Ƚϲ���ֱ����><=���Ƚϣ�Ӧ����strcmp����
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void test3() {
	struct Stu s[3] = { { "zhangsan", 20 }, { "lisi", 30 }, { "wangwu", 10 } };
	int sz = sizeof(s) / sizeof(s[0]);
	//qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);

}

//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//	//��һ���������������������Ԫ�ص�ַ
//	//�ڶ��������������������Ԫ�ظ���
//	//�����������������������ÿ��Ԫ�صĴ�С-��λ���ֽ�
//	//���ĸ��������Ǻ���ָ�룬�Ƚ�����Ԫ�ص����ú����ĵ�ַ-�������ʹ�����Լ�ʵ��
//	//           ����ָ������������ǣ����Ƚϵ�����Ԫ�صĵ�ַ
//	//
//}
//
////void qsort(void* base, 
////	       size_t num, 
////		   size_t width, 
////		   int( *cmp)(const void *e1, const void *e2)
////		   );
//
////ʵ��bubble_sort�����ĳ���Ա�����Ƿ�֪��δ���������������-��֪��
////�ǳ���ԱҲ��֪�������Ƚϵ�����Ԫ�ص�����

void swap( char* e1,  char* e2,int width) {
	for (int i = 0; i < width; i++) {
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
	
}

void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2)) {
	int i = 0, j = 0;
	for (i = 0; i < sz - 1; i++) {  //һ������sz-1��
		for (j = 0; j < sz - 1 - i; j++) {
			//����Ԫ�رȽ�
			if (    cmp((char*)base+j*width,(char*)base+(j+1)*width)  >0   ) {
				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
			}
		}
	}
}
void test4()
{
	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//ʹ��bubble_sort�ĳ���Աһ��֪���Լ��������ʲô����
	//��Ӧ��֪����αȽϴ����������е�Ԫ��
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test5() {
	struct Stu s[3] = { { "zhangsan", 20 }, { "lisi", 30 }, { "wangwu", 10 } };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	//bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}
int main() {
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}