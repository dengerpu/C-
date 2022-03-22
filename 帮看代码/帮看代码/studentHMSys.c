#define _CRT_SECURE_NO_WARNINGS

#include"singleList.h"

/***************学生基本信息链表****************/
Node* list;

/***************学生查询与统计链表****************/
Node* list2;

/***************健康异常统计链表****************/
Node* list3;

/***************健康状况预警链表****************/
Node* list4;

/*****函数声明*********/
//////////////////////////////////////////////////////
// 主业务
//////////////////////////////////////////////////////
//	增加：
void  addStudent();
//	删除：
void deleteStudent();
//	查找：
void queryStudent();
//	修改：
void updateStudnt();
//	打印所有信息: 
void printAll();
//	统计学生信息：
void stats();
//	统计异常信息
void exceptionStats();
//	处理异常信息
void handleExceptions();
/////////////////////////////////////////////
//辅助业务
/////////////////////////////////////////////
//	学院获取
void getAcademy(char* stuID, char* academy);
//	健康状态获取
int getState(int temperature, int cough);
//	获取学号
void getStuID(char* stuID);
//	获取时间
void getTime(char* time);
//	获取日期
void getDate(char* date);
//	主菜单：
void mainMenu();

int main() {


	list = createList();
	list2 = createList();
	list3 = createList();
	list4 = createList();
	
	readFile("data1.txt", list);
	readFile("data2.txt", list2);

	exceptionStats();
	handleExceptions();
	
	sortByDate(list);
	sortByDate(list2);
	sortByDate(list3);
	sortByDate(list4);

	mainMenu();


	getchar();
	return 0;
}


/****************函数定义*****************/
//////////////////////////////////////////

/*
 函数功能：循环显示主菜单，提供选择项提示
		  根据输入选择项调用主业务函数 
 参数：无
 返回值：无
*/
void mainMenu() {
	int select = 0;
	printf("|--------------------------------------|\n");
	printf("|---  欢迎使用学生返校健康管理系统  ---|\n");
	printf("|--------------------------------------|\n");
	printf("\n");
	while (1) {
		printf("|------------------------------|\n");
		printf("|       1. 增加学生信息        |\n");
		printf("|       2. 删除学生信息        |\n");
		printf("|       3. 修改学生信息        |\n");
		printf("|       4. 查找学生信息        |\n");
		printf("|       5. 打印全部信息        |\n");
		printf("|       6. 统计学生信息        |\n");
		printf("|       7. 统计异常信息        |\n");
		printf("|       8. 处理异常信息        |\n");
		printf("|       0. 退出系统            |\n");
		printf("|------------------------------|\n");
		printf("请选择业务：");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			addStudent();
			break;
		case 2:
			deleteStudent();
			break;
		case 3:
			updateStudnt();
			break;
		case 4:
			queryStudent();
			break;
		case 5:
			printAll();
			break;
		case 6:
			stats();
			break;
		case 7:
			printList(list3);
			break;
		case 8:
			printList(list4);
			break;
		case 0:
			exit(0);
		default:
			printf("您的选择有误，请重新选择！\n");
		}
	}

}

/*
 函数功能：添加学生信息
 参数：无
 返回值：无
*/
void addStudent() {
	int loop = 1;
	int select = 0;
	student stu;
	while (loop) {
		printf("----------  增加学生信息  ----------\n");
		printf("姓名：");
		scanf("%s", stu.name);

		getStuID(stu.stuID);//学号
		
		printf("体温：");
		scanf("%f", &stu.temperature);

		printf("是否咳嗽(1是 0否)：");
		scanf("%d", &stu.cough);

		getTime(stu.time);//时间

		getDate(stu.date);//日期

		getAcademy(stu.stuID, stu.academy);//学院
		stu.state = getState(stu.temperature, stu.cough);//健康状态
		stu.day = 0;

		insertNode(list, stu);//插入链表
		writeFile("data1.txt", list);//保存到基本信息文件中
		printf("是否继续添加？1是 0否：");
		while (1) {
			scanf("%d", &select);
			if (select == 1) {
				break;
			}
			else if (select == 0) {
				loop = 0;
				break;
			}
			else {
				printf("输入有误请重新输入(1或0)：");
				continue;
			}
		}
		
	}
	
}

/*
函数功能；删除学生信息，将学生状态置state为0 
参数：无
返回值： 无 
*/
void deleteStudent() {
	int loop = 1;
	int select = 0;
	char stuID[20];
	printf("----------  删除学生信息  ----------\n");
	while (loop) {
		printf("请输入需要删除的学生学号：");
		scanf("%s", stuID);
		deleteNode(list, stuID);
		writeFile("data1.txt", list);//保存到文件
		printf("是否继续删除？1是 0否：");
		while (1) {
			scanf("%d", &select);
			if (select == 1) {
				break;
			}
			else if (select == 0) {
				loop = 0;
				break;
			}
			else {
				printf("输入有误请重新输入(1或0)：");
				continue;
			}
		}
	}
	
}

/*
函数功能；修改学生信息，先根据学号查找
		  找到后重新输入学生数据，然后
		  再写文件
参数：无
返回值： 无
*/
void updateStudnt() {
	int loop = 1;
	int select = 0;
	Node* node;
	char* date[20] = { "" };
	char* stuID[20] = {""};
	printf("----------  修改学生信息  ----------\n");
	while (loop) {
		getStuID(stuID);
		getDate(date);

		node = searchNodeByID(list, stuID,date);

		if (node == NULL) {
			printf("没有找到学生信息!");
			continue;
		}

		printf("姓名：");
		scanf("%s", node->data.name);

		getStuID(stuID);

		printf("体温：");
		scanf("%f", &node->data.temperature);

		printf("是否咳嗽(1是 0否)：");
		scanf("%d", &node->data.cough);

		getTime(node->data.time);//时间

		getDate(node->data.date);//日期

		getAcademy(node->data.stuID, node->data.academy);//学院识别
		
		node->data.state = getState(node->data.temperature, node->data.cough);//状态识别
		writeFile("data1.txt", list);//保存到文件

		printf("是否继续修改？1是 0否：");

		while (1) {
			scanf("%d", &select);
			if (select == 1) {
				break;
			}
			else if (select == 0) {
				loop = 0;
				break;
			}
			else {
				printf("输入有误请重新输入(1或0)：");
				continue;
			}
		}
	}
	
}

/*
函数功能；查询学生信息，可以根据学号
		  和姓名查询
参数：无
返回值： 无
*/
void queryStudent() {
	Node* newNode = NULL;
	int loop = 1;
	int select = 0;
	char* date[20] = { "" };
	char* stuID[20] = {""};
	printf("----------  查询学生信息  ----------\n");
	while (loop) {
		getStuID(stuID);
		getDate(date);
		newNode = searchNode(list, stuID, date);
		if (newNode == NULL) {
			printf("未找到相关信息！");
		}else{
			printCurNode(newNode);
		}
		
		printf("是否继续查询？1是 0否：");

		while (1) {
			scanf("%d", &select);
			if (select == 1) {
				break;
			}
			else if (select == 0) {
				loop = 0;
				break;
			}
			else {
				printf("输入有误请重新输入(1或0)：");
				continue;
			}
		}
	}
}

/*
函数功能；输出全部学生信息
参数：无
返回值： 无
*/
void printAll() {
	printf("----------  输出全部信息  ----------\n");
	printList(list);
}

/*
函数功能：分别按学号、姓名两种形式对学生信息统计
参数：无
返回值：无
*/
void stats() {
	if (list->next == NULL) {
		return;
	}
	Node* newNode = NULL;//list链表中查询到的结点
	Node* newNode2 = NULL;//list2链表中查询到的结点
	Node* pNode = list;//list链表遍历指针
	Node* pNode2 = list2;//list2链表遍历指针
	int mode = 0;//统计方式
	int loop = 1;//外循环控制
	int select = 0;//是否继续添加选择
	char* date[20];
	char* name[20];
	char* stuID[20];
	printf("----------  统计学生信息  ----------\n");
	while (loop) {
		printf("请输入统计方式 1按学号 0按姓名：");
		scanf("%d", &mode);
		switch (mode) {
		case 0://按姓名查找
			printf("请输入学生姓名：");
			scanf("%s", name);
			getDate(date);
			while ((newNode = searchNodeByName(pNode, name)) != NULL) {
				pNode2 = list2;
				if (list2->next == NULL) {
					insertNode(list2, newNode->data);
					writeFile("data2.txt", list2);
				}
				else {
					while ((newNode2 = searchNodeByName(pNode2, name)) != NULL) {
						if (strcmp(newNode2->data.date, newNode->data.date) == NULL) {
							break;
						}
						pNode2 = newNode2;
					}
					if (newNode2 == NULL) {
						insertNode(list2, newNode->data);
						writeFile("data2.txt", list2);
					}
				}
				pNode = newNode;//继续向下查询
			}
			
			printList(list2);
			break;
		case 1://按学号查询
			getStuID(stuID);
			getDate(date);
			while ((newNode = searchNodeByID(pNode, stuID)) != NULL) {
				pNode2 = list2;
				if (list2->next == NULL) {//链表为空
					insertNode(list2, newNode->data);
					writeFile("data2.txt", list2);
				}
				else{
					while ((newNode2 = searchNodeByID(pNode2, stuID)) != NULL) {
						if (strcmp(newNode2->data.date, newNode->data.date) == NULL) {
							break;
						}
						pNode2 = newNode2;
					}
					if (newNode2 == NULL) {
						insertNode(list2, newNode->data);
						writeFile("data2.txt", list2);
					}
				}
				pNode = newNode;//继续向下查询
			}
			printList(list2);
			break;
		default:
			printf("输入有误，请重新输入统计方式：");
			break;
		}

		//printCurNode(searchNode(list, stuID));

		printf("是否继续查询？1是 0否：");
		while (1) {
			scanf("%d", &select);
			if (select == 1) {
				break;
			}
			else if (select == 0) {
				loop = 0;
				break;
			}
			else {
				printf("输入有误请重新输入是否继续查询？1是 0否：");
				continue;
			}
		}
	}
}

/*
函数功能：统计每天健康状态为异常的学生信息
		  便于后期重点观察与健康管理
参数：无
返回值：无
*/
void exceptionStats() {
	if (list->next == NULL) {
		return;
	}
	Node* pNode = list->next;
	//printf("----------  统计异常信息  ----------\n");
	while (pNode) {
		if (pNode->data.state == 0) {
			insertNode(list3, pNode->data);
			writeFile("data3.txt", list3);
		}
		pNode = pNode->next;
	}
}

/*
函数功能：健康状况预警，当某学生健康状况连续三天及以上
		  为非正常时，给出紧急提示
参数：无
返回值：无
*/
void handleExceptions() {
	if (list3->next == NULL) {
		return;
	}
	Node* pNode3 = list3->next;
	Node* pNode4 = list4;
	Node* newNode = NULL;
	//printf("----------  处理异常信息  ----------\n");
	while (pNode3) {
		pNode4 = list4;
		if (list4->next == NULL) {//链表为空
				insertNode(list4, pNode3->data);
				writeFile("data4.txt", list4);
			}
		else {
			while ((newNode = searchNodeByID(pNode4, pNode3->data.stuID)) != NULL) {
				if (strcmp(newNode->data.date, pNode3->data.date) == NULL) {
					break;
				}
				pNode4 = newNode;
			}
			if (newNode == NULL) {
				insertNode(list4, pNode3->data);
				writeFile("data4.txt", list4);
			}
		}
	pNode3 = pNode3->next;
	}
}

/*
函数功能：根据学号的第5、6位识别学院名称
参数：学生学号、需要识别的院校
返回值：无
*/
void getAcademy(char* stuID,char* academy) {
	char* num[4] = {""};
	strncpy(num, stuID + 4, 2);
	num[3] = '\0';
	switch (atol(num)) {
		case 1:
			strcpy(academy, "通信学院");
			break;
		case 2:
			strcpy(academy, "计算机学院");
			break;
		case 3:
			strcpy(academy, "光电学院");
			break;
		case 4:
			strcpy(academy, "自动化学院");
			break;
		case 5:
			strcpy(academy, "经管学院");
			break;
		case 6:
			strcpy(academy, "研究生院");
			break;
		case 7:
			strcpy(academy, "外语学院");
			break;
		case 8:
			strcpy(academy, "安发学院");
			break;
		case 9:
			strcpy(academy, "体育学院");
			break;
		case 10:
			strcpy(academy, "传媒学院");
			break;
		case 11:
			strcpy(academy, "先进制造学院");
			break;
		case 12:
			strcpy(academy, "马克思主义学院");
			break;
	}
}

/*
函数功能：获取学生的健康状态，当学生体温>=37℃
		  或者存在咳嗽情形时，健康状态为异常
		  其余情形正常
参数：学生体温temperature，咳嗽状态cough
返回值：健康状态
*/
int getState(float temperature, int cough) {
	if (temperature <= 37.3 && cough == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void getStuID(char* stuID) {
	char num1[10] = {""};
	char num2[5] = { "" };
	char num3[10] = { "" };
	printf("学号：");
	while (1) {
		scanf("%s", stuID);
		strncpy(num1, stuID, 4);
		num1[4] = '\0';
		strncpy(num2, stuID + 4, 2);
		num2[2] = '\0';
		strncpy(num3, stuID + 6, 3);
		num3[3] = '\0';
		if (strlen(stuID) != 9) {
			printf("学号格式错误，请重新输入!");
			continue;
		}
		if (atol(num1) < 2016 || atol(num1) > 2019 ||
			atol(num2) < 1 || atol(num2) > 12 ||
			atol(num3) < 1 || atol(num3) > 999) {
			printf("学号格式错误，请重新输入！");
			continue;
		}
		else {
			break;
		}
	}
}


/*
函数功能：获取时间，格式为xx：xx
参数：时间
返回值：无
*/
void getTime(char* time) {
	char num1[5] = { "" };
	char num2[5] = { "" };
	char num3[5] = { "" };
	printf("时间：");
	while (1) {
		scanf("%s", time);
		strncpy(num1, time, 2);
		num1[2] = '\0';
		strncpy(num2, time + 2, 1);
		num2[1] = '\0';
		strncpy(num3, time + 3, 2);
		num3[2] = '\0';
		if (strlen(time) != 5) {
			printf("时间格式错误，请重新输入!");
			continue;
		}
		if (atol(num1) < 0 || atol(num1) > 24 ||
			strcmp(num2,":") != 0 ||
			atol(num3) < 0 || atol(num3) > 59) {
			printf("时间格式错误，请重新输入！");
			continue;
		}
		else {
			break;
		}
	}
}

/*
函数功能：获取日期，格式为四位年份+两位月份+两位天数
		  统计时段为2022年4月29至2022年5月12日
参数：时间
返回值：无
*/
void getDate(char* date) {
	char num1[10] = { "" };
	char num2[5] = { "" };
	char num3[5] = { "" };
	printf("日期：");
	while (1) {
		scanf("%s", date);
		strncpy(num1, date, 4);
		num1[4] = '\0';
		strncpy(num2, date + 4, 2);
		num2[2] = '\0';
		strncpy(num3, date + 6, 2);
		num3[2] = '\0';
		if (strlen(date) != 8) {
			printf("日期格式错误，请重新输入!");
			continue;
		}
		if (strcmp(num1,"2022") != 0 ) {
			printf("日期格式错误，请重新输入！");
			continue;
			
		}
		if (strcmp(num2, "04") != 0 && strcmp(num2, "05") != 0) {
			printf("日期格式错误，请重新输入！");
			continue;
		}
		if (strcmp(num2, "04") == 0) {
			if (atol(num3) < 29 || atol(num3) > 30) {
				printf("日期格式错误，请重新输入！");
				continue;
			}
			else {
				break;
			}
		}
		if (strcmp(num2, "05") == 0) {
			if (atol(num3) < 1 || atol(num3) > 12) {
				printf("日期格式错误，请重新输入！");
				continue;
			}
			else {
				break;
			}
		}
		
	}
}