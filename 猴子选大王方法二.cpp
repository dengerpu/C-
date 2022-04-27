#include<stdio.h>
int main()
{
	int n,a[100],i,k=0,c;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		a[i]=0;
	c=n;
	i=1;
	while(c!=1)
	{
		if(a[i]==0)	
			k++;
		if(k==3)
		{
			a[i]=-1;
			k=0;
			c--;
		}
		i++;
		if(i==n+1)
			i=1;
	}
	for(i=1;i<=n;i++)
		if(a[i]==0)
			printf("%d\n",i);
	return 0;
}