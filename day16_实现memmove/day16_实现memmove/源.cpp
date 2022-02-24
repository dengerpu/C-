#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
void* my_memmove(void* dest, void* src ,size_t count) {
	void* ret = dest;
	assert(dest && src);
	if (dest < src) {  //从前到后
		while (count--) {
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else {  //从后往前
		while (count--) {
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}


int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i = 0;
	//my_memcpy(arr+2, arr, 20);

	my_memmove(arr + 2, arr, 20);//处理内存重叠的情况的

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}