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
//登陆
int login() {
	char user[20] = { 0 };
	char pwd[20] = { 0 };
	int i = 3;
	while (i--) {
		printMenuHead(MENU_WIDTH);
		printMenuMidInfo(MENU_WIDTH, "全球新冠疫情管理系统");
		printMenuMidInfo(MENU_WIDTH, "");
		printMenuTail(MENU_WIDTH);
		printMidInfo("账号:");
		scanf("%s", user);
		printMidInfo("密码:");
		scanf("%s", pwd);
		if (strcmp(user, "admin") == 0 && strcmp(pwd, "admin") == 0) {
			printMidInfo("登陆成功\n");
			system("pause");
			system("cls");
			return 1;
		}
		if (i != 0) {
			char buff[32];
			sprintf(buff, "你还有%d次机会\n", i);
			printMidInfo(buff);
		}
		system("pause");
		system("cls");
	}
	return 0;
	
}

//标题栏数据
char head[][COL_LEN_MAX] = { "国家", "洲", "人口总数", "国土面积", "建成区面积", "密度", "新增确诊", "累计确诊", "累计死亡", "累计治愈", "死亡率", "治愈率", "严重指数" };
int length = 1;
//以表格形式打印数据
void printInfoByTable() {
	if (length == 0) {
		printf("还没有学生信息！\n");
		return;
	}
	int cols = sizeof(head) / sizeof(head[0]);
	char row[13][COL_LEN_MAX];
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
	//printf("%-10s  %-10s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "国家", "洲", "人口总数", "国土面积", "建成区面积", "密度", "新增确诊", "累计确诊", "累计死亡", "累计治愈", "死亡率", "治愈率", "严重指数");
	//while (pMove) {
	//	printf("%-10s  %-10s\t%d\t%.0lf\t%.0lf\t%.0lf\t%d\t%d\t%d\t%d\t%.2lf\t%.2lf\t%.2lf\n", pMove->data.country_name, pMove->data.continent, pMove->data.total_peoples, pMove->data.country_area, pMove->data.builder_area, pMove->data.people_density, pMove->data.add, pMove->data.total, pMove->data.death, pMove->data.cure, pMove->data.mortality, pMove->data.cure_rate, pMove->data.severity_index);
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
struct country inputStudent() {
	struct country tempData;
	memset(&tempData, 0, sizeof(tempData));
	printf("请输入国家：");
	scanf("%s", tempData.country_name);
	printf("请输入所属洲：");
	scanf("%s", tempData.continent);
	printf("请输入人口总数：");
	scanf("%d", &(tempData.total_peoples));
	printf("%d\n", tempData.total_peoples);
	printf("请输入国土面积：");
	scanf("%lf", &(tempData.country_area));
	printf("%.0lf\n", tempData.country_area);
	printf("请输入建成区面积：");
	scanf("%lf", &(tempData.builder_area));
	printf("%.0lf\n", tempData.builder_area);
	printf("请输入新增确诊：");
	scanf("%d", &(tempData.add));
	printf("%d\n", tempData.add);
	printf("请输入累计确诊：");
	scanf("%d", &(tempData.total));
	printf("%d\n", tempData.total);
	printf("请输入累计死亡：");
	scanf("%d", &(tempData.death));
	printf("%d\n", tempData.death);
	printf("请输入累计治愈：");
	scanf("%d", &(tempData.cure));
	printf("%d\n", tempData.cure);
	//现存确诊数=累计确诊-累计死亡-累计治愈
	int current = tempData.total - tempData.death - tempData.cure;
	//现存确诊率
	double current_r = current / tempData.total;
	//现存确诊人口占比 = 现存确诊数（个） / 人口数（个）
	double current_rate = current / tempData.total_peoples;
	//现存确诊人口密度=现存确诊数（个）/国家建成面积（平方公里）；
	double current_density = current / tempData.country_area;
	//权重1 + 权重2 = 1；
	double a ; double b;
	//权重2 / 权重1 = 全球城建区人口密度；
	//全球城建区人口密度=全球人口数/全球城建区面积
	double all_density = 76 / 45;
	b = 1 / (all_density - 1);
	a = 1 - b;
	//严重指数 = （权重1 * 现存确诊人口密度 + 权重2 * 现存确诊率） * SQRT（现存确诊 * 1000000 / 全球现存确诊） * 10000；
	tempData.severity_index = (a * current_density + b * current_r) * (current * 10000000 / 4020878) * 10000;
	//double mortality;		//死亡率
	tempData.mortality = tempData.death / tempData.total;
	printf("%.0lf\n", tempData.mortality);
	//double cure_rate;  //治愈率
	tempData.cure_rate = tempData.cure/ tempData.total;
	printf("%.0lf\n", tempData.cure_rate);
	return tempData;
}
//添加信息
void addCountry(struct Node* list) {
	struct country tempData = inputStudent();
	
	//插入链表
	insertNodeNyHead(list,tempData);
}
//通过综合成绩排名
int cmp_by_comprehensive(const void* e1, const void* e2) {
	//return (strcmp(((struct student*)e1)->comprehensive ,((struct student*)e2)->comprehensive));
	return 1;
}
//排序
void sort() {
	//struct students p1;
	//InitStudents(&p1);
	////快速排序
	//qsort(p1.data, p1.size, sizeof(p1.data[0]), cmp_by_comprehensive);
	//free(p1.data);
	//p1.data = NULL;
}
//释放内存
//释放内存
void destory(struct Node* list) {
	free(list);
	list = NULL;
}