#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//��ȡ�ַ���
int my_substr(char* res, int pos, int len, char* substr);

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
