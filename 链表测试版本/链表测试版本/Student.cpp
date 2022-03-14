#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"





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
struct Node* insertNodeByTail(struct Node* listHeadNode, struct student data) {
	//struct Node* L = listHeadNode;
	//struct Node* newNode = createNode(data);//申请一个新结点
	//L->next = newNode;
	//L = newNode;
	//return listHeadNode;
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
		while (strcmp(posNode->data.name,query)) {
			posFrontNode->next = posNode;
			posNode = posNode->next;
			if (posNode == NULL) {
				printf("查找不到,无法删除\n");
				return;
			}
		}
		//查找到，进行删除
		posFrontNode->next = posNode->next;
	}
}
//修改链表信息
void modifyNodeByquery(struct Node* listHeadNode, char* query) {
	//struct Node* modifyNode = findNodeByquery(listHeadNode, query);

}
//查找结点
struct Node* findNodeByquery(struct Node* listHeadNode, char* query) {
	struct Node* searchNode = listHeadNode->next;
	if (searchNode == NULL) {
		return NULL;
	}
	else {
		while (strcmp(searchNode->data.name,query)) {
			searchNode = searchNode->next;
			if (searchNode == NULL) {
				return NULL;
			}
		}
		return searchNode;
	}
}


//打印链表
void printList(struct Node* listHeadNode) {
	struct Node* pMove = listHeadNode->next;
	if (pMove == NULL) {
		printf("表为空\n");
	}
	else {
		printf("%-20s\t%-10s\t%s\t%-20s\t%-20s\t\n", "姓名", "学号", "年龄", "电话", "地址");
		while (pMove != NULL) {
			printf("%-20s\t%-10s\t%d\t%-20s\t%-20s\t\n", pMove->data.name, pMove->data.num, pMove->data.age, pMove->data.tel, pMove->data.addr);
			pMove = pMove->next;
		}
	}
}
//打印结点
void printNode(struct Node* node) {
	if (node == NULL) {
		printf("表为空\n");
	}
	else {
		printf("%-20s\t%-10s\t%s\t%-20s\t%-20s\t\n", "姓名", "学号", "年龄", "电话", "地址");
		printf("%-20s\t%-10s\t%d\t%-20s\t%-20s\t\n", node->data.name, node->data.num, node->data.age, node->data.tel, node->data.addr);
	}
	
}
//读取文件信息
void readInfoFromFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w");  //如果文件不存在，就创建文件
	}
	struct student tempData;
	while (fscanf(fp, "%s%s%d%s%s", tempData.name, tempData.num, &(tempData.age), tempData.tel, tempData.addr) != EOF) {
		insertNodeNyHead(listHeadNode, tempData);
		memset(&tempData, 0, sizeof(tempData));
	}
}

//保存信息到文件
void saveInfoToFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Node* pMove = listHeadNode->next;
	while (pMove) {
		fprintf(fp,"%-20s\t%-10s\t%d\t%-20s\t%-20s\t\n", pMove->data.name, pMove->data.num, pMove->data.age, pMove->data.tel, pMove->data.addr);
		pMove = pMove->next;
	}
}