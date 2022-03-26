#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<pcre.h>
#include<string.h>
int main()
{
	const char* errptr = NULL;
	int erroffset;
	pcre* pPcre = pcre_compile("^([a-z0-9A-Z]+[-|_|\.]?)+[a-z0-9A-Z]@([a-z0-9A-Z]+(-[a-z0-9A-Z]+)?\.)+[a-zA-Z]{2,}$",
		0, &errptr, &erroffset, NULL);
	char email_address[50];
	while (scanf("%s", email_address))
	{
		if (pcre_exec(pPcre, NULL, email_address, strlen(email_address), 0, 0, NULL, 0) < 0)
			printf("邮箱格式错误\n");
		else
			printf("邮箱格式正确\n");
	}
	free(pPcre);
	return 0;
}