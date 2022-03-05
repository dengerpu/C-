#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"


//初始化通讯录
void InitContact(struct Contact* p) {
	//memset(p->data, 0, sizeof(p->data));
	p->data = (PInfo)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (p->data == NULL) {
		printf("%s\n", strerror(errno));
	}
	p->size = 0;
	p->capicty = DEFAULT_SZ;
	//把文件中已经存放的通讯录中的信息加载到通讯录中去
	LoadContact(p);
}
//检查容量是否够
void CheckCapacity(struct Contact* p) {
	if (p->size == p->capicty) {
		//增容
		PInfo ptr = (PInfo)realloc(p->data, sizeof(struct PeoInfo) * DEFAULT_SZ);
		if (ptr != NULL) {
			p->data = ptr;
			p->capicty = p->capicty + DEFAULT_SZ;
			printf("增容成功\n");
		}
		else {
			printf("增容失败\n");
			printf("%s\n", strerror(errno));
			return;
		}

	}
}
//加载文件数据到通讯录中
void LoadContact(Contact* p) {
	PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("data.txt", "r");
	if (pfRead == NULL) {
		printf("LoadContact:%s\n", strerror(errno));
		return;
	}
	//读取文件，存放到通讯录中
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead)) {
		CheckCapacity(p);
		p->data[p->size] = tmp;
		p->size++;
	}
	fclose(pfRead);
	pfRead = NULL;
}

//添加用户
void AddContact(struct Contact* p) {
	//检测当前通讯录的容量
	//1. 如果满了，就增加空间
	//2. 如果不满，啥事都不干
	CheckCapacity(p);
	getchar();
		printf("请输入名字: > ");
		//scanf("%s", p->data[p->size].name);
		//printf("%s\n", p->data[p->size].name);
		gets_s(p->data[p->size].name);
		printf("请输入年龄: > ");
		scanf("%d", &(p->data[p->size].age));  //注意这里要取地址
		//printf("%d\n", p->data[p->size].age);
		getchar();
		printf("请输入性别: > ");
		gets_s(p->data[p->size].sex);
		//scanf("%s", p->data[p->size].sex);
		//printf("%s\n", p->data[p->size].sex);
		printf("请输入电话: > ");
		gets_s(p->data[p->size].tele);
		//scanf("%s", p->data[p->size].tele);
		//printf("%s\n", p->data[p->size].tele);
		printf("请输入地址: > ");
		gets_s(p->data[p->size].addr);
		//scanf("%s", p->data[p->size].addr);
		//printf("%s\n", p->data[p->size].addr);
		p->size++;
		printf("添加成功\n");
	
}
//展示用户
void ShowContact(const struct Contact* p) {
	if (p->size == 0) {
		printf("通讯录为空\n");
	}
	else {
		int i = 0;
		printf("%-20s\t%-5s\t%-5s\t%-11s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
		for (i = 0; i < p->size; i++) {
			printf("%-20s\t%-5d\t%-5s\t%-11s\t%-30s\n",
				p->data[i].name,
				p->data[i].age,
				p->data[i].sex,
				p->data[i].tele,
				p->data[i].addr
			);
		}
	}
}
static int FindByName(const struct Contact* p, char name[NAME_MAX]) {
	if (p->size == 0) {
		printf("通讯录为空\n");
	}
	else {
		for (int i = 0; i < p->size; i++) {
			if (0 == strcmp(p->data[i].name, name)) {
				return i;
			}
		}
		return -1;  //找不到
	}
}
//删除用户
void DelContact(struct Contact* p) {
	char name[NAME_MAX];
	printf("请输入要删除的名字:>");
	scanf("%s", name);
	int ret = FindByName(p, name);
	if (-1 == ret) {
		printf("查找不到\n");
	}
	else {
		for (int i = ret; i < p->size - 1; i++) {
			p->data[i] = p->data[i + 1];
		}
		p->size--;
		printf("删除成功\n");
	}
}

//查找用户
void SearchContact(const struct Contact* p) {
	char name[NAME_MAX];
	printf("请输入要查找的名字:>");
	scanf("%s", name);
	int ret = FindByName(p, name);
	if (-1 == ret) {
		printf("查找不到\n");
	}
	else {
		printf("%-20s\t%-5s\t%-5s\t%-11s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-5d\t%-5s\t%-11s\t%-30s\n",
			p->data[ret].name,
			p->data[ret].age,
			p->data[ret].sex,
			p->data[ret].tele,
			p->data[ret].addr
		);
	}
}

//修改用户
void ModifyContact(struct Contact* p) {
	char name[NAME_MAX];
	printf("请输入要修改用户的名字:>");
	scanf("%s", name);
	int ret = FindByName(p, name);
	if (-1 == ret) {
		printf("查找不到\n");
	}
	else {
		printf("请输入名字:>");
		scanf("%s", p->data[ret].name);
		printf("请输入年龄:>");
		scanf("%d", &(p->data[ret].age));
		printf("请输入性别:>");
		scanf("%s", p->data[ret].sex);
		printf("请输入电话:>");
		scanf("%s", p->data[ret].tele);
		printf("请输入地址:>");
		scanf("%s", p->data[ret].addr);

		printf("修改完成\n");
	}

}
//void qsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*))
//
//参数
//base-- 指向要排序的数组的第一个元素的指针。
//nitems-- 由 base 指向的数组中元素的个数。
//size-- 数组中每个元素的大小，以字节为单位。
//compar-- 用来比较两个元素的函数，即函数指针（回调函数）
//排序
//按照姓名排序
int cmpByName(const void* e1, const void* e2) {
	return strcmp((*(struct PeoInfo*)e1).name, (*(struct PeoInfo*)e2).name);
}
//按照年龄排序
int cmpByAge(const void* e1, const void* e2) {
	return (((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age);
}
void SortContact(struct Contact* p) {
	printf("请输入排序方式：0：姓名  1：年龄（默认为0）\n");
	int input = 0;
	scanf("%d", &input);
	if (input == 1) {
		qsort(p->data, p->size, sizeof(p->data[0]), cmpByAge);
	}
	else {
		qsort(p->data, p->size, sizeof(p->data[0]), cmpByName);
	}
	ShowContact(p);
}
//退出后执行释放函数
void DestroyContact(Contact* ps)
{
	free(ps->data);  //释放内存
	ps->data = NULL;
}

void SaveContact(Contact* p) {
	FILE* pfWrite = fopen("data.txt", "w");
	if (pfWrite == NULL) {
		printf("SaveContact:%s\n", strerror(errno));
		return;
	}
	//通讯录的数据写到文件中去
	int i = 0;
	for (i = 0; i < p->size; i++) {
		fwrite(&(p->data[i]), sizeof(PeoInfo), 1, pfWrite);

	}
	fclose(pfWrite);
	pfWrite = NULL;
}
