#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strcat(char* dest, const char * src) {
	char* ret = dest;
	assert(dest);
	assert(src);
	while (*dest != NULL) {
		dest++;
	}
	while (*dest++ = *src++) {
		
	}
	return ret;
}
int main() {
	char arr[10] = "abcd";  //这里必须加空间大小
	char arr2[] = "efg";
	my_strcat(arr, arr2);
	printf("%s\n", arr);
}