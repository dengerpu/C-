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
	printMenuMidInfo(MENU_WIDTH, "学生信息管理系统");
	printMenuMidInfo(MENU_WIDTH, "");
	const char* subMenus[] = {
		"1.菜单1",
		"2.菜单2",
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
//标题栏数据
char head[][COL_LEN_MAX] = { "标题1","标题2","标题3","标题4","标题5","标题6" };
int length = 1;
//以表格形式打印数据
void printInfoByTable() {
	if (length == 0) {
		printf("还没有学生信息！\n");
		return;
	}
	int cols = sizeof(head) / sizeof(head[0]);
	char row[6][COL_LEN_MAX];
	//system("cls");
	printTableHead(TABLE_WIDTH, cols);
	printTableRow(TABLE_WIDTH, head, cols);
	printTableMidLine(TABLE_WIDTH, cols);
	for (int i = 0; i < length; i++) {
		sprintf(row[0], "%s","内容1");
		sprintf(row[1], "%s", "内容2");
		sprintf(row[2], "%s", "马克思主义学院");
		sprintf(row[3], "%s", "内容4");
		sprintf(row[4], "%s", "内容5");
		sprintf(row[5], "%s", "内容6");
		printTableRow(TABLE_WIDTH, row, cols);
		if (i < length-1) {
			printTableMidLine(TABLE_WIDTH, cols);
		}
		else {
			printTableTail(TABLE_WIDTH, cols);
		}
	}
	char buff[64];
	sprintf(buff, "共%d条数据\n",length);
	printMidInfo(buff);
}
//打印学生链表
void printStudentList(struct Node* list) {
	struct Node* pMove = list->next;
	if (pMove == NULL) {
		printf("表为空\n");
		return;
	}
	//printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", "学号", "姓名", "身份证号", "学院", "学生类型", "专业", "返校路线", "交通工具", "密切接触", "温度", "过去14天病史", "是否发烧", "进校时间");
	//while (pMove) {
	//	printf("%-11s  %-10s%-18s  %-10s  %-10s %-10s %-10s %-10s %-10s %-10s %-16s %-10s %-10s\n", pMove->data.stu_id, pMove->data.name, pMove->data.sid, pMove->data.college, pMove->data.type, pMove->data.major, pMove->data.route, pMove->data.traffic, pMove->data.isClose, pMove->data.temperate, pMove->data.history, pMove->data.isCough, pMove->data.time);
	//	pMove = pMove->next;
	//}
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
//输入学生信息
struct student inputStudent() {
	struct student tempData;
	memset(&tempData, 0, sizeof(tempData));
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
	int total = atof(tempData.course1) + atof(tempData.course2) + atof(tempData.course3) + atof(tempData.course4);
	_gcvt(total, 5, tempData.ptest);   //因为采用的是浮点数，出现整数100将是100. 多个点，所以就把这个点去掉
	removedot(tempData.ptest, strlen(tempData.ptest));
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
	_gcvt(totalGrade, 5, tempData.comprehensive);
	removedot(tempData.comprehensive, strlen(tempData.comprehensive));
	return tempData;
}
//通过综合成绩排名
int cmp_by_comprehensive(const void* e1, const void* e2) {
	return (strcmp(((struct student*)e1)->comprehensive ,((struct student*)e2)->comprehensive));
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
//释放内存
void destory(struct Node* list) {
	free(list);
	list = NULL;
}