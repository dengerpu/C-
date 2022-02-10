#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int my_strlen(char* str) {
	int count = 0;
	while(*str!='\0'){
		count++;
		str++;
	}
	return count;
}
void reverse1(char a[], int length) {
	int left = 0;
	int right = length - 1;
	while (left <= right) {
		char tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left++;
		right--;
	}
}

void reverse(char* arr) {
	char temp = arr[0];
	int len = my_strlen(arr);
	arr[0] = arr[len - 1];
	arr[len - 1] = '\0';
	if (my_strlen(arr + 1) >= 2)
		reverse(arr + 1);
	arr[len - 1] = temp;
	
}


int main() {
	char a[] = "abcdef";
	//printf("%d\n", my_strlen(a));
	reverse1(a, my_strlen(a));
	printf("%s\n", a);
	reverse(a);
	printf("%s\n",a );
	return 0;
}