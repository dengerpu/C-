#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strncpy(char* dest, const char* src, size_t num) {
	assert(dest && src);
	char* ret = dest;
	while (num&&(*dest=*src)) {
		num--;
		dest++;
		src++;
	}
	while (num--) {
		*dest++ = '\0';
	}
	return ret;
}
int main() {
	char arr[] = "abcdef";
	char arr2[] = "hij";
	int a;
	//strcpy(arr, arr2); // hij\0def
	my_strncpy(arr, arr2, 5);   //hij\0\0f
	printf("%s\n", arr);

	return 0;
}