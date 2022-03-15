#pragma once
#include"System.h"
#include"utils.h"

//����Ա����
void adminOption(struct Accounts* userList, struct Node* list);

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


