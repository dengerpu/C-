#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student {
	char stu_num[10];//ѧ��
	char name[15];  //����
	char college[20];//ѧԺ
	char temperate[5];//�¶�
	char isCough;     ///�Ƿ����
	char status;      //����״̬
	char time[8];     //ʱ��
	char date[10];    //����
		
}Student;

typedef struct students {
	Student data[20];
	int size;
}Students;

enum option {
	EXIT,
	ADD,
	MODIFY,
	DELETE,
	SEARCH,
	ABNORMAL,
	PRINT
};


//��ʼ��ѧ����Ϣ
void InitStudent(Students* p);


//���ѧ����Ϣ
void addStudent(Students* p);

//��ӡѧ����Ϣ
void printStudent(const Students* p);

//�������ݵ��ļ�
void saveStudent(const char* filename,const Students* p);

//�޸�ѧ����Ϣ
void modifyStudent(Students* p);

//��ѯѧ����Ϣģ��
void searchStudent(Students* p);



//C�����ṩ�˼�����׼�⺯�������Խ���������(���͡������͡������͵�)������ת��Ϊ�ַ����������о��˸������ķ�������˵����
//�� itoa()��������ֵת��Ϊ�ַ�����
//�� ltoa()����������ֵת��Ϊ�ַ�����
//��ultoa()�����޷��ų�����ֵת��Ϊ�ַ�����
//�� gcvt()������������ת��Ϊ�ַ�����ȡ�������롣
//�� ecvt()����˫���ȸ�����ֵת��Ϊ�ַ�����ת������в�����ʮ����С���㡣
//�� fcvt()��ָ��λ��Ϊת�����ȣ�����ͬecvt()��
//��������������������������������
//�� atof()�����ַ���ת��Ϊ˫���ȸ�����ֵ��
//�� atoi()�����ַ���ת��Ϊ����ֵ��
//�� atol()�����ַ���ת��Ϊ������ֵ��
//�� strtod()�����ַ���ת��Ϊ˫���ȸ�����ֵ�������治�ܱ�ת��������ʣ�����֡�
//�� strtol()�����ַ���ת��Ϊ����ֵ�������治�ܱ�ת��������ʣ�����֡�
//�� strtoul()�����ַ���ת��Ϊ�޷��ų�����ֵ�������治�ܱ�ת��������ʣ�����֡�
//��������������������������������
