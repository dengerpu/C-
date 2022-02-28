#pragma once
#pragma once

//#define MAX 1000  //最大储存用户数

#define DEFAULT_SZ 3    //定义默认的容量

#define NAME_MAX 20  //名字的最大长度
#define SEX_MAX 5    //性别最大长度
#define TELE_MAX 11  //电话号码最大长度
#define ADDR_MAX 30  //地址最大长度

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
typedef struct PeoInfo {  //用户信息
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}*PInfo;
struct Contact {
	struct PeoInfo *data;
	int size;
	int capicty;   //定义容量
};

//声明函数
//初始化通讯录
void InitContact(struct Contact* p);
//添加用户
void AddContact(struct Contact* p);

//展示用户
void ShowContact(const struct Contact* p);
//查找用户
void SearchContact(const struct Contact* p);
//删除用户
void DelContact(struct Contact* p);

//修改用户
void ModifyContact(struct Contact* p);
//排序
void SortContact(struct Contact* p);
//退出后释放内存
void DestroyContact(Contact* ps);