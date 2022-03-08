#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//int substring(char* res, int pos, int len, char* substr)//从pos开始取len个字符到substr中
//{
//	char* p = res;
//	int i = 0;
//	if (pos > strlen(res))
//		return 0;
//	pos--;
//	while (i < len)
//	{
//		substr[i++] = res[pos++];
//		if (pos > strlen(res))
//		{
//			substr[i] = '\0';
//			break;
//		}
//	}
//	substr[i] = '\0';
//	return 1;
//}
int substr(char* res, int pos, int len, char* substr) {//从pos开始取len个字符到substr
	char* p = res;
	int i = 0;
	if (pos > strlen(res)) {
		return 0;
	}
	pos--;
	while (i < len) {
		substr[i++] = res[pos++];
		if (pos > strlen(res)) {
			substr[i] = '\0';
		}
	}
	substr[i] = '\0';
	return 1;
}  

int main() {
	char str[20] = "abcdefg";
	char str2[10];
	substr(str, 5, 5, str2);
	printf("%s\n", str2);
	return 0;
}