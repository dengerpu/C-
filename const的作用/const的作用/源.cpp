#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void test1() {
	int n = 10, m = 20;
	int* p = &n;
	*p = 20;
	p = &m;
}
void test2() {
	int n = 10, m = 20;
	const int* p = &n;
	*p = 20;  //�����Ǵ���� const�������������ε���ָ��ָ�������
	p = &m;		//ָ��ָ������ݲ����Ըı䣬����ָ�������������ݿ��Ըı�
}
void test3() {
	int n = 10, m = 20;
	 int* const p = &n;
	*p = 20;  
	p = &m;//�����Ǵ���� const��������ұ����ε���ָ���������ָ����������ݲ��ɸ���
	//����ָ��ָ������ݿ��Ը�
}

void test4() {
	int n = 10, m = 20;
	const int* const p = &n;  //���ϸ�ָ����������ɸģ�ָ�������Ҳ�����Ը�
	*p = 20;
	p = &m;
}

int main() {


	return 0;
}