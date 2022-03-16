#define _CRT_SECURE_NO_WARNINGS
#include "System.h"

//读取文件中用户信息
void readUserInfoFromFile(const char* filename, struct Accounts* listHeadNode) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w");  //如果文件不存在，就创建文件
	}
	struct Account account;
	while (fscanf(fp, "%s\t%s\t%d\t\n", account.account,account.password,&(account.type)) != EOF) {
		insertUserNodeNyHead(listHeadNode, account);
		memset(&account, 0, sizeof(account));
	}
	//printf("%d\n", getUserLenth(listHeadNode));
	//如果为空，则说明第一次使用系统，
	//第一次启动程序会自动生成管理员账号和密码
	if (getUserLenth(listHeadNode)==0) {
		strcpy(account.account, "admin");
		strcpy(account.password, "admin");
		account.type = 1;
		fprintf(fp, "%s\t%s\t%d\t\n", account.account, account.password, account.type);
	}
	fclose(fp);
	fp = NULL;
}
//保存用户信息到文件
void saveUserInfoToFile(const char* filename, struct Accounts* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Accounts* pMove = listHeadNode->next;
	while (pMove) {
		fprintf(fp, "%s\t%s\t%d\t\n", pMove->account.account, pMove->account.password, pMove->account.type);
		pMove = pMove->next;
	}
	fclose(fp);
	fp = NULL;
}
//查找用户,返回结果为用户类型，如果找不到或为空，返回为0
int findUser(struct Accounts* listHeadNode, char* user, char* pwd) {
	struct Accounts* node = listHeadNode->next;
	if (node == NULL) {
		return 0;
	}
	else {
		while (node != NULL) {
			if (strcmp(node->account.account, user) == 0 && strcmp(node->account.password,pwd) == 0) {
				//printf("%s\n", node->account.account);
				//printf("%s\n", node->account.password);
				//printf("%d\n", node->account.type);
				return node->account.type;
			}
			node = node->next;
		}
		return 0; //查找不到
	}
}
//建议用户修改密码
void AdviceModifyPwd(struct Accounts* userList, char* user, char* pwd) {
	char newpwd[10] = { 0 };
	struct Accounts* node = userList->next;
	strcpy(newpwd, pwd);
	while (strcmp(user, newpwd) == 0) {
		printf("请修改密码：");
		scanf("%s", newpwd);
	}
	while (node != NULL) {
		if (strcmp(node->account.password, user) == 0) {
			strcpy(node->account.password ,newpwd);
			printf("修改密码成功，下次登录生效\n");
			saveUserInfoToFile("data1.txt", userList);
		}
		node = node->next;
	}
}

//登陆
int login(struct Accounts* userList,char* user) {
	char account[10] = { 0 };
	char password[10] = { 0 };
	int i = 3;
	while (i--) {
		printf("---------研究生招生成绩管理系统--------\n");
		printf("\t\t账号:");
		scanf("%s", account);
		printf("\t\t密码:");
		scanf("%s", password);
		int type = findUser(userList, account, password);
		if (type == 1) {
			printf("欢迎管理员登录\n");
			AdviceModifyPwd(userList, account, password);
			return 1;
		}else if(type==2){
			printf("欢迎系统操作员登陆\n");
			AdviceModifyPwd(userList, account, password);
			return 2;
		}
		else if (type ==3 ) {
			printf("欢迎学生登录\n");
			AdviceModifyPwd(userList, account, password);
			strcpy(user, account);//把user传递回去给学生
			return 3;
		}
		else {
			printf("账号或密码错误，请重新输入\n");
			printf("你还有%d次机会\n", i);
			system("pause");
			system("cls");
		}
	}
	return 0;
}

//管理员菜单
void adminMenu() {
	printf("---------研究生招生成绩管理系统--------\n");
	printf("\t\t0.退出成绩管理系统\n");
	printf("\t\t1.添加用户信息\n");
	printf("\t\t2.修改用户信息\n");
	printf("\t\t3.删除用户信息\n");
	printf("\t\t4.查询用户信息\n");
	printf("\t\t5.添加学生成绩信息\n");
	printf("\t\t6.修改学生成绩信息\n");
	printf("\t\t7.删除学生成绩信息\n");
	printf("\t\t8.查询学生成绩信息\n");
	printf("\t\t9.打印用户信息\n");
	printf("\t\t10.打印学生成绩信息\n");
	printf("\t\t11.排序\n");
	printf("----------------------------------------\n");
	printf("请选择操作:>");
}
//系统操作员菜单
void SystemoptionMenu() {
	printf("---------研究生招生成绩管理系统--------\n");
	printf("\t\t0.退出成绩管理系统\n");
	printf("\t\t1.添加学生成绩信息\n");
	printf("\t\t2.修改学生成绩信息\n");
	printf("\t\t3.删除学生成绩信息\n");
	printf("\t\t4.查询学生成绩信息\n");
	printf("\t\t5.打印学生成绩信息\n");
	printf("\t\t6.排序\n");
	printf("---------------------------------------\n");
	printf("请选择操作:>");
}
//学生菜单
void StudentMenu() {
	printf("---------研究生招生成绩管理系统--------\n");
	printf("\t\t0.退出系统\n");
	printf("\t\t1.查看成绩\n");
	printf("---------------------------------------\n");
	printf("请选择操作:>");
}

//创建用户链表
struct Accounts* createUserList() {
	//申请空间
	struct Accounts* listHead = (struct Accounts*)malloc(sizeof(struct Accounts));
	listHead->next = NULL;
	return listHead;
}
//创建用户结点
struct Accounts* createUserNode(struct Account account) {
	struct Accounts* newNode = (struct Accounts*)malloc(sizeof(struct Accounts));
	newNode->account = account;
	newNode->next = NULL;
	return newNode;
}
//用户头插法，插入节点
void insertUserNodeNyHead(struct Accounts* listHeadNode, struct Account account) {
	struct Accounts* newNode = createUserNode(account);//申请一个新结点
	newNode->next = listHeadNode->next;
	listHeadNode->next = newNode;
}

//计算用户链表长度
int getUserLenth(struct Accounts* listHeadNode) {
	int length = 0;
	struct Accounts* node = listHeadNode->next;
	if (node == NULL) {
		return 0;
	}
	else {
		while (node != NULL) {
			node = node->next;
			length++;
		}
		return length;
	}
}
//计算学生成绩链表长度
int getStudentLenth(struct Node* listHeadNode) {
	int length = 0;
	struct Node* node = listHeadNode->next;
	if (node == NULL) {
		return 0;
	}
	else {
		while (node != NULL) {
			node = node->next;
			length++;
		}
		return length;
	}
}


//创建学生链表
struct Node* createList() {
	//申请空间
	struct Node* listHead = (struct Node*)malloc(sizeof(struct Node));
	listHead->next = NULL;
	return listHead;
}

//创建学生成绩结点
struct Node* createNode(struct student data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//学生成绩链表 头插法，插入节点
void insertNodeNyHead(struct Node* listHeadNode, struct student data) {
	struct Node* newNode = createNode(data);//申请一个新结点
	newNode->next = listHeadNode->next;
	listHeadNode->next = newNode;
}
//读取文件中学生成绩信息
void readStudentInfoFromFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w");  //如果文件不存在，就创建文件
	}
	struct student tempData;
	while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", tempData.stu_id, tempData.name, tempData.colleage, tempData.type, tempData.course1, tempData.course2, tempData.course3, tempData.course4, tempData.ptest, tempData.retest, tempData.olanguage, tempData.comprehensive) != EOF) {
		insertNodeNyHead(listHeadNode, tempData);
		memset(&tempData, 0, sizeof(tempData));
	}
	fclose(fp);
	fp = NULL;
}
//保存学生信息到文件
void saveStudentInfoToFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Node* pMove = listHeadNode->next;
	while (pMove) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", pMove->data.stu_id, pMove->data.name, pMove->data.colleage, pMove->data.type, pMove->data.course1, pMove->data.course2, pMove->data.course3, pMove->data.course4, pMove->data.ptest, pMove->data.retest, pMove->data.olanguage, pMove->data.comprehensive);
		pMove = pMove->next;
	}
	fclose(fp);
	fp = NULL;
}

//保存排序后的学生信息到文件
void saveSortStudentInfoToFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Node* pMove = listHeadNode->next;
	int i = 0;
	while (pMove) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", pMove->data.stu_id, pMove->data.name, pMove->data.colleage, pMove->data.type, pMove->data.course1, pMove->data.course2, pMove->data.course3, pMove->data.course4, pMove->data.ptest, pMove->data.retest, pMove->data.olanguage, pMove->data.comprehensive);
		i++;
		if (i % 10 == 0) {   //每隔10条信息以一个空行隔开
			fprintf(fp, "\n");
		}
		pMove = pMove->next;
	}
	fclose(fp);
	fp = NULL;
}

