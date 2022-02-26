#define _CRT_SECURE_NO_WARNINGS
//声明一个结构体类型
#include<stdio.h>
//struct Stu {
//	char name[20];
//	char tele[12];
//	int age;
//}s1,s2,s3;  //全局变量
//struct Stu s4;  //全局变量
//struct    //匿名结构体类
//{
//	int a;
//	char c;
//}sa,*pa;
//
//
//
//struct
//{
//	int a;
//	char c;
//}* psa;
//int main() {
//	//psa = &sa;   //这两个不一样。
//	pa = &sa;//对
//}
////结构体的自引用
//struct Node
//{
//	int data;//4
//	struct Node* next;//4/8
//};
//
//typedef struct Node
//{
//	double d;
//	int data;//4
//	struct Node* next;//4/8
//}Node;
//
//int main()
//{
//	struct Node n1;
//	Node n2;
//
//	return 0;
//}

//struct T
//{
//	double weight;
//	short age;
//};
//
//struct S
//{
//	char c;
//	struct T st;
//	int a;
//	double d;
//	char arr[20];
//};
//int main()
//{
//	//struct S s = {'c', 100, 3.14, "hello bit"};
//	struct S s = { 'c', {55.6, 30}, 100, 3.14, "hello bit" };
//
//	printf("%c %d %lf %s\n", s.c, s.a, s.d, s.arr);
//	printf("%lf\n", s.st.weight);
//
//
//	return 0;
//}
//
//struct S1
//{
//	char c1;//1    1/8  1
//	int a;//4      +3  4/8   4 
//	char c2;//1    
//};
//
//struct S2
//{
//	char c1;
//	char c2;
//	int a;
//};
//
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//
//struct S4
//{
//	char c;
//	struct S3 s3;
//	double d;
//};
//int main() {
//	struct S1 s1 = { 0 };
//	printf("%d\n", sizeof(s1));  //12
	//	//struct S2 s2 = { 0 };
//	//printf("%d\n", sizeof(s2));//?
//	//struct S3 s3;
//	//printf("%d\n", sizeof(s3));
//	struct S4 s4;
//	printf("%d\n", sizeof(s4));
//}

//设置默认对齐数位4
//#pragma pack(4)
//struct S
//{
//	char c1;//1
//	//3
//	double d;//8 4 4
//};
//#pragma pack()
//取消设置的默认对齐数


//设置默认对齐数位1
//#pragma pack(1)
//struct S
//{
//	char c1;//1
//	//3
//	double d;//8 4 4
//};
//#pragma pack()
//取消设置的默认对齐数

//int main()
//{
//	struct S s;
//	printf("%d\n", sizeof(s));//
//
//	return 0;
//}
//#include<stddef.h>
//struct S
//{
//	char c; //1  1/8 1 偏移量0
//	int i;//4  4/8  4   偏移量4
//	double d;//8 8/8 8   偏移量8
//};
//
//int main()
//{
//	//offsetof();
//	printf("%d\n", offsetof(struct S, c));
//	printf("%d\n", offsetof(struct S, i));
//	printf("%d\n", offsetof(struct S, d));
//
//	return 0;
//}

//struct S
//{
//	int a;
//	char c;
//	double d;
//};
//
//void Init(struct S* ps)
//{
//	ps->a = 100;
//	ps->c = 'w';
//	ps->d = 3.14;
//}
//
////传值
//void Print1(struct S tmp)
//{
//	printf("%d %c %lf\n", tmp.a, tmp.c, tmp.d);
//}
//
////传址
//void Print2(const struct S* ps)
//{
//	printf("%d %c %lf\n", ps->a, ps->c, ps->d);
//}
//
//int main()
//{
//	struct S s = {0};
//	Init(&s);
//	Print1(s);
//	Print2(&s);
//
//	/*s.a = 100;
//	s.c = 'w';
//	s.d = 3.14;
//
//	printf("%d\n", s.a);*/
//	return 0;
//}
//struct S {
//	int a;
//	char c;
//	double d;
//};
//void Init(struct S* p) {
//	p->a = 100;
//	(*p).c = 'a';
//	p->d = 1;
//}
//int main() {
//	struct S s1;
//	Init(&s1);
//	printf("%d\n %c\n %lf\n", s1.a, s1.c, s1.d);
//}

//
//位段 - 二进制位
//

//struct S
//{
//	int a : 2;  //比特位
//	int b : 5;
//	int c : 10;
//	int d : 30;
//};
////
//////47bit - 6个字节*8 = 48bit
////
//int main()
//{
//	struct S s;
//
//	printf("%d\n", sizeof(s));//8个字节
//
//	return 0;
//}
//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//
//int main()
//{
//	struct S s = {0};
//
//	s.a = 10;
//	s.b = 20;
//	s.c = 3;
//	s.d = 4;
//
//
//	return 0;
//}
//enum Sex {
//	male,//0
//	female//1
//};
//enum Color
//{
//	RED,//0
//	GREEN,//1
//	BLUE//2
//};
//int main()
//{
//	enum Sex s = male;
//
//	int color = RED;
//
//	printf("%d %d %d\n", RED, GREEN, BLUE);
//
//	printf("%d %d s\n", male, female);
//
//
//	return 0;
//
//}
//联合-联合体-共用体

//union Un
//{
//	char c;//1
//	int i; //4
//};
////5个字节
//
//int main()
//{
//	union Un u;
//	printf("%d\n", sizeof(u));//4
//
//	printf("%p\n", &u);
//
//	printf("%p\n", &(u.c));
//	printf("%p\n", &(u.i));
//
//	return 0;
//}
//
//enum Sex
//{
//	MALE,
//	FEMALE,
//	SECRET
//};
//
//int main()
//{
//	enum Sex s = MALE;
//	printf("%d\n", sizeof(s));
//
//	return 0;
//}

//
union Un
{
	int a;//4 8 4
	char arr[5];//5 1 8 1
};

int main()
{
	union Un u;
	printf("%d\n", sizeof(u));  //8

	return 0;
}
