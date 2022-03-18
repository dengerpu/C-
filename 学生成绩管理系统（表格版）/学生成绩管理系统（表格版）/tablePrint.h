#pragma once


#define WIN_WIDTH 160 // ���ڿ��
#define WIN_HEIGHT 60 // ���ڸ߶�
#define TABLE_WIDTH 148 //�����
#define MENU_WIDTH  40 //�˵����
#define COL_LEN_MAX 64 //�������

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

