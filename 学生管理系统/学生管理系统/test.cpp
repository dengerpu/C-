#define _CRT_SECURE_NO_WARNINGS
#include "student.h"

struct Node* list = NULL;
void keydown() {
	int input = 0;
	struct student tempData;
	scanf("%d", &input);
	switch (input) {
	case 0:
		printf("\t\t���˳�ϵͳ��\n");
		exit(0);
		break;
	case 1:
		printf("\t\t��������Ϣ��\n");
		printf("������Ҫ�����ѧ����Ϣ:>\n");
		printf("������������ѧ�š����䡢�绰����ַ��>");
		scanf("%s%s%d%s%s", tempData.name, tempData.num, &tempData.age, tempData.tel, tempData.addr);
		insertNoByHead(list, tempData);
		saveInfoToFile("student.txt", list);
		break;
	case 2:
		printf("\t\t�������Ϣ��\n");
		printList(list);
		break;
	case 3:
		printf("\t\t��ɾ����Ϣ��\n"); 
		printf("������Ҫɾ����ѧ����Ϣ��������:>");
		scanf("%s", tempData.name);
		deleteNodeByStudent_Name(list, tempData.name);
		saveInfoToFile("student.txt", list);
		break;
	case 4:
		printf("\t\t���޸���Ϣ��\n"); 
		printf("������Ҫ�޸ĵ�ѧ��:>");
		scanf("%s", &tempData.num);
		if (searchNodeBynum(list, tempData.num) == NULL) {
			printf("δ���ҵ������Ϣ\n");
		}
		else {
			struct Node* modifyNode = searchNodeBynum(list, tempData.num);
			printf("������������ѧ�š����䡢�绰����ַ��>");
			scanf("%s%s%d%s%s", modifyNode->data.name, modifyNode->data.num, &(modifyNode->data.age), modifyNode->data.tel, modifyNode->data.addr);
			saveInfoToFile("student.txt", list);
		}
		break;
	case 5:
		printf("\t\t��������Ϣ��\n");
		printf("������Ҫ���ҵ�ѧ��:>");
		scanf("%s", &tempData.num);
		if (searchNodeBynum(list, tempData.num) == NULL) {
			printf("��Ϊ�ջ���Ҳ���\n");
		}
		else {
			printNode(searchNodeBynum(list, tempData.num));
		}
		break;
	default:printf("������������������\n"); break;

	}
}



int main() {
	list = createList();
	readInfofromfile("student.txt", list);
	while (1) {
		menu();
		keydown();
		system("pause");
		system("cls");
	}
	
	return 0;
}