#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int Add(int x, int y) {
	return x + y;
}
int Sub(int x, int y) {
	return x - y;
}
int Mul(int x, int y) {
	return x * y;
}
int Div(int x, int y) {
	return x / y;
}
int Xor(int x, int y)
{
	return x ^ y;
}

void menu() {
	printf("*********************\n");
	printf("****1.加法 2.减法****\n");
	printf("****3.乘法 4.除法****\n");
	printf("********0.退出*******\n");
	printf("*********************\n");
}

//int main() {
//	int x, y, input;
//	
//	//menu();
//	/*do {
//		printf("请选择\n");
//		scanf("%d", &input);
//
//		switch (input) {
//		case 1: 		
//			printf("请输入两个数\n");
//			scanf("%d %d", &x, &y); 
//			printf("%d\n", Add(x, y)); 
//			break;
//		case 2: 
//			printf("请输入两个数\n");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", Sub(x, y)); break;
//		case 3: 
//			printf("请输入两个数\n");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", Mul(x, y)); break;
//		case 4: 
//			printf("请输入两个数\n");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", Div(x, y)); break;
//		default:printf("输入错误，请重新输入\n"); scanf("%d", &input); break;
//		}
//	} while (input);*/
//
//
//	return 0;
//}

//int main() {
//	int (*p)(int, int);//函数指针
//	int (*parr[4])(int, int) = {Add,Sub,Mul,Div};//函数数组指针
//	for (int i = 0; i < 4; i++) {
//		printf("%d\n", parr[i](1, 2));
//	}
//	return 0;
//}
void Calc(int (*pf)(int, int)) {
	int x, y;
	printf("请输入两个数\n");
	scanf("%d %d", &x, &y);
	printf("%d\n", pf(x, y));
}

//int main() {
//		int input = 0;
//
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}

int main() {
	int input = 0;
		int x = 0;
		int y = 0;
	
		//pfArr 是一个函数指针数组 - 转移表
		int(*pfArr[])(int, int) = {0, Add, Sub, Mul, Div, Xor};
		do
		{
			menu();
			printf("请选择:>");
			scanf("%d", &input);
			if (input >= 1 && input <= 5)
			{
				printf("请输入两个操作数:>");
				scanf("%d%d", &x, &y);
				int ret = pfArr[input](x, y);
				printf("%d\n", ret);
			}
			else if (input == 0)
			{
				printf("退出\n");
			}
			else
			{
				printf("选择错误\n");
			}
		} while (input);

}