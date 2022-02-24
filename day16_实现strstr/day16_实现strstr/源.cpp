#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
//strstr  //�����ַ���
char* my_strstr(const char* p1, const char* p2) {
	assert(p1 && p2);
	char* s1 = NULL;
	char* s2 = NULL;
	char* cur = (char*)p1;
	if (*p2 == '\0') {   //p2����ǿ��ַ���
		return (char*)p1;
	}
	while (*cur) {
		s1 = cur;
		s2 = (char *)p2;
		while (s1 && s2 && *s1 == *s2) {
			s1++;
			s2++;
		}
		if (*s2 == '\0') {
			return cur;   //�ҵ��Ӵ�
		}
		cur++;
	}
	return NULL;
}
int main() {
	char arr[] = "abcefg";
	char arr2[] = "abc";
	char * str = my_strstr(arr, arr2);
	printf("%s\n", str);
	return 0;
}