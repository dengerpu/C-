#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct people {
	char name[20];
	char sex[10];
	int age;
};
int main() {
	char ch = 0;
	//������������·����Ҳ�����Ǿ���·��
	//FILE* fp = fopen("C:\\Users\\Administrator.SC-201902031211\\Desktop\\data.txt","r");
	//FILE* fp = fopen("C:\\Users\\Administrator.SC-201902031211\\Desktop\\data.txt", "w");
	//��д��û���ļ�ʱ����
	FILE* fp = fopen("C:\\Users\\Administrator.SC-201902031211\\Desktop\\data.txt", "r+");
	if (fp == NULL) {
		//printf("%s\n", strerror(errno));
		printf("�ļ���ʧ��\n");
	}
	//fgetc���������ȡ�꣬�Ὣ�ļ�ָ���ƶ�����һ���ַ�
	//ch = fgetc(fp);
	//printf("%c\n",ch);
	// ch = fgetc(fp);
	// printf("%c\n", ch);
	// ch = fgetc(fp);
	// printf("%c\n", ch);

	//while (EOF != (ch = fgetc(fp))) {
	//	printf("%c",ch);
	//}

	//fgets��ȡһ��   fgets���������ȡ��Ὣ�ļ�ָ���ƶ�����һ���ַ�
	//char str[200];  //���ﲻ����ָ�������գ���Ϊָ��ֻ�ܽ���4���ֽ�
	//fgets(str, 200, fp);
	//printf("%s\n", str);
	//fgets(str, 200, fp);
	//printf("%s\n", str);
	//fgets(str, 200, fp);
	//printf("%s\n", str);

	//fgets��ȡ�����󣬷���ֵΪNULL
	//while (fgets(str, 200, fp)) {
	//	printf("%s", str);
	//}


	//fread ,����ʵ�ʶ�ȡ�Ĵ�С
	//char str[200];
	//fread(str, 1, 20, fp);//���������������
	//����취1 
	//char str[200] = { 0 };
	//����취2
	//char str[200];
	//memset(str, 0, 200);
	//fread(str, 1, 20, fp);
	//printf("%s", str);

	//����취3
	//char str[200];
	//int n = fread(str, 1, 20, fp);
	//str[n] = '\0';
	//printf("%s", str);

	//char str[200] = { 0 };
	//while (fread(str, 1, 200, fp)) {
	//	printf("%s", str);
	//}



	//д��һ���ַ�  w  ���д 
	//fputc('A', fp);
	//fputc('B', fp);
	//fputc('c', fp);

	//const char* str = "abcdefg";
	//char str[20] = "abcd";
	//char str[20] = { 'a','b' };  
	//fputs(str, fp);

	//fwrite����
	//int num = 123456;
	//fwrite(&num,  sizeof(num),1, fp);

	//fseek(fp, 0, SEEK_SET);
	//
	//int num2;
	//fread(&num2, sizeof(num2),1, fp);
	//printf("%d\n", num2);

	/*struct people p = { "����","��",20 };
	fwrite(&p, sizeof(p), 1, fp);
	fwrite(&p, sizeof(p), 1, fp);
	fwrite(&p, sizeof(p), 1, fp);*/

	//��ȡ���һ������
	//fseek(fp, -1, SEEK_END);
	//int length = 0;
	//while (fread(&ch, 1, 1, fp)) {
	//	if (ch == '\n')
	//		break;
	//	fseek(fp, -2, SEEK_CUR);  //��ǰ����������ʾ�ƶ�����ǰ��ȡ�ַ���ǰһ��
	//	length++;
	//}
	//fseek(fp, -length, SEEK_END);   //�ƶ������һ�е��׵�ַ
	//char* buff = (char*)malloc(sizeof(char) * length);
	//fread(buff,length, 1, fp);
	//printf("%s\n", buff);

	rewind(fp);  //�����ļ�ָ�뵽�ļ���ͷ
	fseek(fp, 0, SEEK_END);
	int  size = ftell(fp);
	printf("�ļ��Ĵ�С��%d\n", size);


	fclose(fp);//�ͷ��ڴ�
	fp = NULL;

	return 0;
}