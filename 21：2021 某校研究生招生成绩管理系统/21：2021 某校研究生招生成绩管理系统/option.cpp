#define _CRT_SECURE_NO_WARNINGS
#include "option.h"
#include<stdlib.h>

//管理员操作
void adminOption(struct Accounts* userList, struct Node* list) {
	int input = 0;
	do {
		adminMenu();
		scanf("%d", &input);
		switch(input) {
			case ADDUSER:addUser(userList); break;
			case MODIFYUSER:modifyUserByUsername(userList); break;
			case DELETEUSER:deleteUserByUsername(userList,NULL); break;
			case QUERYUSER:queryUserByUsername(userList); break;
			case ADDSTUDENT:addStudent(userList,list); break;
			case MODIFYSTUDENT:modifyStudentBySid(list); break;
			case DELETESTUDENT:deleteStudentBySid(userList,list); break;
			case QUERYSTUDENT:queryStudentBynameOrsid(list); break;
			case PRINTUSER:queryAllUser(userList); break;
			case PRINTSTUDENT:queryAllStudent(list); break;
			case SORT:sort(list); break;
			case EXIT:printf("退出模块"); destory(userList, list); exit(0); break;
			default:printf("输入有误，请重新输入"); break;
		}
		system("pause");
		system("cls");

	} while (input);

}
//系统操作员操作
void systemOperationOption(struct Accounts* userList,struct Node* list) {
	int input = 0;
	do {
		SystemoptionMenu();
		scanf("%d", &input);
		switch (input) {
		case 1:addStudent(userList, list); break;
		case 2:modifyStudentBySid(list); break;
		case 3:deleteStudentBySid(userList, list); break;
		case 4:queryStudentBynameOrsid(list); break;
		case 5:queryAllStudent(list); break;
		case 6:sort(list); break;
		case 0:printf("退出模块"); destory(userList, list); exit(0); break;
		default:printf("输入有误，请重新输入"); break;
		}
		system("pause");
		system("cls");

	} while (input);

}
//学生操作
void studentOption(struct Node* list,char* sid) {
	int input = 0;
	do {
		StudentMenu();
		scanf("%d", &input);
		switch (input) {
		case 1:printSingleStudent(list,sid); break;
		case 0:printf("退出模块"); destory(NULL, list); exit(0); break;
		default:printf("输入有误，请重新输入"); break;
		}
		system("pause");
		system("cls");

	} while (input);
}

//查找用户
int findUserByUsername(struct Accounts* userList, char* username) {
	struct Accounts* node = userList->next;
	if (node == NULL) {
		return 0;
	}
	else {
		while (node != NULL) {
			if (strcmp(node->account.account, username) == 0) {
				return 1;
			}
			node = node->next;
		}
		return 0;
	}
}

//添加用户
void addUser(struct Accounts* userList) {
	struct Account account;
	printf("请输入要添加的系统操作员账号：");
	scanf("%s", &account.account);
	int exist  = findUserByUsername(userList, account.account);
	while (exist == 1) {
		printf("该用户已存在,请重新输入：");
		scanf("%s", &account.account);
		exist = findUserByUsername(userList, account.account);
	}
	strcpy(account.password, account.account);
	account.type = 2;
	insertUserNodeNyHead(userList, account);
	//保存到文件中
	//保存用户信息到文件
	saveUserInfoToFile("data1.txt", userList);
}
//修改用户
int modifyUserByUsername(struct Accounts* userList) {
	char username[10] = { 0 };
	struct Accounts* node = userList->next;
	if (node == NULL) {
		printf("表为空\n");
		return 0;
	}
	else {
		printf("请输入要修改的用户名:：");
		scanf("%s", username);
		while (node != NULL) {
			if (strcmp(node->account.account, username) == 0) {
				printf("请输入要修改的密码：");
				scanf("%s", node->account.password);
				printf("请输入要修改的类型（1.管理员，2系统操作员，3.学生）：");
				scanf("%d", &(node->account.type));
				//保存到文件中
				saveUserInfoToFile("data1.txt", userList);
				return 1;
				
			}
			node = node->next;
		}
		printf("无该用户\n");
		return 0;

	}	
}
//删除用户
int deleteUserByUsername(struct Accounts* userList,char* sid) {
	char  username[10] = { 0 };
	if (sid == NULL) {
		printf("请输入要删除的用户名称：");
		scanf("%s", username);
	}
	else {
		strcpy(username, sid);
	}
	struct Accounts* posFrontNode = userList;  //要删除结点的前一个结点
	struct Accounts* posNode = userList->next; //要删除的结点
	if (posNode == NULL) {
		printf("表为空，无法删除\n");
		return 0;
	}
	else {
		while (posNode != NULL) {
			if (strcmp(posNode->account.account, username) == 0) {
				posFrontNode->next = posNode->next;
				printf("删除学生用户成功\n");
				saveUserInfoToFile("data1.txt", userList);
				return 1;
			}
			posFrontNode = posNode;
			posNode = posNode->next;
		}
		printf("无该用户\n");
		return 0;
	}
}
//查找用户
int queryUserByUsername(struct Accounts* userList) {
	char  username[10] = { 0 };
	printf("请输入要查询的用户名称：");
	scanf("%s", username);
	struct Accounts* posNode = userList->next; //要删除的结点
	if (posNode == NULL) {
		printf("表为空\n");
		return 0;
	}
	else {
		while (posNode != NULL) {
			if (strcmp(posNode->account.account, username) == 0) {
				//printf("提示：1.管理员  2.系统操作员  3.学生\n");
				printf("用户名：%s  密码：%s  类型：%d\n", posNode->account.account, posNode->account.password, posNode->account.type);
				return 1;
			}
			posNode = posNode->next;
		}
		printf("无该用户\n");
		return 0;
	}
}
//查找所用用户
void queryAllUser(struct Accounts* userList) {
	struct Accounts* node = userList->next;
	if (node == NULL) {
		printf("表为空\n");
		return;
	}
	else {
		printf("%-8s\t%-8s\t%s\n","账号","密码","类型");
		while (node != NULL) {
			printf("%-8s\t%-8s\t%d\n", node->account.account, node->account.password, node->account.type);
			node = node->next;
		}
	}
}

//查找学生用户（直接返回该学生信息，上个用户相同的模块做麻烦了）
struct Node* findStudentBySid(struct Node* list, char* sid) {
	struct Node* node = list->next;
	if (node == NULL) {
		return NULL;
	}
	else {
		while (node != NULL) {
			if (strcmp(node->data.stu_id, sid) == 0) {
				return node;
			}
			node = node->next;
		}
		return NULL;
	}
}
//判断复试考号是否符合标准，返回值为学院代码
int JudgeSid(char* sid) {
	if (strlen(sid) != 9) {
		printf("复试考号位数错误\n");
		return 0;
	}
	int year = getSidYear(sid);
	int college = getSidCollege(sid);
	int random = getSidNum(sid);
	if (year != 2021) {
		printf("复试考号年份错误\n");
		return 0;
	}
	else if (college < 1 || college>12) {
		printf("复试考号学院代号错误\n");
		return 0;
	}
	else if (random < 0 || random>999) {
		printf("复试考号后三位错误\n");
		return 0;
	}
	else {
		return college;
	}
}


//添加学生成绩
void addStudent(struct Accounts* userList,struct Node* list) {
	struct Account account;
	struct student tempData;
	printf("请输入要添加的学生的信息：\n");
	printf("请输入复试学号：");   //需要判断是否存在
	scanf("%s", tempData.stu_id);
	while (JudgeSid(tempData.stu_id) == 0) {
		printf("请重新输入复试学号：");
		scanf("%s", tempData.stu_id);
	}
	getCollege(JudgeSid(tempData.stu_id), tempData.colleage);
	printf("请输入姓名：");
	scanf("%s", tempData.name);
	printf("请输入报考类别：");
	scanf("%s", tempData.type);
	while (strcmp(tempData.type, "学硕") != 0 && strcmp(tempData.type, "专硕") != 0 && strcmp(tempData.type, "非全日制") != 0) {
		printf("报考类别错误，请重新输入：");
		scanf("%s", tempData.type);
	}
	printf("基础课1成绩：");
	scanf("%s", tempData.course1);
	while (atof(tempData.course1) < 0 || atof(tempData.course1) > 100) {
		printf("输入有误,重新输入：");
		scanf("%s", tempData.course1);
	}
	printf("基础课2成绩：");
	scanf("%s", tempData.course2);
	while (atof(tempData.course2) < 0 || atof(tempData.course2) > 100) {
		printf("输入有误,重新输入：");
		scanf("%s", tempData.course2);
	}
	printf("专业课1成绩：");
	scanf("%s", tempData.course3);
	while (atof(tempData.course3) < 0 || atof(tempData.course3) > 150) {
		printf("输入有误,重新输入：");
		scanf("%s", tempData.course3);
	}
	printf("专业课2成绩：");
	scanf("%s", tempData.course4);
	while (atof(tempData.course4) < 0 || atof(tempData.course4) > 150) {
		printf("输入有误,重新输入：");
		scanf("%s", tempData.course4);
	}
	double total = atof(tempData.course1) + atof(tempData.course2) + atof(tempData.course3) + atof(tempData.course4);
	_gcvt(total, 6, tempData.ptest);
	printf("复试成绩：");
	scanf("%s", tempData.retest);
	while (atof(tempData.retest) < 0 || atof(tempData.retest) > 200) {
		printf("输入有误,重新输入：");
		scanf("%s", tempData.retest);
	}
	printf("口语成绩：");
	scanf("%s", tempData.olanguage);
	while (atof(tempData.olanguage) < 0 || atof(tempData.olanguage) > 20) {
		printf("输入有误,重新输入：");
		scanf("%s", tempData.olanguage);
	}
	float totalGrade = atof(tempData.ptest) * 0.6 + atof(tempData.retest) * 0.3 + atof(tempData.olanguage) * 0.1;
	_gcvt(totalGrade, 6, tempData.comprehensive);
	insertNodeNyHead(list, tempData);
	/*printf("%-5s\t%-5s\t%s\t%s %s %s %s %s %s %s %s %s\n", "复试学号", "姓名", "报考学院", "报考类别", "基础课1", "基础课2", "专业课1", "专业课2", "初试成绩", "复试成绩", "口语成绩", "综合成绩");
	printf("%-5s\t%-5s\t%s\t%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t\n", tempData.stu_id, tempData.name, tempData.colleage, tempData.type, tempData.course1, tempData.course2, tempData.course3, tempData.course4, tempData.ptest, tempData.retest, tempData.olanguage, tempData.comprehensive);*/
	//保存成绩到文件中
	saveStudentInfoToFile("data2.txt", list);

	//自动创建学生账号
	strcpy(account.account, tempData.stu_id);
	strcpy(account.password, account.account);
	account.type = 3;
	insertUserNodeNyHead(userList, account);
	////保存用户信息到文件
	saveUserInfoToFile("data1.txt", userList);
}
//修改用户
void modifyStudentBySid(struct Node* list) {
	char sid[10] = { 0 };
	printf("请输入要修改的考生号：");
	scanf("%s", sid);
	struct Node* modifyNode = findStudentBySid(list, sid);
	if (modifyNode == NULL) {
		printf("无此人信息\n");
	}
	else {
		printf("请输入姓名：");
		scanf("%s", modifyNode->data.name);
		printf("请输入报考类别：");
		scanf("%s", modifyNode->data.type);
		while (strcmp(modifyNode->data.type, "学硕") != 0 && strcmp(modifyNode->data.type, "专硕") != 0 && strcmp(modifyNode->data.type, "非全日制") != 0) {
			printf("报考类别错误，请重新输入：");
			scanf("%s", modifyNode->data.type);
		}
		printf("基础课1成绩：");
		scanf("%s", modifyNode->data.course1);
		while (atof(modifyNode->data.course1) < 0 || atof(modifyNode->data.course1) > 100) {
			printf("输入有误,重新输入：");
			scanf("%s", modifyNode->data.course1);
		}
		printf("基础课2成绩：");
		scanf("%s", modifyNode->data.course2);
		while (atof(modifyNode->data.course2) < 0 || atof(modifyNode->data.course2) > 100) {
			printf("输入有误,重新输入：");
			scanf("%s", modifyNode->data.course2);
		}
		printf("专业课1成绩：");
		scanf("%s", modifyNode->data.course3);
		while (atof(modifyNode->data.course3) < 0 || atof(modifyNode->data.course3) > 150) {
			printf("输入有误,重新输入：");
			scanf("%s", modifyNode->data.course3);
		}
		printf("专业课2成绩：");
		scanf("%s", modifyNode->data.course4);
		while (atof(modifyNode->data.course4) < 0 || atof(modifyNode->data.course4) > 150) {
			printf("输入有误,重新输入：");
			scanf("%s", modifyNode->data.course4);
		}
		int total = atof(modifyNode->data.course1) + atof(modifyNode->data.course2) + atof(modifyNode->data.course3) + atof(modifyNode->data.course4);
		_gcvt(total, 3, modifyNode->data.ptest);   //因为采用的是浮点数，出现整数100将是100. 多个点，所以就把这个点去掉
		if ((modifyNode->data.ptest)[strlen(modifyNode->data.ptest) - 1] == '.') {
			(modifyNode->data.ptest)[strlen(modifyNode->data.ptest) - 1] == '\0';
		}
		printf("复试成绩：");
		scanf("%s", modifyNode->data.retest);
		while (atof(modifyNode->data.retest) < 0 || atof(modifyNode->data.retest) > 200) {
			printf("输入有误,重新输入：");
			scanf("%s", modifyNode->data.retest);
		}
		printf("口语成绩：");
		scanf("%s", modifyNode->data.olanguage);
		while (atof(modifyNode->data.olanguage) < 0 || atof(modifyNode->data.olanguage) > 20) {
			printf("输入有误,重新输入：");
			scanf("%s", modifyNode->data.olanguage);
		}
		float totalGrade = atof(modifyNode->data.ptest) * 0.6 + atof(modifyNode->data.retest) * 0.3 + atof(modifyNode->data.olanguage) * 0.1;
		_gcvt(totalGrade, 5, modifyNode->data.comprehensive);
		//insertNodeNyHead(list, modifyNode->data);
		/*printf("%-5s\t%-5s\t%s\t%s %s %s %s %s %s %s %s %s\n", "复试学号", "姓名", "报考学院", "报考类别", "基础课1", "基础课2", "专业课1", "专业课2", "初试成绩", "复试成绩", "口语成绩", "综合成绩");
		printf("%-5s\t%-5s\t%s\t%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t\n", tempData.stu_id, tempData.name, tempData.colleage, tempData.type, tempData.course1, tempData.course2, tempData.course3, tempData.course4, tempData.ptest, tempData.retest, tempData.olanguage, tempData.comprehensive);*/
		//保存成绩到文件中
		saveStudentInfoToFile("data2.txt", list);
	}
}

//删除学生账户，同时删除用户
int deleteStudentBySid(struct Accounts* userList,struct Node* list) {
	char  sid[10] = { 0 };
	printf("请输入要删除的复试考号：");//删除学生同时也要删除学生对应的账户
	scanf("%s", sid);
	struct Node* posFrontNode = list;  //要删除结点的前一个结点
	struct Node* posNode = list->next; //要删除的结点
	if (posNode == NULL) {
		printf("表为空，无法删除\n");
		return 0;
	}
	else {
		while (posNode != NULL) {
			if (strcmp(posNode->data.stu_id, sid) == 0) {
				posFrontNode->next = posNode->next;
				printf("删除学生信息成功\n");
				saveStudentInfoToFile("data2.txt", list);
				deleteUserByUsername(userList, sid);
				return 1;
			}
			posFrontNode = posNode;
			posNode = posNode->next;
		}
		printf("无该用户\n");
		return 0;
	}
}
//通过学生姓名或者查找
int queryStudentBynameOrsid(struct Node* list) {
	char  query[20] = { 0 };
	printf("请输入要查询的复试考号或者姓名：");
	scanf("%s", query);
	struct Node* posNode = list->next; 
	if (posNode == NULL) {
		printf("表为空\n");
		return 0;
	}
	else {
		while (posNode != NULL) {
			if (strcmp(posNode->data.stu_id, query) == 0|| strcmp(posNode->data.name, query) == 0) {
				printf("%-5s\t%-5s\t%s\t%-8s\t%s %s %s %s %s %s %s %s\n", "复试学号", "姓名", "报考学院", "报考类别", "基础课1", "基础课2", "专业课1", "专业课2", "初试成绩", "复试成绩", "口语成绩", "综合成绩");
				printf("%-5s\t%-5s\t%s\t%-8s\t %s\t %s\t %s\t %s\t %s\t %s\t   %s\t   %s\t\n", posNode->data.stu_id, posNode->data.name, posNode->data.colleage, posNode->data.type, posNode->data.course1, posNode->data.course2, posNode->data.course3, posNode->data.course4, posNode->data.ptest, posNode->data.retest, posNode->data.olanguage, posNode->data.comprehensive);
				return 1;
			}
			posNode = posNode->next;
		}
		printf("无该用户\n");
		return 0;
	}
}
//查找学生成绩
void queryAllStudent(struct Node* list) {
	struct Node* posNode = list->next;
	if (posNode == NULL) {
		printf("表为空\n");
		return;
	}
	else {
		printf("%-5s\t%-5s\t%s\t%-8s\t%s %s %s %s %s %s %s %s\n", "复试学号", "姓名", "报考学院", "报考类别", "基础课1", "基础课2", "专业课1", "专业课2", "初试成绩", "复试成绩", "口语成绩", "综合成绩");
		while (posNode != NULL) {
			printf("%-5s\t%-5s\t%s\t%-8s\t %s\t %s\t %s\t %s\t %s\t %s\t   %s\t   %s\t\n", posNode->data.stu_id, posNode->data.name, posNode->data.colleage, posNode->data.type, posNode->data.course1, posNode->data.course2, posNode->data.course3, posNode->data.course4, posNode->data.ptest, posNode->data.retest, posNode->data.olanguage, posNode->data.comprehensive);
			posNode = posNode->next;
		}
	}
}
//通过综合成绩排名
int cmp_by_comprehensive(const void* e1, const void* e2) {
	//return (strcmp(((struct student*)e1)->comprehensive ,((struct student*)e2)->comprehensive));
	
	//printf("%s\n", ((struct Node*)e1)->data.comprehensive);
//	printf("%s\n", ((struct Node*)e2)->data.comprehensive);
	double a = atof(((struct Node*)e1)->data.comprehensive);
	double b = atof(((struct Node*)e2)->data.comprehensive);
	//printf("a:%lf\n", a);
	//printf("b:%lf\n", b);
	if (a > b) {
		return 1;
	}
	else if (a < b) {
		return -1;
	}
	else {
		return 0;
	}
}
//排序
void sort(struct Node* list) {
	struct Node* list1;//学硕表
	struct Node* list2;//专硕表
	struct Node* list3;//非全日制
	list1 = createList();
	list2 = createList();
	list3 = createList();
	struct Node* posNode = list->next;
	if (posNode == NULL) {
		printf("表为空\n");
		return;
	}
	else {
		while (posNode != NULL) {
			if (strcmp(posNode->data.type, "学硕") == 0) {
				insertNodeNyHead(list1, posNode->data);
				//printf("%s\n", posNode->data.comprehensive);
			}else if (strcmp(posNode->data.type, "专硕") == 0) {
				insertNodeNyHead(list2, posNode->data);
			}else if (strcmp(posNode->data.type, "非全日制") == 0) {
				insertNodeNyHead(list3, posNode->data);
			}
			posNode = posNode->next;
		}
		//对这三个表进行排序
		qsort(list1,getStudentLenth(list1),sizeof(list1),cmp_by_comprehensive);
		qsort(list2, getStudentLenth(list2), sizeof(list2), cmp_by_comprehensive);
		qsort(list3, getStudentLenth(list3), sizeof(list3), cmp_by_comprehensive);

		//queryAllStudent(list1);
		//保存到文件中去
		saveSortStudentInfoToFile("data3.txt", list1);
		saveSortStudentInfoToFile("data4.txt", list2);
		saveSortStudentInfoToFile("data5.txt", list3);
		printf("排序成功\n");
	}
	free(list1);
	free(list2);
	free(list3);
}
//释放内存
void destory(struct Accounts* userList, struct Node* list) {
	if (userList != NULL) {
		free(userList);
	}
	if (list != NULL) {
		free(list);
	}
}
//打印学生成绩
void printSingleStudent(struct Node*list ,char *sid) {
	struct Node* posNode = findStudentBySid(list, sid);
	if (posNode == NULL) {
		printf("暂无成绩\n");
		return;
	}
	printf("%-5s\t%-5s\t%s\t%-8s\t%s %s %s %s %s %s %s %s\n", "复试学号", "姓名", "报考学院", "报考类别", "基础课1", "基础课2", "专业课1", "专业课2", "初试成绩", "复试成绩", "口语成绩", "综合成绩");
	printf("%-5s\t%-5s\t%s\t%-8s\t %s\t %s\t %s\t %s\t %s\t %s\t   %s\t   %s\t\n", posNode->data.stu_id, posNode->data.name, posNode->data.colleage, posNode->data.type, posNode->data.course1, posNode->data.course2, posNode->data.course3, posNode->data.course4, posNode->data.ptest, posNode->data.retest, posNode->data.olanguage, posNode->data.comprehensive);
}