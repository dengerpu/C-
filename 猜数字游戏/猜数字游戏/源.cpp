#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>


void menu() {  //菜单
	printf("*********************\n");
	printf("*****猜数字游戏******\n");
	printf("****1.play  0.exit***\n");
	printf("*********************\n");
}
void game() {
	int input = 0;
	int ret = rand()%100+1;
	printf("请输入要猜的数字\n", ret);
	scanf("%d", &input);
	while (input != ret) {
		if (input < ret) {
			printf("猜小了\n");
			printf("请输入要猜的数字\n", ret);
			scanf("%d", &input);
		}
		else if (input > ret) {
			printf("猜大了\n");
			printf("请输入要猜的数字\n", ret);
			scanf("%d", &input);
		}
	}
	if(input == ret)
		printf("恭喜你猜对了\n");

}

int main() {
	int num = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		scanf("%d", &num);
		if (num == 1) {
			game();
		}
		else if (num == 0) {
			break;
		}
		else {
			printf("输入非法,请重新输入\n");
		}
	
	} while (num == 1);
	

	return 0;
}