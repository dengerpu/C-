#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student {
	char stu_num[8];//ѧ��
	char name[15];  //����
	char college[20];//ѧԺ
	char temperate[4];//�¶�
	char isCough;     ///�Ƿ����
	char status;      //����״̬
	char time[5];     //ʱ��
	char date[8];    //����
		
}Student;

typedef struct students {
	Student data[10];
	int size;
}Students;

enum option {
	EXIT,
	ADD,
	MODIFY,
	DELETE,
	SEARCH,
	ABNORMAL
};
enum college {
	ͨ��ѧԺ = 1,    //01	
	�����ѧԺ,  //02
	���ѧԺ,	 //03
	�Զ���ѧԺ, //04
	����ѧԺ,    //05
	�о���Ժ,    //06
	����ѧԺ,    //07
	����ѧԺ,     //08
	����ѧԺ,     //09
	��ýѧԺ,     //10
	�Ƚ�����ѧԺ, //11
	���˼����ѧԺ,//12
}enum_college;


//��ʼ��ѧ����Ϣ
void InitStudent(Students* p);


//���ѧ����Ϣ
void addStudent(Students* p);

//��ӡѧ����Ϣ
void printStudent(Students* p);



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
