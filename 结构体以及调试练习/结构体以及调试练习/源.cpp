#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//struct 结构体关键字 Stu结构体标签  struct Stu 结构体类型
//struct Stu {
//	//成员变量
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//}s1,s2,s3;  //s1,s2,s3是三个全局的结构体变量
//
//typedef struct Stu {
//	//成员变量
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//
//}Stu;  //结构体类型重命名
//int main() {
//	Stu s4 = { "张三", 20, "15249287076", "男" };//局部变量
//	//struct Stu s5 = { "旺财", 30, "15596668862", "保密" };
//
//	printf("%s\n", s4.name);
//	/*printf("%s\n", s5.name);*/
//
//	return 0;
//}


////结构体嵌套
//struct S
//{
//	int a;
//	char c;
//	char arr[20];
//	double d;
//};
//
//struct T
//{
//	char ch[10];
//	struct S s;
//	char *pc;
//};
//
//int main()
//{
//	char arr[] = "hello bit\n";
//	struct T t = { "hehe", {100, 'w', "hello world", 3.14}, arr};
//	printf("%s\n", t.ch);//hehe
//	printf("%s\n", t.s.arr);//hello world
//	printf("%lf\n", t.s.d);//3.14
//	printf("%s\n", t.pc);//hello bit
//
//
//	return 0;
//}



//typedef struct Stu
//{
//	//成员变量
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//}Stu;
//
//
//void Print1(Stu tmp)  //局部变量是拷贝一份
//{
//	printf("name: %s\n", tmp.name);
//	printf("age:  %d\n", tmp.age);
//	printf("tele: %s\n", tmp.tele);
//	printf("sex:  %s\n", tmp.sex);
//}
//
//void Print2(Stu* ps)
//{
//	printf("name: %s\n", ps->name);
//	printf("age : %d\n", ps->age);
//	printf("tele: %s\n", ps->tele);
//	printf("sex : %s\n", ps->sex);
//}
//
//int main()
//{
//	Stu s = { "李四", 40, "15598886688", "男" };
//	//打印结构体数据
//	//Print1 和Print2 哪个更好？
//	Print1(s);
//	Print2(&s);
//
//	return 0;
//}

//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret = 0;
//	ret = Add(a, b);
//	printf("%d\n", ret);
//	return 0;
//}

//
//int main()
//{
//	{
//		int tmp = 0;
//		printf("tmp = %d\n", tmp);
//	}
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//	
//	return 0;
//}

//void test2()
//{
//	printf("hehe\n");
//}
//void test1()
//{
//	test2();
//}
//void test()
//{
//	test1();
//}
//int main()
//{
//	test();
//	return 0;
//}

int main()
{
	int i = 0;
	int sum = 0;//保存最终结果
	int n = 0;
	int ret = 1;//保存n的阶乘
	scanf("%d", &n);//3 1!+2!+3! = 1+2+6=9 
	for (i = 1; i <= n; i++)
	{
		int j = 0;
		ret = 1;
		for (j = 1; j <= i; j++)
		{
			ret *= j;
		}
		sum += ret;
	}
	printf("%d\n", sum);
	return 0;
}