#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strncat(char* dest, char* src, size_t num) {
	assert(dest && src);
	char* ret = dest;
	while (*dest) {
		dest++;
	}
	while (num--) {
		if (*src=='\0') {  //Óöµ½\0¾ÍÖÕÖ¹³ÌĞò
			return ret;
		}
		*dest++ = *src++;
	}
	*dest = '\0';
	return ret;

}
int main() {
	char arr[20] = "abcdef";
	char arr2[] = "hij";
	//strncat(arr, arr2,2);//×Ö·û´®Æ´½Ó
	my_strncat(arr, arr2, 1);
	printf("%s\n", arr);
	return 0;
}