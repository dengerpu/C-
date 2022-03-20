#define _CRT_SECURE_NO_WARNINGS

#include"sequenceList.h"

/******************�������Ա�****************/
StuList stuList = {""};

AccoList accoList = { "" };

/****************��ҵ����*****************/
////////////////////////////////////////////
//	���˵�
void mainMenu();
//	����Աϵͳ
void adminSys();
//	����Աϵͳ
void userSys();
//	ѧ��ϵͳ
void studentSys();
//	���ӣ�
void  addStudent();
//	ɾ����
void deleteStudent();
//	���ң�
void queryStudent();
//	�޸ģ�
void updateStudnt();
//	��ӡ������Ϣ: 
void printAll();

/****************����ҵ����*****************/
////////////////////////////////////////////
//	ѧԺ��ȡ
void getInstitute(char* stu_id, char* institute);
//	��ȡѧ��
void getStuID(char* stu_id);
//  ��ȡ�����γɼ�
int getBasSco();
//  ��ȡרҵ�γɼ�
int getSpeSco();
//	��ȡ�������
void getCategory(char* category);
//	�����ǰѧ����Ϣ
void printCurStu(Student stu);
// д�ļ�
void writeFileStu(char* fileName, StuList* list);
void writeFileAcco(char* fileName, AccoList* list);
// ���ļ�
void readFileAcco(char* fileName, AccoList* accoList);
void readStuFile(char* fileName, StuList* stuList);
// ������������
void sortCate(StuList stulist);

/*******************������*******************/
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

/***************��ҵ��������***************/
/////////////////////////////////////////////

/*
�������ܣ�ѭ����ʾ�û�����,�ṩѡ������ʾ
		  ��������ѡ���������Ӧ�û�������
��������
����ֵ����
*/
void mainMenu() {
	int userSelect = 0;
	printf("|----------------------------------|\n");
	printf("|---  ��ӭʹ��ѧ���ɼ�����ϵͳ  ---|\n");
	printf("|----------------------------------|\n");
	printf("\n");
	while (1) {
		printf("|--------------�û�����------------|\n");
		printf("|            1. ����Ա             |\n");
		printf("|            2. ����Ա             |\n");
		printf("|            3. ѧ  ��             |\n");
		printf("|            0. �˳�ϵͳ           |\n");
		printf("|----------------------------------|\n");
		printf("��ѡ���û����ͣ�");
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
			printf("��������\n");
			break;
		}
	}
}

/*
�������ܣ�ѭ����ʾ����Ա�ɲ���ҵ���ṩѡ������ʾ
		  ��������ѡ���������ҵ���� 
��������
����ֵ����
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
	printf("����Ա�˻���admin\n");
	printf("���������Ա���룺");
	while (loop) {
		scanf("%s", acco.pwd);
		index = locateAcco(&accoList, "admin");
		if (strcmp(acco.pwd, accoList.account[index].pwd) != 0) {
			printf("����������������룺");
			continue;
		}
		printf("��¼�ɹ�!\n");
		if (strcmp(acco.pwd, "admin") == 0) {
			printf("���޸ĳ������룺");
			scanf("%s", accoList.account[index].pwd);
			writeFileAcco("data1.txt", &accoList);
		}
		loop = 0;
	}
	
	printf("|----------------------------------|\n");
	printf("|---     ��ӭʹ�ù���Աϵͳ     ---|\n");
	printf("|----------------------------------|\n");
	while (1) {
		printf("|----------------------------------|\n");
		printf("|         1. ����ѧ����Ϣ          |\n");
		printf("|         2. ɾ��ѧ����Ϣ          |\n");
		printf("|         3. �޸�ѧ����Ϣ          |\n");
		printf("|         4. ����ѧ����Ϣ          |\n");
		printf("|         5. ��ӡȫ����Ϣ          |\n");
		printf("|         0. �˳�����Աϵͳ        |\n");
		printf("|----------------------------------|\n");
		printf("��ѡ��ҵ��");
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
			printf("����ѡ������������ѡ��\n");
		}
	}
}

/*
�������ܣ�ѭ����ʾ����Ա�ɲ���ҵ���ṩѡ������ʾ
		  ��������ѡ���������ҵ����
��������
����ֵ����
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
	printf("����Ա�˻���user01\n");
	printf("���������Ա���룺");
	while (loop) {
		scanf("%s", acco.pwd);
		index = index = locateAcco(&accoList, "user01");
		if (strcmp(acco.pwd, accoList.account[index].pwd) != 0) {
			printf("����������������룺");
			continue;
		}
		if (strcmp(acco.pwd, "user01") == 0) {
			printf("���޸ĳ�ʼ���룺");
			scanf("%s", accoList.account[index].pwd);
			writeFileAcco("data1.txt", &accoList);
		}
		loop = 0;
	}
	printf("|----------------------------------|\n");
	printf("|---     ��ӭʹ�ò���Աϵͳ     ---|\n");
	printf("|----------------------------------|\n");
	while (1) {
		printf("|----------------------------------|\n");
		printf("|         1. ����ѧ����Ϣ          |\n");
		printf("|         2. ����ѧ����Ϣ          |\n");
		printf("|         0. �˳�����Աϵͳ        |\n");
		printf("|----------------------------------|\n");
		printf("��ѡ��ҵ��");
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
			printf("����ѡ������������ѡ��\n");
		}
	}
}

/*
�������ܣ�ѭ����ʾѧ����ѯҵ��
��������
����ֵ����
*/
void studentSys() {
	int index = -1;
	int select = 0;
	char stu_id[20] = { "" };
	int loop = 1;
	char pwd[20] = { "" };
	printf("������ѧ�ţ�");
	getStuID(stu_id);
	index = locateAcco(&accoList,stu_id);
	if (index == -1) {
		return;
	}
	printf("���������룺");
	while (loop) {
		scanf("%s", pwd);
		if (strcmp(pwd, accoList.account[index].pwd) != 0) {
			printf("����������������룺");
			continue;
		}
		if (strcmp(pwd, stu_id) == 0) {
			printf("���޸ĳ�ʼ���룺");
			scanf("%s", accoList.account[index].pwd);
			writeFileAcco("data1.txt", &accoList);
		}
		loop = 0;
	}
	printf("|----------------------------------|\n");
	printf("|---      ��ӭʹ��ѧ��ϵͳ      ---|\n");
	printf("|----------------------------------|\n");
	while (1) {
		printf("|----------------------------------|\n");
		printf("|         1. ����ѧ����Ϣ          |\n");
		printf("|         0. �˳�ѧ��ϵͳ          |\n");
		printf("|----------------------------------|\n");
		printf("��ѡ��ҵ��");
		scanf("%d", &select);
		switch (select) {
		case 1:
			queryStudent();
			break;
		case 0:
			return;
		default:
			printf("����ѡ������������ѡ��\n");
		}
	}
}

/*
�������ܣ������������Ϣ����ӵ�ѧ��������
��������
����ֵ����
*/
void addStudent() {
	int select = 0;
	int loop = 1;
	Student stu = {""};
	Account acco = { "" };
	printf("----------    ����ѧ����Ϣ    ----------\n");
	while (loop) {
		printf("������");
		scanf("%s", stu.name);
		printf("ѧ�ţ�");
		getStuID(stu.stu_id);
		getInstitute(stu.stu_id, stu.institute);
		getCategory(stu.category);
		printf("�����������1�ɼ���");
		stu.basSco_1 = getBasSco();
		printf("�����������2�ɼ���");
		stu.basSco_2 = getBasSco();
		printf("������רҵ��1�ɼ���");
		stu.speSco_1 = getSpeSco();
		printf("������רҵ��2�ɼ���");
		stu.speSco_2 = getSpeSco();
		printf("���������ɼ���");
		scanf("%f", &stu.orExamSco);
		printf("�����븴�Գɼ���");
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

		printf("�Ƿ������ӣ�1�� 0��");
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
				printf("������������������(1��0)��");
				continue;
			}
		}
	}
	writeFileStu("data2.txt", &stuList);
	writeFileAcco("data1.txt", &accoList);
}

/*
�������ܣ�ɾ��ѧ����Ϣ����ѧ��״̬��stateΪ0
��������
����ֵ�� ��
*/
void deleteStudent() {
	int loop = 1;
	int select = 0;
	char stu_id[20] = {""};
	printf("----------  ɾ��ѧ����Ϣ  ----------\n");
	while (loop) {
		printf("��������Ҫɾ����ѧ��ѧ�ţ�");
		getStuID(stu_id);
		deleteStu(&stuList, stu_id);
		deleteAcco(&accoList, stu_id);
		printf("�Ƿ����ɾ����1�� 0��");
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
				printf("������������������(1��0)��");
				continue;
			}
		}
	}
	writeFileStu("data2.txt", &stuList);
	writeFileAcco("data1.txt", &accoList);
}

/*
�������ܣ���ѯѧ����Ϣ�����Ը���ѧ��
		  ��������ѯ
��������
����ֵ�� ��
*/
void queryStudent() {
	int loop = 1;
	int select = 0;
	int index = -1;
	char stu_id[20] = { " " };
	printf("----------  ��ѯѧ����Ϣ  ----------\n");
	while (loop) {
		printf("��������Ҫ��ѯ��ѧ��ѧ�ţ�");
		getStuID(stu_id);
		index = locateStu(&stuList, stu_id);
		if (index == -1) {
			//printf("δ�ҵ������Ϣ��");
		}else {
			printCurStu(stuList.student[index]);
		}

		printf("�Ƿ������ѯ��1�� 0��");

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
				printf("������������������(1��0)��");
				continue;
			}
		}
	}
}

/*
�������ܣ��޸�ѧ����Ϣ���ȸ���ѧ�Ų���
		  �ҵ�����������ѧ�����ݣ�Ȼ��
		  ��д�ļ�
��������
����ֵ�� ��
*/
void updateStudnt() {
	int loop = 1;
	int select = 0;
	int index = -1;
	char stu_id[20] = { " " };
	printf("----------  �޸�ѧ����Ϣ  ----------\n");
	while (loop) {
		printf("��������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
		getStuID(stu_id);
		index = locateStu(&stuList, stu_id);

		if (index == -1) {
			printf("û���ҵ�ѧ����Ϣ!");
			continue;
		}

		printf("�������޸���Ϣ��\n");
		printf("������");
		scanf("%s", stuList.student[index].name);
		printf("ѧ�ţ�");
		getStuID(stuList.student[index].stu_id);
		getInstitute(stuList.student[index].stu_id, stuList.student[index].institute);
		getCategory(stuList.student[index].category);
		printf("�����������1�ɼ���");
		stuList.student[index].basSco_1 = getBasSco();
		printf("�����������2�ɼ���");
		stuList.student[index].basSco_2 = getBasSco();
		printf("������רҵ��1�ɼ���");
		stuList.student[index].speSco_1 = getSpeSco();
		printf("������רҵ��2�ɼ���");
		stuList.student[index].speSco_2 = getSpeSco();
		printf("���������ɼ���");
		scanf("%f", &stuList.student[index].orExamSco);
		printf("�����븴�Գɼ���");
		scanf("%f", &stuList.student[index].reExamSco);
		stuList.student[index].preExamSco = stuList.student[index].basSco_1 +
			stuList.student[index].basSco_2 +
			stuList.student[index].speSco_1 +
			stuList.student[index].speSco_2;
		stuList.student[index].totalSco = stuList.student[index].preExamSco * 0.6 +
			stuList.student[index].reExamSco * 0.3 +
			stuList.student[index].orExamSco * 0.1;
		stuList.student[index].state = 1;

		printf("�Ƿ�����޸ģ�1�� 0��");

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
				printf("������������������(1��0)��");
				continue;
			}
		}
	}
	writeFileStu("data2.txt", &stuList);
}

/*
�������ܣ���ӡ������ʵ�ʴ��ڵ�ѧ����Ϣ
��������
����ֵ�� ��
*/
void printAll() {
	if (stuList.stuLength == 0) {
		printf("��ѧ����Ϣ\n");
		return;
	}
	int i = 0;
	printf("----------  ��ӡȫ����Ϣ  ----------\n");
	printf("|----------------------------------------------------------------------------------------------------------------------|\n");
	printf("|%-10s|%-10s|%-15s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|\n", 
		"ѧ��", "����", "����ѧԺ", "�������", "������1", "������2","רҵ��1",
		"רҵ��2","�����ܷ�","���Գɼ�","����ɼ�", "�ۺϳɼ�");
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
�������ܣ�����ѧ�ŵĵ�5��6λʶ��ѧԺ����
������ѧ��ѧ�š���Ҫʶ���ԺУ
����ֵ����
*/
void getInstitute(char* stu_id, char* institute) {
	char num[4] = { " " };
	strncpy(num, stu_id + 4, 2);
	num[3] = '\0';
	switch (atol(num)) {
	case 1:
		strcpy(institute, "ͨ��ѧԺ");
		break;
	case 2:
		strcpy(institute, "�����ѧԺ");
		break;
	case 3:
		strcpy(institute, "���ѧԺ");
		break;
	case 4:
		strcpy(institute, "�Զ���ѧԺ");
		break;
	case 5:
		strcpy(institute, "����ѧԺ");
		break;
	case 6:
		strcpy(institute, "�о���Ժ");
		break;
	case 7:
		strcpy(institute, "����ѧԺ");
		break;
	case 8:
		strcpy(institute, "����ѧԺ");
		break;
	case 9:
		strcpy(institute, "����ѧԺ");
		break;
	case 10:
		strcpy(institute, "��ýѧԺ");
		break;
	case 11:
		strcpy(institute, "�Ƚ�����ѧԺ");
		break;
	case 12:
		strcpy(institute, "���˼����ѧԺ");
		break;
	}
}

/*
�������ܣ����ݸ�ʽ 4λ���(2021)+ 2λѧԺ���(01-12֮��)+
		  3λ����(001-999֮��)����ѧ��
������ѧ��
����ֵ����
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
			printf("ѧ�Ÿ�ʽ�������������룺");
			continue;
		}
		if (atol(num1) < 2016 || atol(num1) > 2023 ||
			atol(num2) < 1 || atol(num2) > 12 ||
			atol(num3) < 1 || atol(num3) > 999) {
			printf("ѧ�Ÿ�ʽ�������������룺");
			continue;
		}
		else {
			break;
		}
	}
}

/*
�������ܣ��õ������γɼ����ɼ�����0��С��100
��������
����ֵ����
*/
int getBasSco() {
	int score = -1;
	while (1) {
		scanf("%d", &score);
		if (score < 0 || score > 100) {
			printf("��������������������룺");
			continue;
		}
		break;
	}
	return score;
}

/*
�������ܣ��õ�רҵ�γɼ����ɼ�����0��С��150
��������
����ֵ����
*/
int getSpeSco() {
	int score = -1;
	while (1) {
		scanf("%d", &score);
		if (score < 0 || score > 150) {
			printf("��������������������룺");
			continue;
		}
		break;
	}
	return score;
}

/*
�������ܣ��жϱ�������Ƿ���ȷ
�������������
����ֵ����
*/
void getCategory(char* category) {
	printf("�����뱨�����(ѧ˶ ר˶ ��ȫ����)��");
	while (1) {
		scanf("%s", category);
		if (strcmp(category, "ѧ˶") && strcmp(category, "ר˶") && strcmp(category, "��ȫ����")) {
			printf("�������������뱨�����(ѧ˶ ר˶ ��ȫ����)��");
			continue;
		}
		break;
	}
}

/*
�������ܣ������ǰѧ����Ϣ
������ѧ��
����ֵ����
*/
void printCurStu(Student stu) {
	printf("|----------------------------------------------------------------------------------------------------------------------|\n");
	printf("|%-10s|%-10s|%-15s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|\n",
		"ѧ��", "����", "����ѧԺ", "�������", "������1", "������2", "רҵ��1",
		"רҵ��2", "�����ܷ�", "���Գɼ�", "����ɼ�", "�ۺϳɼ�");
	printf("|----------+----------+---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------|\n");
	printf("|%-10s|%-10s|%-15s|%-8s|%-8d|%-8d|%-8d|%-8d|%-8.2f|%-8.2f|%-8.2f|%-8.2f|\n", stu.stu_id,
		stu.name, stu.institute, stu.category, stu.basSco_1,
		stu.basSco_2, stu.speSco_1, stu.speSco_2, stu.preExamSco,
		stu.reExamSco,stu.orExamSco, stu.totalSco);
	printf("|----------------------------------------------------------------------------------------------------------------------|\n");
}

/*
�������ܣ����ļ������ݶ������
�������ļ��������Ա�
����ֵ����
*/
void readStuFile(char* fileName,StuList* stuList) {
	Student stu = {""};
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {//�ļ������ڣ��򴴽��ļ�
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
	if (fp == NULL) {//�ļ������ڣ��򴴽��ļ�
		fp = fopen(fileName, "w");
	}

	while ((fscanf(fp, "%s\t%s\t%d\n",acco.account,acco.pwd, &acco.state)) != EOF) {
		insertAcco(accoList, acco);
	}
	fclose(fp);
}

/*
�������ܣ�����������д���ļ���
�������ļ��������Ա�
����ֵ����
*/
void writeFileStu(char* fileName,StuList* list) {
	int index = 0;
	FILE* fp = fopen(fileName, "w");
	for(index = 0;index < list->stuLength;index++){
		if (list->student[index].state == 0) {//��ɾ��ѧ����д���ļ�
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
�������ܣ��������������࣬��д���Ӧ�ļ�
���������Ա�
����ֵ����
*/
void sortCate(StuList stuList){
	if (stuList.stuLength == 0) {
		return;
	}
	sorList(&stuList);
	int i = 0;
	StuList list1, list2, list3;//ѧ˶��ר˶����ȫ����
	initStuList(&list1);
	initStuList(&list2);
	initStuList(&list3);
	for (i = 0; i < stuList.stuLength; i++) {
		if (strcmp(stuList.student[i].category, "ѧ˶") == 0) {
			insertStu(&list1, stuList.student[i]);
		}
		if (strcmp(stuList.student[i].category, "ר˶") == 0) {
			insertStu(&list2, stuList.student[i]);
		}
		if (strcmp(stuList.student[i].category, "��ȫ����") == 0) {
			insertStu(&list3, stuList.student[i]);
		}
	}
	writeFileStu("data3.txt", &list1);
	writeFileStu("data4.txt", &list2);
	writeFileStu("data5.txt", &list3);
}