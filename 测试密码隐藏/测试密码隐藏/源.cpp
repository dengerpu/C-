#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
int main()
{
	char ch = {0};
	int i = 0;
	char a[20];
	printf("������������ݣ�");
	while (ch != '\r')
	{
		ch = _getch();             //��_getch()�������ַ�������ʾ����Ļ�� 
		if (ch == '\b')             //�������˸��ʱ��\bʱ������Ҫ�ÿո�������             
		{
			--i;
			printf("\b \b");      //�������˼����˵���Ѿ�������ַ���һ�����ÿո�\r�����棬���˻�һ����      
		}
		else if (ch == '\r')        //�������س���\rʱ�����Ǿ��˳�ѭ��        
			break;
		else
		{
			printf("#");         //ÿ����һ�ξ���ʾһ��#
			a[i++] = ch;           //���ոյ��ַ������ַ�������           
		}
	}
	printf("\n");
	return 0;
}