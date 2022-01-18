#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int day;
	scanf("%d", &day);

	//switch (day) {
	//case 1: printf("星期一\n"); break;
	//case 2: printf("星期二\n"); break;
	//case 3: printf("星期三\n"); break;
	//case 4: printf("星期四\n"); break;
	//case 5: printf("星期五\n"); break;
	//case 6: printf("星期六\n"); break;
	//case 7: printf("星期天\n"); break;
	//}

	switch (day){
	default:printf("输入错误\n"); break;
	case 1: if (day == 1) printf("111");
	case 2:
	case 3:
	case 4:
	case 5: printf("工作日\n"); break;
	case 6:
	case 7:printf("休息日\n"); break;
	}

	return 0;
}