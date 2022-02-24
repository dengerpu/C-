#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>


void* my_memcpy(void *dest,const void *src,size_t num) {
	void* ret = dest;
	assert(dest && src);
	while (num--) {
		*(char*)dest = *(char*)src;
		//(char*)dest++;  //这是错的，因为++的优先级高
		++ (char*)dest;
		++ (char*)src;

	}
	return ret;
}
int main() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = { 0 };
	my_memcpy(arr2, arr1,sizeof(arr1));
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr2[i]);
	}

	return 0;
}