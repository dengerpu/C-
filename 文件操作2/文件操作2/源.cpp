#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<errno.h>
//
//int main() {
//	FILE * pf = fopen("test.txt","r");
//	if (pf == NULL) {
//		printf("%s\n", strerror(errno));
//	}
//	//1. �ı��ļ���ȡ�Ƿ�������жϷ���ֵ�Ƿ�Ϊ EOF �� fgetc �������� NULL �� fgets ��
//	//	���磺
//	//	fgetc �ж��Ƿ�Ϊ EOF .
//	//	fgets �жϷ���ֵ�Ƿ�Ϊ NULL .
//	//	2. �������ļ��Ķ�ȡ�����жϣ��жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ�����
//	//	���磺
//	//	fread�жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ�����
//	//��ȡ�ļ�
//	int ch = 0;
//	while ((ch = fgetc(pf)) != EOF) {
//		putchar(ch);
//	}
//	//�ж���ʲôԭ�������
//	if (ferror(pf)) {
//		printf("I/O error when reading\n");
//	}
//	else if (feof(pf)) {
//		//printf("%d", feof(pf));
//		printf("End of file reached successfully\n");
//	}
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main() {
//	FILE * pf = fopen("test.txt", "r");
//	if (pf == NULL) {
//		return 0;
//	}
//	//1.��λ�ļ�ָ��
//	//fseek(pf, -2, SEEK_END);  //�Ӻ���ǰƫ��2����λ   abcdefg  �õ�f
//	//fseek(pf, 1, SEEK_CUR);  //�ӵ�ǰ����ƫ��2����λ abcdefg c
//	fseek(pf, 2, SEEK_SET);   //�ӿ�ʼ����
//	
//	//��ȡ�ļ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

int main() {
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		printf("%s\n", strerror(errno));
		return 0;
	}
	//��λ�ļ�ָ��
	fseek(pf, -2, SEEK_END);
	
	//��ȡ�ļ�
	int ch = fgetc(pf);
	printf("%c\n", ch);
	int pos = ftell(pf);   //�����ļ�ָ���������ʼλ�õ�ƫ����
	printf("%d\n", pos);
	rewind(pf);
	ch = fgetc(pf); //���ļ�ָ��ص��ļ�����ʼλ��
	printf("%c\n", ch);


	fclose(pf);
	pf = NULL;
	return 0;
}