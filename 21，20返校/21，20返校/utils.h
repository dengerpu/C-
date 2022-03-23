#pragma once
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define WIN_WIDTH 160 // ���ڿ��
#define WIN_HEIGHT 60 // ���ڸ߶�
#define TABLE_WIDTH 158 //�����
#define MENU_WIDTH  40 //�˵����
#define COL_LEN_MAX 64 //�������

#define DEFAULT_SZ 10 //Ĭ�������С
#define DEFAULT_PAGE_NUM 10  //Ĭ��ÿҳ��ʾ����������

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
//��ӡ��ͷ�������ڴ�ӡ�˵� ��������������������������
void printMenuHead(int tableWidth);
//��ӡ����м����Ϣ���� �˵����ݩ�����������������ݣ�
void printMenuMidInfo(int tableWidth, const char* str);
//��ӡ��β�������ڴ�ӡ�˵� ��������������������������
void printMenuTail(int tableWidth);

//��ӡ�������ʽ�� ���������Щ������Щ�����������������������������ݣ�
void printTableHead(int tableWidth, int cols);
//��ӡ��ͷ����     ���� ����1�� ����2�� ����3����������ݣ���������������ݣ�
void printTableRow(int tableWidth, char cols[][COL_LEN_MAX], int n);
//��ӡ����м�ָ��ߣ����������੤ ���੤�����ȣ���������������ݣ�
void printTableMidLine(int tableWidth, int cols);
//��ӡ����β��      ���������ة������ة����������������ڴ�ӡ���ݣ�
void printTableTail(int tableWidth, int cols);


//���д�ӡ
void printMidInfo(const char* str);

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

//��ȡ���ڵ����
int getYear(char* date);
//��ȡ���ڵ��·�
int getMonth(char* date);
//��ȡ���ڵ���
int getDay(char* date);



