#define _CRT_SECURE_NO_WARNINGS
#include "studentOption.cpp"

//enum option {
//	EXIT,
//	ADD,
//	MODIFY,
//	QUERY,
//	STATISTICS,
//	ADVICE,
//	PRINT
//};

int main() {
	int input = 0;
	struct Node* list;
	list = createList();
	readInfoFromFile("data1.txt", list);
	do {
		 menu();
		scanf("%d", &input);
		switch (input) {
		case ADD:addStudent(list); saveInfoToFile("data1.txt", list); break;
		case MODIFY:modifyStudent(list); saveInfoToFile("data1.txt", list); break;
		case QUERY:abnormalStatus(list); break;
		case STATISTICS:deadlineStatics(list); break;
		case ADVICE:abnormalAdvice(list); break;
		case PRINT:printList(list); break;
		case EXIT:printf("退出\n"); break;
		default:printf("输入有误，请重新输入\n"); break;
		}
		system("pause");
		system("cls");
	} while (input);

	return 0;
}