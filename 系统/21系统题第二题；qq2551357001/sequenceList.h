
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/***********定义学生类型数据结构************/
typedef struct student {
	char stu_id[10];//学号
	char name[20];//姓名
	char institute[20];//报考学院
	char category[20];//报考类别
	int basSco_1;//基础课1成绩
	int basSco_2;//基础课2成绩
	int speSco_1;//专业课1成绩
	int speSco_2;//专业课2成绩
	float preExamSco;//初试总成绩
	float reExamSco;//复试试成绩
	float orExamSco;//口语成绩
	float totalSco;//总成绩
	int state;//学生是否存在
}Student;

/***********定义账户类型数据结构************/
typedef struct acco{
	char account[20];//账号
	char pwd[20];//密码
	int state;//账号是否存在
}Account;

/***************创建顺序表****************/
typedef struct StuList {
	Student* student;//学生数组存储空间基地址
	int stuLength;//学生数组当前长度
	int stuSize;//学生数组当前分配的存储容量
}StuList;

typedef struct AccoList {
	Account* account;//账户数组存储空间基地址
	int accoLength;//账户数组当前长度
	int accoSize; //账户数组当前分配的存储容量
}AccoList;

/*
函数功能：构建一个空的线性表list
参数：线性表
返回值：无
*/
void initStuList(StuList* list) {
	list->student = (Student*)malloc(sizeof(Student) * 10);
	list->stuLength = 0; //空表长度为0
	list->stuSize = 10; //初试存储容量
}

void initAccoList(AccoList* list) {
	list->account = (Account*)malloc(sizeof(Account) * 10);
	list->accoLength = 0;
	list->accoSize = 10;
}

/*
函数功能：在线性表末尾插入数据
参数：线性表，学生数据
返回值：无
*/
void insertStu(StuList* list, Student stu) {
	if (list->stuLength >= list->stuSize * 0.8) {
		Student* newbase = (Student*)realloc(list->student,
			sizeof(Student) * (list->stuSize * 1.5));
		if (!newbase) {
			printf("空间分配失败！");
			return;
		}
		list->student = newbase;
	}
	
	list->student[list->stuLength] = stu;
	++list->stuLength;
	list->stuSize = list->stuSize + list->stuSize * 1.5;
}

void insertAcco(AccoList* list, Account acco) {
	if (list->accoLength >= list->accoSize * 0.8) {
		Account* newbase = (Account*)realloc(list->account,
			sizeof(Account) * (list->accoSize * 1.5));
		if (!newbase) {
			printf("空间分配失败！");
			return;
		}
		list->account = newbase;
	}
	list->account[list->accoLength] = acco;
	++list->accoLength;
	list->accoSize = list->accoSize + list->accoSize * 1.5;
}

/*
函数功能：通过学号查找学生
参数：线性表，学生学号
返回值：该学生指针
*/
int locateStu(StuList* list, char* stu_id) {
	if (list->stuLength == 0) {
		printf("无学生信息！\n");
		return -1;
	}
	int i = 0;
	for (i = 0; i < list->stuLength && strcmp(list->student[i].stu_id, stu_id); i++);
	if (i >= list->stuLength) {
		printf("没有该学生信息！\n");
		return -1;
	}
	if (list->student[i].state == 0) {
		printf("该学生已被删除！\n");
		return -1;
	}
	return i;
}

int locateAcco(AccoList* list, char* account) {
	if (list->accoLength == 0) {
		printf("无账号信息！");
		return -1;
	}
	int i = 0;
	for (i = 0; i < list->accoLength && strcmp(list->account[i].account, account); i++);
	if (i >= list->accoLength) {
		printf("没有该账号信息！");
		return -1;
	}
	if (list->account[i].state == 0) {
		printf("该账号已被删除！");
		return -1;
	}
	return i;
}

/*
函数功能：通过学号删除学生，该删除为逻辑删除
		  state = 0表示已被删除
参数：线性表，学生学号
返回值：无
*/
void deleteStu(StuList* list, char* stu_id) {
	if (list->stuLength == 0) {
		printf("无学生信息！\n");
		return;
	}
	int index = locateStu(list, stu_id);
	if (index == -1) {
		return;
	}
	list->student[index].state = 0;
	printf("删除成功！");
}

void deleteAcco(AccoList* list, char* account) {
	if (list->accoLength == 0) {
		printf("无账号信息！\n");
		return;
	}
	int index = locateAcco(list, account);
	if (index == -1) {
		return;
	}
	list->account[index].state = 0;
	printf("删除成功！");
}

void swapNode(Student* stu1, Student* stu2) {
	Student stu = { "" };
	stu = *stu1;
	*stu1 = *stu2;
	*stu2 = stu;
}

void sorList(StuList* stuList) {
	int flag = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < stuList->stuLength - 1; i++) {
		flag = 0;
		for (j = i; j < stuList->stuLength - 1; j++) {
			if (stuList->student[j].totalSco < stuList->student[j + 1].totalSco) {
				flag = 1;
				swapNode(&stuList->student[j], &stuList->student[j + 1]);
			}
			if (stuList->student[j].totalSco == stuList->student[j + 1].totalSco) {
				if (stuList->student[j].preExamSco < stuList->student[j + 1].preExamSco) {
					flag = 1;
					swapNode(&stuList->student[j], &stuList->student[j + 1]);
				}
				if (stuList->student[j].preExamSco == stuList->student[j + 1].preExamSco) {
					if (stuList->student[j].reExamSco < stuList->student[j + 1].reExamSco) {
						flag = 1;
						swapNode(&stuList->student[j], &stuList->student[j + 1]);
					}
					if (stuList->student[j].reExamSco == stuList->student[j + 1].reExamSco) {
						if (stuList->student[j].speSco_1 < stuList->student[j + 1].speSco_1) {
							flag = 1;
							swapNode(&stuList->student[j], &stuList->student[j + 1]);
						}
						if (stuList->student[j].speSco_1 == stuList->student[j + 1].speSco_1) {
							if (stuList->student[j].speSco_2 < stuList->student[j + 1].speSco_2) {
								flag = 1;
								swapNode(&stuList->student[j], &stuList->student[j + 1]);
							}
						}
					}
				}
			}
		}
		if (flag == 0) {
			return;
		}
	}
}
