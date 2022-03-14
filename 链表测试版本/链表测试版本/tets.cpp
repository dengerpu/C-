#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"

//�˵�
void menu() {
	printf("----------------ѧ������ϵͳ----------------\n");
	printf("\t\t0.�˳�ϵͳ\n");
	printf("\t\t1.������Ϣ\n");
	printf("\t\t2.�����Ϣ\n");
	printf("\t\t3.ɾ����Ϣ\n");
	printf("\t\t4.�޸���Ϣ\n");
	printf("\t\t5.������Ϣ\n");
	printf("--------------------------------------------\n");
	printf("��ѡ�����:>");
}

int main() {
	int input = 0;
	struct Node* list = createList();
	readInfoFromFile("student.txt", list);
	struct student tempData;
	//char name[20];  //����
	//char num[10];	//ѧ��
	//int age;		//����
	//char tel[20];	//�绰
	//char addr[20];	//��ַ
	do {
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("\t\t��������Ϣ��\n");
			printf("������Ҫ�����ѧ����Ϣ:>\n");
			printf("������������ѧ�š����䡢�绰����ַ��>");
			scanf("%s%s%d%s%s", tempData.name, tempData.num, &(tempData.age), tempData.tel, tempData.addr);
			insertNodeNyHead(list, tempData);
			//list = insertNodeByTail(list, tempData);
			break;
		case 2:
			printf("\t\t�������Ϣ��\n");
			printList(list);
			break;
		case 3:
			printf("\t\t��ɾ����Ϣ��\n");
			printf("������Ҫɾ����ѧ����Ϣ��������:>");
			scanf("%s", tempData.name);
			deleteNodeByquery(list, tempData.name);
			break;
		case 4:
			printf("\t\t���޸���Ϣ��\n");
			printf("������Ҫ�޸ĵ�ѧ��:>");
			scanf("%s", &tempData.num);
			if (findNodeByquery(list, tempData.num) == NULL) {
				printf("δ���ҵ������Ϣ\n");
			}
			else {
				struct Node* modifyNode = findNodeByquery(list, tempData.num);
				printf("������������ѧ�š����䡢�绰����ַ��>");
				scanf("%s%s%d%s%s", modifyNode->data.name, modifyNode->data.num, &(modifyNode->data.age), modifyNode->data.tel, modifyNode->data.addr);
				
			}
			break;
		case 5:printf("\t\t��������Ϣ��\n");
			printf("������Ҫ���ҵ�ѧ��:>");
			scanf("%s", &tempData.num);
			if (findNodeByquery(list, tempData.num) == NULL) {
				printf("��Ϊ�ջ���Ҳ���\n");
			}
			else {
				printNode(findNodeByquery(list, tempData.num));
			}
			break;
		case 0:saveInfoToFile("student.txt", list); exit(0); break;
		default:printf("������������������\n"); break;
		
		}
		system("pause");
		system("cls");
	} while (input);

	return 0;
}