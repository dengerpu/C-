#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>

//int main() {
//	//rֻ����Ϊ���������ݣ���һ���Ѿ����ڵ��ı��ļ�
//	FILE* pf = fopen("text.txt", "w");
//	if (pf == NULL) {
//		printf("%s\n", strerror(errno));
//	}else {
//		printf("���ļ��ɹ�\n");
//	}
//	
//	return 0;
//}

//int main() {
//	//û���ļ��ᴴ���ļ����ļ������ݻᱻ����
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL) {
//		printf("%s\n", strerror(errno));
//	}
//	else {
//		fputs("heelo world1", pf);
//		//�ر��ļ�
//		fclose(pf);
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1, pf);//�����Ƶ���ʽд���ļ���
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main() {
//	FILE* pfwrite = fopen("test.txt", "w");
//	if (pfwrite == NULL) {
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//�ļ��򿪳ɹ�
//
//		fputc('b', pfwrite);
//		fputc('i', pfwrite);
//		fputc('t', pfwrite);
//
//		fclose(pfwrite);
//		pfwrite = NULL;
//	
//
//	return 0;
//}

//int main(){
//	FILE* pfRead = fopen("test.txt", "r");
//	if (pfRead == NULL) {
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	printf("%c", fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//
//	fclose(pfRead);
//	pfRead = NULL;
//	return 0;
//}

//�Ӽ�������
//�������Ļ.
//����&��Ļ�����ⲿ�豸
//
//����-��׼�����豸- stdin
//��Ļ-��׼����豸- stdout
//��һ������Ĭ�ϴ򿪵��������豸

//int main() {
//	int ch = fgetc(stdin);
//	fputc(ch,stdout);
//	return 0;
//}

//int main() {
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL) {
//		return 0;
//	}
//	//��ȡ�ļ�
//	fgets(buf, 1024, pf);
//	puts(buf);
//	fgets(buf, 1024, pf);
//	puts(buf);
//
//	fclose(pf);
//	pf = NULL;
//}
//
//int main() {
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL) {
//		return 0;
//	}
//	//д�ļ�
//	fputs("heelo\n", pf);
//	fputs("word2\n", pf);
//
//	fclose(pf);
//	pf = NULL;
//}

//int main() {
//	//�Ӽ��̶�ȡһ���ı���Ϣ
//	char buff[1024] = { 0 };
//	fgets(buff, 1024, stdin);//�ӱ�׼��������ȡ
//	fputs(buff, stdout);  //�������׼�����
//
//	return 0;
//}

//struct S {
//	int n;
//	float score;
//	char arr[10];
//};
//int main(){
//	struct S s = { 1,3.14,"heelo" };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL) {
//		return 0;
//	}
//	//��ʽ������ʽд�ļ�
//	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main() {
//	struct S s = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL) {
//		return 0;
//	}
//	//��ʽ������������
//	fscanf(pf, "%d %f %s", &(s.n), &(s.score), s.arr);
//	printf("%d %.2f %s\n", s.n, s.score, s.arr);
//
//	fclose(pf);
//	pf == NULL;
//	return 0;
//}
//int main() {
//	struct S s = { 0 };
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr);
//	fprintf(stdout, "%d %.2f %s", s.n, s.score, s.arr);
//}

//int main() {
//	struct S s = { 100,3.14f,"abcdef" };
//	struct S tmp = { 0 };
//	char buf[1024] = { 0 };
//
//	//�Ѹ�ʽ��������ת�����ַ����洢��buf
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
//	printf("buf:%s\n", buf);
//	//��buf�ж�ȡ��ʽ�������ݵ�tmp��
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), &(tmp.arr));
//
//	printf("tmp:%d %f %s\n", tmp.n, tmp.score, tmp.arr);
//
//	return 0;
//}

struct  S {
	char name[20];
	int age;
	double score;
};
//int main() {
//	struct S s = { "����",20,55.6 };
//
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL) {
//		return 0;
//	}
//	//�����Ƶ���ʽд�ļ�
//	fwrite(&s, sizeof(struct S), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//	
//}

int main()
{
	//struct S s = { "����", 20, 55.6 };
	struct S tmp = { 0 };

	FILE* pf = fopen("test.txt", "rb");
	if (pf == NULL)
	{
		return 0;
	}
	//�����Ƶ���ʽ���ļ�
	fread(&tmp, sizeof(struct S), 1, pf);
	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);

	fclose(pf);
	pf = NULL;
	return 0;
}