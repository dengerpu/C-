#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
int main()
{
	char ch = {0};
	int i = 0;
	char a[20];
	printf("请输入你的内容：");
	while (ch != '\r')
	{
		ch = _getch();             //用_getch()函数，字符不会显示在屏幕上 
		if (ch == '\b')             //当遇到退格符时即\b时，我们要用空格来代替             
		{
			--i;
			printf("\b \b");      //这里的意思就是说将已经输入的字符退一个格，用空格\r来代替，再退回一个格      
		}
		else if (ch == '\r')        //当遇到回车符\r时，我们就退出循环        
			break;
		else
		{
			printf("#");         //每输入一次就显示一个#
			a[i++] = ch;           //将刚刚的字符放入字符数组里           
		}
	}
	printf("\n");
	return 0;
}