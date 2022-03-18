#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DEFAULT_SZ 10
struct student {
	char stu_id[10];	//复试学号
	char name[20];		//姓名
	char colleage[20];	//报考学院
	char type[10];      //报考类别
	char course1[6];	//基础课1
	char course2[6];	//基础课2
	char course3[6];	//专业课1
	char course4[6];	//专业课2
	char ptest[10];		//初试成绩
	char retest[10];		//复试成绩
	char olanguage[6];  //口语成绩
	char comprehensive[10];//综合成绩
};

struct students {
	struct student* data;   //存储学生数据的数组
	int size;				//数组长度
	int capicity;			//当前容量
};
struct Node {    //学生成绩链表
	struct student data;
	struct Node* next;
};

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
		struct student* p = (struct student*)realloc(stu->data, sizeof(struct student) * (DEFAULT_SZ+stu->capicity));
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
	while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", tempData.stu_id, tempData.name, tempData.colleage, tempData.type, tempData.course1, tempData.course2, tempData.course3, tempData.course4, tempData.ptest, tempData.retest, tempData.olanguage, tempData.comprehensive) != EOF) {
		insertNodeNyHead(listHeadNode, tempData);
		memset(&tempData, 0, sizeof(tempData));
	}
	fclose(fp);
	fp = NULL;
}
//查找学生成绩
void queryAllStudentByArray(struct student* list, int length) {
	if (length == 0) {
		printf("表为空\n");
		return;
	}
	else {
		printf("%-5s\t%-5s\t%s\t%-8s\t%s %s %s %s %s %s %s %s\n", "复试学号", "姓名", "报考学院", "报考类别", "基础课1", "基础课2", "专业课1", "专业课2", "初试成绩", "复试成绩", "口语成绩", "综合成绩");
		for (int i = 0; i < length; i++) {
			printf("%-5s\t%-5s\t%s\t%-8s\t %s\t %s\t %s\t %s\t %s\t %s\t   %s\t   %s\t\n", list[i].stu_id, list[i].name, list[i].colleage, list[i].type, list[i].course1, list[i].course2, list[i].course3, list[i].course4, list[i].ptest, list[i].retest, list[i].olanguage, list[i].comprehensive);
		}
	}
}
//打印链表
void printList(struct Node* list) {
	struct Node* posNode = list->next;
	if (posNode == NULL) {
		printf("表为空\n");
		return;
	}
	else {
		printf("%-5s\t%-5s\t%s\t%-8s\t%s %s %s %s %s %s %s %s\n", "复试学号", "姓名", "报考学院", "报考类别", "基础课1", "基础课2", "专业课1", "专业课2", "初试成绩", "复试成绩", "口语成绩", "综合成绩");
		while (posNode != NULL) {
			printf("%-5s\t%-5s\t%s\t%-8s\t %s\t %s\t %s\t %s\t %s\t %s\t   %s\t   %s\t\n", posNode->data.stu_id, posNode->data.name, posNode->data.colleage, posNode->data.type, posNode->data.course1, posNode->data.course2, posNode->data.course3, posNode->data.course4, posNode->data.ptest, posNode->data.retest, posNode->data.olanguage, posNode->data.comprehensive);
			posNode = posNode->next;
		}
	}
}
void sort(struct Node* list) {
	//struct student list1[STUDENT_MAX] ;//学硕表
	//struct student list2[STUDENT_MAX];//专硕表
	//struct student list3[STUDENT_MAX];//非全日制
	struct students p1;
	struct students p2;
	struct students p3;
	InitStudents(&p1);
	InitStudents(&p2);
	InitStudents(&p3);
	//printList(list);
	struct Node* posNode = list->next;
	if (posNode == NULL) {
		printf("表为空\n");
		return;
	}
	else {
		while (posNode != NULL) {
			if (strcmp(posNode->data.type, "学硕") == 0) {
				p1.data[p1.size] = posNode->data;
				p1.size++;
				CheckCapacity(&p1);
			}
			else if (strcmp(posNode->data.type, "专硕") == 0) {
				p2.data[p2.size] = posNode->data;
				p2.size++;
				CheckCapacity(&p2);
			}
			else if (strcmp(posNode->data.type, "非全日制") == 0) {
				p3.data[p3.size] = posNode->data;
				p3.size++;
				CheckCapacity(&p3);
			}
			posNode = posNode->next;
		}
		//打印成绩
		queryAllStudentByArray(p1.data, p1.size);
		//对这三个表进行排序
		//qsort(p1.data, p1.size, sizeof(p1.data[0]), cmp_by_comprehensive);

		printf("排序成功\n");
	}
	free(p1.data);
	p1.data = NULL;
	free(p2.data);
	p2.data = NULL;
	free(p3.data);
	p3.data = NULL;
}
int main() {
	struct Node* list = NULL;		//学生成绩链表
	list = createList();
	readStudentInfoFromFile("data2.txt", list);
	sort(list);
}