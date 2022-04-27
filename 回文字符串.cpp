/*输入一个字符串，求出其中最长的回文子串。注意：判断时忽略所有标点符号和空格，且忽略大小写，但输出应保持原样（在回文串的首部和尾部不要输出多余字符）。输入字符串长度不超过100，且占据单独一行，如果有多个，输出起始位置最靠左的。
样例输入：Confuciuss say:Madam,I'm Adam.
样例输出：Madam,I'm Adam
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
		s2[i]=s[i];                    //删除标点符号
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))	
		{
			t[m]=i;
			if((s[i]>='a'&&s[i]<='z'))
				s[i]=s[i]-32;             //全部字母换成大写
				s1[m++]=s[i];              //s1数组为纯大写字母数组，无其他符号
			
		}
	}
	for (i=0;i<m;i++)  
	{         
		for (j=0;j<=i&&i+j<m;j++)  
		{        
			if(s1[i-j]!=s1[i+j])
				break; //奇数   
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
				break; //偶数     
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