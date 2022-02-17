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
	printf("****1.�ӷ� 2.����****\n");
	printf("****3.�˷� 4.����****\n");
	printf("********0.�˳�*******\n");
	printf("*********************\n");
}

//int main() {
//	int x, y, input;
//	
//	//menu();
//	/*do {
//		printf("��ѡ��\n");
//		scanf("%d", &input);
//
//		switch (input) {
//		case 1: 		
//			printf("������������\n");
//			scanf("%d %d", &x, &y); 
//			printf("%d\n", Add(x, y)); 
//			break;
//		case 2: 
//			printf("������������\n");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", Sub(x, y)); break;
//		case 3: 
//			printf("������������\n");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", Mul(x, y)); break;
//		case 4: 
//			printf("������������\n");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", Div(x, y)); break;
//		default:printf("�����������������\n"); scanf("%d", &input); break;
//		}
//	} while (input);*/
//
//
//	return 0;
//}

//int main() {
//	int (*p)(int, int);//����ָ��
//	int (*parr[4])(int, int) = {Add,Sub,Mul,Div};//��������ָ��
//	for (int i = 0; i < 4; i++) {
//		printf("%d\n", parr[i](1, 2));
//	}
//	return 0;
//}
void Calc(int (*pf)(int, int)) {
	int x, y;
	printf("������������\n");
	scanf("%d %d", &x, &y);
	printf("%d\n", pf(x, y));
}

//int main() {
//		int input = 0;
//
//	do
//	{
//		menu();
//		printf("��ѡ��:>");
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
//			printf("�˳�\n");
//			break;
//		default:
//			printf("ѡ�����\n");
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
	
		//pfArr ��һ������ָ������ - ת�Ʊ�
		int(*pfArr[])(int, int) = {0, Add, Sub, Mul, Div, Xor};
		do
		{
			menu();
			printf("��ѡ��:>");
			scanf("%d", &input);
			if (input >= 1 && input <= 5)
			{
				printf("����������������:>");
				scanf("%d%d", &x, &y);
				int ret = pfArr[input](x, y);
				printf("%d\n", ret);
			}
			else if (input == 0)
			{
				printf("�˳�\n");
			}
			else
			{
				printf("ѡ�����\n");
			}
		} while (input);

}