#define _CRT_SECURE_NO_WARNINGS

#include"sequenceList.h"

/******************创建线性表****************/
StuList stuList = {""};

AccoList accoList = { "" };

/****************主业务函数*****************/
////////////////////////////////////////////
//	主菜单
void mainMenu();
//	管理员系统
void adminSys();
//	操作员系统
void userSys();
//	学生系统
void studentSys();
//	增加：
void  addStudent();
//	删除：
void deleteStudent();
//	查找：
void queryStudent();
//	修改：
void updateStudnt();
//	打印所有信息: 
void printAll();

/****************辅助业务函数*****************/
////////////////////////////////////////////
//	学院获取
void getInstitute(char* stu_id, char* institute);
//	获取学号
void getStuID(char* stu_id);
//  获取基础课成绩
int getBasSco();
//  获取专业课成绩
int getSpeSco();
//	获取报考类别
void getCategory(char* category);
//	输出当前学生信息
void printCurStu(Student stu);
// 写文件
void writeFileStu(char* fileName, StuList* list);
void writeFileAcco(char* fileName, AccoList* list);
// 读文件
void readFileAcco(char* fileName, AccoList* accoList);
void readStuFile(char* fileName, StuList* stuList);
// 将报考类别分类
void sortCate(StuList stulist);

/*******************主函数*******************/
/////////////////////////////////////////////
int main() {

	initStuList(&stuList);
	initAccoList(&accoList);

	readFileAcco("data1.txt", &accoList);
	readStuFile("data2.txt", &stuList);

	sortCate(stuList);

	mainMenu();

	getchar();
	return 0;
}

/***************主业务函数定义***************/
/////////////////////////////////////////////

/*
函数功能：循环显示用户类型,提供选择项提示
		  根据输入选择项调用相应用户处理函数
参数：无
返回值：无
*/
void mainMenu() {
	int userSelect = 0;
	printf("|----------------------------------|\n");
	printf("|---  欢迎使用学生成绩管理系统  ---|\n");
	printf("|----------------------------------|\n");
	printf("\n");
	while (1) {
		printf("|--------------用户类型------------|\n");
		printf("|            1. 管理员             |\n");
		printf("|            2. 操作员             |\n");
		printf("|            3. 学  生             |\n");
		printf("|            0. 退出系统           |\n");
		printf("|----------------------------------|\n");
		printf("请选择用户类型：");
		scanf("%d", &userSelect);
		switch (userSelect) {
		case 1:
			adminSys();
			break;
		case 2:
			userSys();
			break;
		case 3:
			studentSys();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("输入有误！\n");
			break;
		}
	}
}

/*
函数功能：循环显示管理员可操作业务，提供选择项提示
		  根据输入选择项调用主业务函数 
参数：无
返回值：无
*/
void adminSys() {
	Account acco = { "" };
	int index = -1;
	int select = 0;
	int loop = 1;
	index = locateAcco(&accoList, "admin");
	if (index == -1) {
		strcpy(acco.account, "admin");
		strcpy(acco.pwd, "admin");
		acco.state = 1;
		insertAcco(&accoList, acco);
	}
	printf("管理员账户：admin\n");
	printf("请输入管理员密码：");
	while (loop) {
		scanf("%s", acco.pwd);
		index = locateAcco(&accoList, "admin");
		if (strcmp(acco.pwd, accoList.account[index].pwd) != 0) {
			printf("密码错误，请重新输入：");
			continue;
		}
		printf("登录成功!\n");
		if (strcmp(acco.pwd, "admin") == 0) {
			printf("请修改初试密码：");
			scanf("%s", accoList.account[index].pwd);
			writeFileAcco("data1.txt", &accoList);
		}
		loop = 0;
	}
	
	printf("|----------------------------------|\n");
	printf("|---     欢迎使用管理员系统     ---|\n");
	printf("|----------------------------------|\n");
	while (1) {
		printf("|----------------------------------|\n");
		printf("|         1. 增加学生信息          |\n");
		printf("|         2. 删除学生信息          |\n");
		printf("|         3. 修改学生信息          |\n");
		printf("|         4. 查找学生信息          |\n");
		printf("|         5. 打印全部信息          |\n");
		printf("|         0. 退出管理员系统        |\n");
		printf("|----------------------------------|\n");
		printf("请选择业务：");
		scanf("%d", &select);
		switch (select) {
		case 1:
			addStudent();
			break;
		case 2:
			deleteStudent();
			break;
		case 3:
			updateStudnt();
			break;
		case 4:
			queryStudent();
			break;
		case 5:
			printAll();
			break;
		case 0:
			return;
		default:
			printf("您的选择有误，请重新选择！\n");
		}
	}
}

/*
函数功能：循环显示操作员可操作业务，提供选择项提示
		  根据输入选择项调用主业务函数
参数：无
返回值：无
*/
void userSys() {
	Account acco = { "" };
	int index = -1;
	int select = 0;
	int loop = 1;
	index = locateAcco(&accoList, "user01");
	if (index == -1) {
		strcpy(acco.account, "user01");
		strcpy(acco.pwd, "user01");
		acco.state = 1;
		insertAcco(&accoList, acco);
	}
	printf("操作员账户：user01\n");
	printf("请输入操作员密码：");
	while (loop) {
		scanf("%s", acco.pwd);
		index = index = locateAcco(&accoList, "user01");
		if (strcmp(acco.pwd, accoList.account[index].pwd) != 0) {
			printf("密码错误，请重新输入：");
			continue;
		}
		if (strcmp(acco.pwd, "user01") == 0) {
			printf("请修改初始密码：");
			scanf("%s", accoList.account[index].pwd);
			writeFileAcco("data1.txt", &accoList);
		}
		loop = 0;
	}
	printf("|----------------------------------|\n");
	printf("|---     欢迎使用操作员系统     ---|\n");
	printf("|----------------------------------|\n");
	while (1) {
		printf("|----------------------------------|\n");
		printf("|         1. 增加学生信息          |\n");
		printf("|         2. 查找学生信息          |\n");
		printf("|         0. 退出操作员系统        |\n");
		printf("|----------------------------------|\n");
		printf("请选择业务：");
		scanf("%d", &select);
		switch (select) {
		case 1:
			addStudent();
			break;
		case 2:
			queryStudent();
			break;
		case 0:
			return;
		default:
			printf("您的选择有误，请重新选择！\n");
		}
	}
}

/*
函数功能：循环显示学生查询业务
参数：无
返回值：无
*/
void studentSys() {
	int index = -1;
	int select = 0;
	char stu_id[20] = { "" };
	int loop = 1;
	char pwd[20] = { "" };
	printf("请输入学号：");
	getStuID(stu_id);
	index = locateAcco(&accoList,stu_id);
	if (index == -1) {
		return;
	}
	printf("请输入密码：");
	while (loop) {
		scanf("%s", pwd);
		if (strcmp(pwd, accoList.account[index].pwd) != 0) {
			printf("密码错误，请重新输入：");
			continue;
		}
		if (strcmp(pwd, stu_id) == 0) {
			printf("请修改初始密码：");
			scanf("%s", accoList.account[index].pwd);
			writeFileAcco("data1.txt", &accoList);
		}
		loop = 0;
	}
	printf("|----------------------------------|\n");
	printf("|---      欢迎使用学生系统      ---|\n");
	printf("|----------------------------------|\n");
	while (1) {
		printf("|----------------------------------|\n");
		printf("|         1. 查找学生信息          |\n");
		printf("|         0. 退出学生系统          |\n");
		printf("|----------------------------------|\n");
		printf("请选择业务：");
		scanf("%d", &select);
		switch (select) {
		case 1:
			queryStudent();
			break;
		case 0:
			return;
		default:
			printf("您的选择有误，请重新选择！\n");
		}
	}
}

/*
函数功能：根据输入的信息，添加到学生数组中
参数：无
返回值：无
*/
void addStudent() {
	int select = 0;
	int loop = 1;
	Student stu = {""};
	Account acco = { "" };
	printf("----------    增加学生信息    ----------\n");
	while (loop) {
		printf("姓名：");
		scanf("%s", stu.name);
		printf("学号：");
		getStuID(stu.stu_id);
		getInstitute(stu.stu_id, stu.institute);
		getCategory(stu.category);
		printf("请输入基础课1成绩：");
		stu.basSco_1 = getBasSco();
		printf("请输入基础课2成绩：");
		stu.basSco_2 = getBasSco();
		printf("请输入专业课1成绩：");
		stu.speSco_1 = getSpeSco();
		printf("请输入专业课2成绩：");
		stu.speSco_2 = getSpeSco();
		printf("请输入口语成绩：");
		scanf("%f", &stu.orExamSco);
		printf("请输入复试成绩：");
		scanf("%f", &stu.reExamSco);
		stu.preExamSco = stu.basSco_1 +
			stu.basSco_2 +
			stu.speSco_1 + 
			stu.speSco_2;
		stu.totalSco = stu.preExamSco * 0.6 +
			stu.reExamSco * 0.3 +
			stu.orExamSco * 0.1;
		stu.state = 1;

		strcpy(acco.account, stu.stu_id);
		strcpy(acco.pwd, stu.stu_id);
		acco.state = 1;

		insertStu(&stuList, stu);
		insertAcco(&accoList, acco);

		printf("是否继续添加？1是 0否：");
		while (1) {
			scanf("%d", &select);
			if (select == 1) {
				break;
			}
			else if (select == 0) {
				loop = 0;
				break;
			}
			else {
				printf("输入有误请重新输入(1或0)：");
				continue;
			}
		}
	}
	writeFileStu("data2.txt", &stuList);
	writeFileAcco("data1.txt", &accoList);
}

/*
函数功能；删除学生信息，将学生状态置state为0
参数：无
返回值： 无
*/
void deleteStudent() {
	int loop = 1;
	int select = 0;
	char stu_id[20] = {""};
	printf("----------  删除学生信息  ----------\n");
	while (loop) {
		printf("请输入需要删除的学生学号：");
		getStuID(stu_id);
		deleteStu(&stuList, stu_id);
		deleteAcco(&accoList, stu_id);
		printf("是否继续删除？1是 0否：");
		while (1) {
			scanf("%d", &select);
			if (select == 1) {
				break;
			}
			else if (select == 0) {
				loop = 0;
				break;
			}
			else {
				printf("输入有误请重新输入(1或0)：");
				continue;
			}
		}
	}
	writeFileStu("data2.txt", &stuList);
	writeFileAcco("data1.txt", &accoList);
}

/*
函数功能；查询学生信息，可以根据学号
		  和姓名查询
参数：无
返回值： 无
*/
void queryStudent() {
	int loop = 1;
	int select = 0;
	int index = -1;
	char stu_id[20] = { " " };
	printf("----------  查询学生信息  ----------\n");
	while (loop) {
		printf("请输入需要查询的学生学号：");
		getStuID(stu_id);
		index = locateStu(&stuList, stu_id);
		if (index == -1) {
			//printf("未找到相关信息！");
		}else {
			printCurStu(stuList.student[index]);
		}

		printf("是否继续查询？1是 0否：");

		while (1) {
			scanf("%d", &select);
			if (select == 1) {
				break;
			}
			else if (select == 0) {
				loop = 0;
				break;
			}
			else {
				printf("输入有误请重新输入(1或0)：");
				continue;
			}
		}
	}
}

/*
函数功能；修改学生信息，先根据学号查找
		  找到后重新输入学生数据，然后
		  再写文件
参数：无
返回值： 无
*/
void updateStudnt() {
	int loop = 1;
	int select = 0;
	int index = -1;
	char stu_id[20] = { " " };
	printf("----------  修改学生信息  ----------\n");
	while (loop) {
		printf("请输入需要修改的学生学号：");
		getStuID(stu_id);
		index = locateStu(&stuList, stu_id);

		if (index == -1) {
			printf("没有找到学生信息!");
			continue;
		}

		printf("请输入修改信息：\n");
		printf("姓名：");
		scanf("%s", stuList.student[index].name);
		printf("学号：");
		getStuID(stuList.student[index].stu_id);
		getInstitute(stuList.student[index].stu_id, stuList.student[index].institute);
		getCategory(stuList.student[index].category);
		printf("请输入基础课1成绩：");
		stuList.student[index].basSco_1 = getBasSco();
		printf("请输入基础课2成绩：");
		stuList.student[index].basSco_2 = getBasSco();
		printf("请输入专业课1成绩：");
		stuList.student[index].speSco_1 = getSpeSco();
		printf("请输入专业课2成绩：");
		stuList.student[index].speSco_2 = getSpeSco();
		printf("请输入口语成绩：");
		scanf("%f", &stuList.student[index].orExamSco);
		printf("请输入复试成绩：");
		scanf("%f", &stuList.student[index].reExamSco);
		stuList.student[index].preExamSco = stuList.student[index].basSco_1 +
			stuList.student[index].basSco_2 +
			stuList.student[index].speSco_1 +
			stuList.student[index].speSco_2;
		stuList.student[index].totalSco = stuList.student[index].preExamSco * 0.6 +
			stuList.student[index].reExamSco * 0.3 +
			stuList.student[index].orExamSco * 0.1;
		stuList.student[index].state = 1;

		printf("是否继续修改？1是 0否：");

		while (1) {
			scanf("%d", &select);
			if (select == 1) {
				break;
			}
			else if (select == 0) {
				loop = 0;
				break;
			}
			else {
				printf("输入有误请重新输入(1或0)：");
				continue;
			}
		}
	}
	writeFileStu("data2.txt", &stuList);
}

/*
函数功能；打印数组中实际存在的学生信息
参数：无
返回值： 无
*/
void printAll() {
	if (stuList.stuLength == 0) {
		printf("无学生信息\n");
		return;
	}
	int i = 0;
	printf("----------  打印全部信息  ----------\n");
	printf("|----------------------------------------------------------------------------------------------------------------------|\n");
	printf("|%-10s|%-10s|%-15s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|\n", 
		"学号", "姓名", "报考学院", "报考类别", "基础课1", "基础课2","专业课1",
		"专业课2","初试总分","复试成绩","口语成绩", "综合成绩");
	printf("|----------+----------+---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------|\n");

	for (i = 0; i < stuList.stuLength; i++) {
		if (stuList.student[i].state == 0) {
			continue;
		}
		printf("|%-10s|%-10s|%-15s|%-8s|%-8d|%-8d|%-8d|%-8d|%-8.2f|%-8.2f|%-8.2f|%-8.2f|\n",
			stuList.student[i].stu_id,stuList.student[i].name, 
			stuList.student[i].institute,stuList.student[i].category, 
			stuList.student[i].basSco_1,stuList.student[i].basSco_2, 
			stuList.student[i].speSco_1, stuList.student[i].speSco_2, 
			stuList.student[i].preExamSco,stuList.student[i].reExamSco, 
			stuList.student[i].orExamSco, stuList.student[i].totalSco);
		if (i < stuList.stuLength){
			printf("|----------+----------+---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------|\n");
		}else{
			printf("|----------------------------------------------------------------------------------------------------------------------|\n");
		}
	}
}

/*
函数功能：根据学号的第5、6位识别学院名称
参数：学生学号、需要识别的院校
返回值：无
*/
void getInstitute(char* stu_id, char* institute) {
	char num[4] = { " " };
	strncpy(num, stu_id + 4, 2);
	num[3] = '\0';
	switch (atol(num)) {
	case 1:
		strcpy(institute, "通信学院");
		break;
	case 2:
		strcpy(institute, "计算机学院");
		break;
	case 3:
		strcpy(institute, "光电学院");
		break;
	case 4:
		strcpy(institute, "自动化学院");
		break;
	case 5:
		strcpy(institute, "经管学院");
		break;
	case 6:
		strcpy(institute, "研究生院");
		break;
	case 7:
		strcpy(institute, "外语学院");
		break;
	case 8:
		strcpy(institute, "安发学院");
		break;
	case 9:
		strcpy(institute, "体育学院");
		break;
	case 10:
		strcpy(institute, "传媒学院");
		break;
	case 11:
		strcpy(institute, "先进制造学院");
		break;
	case 12:
		strcpy(institute, "马克思主义学院");
		break;
	}
}

/*
函数功能：根据格式 4位年份(2021)+ 2位学院编号(01-12之间)+
		  3位数字(001-999之间)创建学号
参数：学号
返回值：无
*/
void getStuID(char* stu_id) {
	char num1[10] = { "" };
	char num2[5] = { "" };
	char num3[10] = { "" };
	while (1) {
		scanf("%s", stu_id);
		strncpy(num1, stu_id, 4);
		num1[4] = '\0';
		strncpy(num2, stu_id + 4, 2);
		num2[2] = '\0';
		strncpy(num3, stu_id + 6, 3);
		num3[3] = '\0';
		if (strlen(stu_id) != 9) {
			printf("学号格式错误，请重新输入：");
			continue;
		}
		if (atol(num1) < 2016 || atol(num1) > 2023 ||
			atol(num2) < 1 || atol(num2) > 12 ||
			atol(num3) < 1 || atol(num3) > 999) {
			printf("学号格式错误，请重新输入：");
			continue;
		}
		else {
			break;
		}
	}
}

/*
函数功能：得到基础课成绩，成绩大于0，小于100
参数：无
返回值：无
*/
int getBasSco() {
	int score = -1;
	while (1) {
		scanf("%d", &score);
		if (score < 0 || score > 100) {
			printf("分数输入错误，请重新输入：");
			continue;
		}
		break;
	}
	return score;
}

/*
函数功能：得到专业课成绩，成绩大于0，小于150
参数：无
返回值：无
*/
int getSpeSco() {
	int score = -1;
	while (1) {
		scanf("%d", &score);
		if (score < 0 || score > 150) {
			printf("分数输入错误，请重新输入：");
			continue;
		}
		break;
	}
	return score;
}

/*
函数功能：判断报考类别是否正确
参数：报考类别
返回值：无
*/
void getCategory(char* category) {
	printf("请输入报考类别(学硕 专硕 非全日制)：");
	while (1) {
		scanf("%s", category);
		if (strcmp(category, "学硕") && strcmp(category, "专硕") && strcmp(category, "非全日制")) {
			printf("输入有误！请输入报考类别(学硕 专硕 非全日制)：");
			continue;
		}
		break;
	}
}

/*
函数功能：输出当前学生信息
参数：学生
返回值：无
*/
void printCurStu(Student stu) {
	printf("|----------------------------------------------------------------------------------------------------------------------|\n");
	printf("|%-10s|%-10s|%-15s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|\n",
		"学号", "姓名", "报考学院", "报考类别", "基础课1", "基础课2", "专业课1",
		"专业课2", "初试总分", "复试成绩", "口语成绩", "综合成绩");
	printf("|----------+----------+---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------|\n");
	printf("|%-10s|%-10s|%-15s|%-8s|%-8d|%-8d|%-8d|%-8d|%-8.2f|%-8.2f|%-8.2f|%-8.2f|\n", stu.stu_id,
		stu.name, stu.institute, stu.category, stu.basSco_1,
		stu.basSco_2, stu.speSco_1, stu.speSco_2, stu.preExamSco,
		stu.reExamSco,stu.orExamSco, stu.totalSco);
	printf("|----------------------------------------------------------------------------------------------------------------------|\n");
}

/*
函数功能：将文件中数据读入表中
参数：文件名，线性表
返回值：无
*/
void readStuFile(char* fileName,StuList* stuList) {
	Student stu = {""};
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {//文件不存在，则创建文件
		fp = fopen(fileName, "w");
	}
	
	while ((fscanf(fp, "%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%f\t%f\t%f\t%f\t%d\n",
		stu.stu_id, stu.name, stu.institute,stu.category, &stu.basSco_1,
		&stu.basSco_2,&stu.speSco_1,&stu.speSco_2, &stu.preExamSco,
		&stu.reExamSco, &stu.orExamSco, &stu.totalSco,&stu.state)) != EOF ) {
		insertStu(stuList, stu);
	}
	fclose(fp);
}



void readFileAcco(char* fileName,AccoList* accoList) {
	Account acco = { "" };
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {//文件不存在，则创建文件
		fp = fopen(fileName, "w");
	}

	while ((fscanf(fp, "%s\t%s\t%d\n",acco.account,acco.pwd, &acco.state)) != EOF) {
		insertAcco(accoList, acco);
	}
	fclose(fp);
}

/*
函数功能：将表中数据写入文件中
参数：文件名，线性表
返回值：无
*/
void writeFileStu(char* fileName,StuList* list) {
	int index = 0;
	FILE* fp = fopen(fileName, "w");
	for(index = 0;index < list->stuLength;index++){
		if (list->student[index].state == 0) {//被删除学生不写入文件
			continue;
		}
		fprintf(fp, "%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%.2f\t%.2f\t%.2f\t%.2f\t%d\n",
			list->student[index].stu_id, list->student[index].name, 
			list->student[index].institute,list->student[index].category,
			list->student[index].basSco_1, list->student[index].basSco_2,
			list->student[index].speSco_1, list->student[index].speSco_2, 
			list->student[index].preExamSco,list->student[index].reExamSco, 
			list->student[index].orExamSco, list->student[index].totalSco,
			list->student[index].state);
	}
	fclose(fp);
}

void writeFileAcco(char* fileName, AccoList* list) {
	int index = 0;
	FILE* fp = fopen(fileName, "w");
	for (index = 0; index < list->accoLength; index++) {
		if (list->account[index].state == 0) {
			continue;
		}
		fprintf(fp, "%s\t%s\t%d\n",list->account[index].account,
			list->account[index].pwd,
			list->account[index].state);
	}
	fclose(fp);
}

/*
函数功能：将表按报考类别分类，并写入对应文件
参数：线性表
返回值：无
*/
void sortCate(StuList stuList){
	if (stuList.stuLength == 0) {
		return;
	}
	sorList(&stuList);
	int i = 0;
	StuList list1, list2, list3;//学硕，专硕，非全日制
	initStuList(&list1);
	initStuList(&list2);
	initStuList(&list3);
	for (i = 0; i < stuList.stuLength; i++) {
		if (strcmp(stuList.student[i].category, "学硕") == 0) {
			insertStu(&list1, stuList.student[i]);
		}
		if (strcmp(stuList.student[i].category, "专硕") == 0) {
			insertStu(&list2, stuList.student[i]);
		}
		if (strcmp(stuList.student[i].category, "非全日制") == 0) {
			insertStu(&list3, stuList.student[i]);
		}
	}
	writeFileStu("data3.txt", &list1);
	writeFileStu("data4.txt", &list2);
	writeFileStu("data5.txt", &list3);
}