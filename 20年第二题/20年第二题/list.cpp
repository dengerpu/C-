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
struct Node* createNode(struct country data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//学生成绩链表 头插法，插入节点
void insertNodeNyHead(struct Node* listHeadNode, struct country data) {
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
	struct country tempData;
	//while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", tempData.stu_id, tempData.name, tempData.colleage, tempData.type, tempData.course1, tempData.course2, tempData.course3, tempData.course4, tempData.ptest, tempData.retest, tempData.olanguage, tempData.comprehensive) != EOF) {
	//	insertNodeNyHead(listHeadNode, tempData);
	//	memset(&tempData, 0, sizeof(tempData));
	//}
	fclose(fp);
	fp = NULL;
}
//保存学生信息到文件
void saveStudentInfoToFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Node* pMove = listHeadNode->next;
	//while (pMove) {
	//	fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", pMove->data.stu_id, pMove->data.name, pMove->data.colleage, pMove->data.type, pMove->data.course1, pMove->data.course2, pMove->data.course3, pMove->data.course4, pMove->data.ptest, pMove->data.retest, pMove->data.olanguage, pMove->data.comprehensive);
	//	pMove = pMove->next;
	//}
	fclose(fp);
	fp = NULL;
}

//初始化students
void InitStudents(struct courties* stu) {
	//分配DEFAULT_SZ个大小
	stu->data = (struct country*)malloc(sizeof(struct country) * DEFAULT_SZ);
	if (stu->data == NULL) {  //分配失败
		printf("%s\n", strerror(errno));
		return;
	}
	stu->size = 0;
	stu->capicity = DEFAULT_SZ;
}
//检查容量是否够用
void CheckCapacity(struct courties* stu) {
	if (stu->size == stu->capicity) {  //容量不够用，再次分配容量
		struct country* p = (struct country*)realloc(stu->data, sizeof(struct country) * (DEFAULT_SZ + stu->capicity));
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
//解决bug，去除  .
void removedot(char* arr, int length) {
	if (arr[length - 1] == '.') {
		arr[length - 1] = '\0';
	}
}

