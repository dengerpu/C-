#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>
struct people {
	char name[50];
	char sex[10];
	int age;
};
struct peoples {
	struct people data[50];
	int size;
};
int main() {
	FILE* fp = fopen("C:\\Users\\Administrator.SC-201902031211\\Desktop\\data.txt", "r+");
	if (fp == NULL) {
		printf("%s\n", strerror(errno));
	}
	struct peoples ps;
	ps.data[0] = { "张三","男",15 };
	ps.data[1] = { "李四","女",18 };
	ps.size = 2;
	for (int i = 0; i < ps.size; i++) {
		fwrite(&ps, sizeof(struct people), 1, fp);
	}

	

	
	return 0;
}