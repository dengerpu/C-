#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
enum COLLEGE {
	ͨ��ѧԺ = 1,		//01
	�����ѧԺ,		//02
	���ѧԺ,		//03
	�Զ���ѧԺ,		//04
	����ѧԺ,		//05
	�о���Ժ,		//06
	����ѧԺ,		//07
	����ѧԺ,		//08
	����ѧԺ,		//09
	��ýѧԺ,		//10
	�Ƚ�����ѧԺ,	//11
	���˼����ѧԺ	//12
};


//��ȡ�ַ���
int my_substr(char* res, int pos, int len, char* substr);

//��ȡѧԺ
void getCollege(int num, char* college);
//��ȡѧ�����
int getSidYear(char* id);
//��ȡѧ��ѧԺ����
int getSidCollege(char* id);
//��ȡѧ�������
int getSidNum(char* id);

//��ȡ���
int getYear(char* date);
//��ȡ��
int getMonth(char* date);
//��ȡ��
int getDay(char* date);

