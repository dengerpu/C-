#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"



//菜单
void menu() {
	printf("----------------学生管理系统----------------\n");
	printf("\t\t0.退出系统\n");
	printf("\t\t1.插入信息\n");
	printf("\t\t2.浏览信息\n");
	printf("\t\t3.删除信息\n");
	printf("\t\t4.修改信息\n");
	printf("\t\t5.查找信息\n");
	printf("--------------------------------------------\n");
	printf("请选择操作:>");
}

//创建链表
struct Node* createList() {
	//申请空间
	struct Node* listHead = (struct Node*)malloc(sizeof(struct Node));
	listHead->next = NULL;
	return listHead;
}

//创建结点
struct Node* createNode(struct student data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//头插法，插入节点
void insertNodeNyHead(struct Node* listHeadNode, struct student data) {
	struct Node* newNode = createNode(data);//申请一个新结点
	newNode->next = listHeadNode->next;
	listHeadNode->next = newNode;
}

//尾插法，插入节点
void insertNodeByTail(struct Node* listHeadNode, struct student data) {
	struct Node* newNode = createNode(data);//申请一个新结点
	listHeadNode->next = newNode;
	listHeadNode = newNode;
}

//删除链表
void deleteNodeByquery(struct Node* listHeadNode, char* query) {
	struct Node* posFrontNode = listHeadNode;  //要删除结点的前一个结点
	struct Node* posNode = listHeadNode->next; //要删除的结点
	if (posNode == NULL) {
		printf("表为空，无法删除\n");
		return;
	}
	else {
		/*while (不满足查询条件) {
			posFrontNode->next = posNode;
			posNode = posNode->next;
			if (posNode == NULL) {
				printf("查找不到,无法删除\n");
				return;
			}
		}
		查找到，进行删除
		posFrontNode->next = posNode->next;*/
	}
}
//查找结点
struct Node* findNodeByquery(struct Node* listHeadNode, char* query) {
	struct Node* searchNode = listHeadNode->next;
	if (searchNode == NULL) {
		return NULL;
	}
	else {
		/*while (不满足条件) {
			searchNode = searchNode->next;
			if (searchNode == NULL) {
				return NULL;
			}
		}
		return searchNode;*/
	}
}


//打印链表
void printList(struct Node* listHeadNode) {
	struct Node* pMove = listHeadNode->next;
	while (pMove != NULL) {
		printf("%d\n", pMove->data);
		pMove = pMove->next;
	}
}
//打印结点
void printNode(struct Node* node) {
	printf("打印结点信息\n");
}
//读取文件信息
void readInfoFromFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w");  //如果文件不存在，就创建文件
	}
	struct student tempData;
	/*while (fscanf(fp, "%d\n", &(tempData.data)) != EOF) {
		insertNodeNyHead(listHeadNode, tempData);
		memset(&tempData, 0, sizeof(tempData));
	}*/
}

//保存信息到文件
void saveInfoToFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Node* pMove = listHeadNode->next;
	/*while (pMove) {
		fprintf(fp, "%d", pMove->data.data);
		pMove = pMove->next;
	}*/
}