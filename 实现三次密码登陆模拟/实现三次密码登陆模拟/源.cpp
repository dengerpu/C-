#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//strcpy(arr,arr1); //�ַ�����������arr1���ַ�������arr


int main() {
	char s[20];
	int i = 1;
	printf("����������:\n");
	while (i <= 3) {
		scanf("%s", s);
		if (strcmp(s, "123456")==0) {
			printf("%s", s);
			printf("��½�ɹ�\n");
			break;
		}
		else {
			if(i<=2)
			printf("�����������������\n");	
		}
		i++;
	}
	if (i > 3) {
		printf("��������Ѿ���������\n");
	}

	return 0;
}