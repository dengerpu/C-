#pragma once
#include"System.h"
#include"utils.h"

//����Ա����
void adminOption(struct Accounts* userList, struct Node* list);
//ϵͳ����Ա����
void systemOperationOption(struct Accounts* userList, struct Node* list);
//ѧ������
void studentOption(struct Node* list,char* sid);

//����û�
void addUser(struct Accounts* userList);
//�����û�
int findUserByUsername(struct Accounts* userList, char* username);
//�޸��û�
int modifyUserByUsername(struct Accounts* userList);
//ɾ���û�
int deleteUserByUsername(struct Accounts* userList,char* sid);
//�����û�
int queryUserByUsername(struct Accounts* userList);
//���������û�
void queryAllUser(struct Accounts* userList);

//���ѧ���ɼ�
void addStudent(struct Accounts* userList, struct Node* list);
//�޸��û�
void modifyStudentBySid(struct Node* list);
//ɾ��ѧ���˻���ͬʱɾ���û�
int deleteStudentBySid(struct Accounts* userList, struct Node* list);
//ͨ��ѧ���������߲���
int queryStudentBynameOrsid(struct Node* list);
//����ѧ���ɼ�
void queryAllStudent(struct Node* list);
//����
void sort(struct Node* list);

//�ͷ��ڴ�
void destory(struct Accounts* userList, struct Node* list);

//����ѧ���û���ֱ�ӷ��ظ�ѧ����Ϣ���ϸ��û���ͬ��ģ�����鷳�ˣ�
struct Node* findStudentBySid(struct Node* list, char* sid);
//��ӡѧ���ɼ�
void printSingleStudent(struct Node* list, char* sid);

