#include<stdio.h>
void hano(int n,char x,char y,char z)
{
	if(n==1)
		printf("%c-->%c\n",x,z);
	else
	{
		hano(n-1,x,z,y);//把n-1个盘子从x上借助于z移动到y上
		printf("%c-->%c\n",x,z);
		hano(n-1,y,x,z);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	hano(n,'A','B','C');
	
	return 0;
}