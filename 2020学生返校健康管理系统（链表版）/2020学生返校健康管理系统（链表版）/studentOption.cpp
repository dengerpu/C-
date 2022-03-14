#pragma once
#include "Student.h"
enum COLLEGE{
	通信学院=1,		//01
	计算机学院,		//02
	光电学院,		//03
	自动化学院,		//04
	经管学院,		//05
	研究生院,		//06
	外语学院,		//07
	安法学院,		//08
	体育学院,		//09
	传媒学院,		//10
	先进制造学院,	//11
	马克思主义学院	//12
};
//获取学院
void getCollege(int num,char *college) {
	switch (num) {
	case 通信学院:strcpy(college, "通信学院"); break;
	case 计算机学院:strcpy(college, "计算机学院"); break;
	case 光电学院:strcpy(college, "光电学院"); break;
	case 自动化学院:strcpy(college, "自动化学院"); break;
	case 经管学院:strcpy(college, "经管学院"); break;
	case 研究生院:strcpy(college, "研究生院"); break;
	case 外语学院:strcpy(college, "外语学院"); break;
	case 安法学院:strcpy(college, "安法学院"); break;
	case 体育学院:strcpy(college, "体育学院"); break;
	case 传媒学院:strcpy(college, "传媒学院"); break;
	case 先进制造学院:strcpy(college, "先进制造学院"); break;
	case 马克思主义学院:strcpy(college, "马克思主义学院"); break;
	default:strcpy(college, "无"); break;
	};
}
//获取健康状态
char  getStatus(char* temperate, char isCough) {
	float temp = (float)atof(temperate);
	if (temp >= 37.3 && isCough == '1') {
		return '0';
	}else {
		return '1';
	}
}

//添加学生信息
void addStudent(struct Node* list) {
	struct student tempData;
	int flag = 1;
	memset(&(tempData), 0, sizeof(tempData));
	printf("请输入学生的各项信息：\n");
	while (flag) {
		printf("学生学号：");
		scanf("%s", tempData.stu_id);
		int year = getSidYear(tempData.stu_id);
		int college = getSidCollege(tempData.stu_id);
		int num = getSidNum(tempData.stu_id);
		if (year < 2016 || year>2019) {
			printf("该学号年份信息无效，请重新输入！\n");
		}
		else if (college < 0 || college>12) {
			printf("该学号学院信息无效，请重新输入！\n");
		}
		else if (num < 0 || num>999) {
			printf("该学号信息无效，请重新输入！\n");
		}
		else {
			flag = 0;
		}
	}
	printf("学生姓名：");
	scanf("%s", tempData.name);
	printf("学生体温：");
	scanf("%s", tempData.temperate);
	printf("是否咳嗽：");
	getchar();
	scanf("%c", &(tempData.isCough));
	printf("时间：");
	scanf("%s", tempData.time);
	printf("日期：");
	scanf("%s", tempData.date);
	tempData.status = getStatus(tempData.temperate,tempData.isCough);
	int cid = getSidCollege(tempData.stu_id);
	getCollege(cid, tempData.colleage);
	insertNodeNyHead(list, tempData);
}
//根据学号查找学生信息
struct Node* findBySid(struct Node* list, char* sid) {
	struct Node* searchNode = list->next;
	//printf("%s\n", sid);
	if (searchNode == NULL) {
		printf("表为空\n");
	}
	else{
		while (searchNode != NULL) {
			if (strcmp(searchNode->data.stu_id, sid) == 0) {
				return searchNode;
			}
			searchNode = searchNode->next;
			if (searchNode == NULL) {
				//printf("查找不到\n");
				return NULL;
			}
		}
	}
}
//修改学生信息
void modifyStudent(struct Node* list) {
	//struct Node* modifyNode;
	char modify[20] = { 0 };
	char sid[20] = { 0 };
	printf("请输入需要修改信息的学生学号：");
	scanf("%s", sid);
	struct Node* modifyNode = findBySid(list, sid);
	if (modifyNode == NULL) {
		printf("查找不到\n");
	}
	else {
		printf("请输入要修改的项(学号、姓名、体温、是否咳嗽、时间、日期)：");
		scanf("%s", modify);
		if (strcmp(modify, "学号") == 0) {
			printf("请输入新修改的学号：");
			scanf("%s", modifyNode->data.stu_id);
		}else if (strcmp(modify, "姓名")==0) {
			printf("请输入新修改的姓名：");
			scanf("%s", modifyNode->data.name);
		}else if (strcmp(modify, "体温")==0) {
			printf("请输入新修改的体温：");
			scanf("%s", modifyNode->data.temperate);
		}
		else if (strcmp(modify, "是否咳嗽")==0) {
			getchar();
			printf("请输入新修改的是否咳嗽：");
			scanf("%c", &(modifyNode->data.isCough));
		}
		else if (strcmp(modify, "时间")==0) {
			printf("请输入新修改的时间：");
			scanf("%s", modifyNode->data.time);
		}
		else if (strcmp(modify, "日期")==0) {
			printf("请输入新修改的日期：");
			scanf("%s", modifyNode->data.date);
		}
		else {
			printf("无该选项\n");
		}
		modifyNode->data.status = getStatus(modifyNode->data.temperate, modifyNode->data.isCough);
		int cid = getSidCollege(modifyNode->data.stu_id);
		getCollege(cid, modifyNode->data.colleage);
		printf("修改成功\n");
	}
}
void deadlineStatics(struct Node* list) {
	char query[20] = { 0 };
	char deadline[20] = { 0 };
	int flag = 1;  //用于控制截止几年几月几日该生的健康信息管理只打印一次
	int flag1 = 1; //控制学号姓名学院只打印一次
	struct Node* findNode = list->next;
	if (findNode == NULL) {
		printf("表为空\n");
	}
	else {
		FILE* fp = fopen("data2.txt", "w");
		printf("请输入学生学号或者姓名：");
		scanf("%s", query);
		printf("请输入当前日期：");
		scanf("%s", deadline);
		while (findNode != NULL) {
			if ((strcmp(findNode->data.stu_id, query) == 0) || (strcmp(findNode->data.name, query) == 0)) {
				if (flag) {
					printf("截止%d年%d月%d日该生的健康管理信息为：\n", getYear(deadline), getMonth(deadline), getDay(deadline));
					flag = 0;
				}
				if (strcmp(findNode->data.date, deadline) < 0) {
					if (flag1 == 1) {
						printf("学号：%s\n",findNode->data.stu_id);
						printf("姓名：%s\n", findNode->data.name);
						printf("学院：%s\n", findNode->data.colleage);
						printf("%-5s\t%s\t%s\t%s\t%s\t\n", "体温", "是否咳嗽", "健康状态", "统计时间", "日期");
						flag1 = 0;
					}
					printf("%-5s\t%c\t\t%c\t\t%s\t\t%s\t\n", findNode->data.temperate, findNode->data.isCough, findNode->data.status, findNode->data.time, findNode->data.date);
					fprintf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\t\n", findNode->data.stu_id, findNode->data.name, findNode->data.colleage, findNode->data.temperate, findNode->data.isCough, findNode->data.status, findNode->data.time, findNode->data.date);
				}
			}
			findNode = findNode->next;
		}
		fclose(fp);  //释放内存
		fp = NULL;
		if (flag == 1) {
			printf("无此人信息\n");
		}
		if (flag1 == 1) {
			printf("无满足条件\n");
		}
	}
}
//统计每天健康状态异常的学生信息，保存到文件data3.txt
void abnormalStatus(struct Node* list) {
	struct Node* node = list->next;
	FILE* fp = fopen("data3.txt", "w");
	if (node == NULL) {
		printf("表为空\n");
	}else {
		while (node != NULL) {
			if (node->data.status == '0') {
				fprintf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\t\n", node->data.stu_id, node->data.name, node->data.colleage, node->data.temperate, node->data.isCough, node->data.status, node->data.time, node->data.date);
				printf("%-10s\t%s\t%-10s\t%-5s\t%c\t\t%c\t\t%s\t\t%s\t\n", node->data.stu_id, node->data.name, node->data.colleage, node->data.temperate, node->data.isCough, node->data.status, node->data.time, node->data.date);
			}
			node = node->next;
		}
	}
	fclose(fp);
	fp = NULL;

}
int cmp_stu_by_sid(const void* e1, const void* e2) {
	return (strcmp(((struct Node*)e1)->data.stu_id, ((struct Node*)e2)->data.stu_id));
}

//统计连续三天及其以上健康状态为异常的学生，存储到data4.txt
void abnormalAdvice(struct Node* list) {
	struct Node* node = list->next;
	struct Node* node2 = NULL;
	struct Node* node3 = NULL;
	FILE* fp = fopen("data4.txt", "w");
	int length = getLenth(list);
	if (node == NULL) {
		printf("表为空\n");
	}
	else {
		qsort(list, length, sizeof(list), cmp_stu_by_sid);
		//printList(list);
		while (node != NULL) {
			if (node->next != NULL) {
				node2 = node->next;
			}
			if (node2 != NULL && node2->next != NULL) {
				node3 = node2->next;
			}
			if (node != NULL && node2 != NULL && node3 != NULL) {  //不需要判断Node3，Node2为空，3必为空
				if (node->data.status == '0' && node2->data.status == '0' && node3->data.status == '0' && (strcmp(node->data.stu_id, node2->data.stu_id) == 0) && (strcmp(node3->data.stu_id, node2->data.stu_id) == 0)) {
					fprintf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\t\n", node->data.stu_id, node->data.name, node->data.colleage, node->data.temperate, node->data.isCough, node->data.status, node->data.time, node->data.date);
					printf("%-10s\t%s\t%-10s\t%-5s\t%c\t\t%c\t\t%s\t\t%s\t\n", node->data.stu_id, node->data.name, node->data.colleage, node->data.temperate, node->data.isCough, node->data.status, node->data.time, node->data.date);
				}
			}
			node = node->next;
		}
	}
	fclose(fp);
	fp = NULL;

}
