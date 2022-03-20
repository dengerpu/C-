#define _CRT_SECURE_NO_WARNINGS
#include"list.h"

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
	while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", tempData.stu_id, tempData.name, tempData.sid, tempData.college, tempData.type, tempData.major, tempData.route, tempData.traffic, tempData.isClose, tempData.temperate, tempData.history, tempData.isCough, tempData.time) != EOF) {
		insertNodeNyHead(listHeadNode, tempData);
		memset(&tempData, 0, sizeof(tempData));
	}
	fclose(fp);
	fp = NULL;
}
//保存学生信息到文件
void saveStudentInfoToFile(struct Node* listHeadNode) {
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
	FILE* fp = NULL;
	struct Node* pMove = listHeadNode->next;
	while (pMove) {
		for (int i = 0; i < count; i++) {
			if (strcmp(collegeArr[i], pMove->data.college) == 0) {
				char newfilename[20] = { 0 };
				strcpy(newfilename, collegeArr[i]);
				strcat(newfilename, ".txt");
				fp = fopen(newfilename, "a+");
				fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", pMove->data.stu_id, pMove->data.name, pMove->data.sid, pMove->data.college, pMove->data.type, pMove->data.major, pMove->data.route, pMove->data.traffic, pMove->data.isClose, pMove->data.temperate, pMove->data.history, pMove->data.isCough, pMove->data.time);
			}
		}

		pMove = pMove->next;
	}
	fclose(fp);
	fp = NULL;
}
//保存排序后的数组信息到文件中
void saveStudentArrInfoToFile(const char* filename, struct student* arr,int length) {
	FILE* fp = NULL;
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("打开文件失败\n");
		return;
	}
	else {
		for (int i = 0; i < length; i++) {
			fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", arr[i].stu_id, arr[i].name, arr[i].sid, arr[i].college, arr[i].type, arr[i].major, arr[i].route, arr[i].traffic, arr[i].isClose, arr[i].temperate, arr[i].history, arr[i].isCough, arr[i].time);
		}
	}	
	fclose(fp);
	fp = NULL;
}
//保存所有学生信息到文件
void saveALLStudentInfoToFile(const char* filename, struct Node* listHeadNode){
	FILE* fp = fopen(filename,"w");
	struct Node* pMove = listHeadNode->next;
	while (pMove) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", pMove->data.stu_id, pMove->data.name, pMove->data.sid, pMove->data.college, pMove->data.type, pMove->data.major, pMove->data.route, pMove->data.traffic, pMove->data.isClose, pMove->data.temperate, pMove->data.history, pMove->data.isCough, pMove->data.time);
		pMove = pMove->next;
	}
	fclose(fp);
	fp = NULL;
}

//初始化students
void InitStudents(struct students* stu) {
	//分配DEFAULT_SZ个大小
	stu->data = (struct student*)malloc(sizeof(struct student) * DEFAULT_SZ);
	if (stu->data == NULL) {  //分配失败
		printf("%s\n", strerror(errno));
		return;
	}
	stu->size = 0;
	stu->capicity = DEFAULT_SZ;
}
//检查容量是否够用
void CheckCapacity(struct students* stu) {
	if (stu->size == stu->capicity) {  //容量不够用，再次分配容量
		struct student* p = (struct student*)realloc(stu->data, sizeof(struct student) * (DEFAULT_SZ + stu->capicity));
		if (p != NULL) {
			stu->data = p;
			stu->capicity = stu->capicity + DEFAULT_SZ;
		}
		else {
			printf("%s\n", strerror(errno));
			return;
		}
	}
}

