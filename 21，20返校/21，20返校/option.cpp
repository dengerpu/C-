#define _CRT_SECURE_NO_WARNINGS
#include "option.h"
const char* collegeArr[] = {
	"通信学院",
	"计算机学院",
	"光电学院",
	"自动化学院",
	"经管学院",
	"研究生院",
	"外语学院",
	"安法学院",
	"体育学院",
	"传媒学院",
	"先进制造学院",
	"马克思主义学院"
};
//初始化系统
void init() {
	char cmd[128];
	sprintf(cmd, "mode con lines=%d cols=%d", WIN_HEIGHT, WIN_WIDTH); //改变窗口大小
	system(cmd);
	//初始化链表，加载文件数据等操作
}
//菜单
void menu() {
	printMenuHead(MENU_WIDTH);
	printMenuMidInfo(MENU_WIDTH, "2020学生返校健康管理系统");
	printMenuMidInfo(MENU_WIDTH, "");
	const char* subMenus[] = {
		"1.添加学生信息",
		"2.修改学生信息",
		"3.菜单3",
		"4.菜单4",
		"5.菜单5",
		"6.菜单6",
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

//判断学号是否合法
int illegal(char* sid) {
	int year = 0, college_id = 0, num = 0;
	if (strlen(sid) < 0 || strlen(sid) > 9) {//学号长度大于0或者小于9不合法
		return 1;   
	}
	 year = getSidYear(sid);
	if (year < 2016 || year>2019) { //学号年份不合法
		return 1;    
	}
	college_id = getSidCollege(sid);
	if (college_id < 0 || college_id>12) {//学院代码不合法
		return 1;
	}
	num = getSidCollege(sid);
	if (num < 0 || num>999) {  //后三位不合法
		return 1;
	}
	return 0;
}
//计算健康状态
char getStatus( char isCough, char* temperate) {
	if (isCough == '1' && atof(temperate) >= 37.5) {  
		return '0';  //健康状态异常
	}
	return '1';	//健康状态正常
}
//输入学生信息
struct student inputStudent() {
	struct student tempData;
	memset(&tempData, 0, sizeof(tempData));
	printf("请输入学生的各项信息：\n");
	printf("学生学号：");
	scanf("%s", tempData.stu_id);
	while (illegal(tempData.stu_id)) {
		printf("该学号信息无效，请重新输入!\n");
		printf("学生学号：");
		scanf("%s", tempData.stu_id);
	}
	printf("学生姓名：");
	scanf("%s", tempData.name);
	printf("学生体温：");
	scanf("%s", tempData.temperate);
	getchar();
	printf("是否咳嗽：");
	scanf("%c", &(tempData.isCough));
	printf("时间：");
	scanf("%s", tempData.time);
	printf("日期：");
	scanf("%s", tempData.date);
	//获取健康状态
	tempData.status = getStatus(tempData.isCough, tempData.temperate);
	//获取学院
	int college_id = getSidCollege(tempData.stu_id);
	getCollege(college_id, tempData.colleage);
	return tempData;
}
//添加学生信息
void addStudent(struct Node* list) {
	struct student tempData = inputStudent();
	//插入链表中
	insertNodeNyHead(list,tempData);
	//保存到文件中
	saveStudentInfoToFile("data1.txt", list);
	
}
//根据学号查找学生信息
struct Node* findStudentByStuId(struct Node* list,char *sid) {
	struct Node* pMove = list->next;
	if (pMove == NULL) {
		return NULL;
	}
	while (pMove) {
		if (strcmp(pMove->data.stu_id, sid) == 0) {
			return pMove;
		}
		pMove = pMove->next;
	}
	return NULL;
}
//修改学生信息
void modifyStudent(struct Node* list) {
	char sid[20] = { 0 };
	char modifyItem[20] = { 0 };
	struct Node* modifyNode = NULL;
	printf("请输入需要修改信息的学生学号：");
	scanf("%s", sid);
	modifyNode = findStudentByStuId(list, sid);
	if (modifyNode == NULL) {
		printf("表为空或者该学生信息不存在\n");
	}
	else {
		printf("请输入要修改的项：");
		scanf("%s", modifyItem);
		if (strcmp(modifyItem, "学号") == 0) {
			printf("请输入学号：");
			scanf("%s", modifyNode->data.stu_id);
			while (illegal(modifyNode->data.stu_id)) {
				printf("该学号信息无效，请重新输入!\n");
				printf("学生学号：");
				scanf("%s", modifyNode->data.stu_id);
			}
		}else if (strcmp(modifyItem, "姓名") == 0) {
			printf("请输入姓名：");
			scanf("%s", modifyNode->data.name);
		}else if (strcmp(modifyItem, "体温") == 0) {
			printf("请输入体温：");
			scanf("%s", modifyNode->data.temperate);
		}
		else if (strcmp(modifyItem, "是否咳嗽") == 0) {
			printf("请输入是否咳嗽：");
			scanf("%c", &(modifyNode->data.isCough));
		}
		else if (strcmp(modifyItem, "时间") == 0) {
			printf("请输入时间：");
			scanf("%s", modifyNode->data.time);
		}
		else if (strcmp(modifyItem, "日期") == 0) {
			printf("请输入日期：");
			scanf("%s", modifyNode->data.date);
		}
		else {
			printf("输入有误\n");
			return;
		}
		//重新获取健康状态
		modifyNode->data.status = getStatus(modifyNode->data.isCough, modifyNode->data.temperate);
		//重新获取学院
		int college_id = getSidCollege(modifyNode->data.stu_id);
		getCollege(college_id, modifyNode->data.colleage);
		//保存到文件中
		saveStudentInfoToFile("data1.txt", list);
	}
}
//标题栏数据
char head[][COL_LEN_MAX] = { "学号","姓名","学院","体温","是否咳嗽","健康状态","时间","日期"};
//以表格形式打印数据
void printInfoByTable(struct Node* list) {
	struct Node* pMove = list->next;
	if (pMove == NULL) {
		printf("还没有学生信息！\n");
		return;
	}
	else {
		int cols = sizeof(head) / sizeof(head[0]);
		char row[8][COL_LEN_MAX];
		//system("cls");
		printTableHead(TABLE_WIDTH, cols);
		printTableRow(TABLE_WIDTH, head, cols);
		printTableMidLine(TABLE_WIDTH, cols);
		while (pMove) {
			sprintf(row[0], "%s", pMove->data.stu_id);
			sprintf(row[1], "%s", pMove->data.name);
			sprintf(row[2], "%s", pMove->data.colleage);
			sprintf(row[3], "%s", pMove->data.temperate);
			sprintf(row[4], "%c", pMove->data.isCough);
			sprintf(row[5], "%c", pMove->data.status);
			sprintf(row[6], "%s", pMove->data.time);
			sprintf(row[7], "%s", pMove->data.date);
			printTableRow(TABLE_WIDTH, row, cols);
			if (pMove->next!=NULL) {   //还没有到最后一行
				printTableMidLine(TABLE_WIDTH, cols);
			}
			else {
				printTableTail(TABLE_WIDTH, cols);
			}
			pMove = pMove->next;
		}
			char buff[64];
			sprintf(buff, "共%d条数据\n", getStudentLenth(list));
			printMidInfo(buff);
			
		}
}

//打印学生数组
void printStudentArr(struct student* arr, int length) {
	if (arr == NULL) {
		printf("表为空\n");
		return;
	}
	/*printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", "学号", "姓名", "身份证号", "学院", "学生类型", "专业", "返校路线", "交通工具", "密切接触", "温度", "过去14天病史", "是否发烧", "进校时间");
	for (int i = 0; i < length; i++) {
		printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", arr[i].stu_id, arr[i].name, arr[i].sid, arr[i].college, arr[i].type, arr[i].major, arr[i].route, arr[i].traffic, arr[i].isClose, arr[i].temperate, arr[i].history, arr[i].isCough, arr[i].time);
	}*/
}
//通过综合成绩排名
int cmp_by_comprehensive(const void* e1, const void* e2) {
	//return (strcmp(((struct student*)e1)->comprehensive ,((struct student*)e2)->comprehensive));
	return 1;
}
//排序
void sort() {
	struct students p1;
	InitStudents(&p1);
	//快速排序
	qsort(p1.data, p1.size, sizeof(p1.data[0]), cmp_by_comprehensive);
	free(p1.data);
	p1.data = NULL;
}
//释放内存
void destory(struct Node* list) {
	free(list);
	list = NULL;
}