#define _CRT_SECURE_NO_WARNINGS
#include "option.h"
//初始化系统
void init() {
	char cmd[128];
	sprintf(cmd, "mode con lines=%d cols=%d", WIN_HEIGHT, WIN_WIDTH); //改变窗口大小
	system(cmd);
	//初始化链表，加载文件数据等操作
}
//登陆
int login() {
	char user[20] = { 0 };
	char pwd[20] = { 0 };
	int i = 3;
	char buff[64] = { 0 };
	while (i--) {
		printMenuHead(MENU_WIDTH);
		printMenuMidInfo(MENU_WIDTH, "登陆系统");
		printMenuTail(MENU_WIDTH);
		printMidInfo("账号：");
		scanf("%s", user);
		printMidInfo("密码：");
		scanf("%s", pwd);
		if (strcmp(user, "admin") == 0 && strcmp(pwd, "admin")==0) {
			printMidInfo("登陆成功\n");
			return 1;
		}
		else {
			if (i != 0) {
				sprintf(buff, "你还有%d次机会\n", i);
				printMidInfo(buff);
			}	
		}
		system("pause");
		system("cls");
	}
	return 0;
}
//菜单
void menu() {
	printMenuHead(MENU_WIDTH);
	printMenuMidInfo(MENU_WIDTH, "返校信息管理系统");
	printMenuMidInfo(MENU_WIDTH, "");
	const char* subMenus[] = {
		"1.添加学生信息",
		"2.根据学院排序",
		"3.菜单3",
		"4.查找学生信息",
		"5.修改学生信息",
		"6.打印学生信息",
		"0.退出系统"
	};
	int count = sizeof(subMenus) / sizeof(subMenus[0]);
	for (int i = 0; i < count; i++) {
		printMenuMidInfo(MENU_WIDTH, subMenus[i]);
	}
	printMenuMidInfo(MENU_WIDTH, "");
	printMenuTail(MENU_WIDTH);
	printMidInfo("请选择（0-6）");
}

////标题栏数据
//char head[][COL_LEN_MAX] = { "学号","姓名","身份证号","学院","学生类型","专业","返校路线","交通工具","密切接触","温度","过去14天病史","是否发烧","进校时间" };
////打印学生信息
//void printStudent(struct Node* list) {
//	struct Node* pMove = list->next;
//	if (pMove == NULL) {
//		printMidInfo("表为空\n");
//		return;
//	}
//	int col = sizeof(head) / sizeof(head[0]);
//	char row[13][COL_LEN_MAX];
//	int i = 0;
//	//system("cls");
//	printTableHead(TABLE_WIDTH, col);
//	printTableRow(TABLE_WIDTH, head, col);
//	printTableMidLine(TABLE_WIDTH, col);
//	while (pMove) {
//		sprintf(row[0], "%s", pMove->data.stu_id);
//		sprintf(row[1], "%s", pMove->data.name);
//		sprintf(row[2], "%s", pMove->data.sid);
//		sprintf(row[3], "%s", pMove->data.college);
//		sprintf(row[4], "%s", pMove->data.type);
//		sprintf(row[5], "%s", pMove->data.major);
//		sprintf(row[6], "%s", pMove->data.route);
//		sprintf(row[7], "%s", pMove->data.traffic);
//		sprintf(row[8], "%s", pMove->data.isClose);
//		sprintf(row[9], "%s", pMove->data.temperate);
//		sprintf(row[10], "%s", pMove->data.history);
//		sprintf(row[11], "%s", pMove->data.isCough);
//		sprintf(row[12], "%s", pMove->data.time);
//		printTableRow(TABLE_WIDTH, row, col);
//		if (pMove->next != NULL) {
//			printTableMidLine(TABLE_WIDTH, col);
//		}
//		else {
//			printTableTail(TABLE_WIDTH, col);
//		}
//		pMove = pMove->next;
//		i++;
//	}
//	char buff[64];
//	sprintf(buff, "共%d条 \n" ,i);
//	printMidInfo(buff);
//}
void printStudent(struct Node* list) {
	struct Node* pMove = list->next;
	if (pMove == NULL) {
		printf("表为空\n");
		return;
	}
	printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", "学号", "姓名", "身份证号", "学院", "学生类型", "专业", "返校路线", "交通工具", "密切接触", "温度", "过去14天病史", "是否发烧", "进校时间");
	while (pMove) {
		printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", pMove->data.stu_id, pMove->data.name, pMove->data.sid, pMove->data.college, pMove->data.type, pMove->data.major, pMove->data.route, pMove->data.traffic, pMove->data.isClose, pMove->data.temperate, pMove->data.history, pMove->data.isCough, pMove->data.time);
		pMove = pMove->next;
	}
}
//打印数组
void printStudentArr(struct student* arr, int length) {
	if (arr == NULL) {
		printf("表为空\n");
		return;
	}
	printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", "学号", "姓名", "身份证号", "学院", "学生类型", "专业", "返校路线", "交通工具", "密切接触", "温度", "过去14天病史", "是否发烧", "进校时间");
	for (int i = 0; i < length; i++) {
		printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", arr[i].stu_id, arr[i].name, arr[i].sid, arr[i].college, arr[i].type, arr[i].major, arr[i].route, arr[i].traffic, arr[i].isClose, arr[i].temperate, arr[i].history, arr[i].isCough, arr[i].time);
	}
}
//输入学生信息
struct student inputStudent() {
	struct student tempData;
	memset(&tempData, 0, sizeof(tempData));
	printf("请输入学号:");
	scanf("%s", tempData.stu_id);
	printf("请输入姓名:");
	scanf("%s", tempData.name);
	printf("请输入身份证号:");
	scanf("%s", tempData.sid);
	printf("请输入学院:");
	scanf("%s", tempData.college);
	printf("请输入类型:");
	scanf("%s", tempData.type);
	printf("请输入专业:");
	scanf("%s", tempData.major);
	printf("请输入返校路线:");
	scanf("%s", tempData.route);
	printf("请输入交通工具:");
	scanf("%s", tempData.traffic);
	printf("请输入是否密切接触:");
	scanf("%s", tempData.isClose);
	printf("请输入温度:");
	scanf("%s", tempData.temperate);
	printf("请输入过去14天病史:");
	scanf("%s", tempData.history);
	printf("请输入是否发烧咳嗽:");
	scanf("%s", tempData.isCough);
	printf("请输入进校时间:");
	scanf("%s", tempData.time);
	return tempData;
}

//添加学生信息
void addStudent(struct Node* list) {
	struct student tempData = inputStudent();
	//插入链表中
	insertNodeNyHead(list, tempData);
	//存入文件
	saveStudentInfoToFile(list);
	//保存所有学生到文件中去
	saveALLStudentInfoToFile("data.txt", list);
}
//根据学生学号或姓名或身份证号
struct Node* searchStudent(struct Node* list) {
	struct Node *newList = createList();
	struct Node* pMove = list->next;
	if (pMove == NULL) {
		printf("表为空\n");
		return NULL;
	}
	char query[20] = { 0 };
	printf("请输入要搜索的关键字（学号姓名身份证号均可（学号身份证号为主关键字））:");
	int flag = 1;
	scanf("%s", query);
	while (pMove != NULL) {
		if (strcmp(query, pMove->data.stu_id) == 0 || strcmp(query, pMove->data.sid) == 0 || strcmp(query, pMove->data.name) == 0) {
			if (flag) {
				printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", "学号", "姓名", "身份证号", "学院", "学生类型", "专业", "返校路线", "交通工具", "密切接触", "温度", "过去14天病史", "是否发烧", "进校时间");
				
				flag = 0;
			}
			insertNodeNyHead(newList, pMove->data);
			printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", pMove->data.stu_id, pMove->data.name, pMove->data.sid, pMove->data.college, pMove->data.type, pMove->data.major, pMove->data.route, pMove->data.traffic, pMove->data.isClose, pMove->data.temperate, pMove->data.history, pMove->data.isCough, pMove->data.time);
		}
		pMove = pMove->next;
	}
	if (flag) {
		printf("查无此人\n");
		return NULL;
	}
	return newList;

}
int cmp_by_college(const void* e1, const void* e2) {
	
	if (strcmp(((struct student*)e1)->type, ((struct student*)e2)->type) > 0) {//先按学生类型排
		return 1;
	}else if (strcmp(((struct student*)e1)->type, ((struct student*)e2)->type) < 0) {
		return -1;
	}
	else if (strcmp(((struct student*)e1)->type, ((struct student*)e2)->type) == 0) {
		if (strcmp(((struct student*)e1)->major, ((struct student*)e2)->major) > 0) {
			return 1;
		}
		else if (strcmp(((struct student*)e1)->major, ((struct student*)e2)->major) < 0) {
			return -1;
		}
		else if (strcmp(((struct student*)e1)->major, ((struct student*)e2)->major) == 0) {
			if (strcmp(((struct student*)e1)->stu_id, ((struct student*)e2)->stu_id) > 0) {//先按学生类型排
				return 1;
			}
			else if (strcmp(((struct student*)e1)->stu_id, ((struct student*)e2)->stu_id) < 0) {
				return -1;
			}
			else {
				return 0;
			}
		}
	}
}
//排序
void sortStudent(struct Node* list) {
	const char* collegeArr[] = {
		"通信学院",
		"计算机学院",
		"自动化学院",
		"先进制造学院",
		"光电学院",
		"软件学院",
		"理学院",
		"经管学院",
		"传媒学院",
		"外语学院",
		"国际学院",
		"安法学院"
	};
	int count = sizeof(collegeArr) / sizeof(collegeArr[0]);
	char college[20] = { 0 };
	char filename[20] = { 0 };
	int flag = 1;
	struct students arr;
	InitStudents(&arr);
	while (flag) {
		printf("请输入学院名:");
		scanf("%s", college);
		for (int i = 0; i < count; i++) {
			if (strcmp(college, collegeArr[i]) == 0) {
				flag = 0;
			}
		}
	}
	strcpy(filename, college);
	char newfilename[20] = { 0 };
	strcpy(newfilename, filename);
	strcat(filename, ".txt");
	FILE* fp = fopen(filename, "r+");
	if (fp == NULL) {
		printf("无该学院信息\n");
	}
	else {
		struct student tempData;
		while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", tempData.stu_id, tempData.name, tempData.sid, tempData.college, tempData.type, tempData.major, tempData.route, tempData.traffic, tempData.isClose, tempData.temperate, tempData.history, tempData.isCough, tempData.time) != EOF) {
			arr.data[arr.size++] = tempData;
			CheckCapacity(&arr);
			memset(&tempData, 0, sizeof(tempData));
		}
	}
	if (arr.size == 0) {
		printf("该学院无学生信息\n");
	}
	else {
		qsort(arr.data, arr.size, sizeof(arr.data[0]), cmp_by_college);
		printStudentArr(arr.data, arr.size);
		strcat(newfilename, "排序.txt");
		saveStudentArrInfoToFile(newfilename, arr.data, arr.size);
	}
	fclose(fp);
	fp = NULL;
	free(arr.data);
	arr.data = NULL;
}
void modifyStudent() {
	const char* collegeArr[] = {
		"通信学院",
		"计算机学院",
		"自动化学院",
		"先进制造学院",
		"光电学院",
		"软件学院",
		"理学院",
		"经管学院",
		"传媒学院",
		"外语学院",
		"国际学院",
		"安法学院"
	};
	int count = sizeof(collegeArr) / sizeof(collegeArr[0]);
	char college[20] = { 0 };
	char filename[20] = { 0 };
	int flag = 1;
	struct Node* newList = createList();
	while (flag) {
		printf("请输入学院名:");
		scanf("%s", college);
		for (int i = 0; i < count; i++) {
			if (strcmp(college, collegeArr[i]) == 0) {
				flag = 0;
			}
		}
	}
	strcpy(filename, college);
	char newfilename[20] = { 0 };
	strcpy(newfilename, filename);
	strcat(newfilename, "排序.txt");
	FILE* fp = fopen(newfilename, "r+");
	if (fp == NULL) {
		printf("无该学院信息\n");
	}
	else {
		struct student tempData;
		while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", tempData.stu_id, tempData.name, tempData.sid, tempData.college, tempData.type, tempData.major, tempData.route, tempData.traffic, tempData.isClose, tempData.temperate, tempData.history, tempData.isCough, tempData.time) != EOF) {
			insertNodeNyHead(newList, tempData);
			memset(&tempData, 0, sizeof(tempData));
		}
	}
	if (newList->next == 0) {
		printf("该学院无学生信息\n");
	}
	else {
		char query[20] = { 0 };
		printf("请输入要修改的学生学号:");
		scanf("%s", query);
		struct Node* pMove = newList->next;
		int findFlag = 1;
		while (pMove) {
			if (strcmp(query, pMove->data.stu_id) == 0) {
				struct student modifyStudent = inputStudent();
				findFlag = 0;
				pMove->data = modifyStudent;
			}
			pMove = pMove->next;
		}
		if (findFlag == 1) {
			printf("无此人\n");
		}
		else {
			saveALLStudentInfoToFile(newfilename, newList);
		}

	}
	fclose(fp);
	fp = NULL;

}