/*����һ���ַ��������������Ļ����Ӵ���ע�⣺�ж�ʱ�������б����źͿո��Һ��Դ�Сд�������Ӧ����ԭ�����ڻ��Ĵ����ײ���β����Ҫ��������ַ����������ַ������Ȳ�����100����ռ�ݵ���һ�У�����ж���������ʼλ�����ġ�
�������룺Confuciuss say:Madam,I'm Adam.
���������Madam,I'm Adam
*/
#include<stdio.h>
#include<string.h>
int main()
{ 
	char s[100],s1[100],s2[100];
	int i=0,j,m=0,n,t[100],max=0,x,y; 
	gets(s); 
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		s2[i]=s[i];                    //ɾ��������
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))	
		{
			t[m]=i;
			if((s[i]>='a'&&s[i]<='z'))
				s[i]=s[i]-32;             //ȫ����ĸ���ɴ�д
				s1[m++]=s[i];              //s1����Ϊ����д��ĸ���飬����������
			
		}
	}
	for (i=0;i<m;i++)  
	{         
		for (j=0;j<=i&&i+j<m;j++)  
		{        
			if(s1[i-j]!=s1[i+j])
				break; //����   
			if((2*j+1)>max)     
			{              
				max=2*j+1;      
				x=t[i-j];           
				y=t[i+j];          
			}    
		}        
		for (j=0;j<=i&&i+j<m;j++)   
		{         
			if (s1[i-j]!=s1[i+j+1])
				break; //ż��     
			if ((2*j+2)>max)      
			{       
				max=2*j+2;    
				x=t[i-j];     
				y=t[i+j+1];    
			} 
		}  
	}  
	for (i=x;i<=y;i++) 
		printf("%c",s2[i]); 
	printf("\n");
	return 0;
}