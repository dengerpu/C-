#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// 初始数据
const string stuInfoFileName = "data1.txt";
const string inquireDataFileName = "data2.txt";
const string unusualDataFileName = "data3.txt";
const string warningDataFileName = "data4.txt";
// 月份对应天数（平年）
map<int, int> dayOfMonth = { {1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, 
	{7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31} };
// 学院
map<string, string> faculties = { {"01", "通信学院"}, {"02", "计算机学院"}, {"03", "光电学院"}, {"04", "自动化学院"},
	{"05", "经管学院"}, {"06", "研究生院"}, {"07", "外语学院"}, {"08", "安法学院"},
	{"09", "体育学院"}, {"10", "传媒学院"}, {"11", "先进制造学院"}, {"12", "马克思主义学院"} };

// 是否是闰年
inline bool isLeapYear(int);

// 时间类
class Time {
public:
	int hour;
	int minute;
	int second;

	Time(): hour(0), minute(0), second(0) { }

	Time(string str) {
		fromString(str);
	}

	// 字符串转时间对象，返回是否转换成功
	bool fromString(string str) {
		int n = str.size();		// 字符串长度
		if (n != 2 && n != 5 && n != 8)
			return false;
		try {
			hour = n >= 2 ? stoi(str.substr(0, 2)) : 0;
			if (hour < 0 || hour >= 24) {
				hour = 0;
				return false;
			}
			minute = n >= 5 ? stoi(str.substr(3, 2)) : 0;
			if (minute < 0 || minute >= 60) {
				minute = 0;
				return false;
			}
			second = n >= 8 ? stoi(str.substr(6, 2)) : 0;
			if (second < 0 || second >= 60) {
				second = 0;
				return false;
			}
		} catch (...) {		// 转数字异常
			return false;
		}
		return true;
	}

	// 时间对象转字符串
	string toString() {
		char str_c[9];
		sprintf(str_c, "%02d:%02d:%02d", hour, minute, second);
		return string(str_c);
	}

	inline bool operator == (const Time& time) const {
		return hour == time.hour && minute == time.minute && second == time.second;
	}

	inline bool operator != (const Time& time) const {
		return !(*this == time);
	}

	inline bool operator < (const Time& time) const {
		return hour == time.hour ? (minute == time.minute ? (second == time.second ? 
			false : second < time.second) : minute < time.minute) : hour < time.hour;
	}

	inline bool operator > (const Time& time) const {
		return time < *this;
	}
};

// 日期类
class Date {
public:
	int year;
	int month;
	int day;

	Date() : year(1970), month(1), day(1) { }

	Date(string str) {
		fromString(str);
	}

	// 字符串转日期对象，返回是否转换成功
	bool fromString(string str) {
		int n = str.size();
		if (n != 8)
			return false;
		try {
			year = stoi(str.substr(0, 4));
			month = stoi(str.substr(4, 2));
			if (month < 0 || month > 12) {
				month = 1;
				return false;
			}
			day = stoi(str.substr(6, 2));
			if (day < 0 || day > dayOfMonth[month] + (int)(month == 2 && isLeapYear(year))) {	// 闰年2月多一天
				day = 1;
				return false;
			}
		} catch (...) {
			return false;
		}
		return true;
	}

	// 日期对象转字符串
	string toString() {
		char str_c[9];
		sprintf(str_c, "%04d%02d%02d", year, month, day);
		return string(str_c);
	}

	// 两个日期是否相邻
	bool isAdjacent(Date& date) {
		Date date1, date2;	// date1小，date2大
		if (*this < date) {
			date1 = *this;
			date2 = date;
		} else if (*this > date) {
			date1 = date;
			date2 = *this;
		} else {	// 两天相等
			return false;
		}
		if (date1.year != date2.year) {		// 年份不相等
			return date2.year - date1.year == 1 && date1.month == 12 && date1.day == 31 && date2.month == 1 && date2.day == 1;
		} else if (date1.month != date2.month) {	// 同年，月份不相等
			return date2.month - date1.month == 1 && date2.day == 1 
				&& date1.day == dayOfMonth[date1.month] + (date1.month == 2 && isLeapYear(date1.year));
		} else {	// 同一个月
			return date2.day - date1.day == 1;
		}
	}

	inline bool operator == (const Date& date) const {
		return year == date.year && month == date.month && day == date.day;
	}

	inline bool operator != (const Date& date) const {
		return !(*this == date);
	}

	inline bool operator < (const Date& date) const {
		return year == date.year ? (month == date.month ? (day == date.day ?
			false : day < date.day) : month < date.month) : year < date.year;
	}

	inline bool operator > (const Date& date) const {
		return date < *this;
	}
};

// 学生类
class Student {
public:
	string id;
	string name;
	string fctId;
	double bodyTem;
	bool hasCough;
	bool healthyState;
	Time time;
	Date date;

	Student(): bodyTem(36), hasCough(false), healthyState(true) { }

	// 是否健康
	bool isHealthy() {
		healthyState = bodyTem < 37.3f && !hasCough;
		return healthyState;
	}

	inline bool operator < (Student& stu) {
		return id == stu.id ? (date == stu.date ? (time == stu.time ? true : time < stu.time) : date < stu.date) : id < stu.id;
	}

	inline bool operator > (Student& stu) {
		return stu < *this;
	}
};

// 学生列表
vector<Student> stuList;

// 是否是闰年
inline bool isLeapYear(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

// 按照学号查找学生索引
vector<int> searchStudentById(string id) {
	vector<int> res;	// 满足条件的索引列表
	int n = stuList.size();
	for (int i = 0; i < n; ++i) {
		if (stuList[i].id == id)
			res.push_back(i);	// 将该索引加入列表
	}
	return res;
}

// 按照姓名查找学生索引
vector<int> searchStudentByName(string name) {
	vector<int> res;	// 满足条件的索引列表
	int n = stuList.size();
	for (int i = 0; i < n; ++i) {
		if (stuList[i].name == name)
			res.push_back(i);	// 将该索引加入列表
	}
	return res;
}

// 初始化系统
void init() {
	ifstream file;
	file.open(stuInfoFileName);
	if (!file.is_open()) {		// 文件不存在，新建一个空文件
		ofstream newFile(stuInfoFileName, ios::_Noreplace);
		newFile.close();
	} else {
		Student stu;
		string time;
		string date;
		while (true) {
			file >> stu.id;
			if (!file.eof()) {	// 未遇到文件尾，说明还有数据
				file >> stu.name >> stu.fctId >> stu.bodyTem >> stu.hasCough >> stu.healthyState >> time >> date;
				stu.isHealthy();	// 验证是否健康
				stu.time.fromString(time);		// 字符串转时间
				stu.date.fromString(date);		// 字符串转日期
				stuList.push_back(stu);			// 加入学生列表
			} else {	// 遇到文件尾，结束
				break;
			}
		}
		file.close();
		sort(stuList.begin(), stuList.end());	// 排序（按照Student类中重载的 < 运算符进行重载）
	}
}

// 保存学生信息
void saveStuData() {
	ofstream file(stuInfoFileName);
	for (auto& stu : stuList) {
		file << stu.id << " " << stu.name << " " << stu.fctId << " " << stu.bodyTem << " " 
			<< stu.hasCough << " " << stu.healthyState << " " << stu.time.toString() << " " << stu.date.toString() << "\n";
	}
	file.flush();	// 这一句的作用的将文件流中剩余的部分一次性全部写入文件，防止文件流残留数据
	file.close();
}

// 退出系统（退出前先保存）
void quit() {
	saveStuData();
}

// 打印单个学生信息
void printStudentInfo(Student& stu) {
	if (faculties.count(stu.fctId) > 0) {
		// 用printf输出string对象时需要调用c_str()获取字符串对应的char[]类型数据，否则会出现错误
		printf("%s\t%s\t%s\t%.1lf\t%d\t\t%d\t\t%s\t%s\n", stu.id.c_str(), stu.name.c_str(),
			faculties[stu.fctId].c_str(), stu.bodyTem, stu.hasCough, stu.healthyState, 
			stu.time.toString().c_str(), stu.date.toString().c_str());
	}
}

// 输出单个学生信息至文件流
void outputStudentInfo(Student& stu, ofstream& file) {
	if (faculties.count(stu.fctId) > 0) {
		file << stu.id << "\t" << stu.name << "\t" << faculties[stu.fctId] << "\t" << stu.bodyTem << "\t"
			<< stu.hasCough << "\t\t" << stu.healthyState << "\t\t" << stu.time.toString() << "\t" << stu.date.toString() << "\n";
	}
}

// 添加数据
void addData() {
	char buffer[128] = { 0 };	// 用于scanf的缓冲区
	Student stu;
	while (true) {		// 输入失败则会一直循环，后面的代码也有类似写法
		printf("请输入学生信息:\n");
		printf("学生学号: ");
		scanf("%s", buffer);	// scanf不能直接传入string对象，需要用char[]变量转换
		stu.id = buffer;
		stu.fctId = stu.id.substr(4, 2);
		if (stu.id.size() != 9 || faculties.count(stu.fctId) == 0) {	// 查看学院编号是否存在
			printf("该学号信息无效, 请重新输入!\n");
		} else {	// 输入成功，继续进行其他信息输入
			break;
		}
	}
	vector<int> stuIs = searchStudentById(stu.id);	// 查询系统中是否已存在该学生的信息
	if (stuIs.size() == 0) {	// 不存在则需要用户输入姓名
		printf("学生姓名: ");
		scanf("%s", buffer);
		stu.name = buffer;
	} else {	// 存在则自动从系统中获取姓名，避免重复输入
		stu.name = stuList[stuIs[0]].name;
		printf("学生姓名: %s\n", stu.name.c_str());
	}
	printf("学生体温: ");
	scanf("%lf", &stu.bodyTem);
	printf("是否咳嗽 (1:是  0:否): ");
	int temp;
	scanf("%d", &temp);		// scanf不能直接传入bool变量，需要用int变量转换
	stu.hasCough = temp;
	stu.isHealthy();	// 验证是否健康
	while (true) {
		printf("时间 (hh:mm): ");
		scanf("%s", buffer);
		if (!stu.time.fromString(buffer)) {		// 时间转换失败，格式错误
			printf("时间错误, 请重新输入!\n");
		} else {
			break;
		}
	}
	while (true) {
		printf("日期(yyyyMMdd): ");
		scanf("%s", buffer);
		if (!stu.date.fromString(buffer) || stu.date.year < stoi(stu.id.substr(0, 4))) {	// 日期转换失败，或输入年份小于该生入学年份
			printf("日期错误, 请重新输入!\n");
		} else {
			break;
		}
	}
	stuList.push_back(stu);		// 加入学生列表
	printf("已添加√\n");
}

// 更改数据
void changeData(string stuId) {
	vector<int> stuIs = searchStudentById(stuId);	// 查询该学号对应的索引列表
	int n = stuIs.size();	// 信息条数
	int no = 0;		// 表示第几条信息（供用户选择）
	if (n == 0) {
		printf("该学号不存在!\n");
		return;
	} else if (n == 1) {	// 只有一条信息，无需选择
		printf("以下为该学生信息:\n学号\t\t姓名\t学院\t\t体温\t是否咳嗽\t健康状态\t时间\t\t日期\n");
		printStudentInfo(stuList[stuIs[0]]);
	} else {	// 存在多条信息，需要用户选择修改哪一条
		printf("以下为该学生信息:\n\t学号\t\t姓名\t学院\t\t体温\t是否咳嗽\t健康状态\t时间\t\t日期\n");
		int i = 0;
		// 将查询到的信息一一输出供用户查看
		for (auto& index : stuIs) {
			printf("%d.\t", ++i);
			printStudentInfo(stuList[index]);
		}
		while (true) {
			printf("请选择需要修改哪条信息: ");
			scanf("%d", &no);
			if (no < 1 || no > n) {
				printf("输入无效! 请重新输入.\n");
			} else {
				--no;
				break;
			}
		}
	}
	Student& stu = stuList[stuIs[no]];	// 使用引用直接修改列表中的对象
	printf("请选择需要修改的项:\n    01. 体温\n    02. 是否咳嗽\n    03. 时间\n    04. 日期\n    -1. 退出\n");
	int item;		// 第几项
	scanf("%d", &item);
	char buffer[16] = { 0 };
	switch (item)	// 根据用户输入的项目进行修改
	{
	case 1:
		printf("输入修改后的学生体温: ");
		scanf("%lf", &stu.bodyTem);
		stu.isHealthy();	// 注意修改体温、是否咳嗽后需要重新验证健康状态
		break;
	case 2:
		printf("输入修改后的是否咳嗽 (1:是  0:否): ");
		int temp;
		scanf("%d", &temp);
		stu.hasCough = temp;
		stu.isHealthy();
		break;
	case 3:
		while (true) {
			printf("输入修改后的时间 (hh:mm): ");
			scanf("%s", buffer);
			if (!stu.time.fromString(buffer)) {
				printf("时间错误, 请重新输入!\n");
			} else {
				break;
			}
		}
		break;
	case 4:
		while (true) {
			printf("输入修改后的日期 (yyyyMMdd): ");
			scanf("%s", buffer);
			if (!stu.date.fromString(buffer) || stu.date.year < stoi(stu.id.substr(0, 4))) {
				printf("日期错误, 请重新输入!\n");
			} else {
				break;
			}
		}
		break;
	default:
		return;
	}
	printf("修改完成√\n");
}

// 删除数据
void deleteData(string stuId) {
	vector<int> stuIs = searchStudentById(stuId);	// 查询该学号对应的索引列表
	int n = stuIs.size();	// 信息条数
	int no = 0;		// 第几条信息（供用户选择）
	if (n == 0) {
		printf("该学号不存在!\n");
		return;
	} else if (n == 1) {	// 只有一条信息，无需选择
		printf("以下为该学生信息:\n学号\t\t姓名\t学院\t\t体温\t是否咳嗽\t健康状态\t时间\t\t日期\n");
		printStudentInfo(stuList[0]);
	} else {	// 存在多条信息，需要用户选择修改哪一条
		printf("以下为该学生信息:\n\t学号\t\t姓名\t学院\t\t体温\t是否咳嗽\t健康状态\t时间\t\t日期\n");
		int i = 0;
		// 将查询到的信息一一输出供用户查看
		for (auto& index : stuIs) {
			printf("%d.\t", ++i);
			printStudentInfo(stuList[index]);
		}
		while (true) {
			printf("请选择需要修改哪条信息: ");
			scanf("%d", &no);
			if (no < 1 || no > n) {
				printf("输入无效! 请重新输入.\n");
			} else {
				--no;
				break;
			}
		}
	}
	printf("确认是否删除 (1:删除  0:取消)?\n");
	int op;
	scanf("%d", &op);
	if (op == 1) {
		stuList.erase(stuList.begin() + stuIs[no]);		// 删除列表中对应项目
		printf("已删除√\n");
	}
}

// 按照不同项目和截止日期查询数据
// itemNo: 1.学号, 2.姓名
void inquireDataByItem(string item, Date date, int itemNo) {
	vector<int> stuIs;
	switch (itemNo) {
	case 1:
		stuIs = searchStudentById(item);
		break;
	case 2:
		stuIs = searchStudentByName(item);
		break;
	default:
		return;
	}
	int n = stuIs.size();
	// 没有这个学号的信息
	if (n == 0) {
		printf("无相关信息.\n");
		return;
	}
	Student& stuTemp = stuList[stuIs[0]];	// 查询到数据的第一条
	// 没有这么早的信息（信息都是按照日期排好序的，直接比较第一条就行）
	if (date < stuTemp.date) {
		printf("无相关信息.\n");
		return;
	}
	ofstream file(inquireDataFileName);
	// 基本信息（分别输出至屏幕和文件）
	printf("--------------------------------\n截至%d年%d月%d日, 该生的健康管理信息为:\n学号: %s\n姓名: %s\n学院: %s\n体温\t是否咳嗽\t健康状态\t时间\t\t日期\n", 
		date.year, date.month, date.day, stuTemp.id.c_str(), stuTemp.name.c_str(), faculties[stuTemp.fctId].c_str());
	file << "截至" << date.year << "年" << date.month << "月" << date.day 
		<< "日, 该生的健康管理信息为:\n学号: " << stuTemp.id << "\n姓名: " << stuTemp.name << "\n学院: " << faculties[stuTemp.fctId] 
		<< "\n体温\t是否咳嗽\t健康状态\t时间\t\t日期\n";
	// 逐条输出其他信息
	for (auto& index : stuIs) {
		Student& stu = stuList[index];
		if (!(stu.date > date)) {	// 在截止日期之前或当天
			printf("%.1lf\t%d\t\t%d\t\t%s\t%s\n", stu.bodyTem, stu.hasCough, stu.healthyState, stu.time.toString().c_str(), stu.date.toString().c_str());
			file << stu.bodyTem << "\t" << stu.hasCough << "\t\t" << stu.healthyState << "\t\t" << stu.time.toString() << "\t" << stu.date.toString() << "\n";
		} else {	// 超过截止日期直接退出
			break;
		}
	}
	printf("--------------------------------\n");	// 愉快的分界线
	file.flush();
	file.close();
}

// 查询数据
void inquireData() {
	printf("请选择查询方式:\n    01.按照学号查询\n    02.按照姓名查询\n");
	int item = 0;	// 查询方式
	scanf("%d", &item);
	char buf1[128] = { 0 };
	char dateBuf[9] = { 0 };
	Date date;
	switch (item) {
	case 1:
		printf("请输入学生学号: ");
		scanf("%s", buf1);
		break;
	case 2:
		printf("请输入学生姓名: ");
		scanf("%s", buf1);
		break;
	default:
		return;
	}
	while (true) {
		printf("请输入当前日期(yyyyMMdd): ");
		scanf("%s", dateBuf);
		if (!date.fromString(dateBuf)) {
			printf("日期错误, 请重新输入!\n");
		}
		else {
			break;
		}
	}
	inquireDataByItem(buf1, date, item);	// 按照用户输入的项目查询数据
}

// 异常数据统计
void unusualDataDetect() {
	ofstream file(unusualDataFileName);
	bool hasData = false;	// 是否有异常数据
	map<Date, vector<Student>> dateMap;		// 按照日期统计，相同日期的学生信息放在同一个列表里
	// 遍历找出异常数据
	for (auto& stu : stuList) {
		if (!stu.healthyState) {
			dateMap[stu.date].emplace_back(stu);
			if (!hasData) {
				hasData = true;
			}
		}
	}
	if (hasData) {	// 有异常数据，输入提示
		printf("----------------\n异常信息如下:\n学号\t\t姓名\t学院\t\t体温\t是否咳嗽\t健康状态\t时间\t\t日期\n");
		file << "异常信息如下:\n学号\t\t姓名\t学院\t\t体温\t是否咳嗽\t健康状态\t时间\t\t日期\n";
	}
	// 遍历刚刚找出的异常数据并输出
	for (auto& data : dateMap) {
		// data.first是日期，首先输出
		printf("----%d年%d月%d日----\n", data.first.year, data.first.month, data.first.day);
		file << "----" << data.first.year << "年" << data.first.month << "月"
			<< data.first.day << "日----\n";
		// data.second是学生信息列表，逐条输出
		for (auto& stu : data.second) {
			printStudentInfo(stu);
			outputStudentInfo(stu, file);
		}
	}
	file.flush();
	file.close();
	if (hasData) {
		printf("----------------\n统计完成√\n");
	} else {
		printf("无异常信息.\n");
	}
}

// 健康状况预警（出现连续三天不健康的情况）（代码重灾区）
void warningDataDetect() {
	ofstream file(warningDataFileName);
	// 算法说明：寻找列表中的若干连续区间，使用滑动窗口算法
	bool hasData = false;		// 是否有预警数据
	bool isWarning = false;		// 标记某一个学生是否出现预警
	int cnt = 0;				// 记录某个连续异常区间的天数
	Student lastStu;			// 上一条信息对应的学生信息
	Date startDate, lastDate, lastUsDate;	// 记录区间起始日期、上一条信息的日期以及上一条异常信息的日期
	vector<vector<Date>> warningDates;	// 保存出现异常的日期区间列表
	// 遍历所有信息（已排序）
	for (auto& stu : stuList) {
		// 1. 处理下一名学生之前，输出上一名学生的预警数据并重置辅助变量
		if (lastStu.id != stu.id) {
			if (isWarning) {			// 上一名学生存在预警数据
				if (!hasData) {			// 第一次出现预警数据，给出提示
					hasData = true;
					printf("----------------\n以下学生已连续三天出现身体健康状态异常:\n");
					file << "以下学生已连续三天出现身体健康状态异常:\n";
				}
				if (cnt > 0) {			// 处理上一名学生还未加入异常区间列表的数据
					warningDates.push_back({ startDate, lastDate });
				}
				printf("--------\n学号: %s\n姓名: %s\n学院: %s\n异常日期: ", lastStu.id.c_str(), lastStu.name.c_str(), faculties[lastStu.fctId].c_str());
				file << "--------\n学号: " << lastStu.id << "\n姓名: " << lastStu.name << "\n学院: " << faculties[lastStu.fctId] << "\n异常日期: ";
				// 输出各个异常日期区间
				int n = warningDates.size();
				for (int i = 0; i < n; ++i) {
					if (i) {		// 中间的数据用逗号分隔
						printf(", ");
						file << ", ";
					}
					// 起始日期
					printf("%d.%d.%d", warningDates[i][0].year, warningDates[i][0].month, warningDates[i][0].day);
					file << warningDates[i][0].year << "." << warningDates[i][0].month << "." << warningDates[i][0].day;
					if (warningDates[i][0] != warningDates[i][1]) {		// 终止日期（与起始时间不一样时才输出）
						printf("~%d.%d.%d", warningDates[i][1].year, warningDates[i][1].month, warningDates[i][1].day);
						file << "~" << warningDates[i][1].year << "." << warningDates[i][1].month << "." << warningDates[i][1].day;
					}
				}
				printf("\n");	// 换行
				file << "\n";
			}
			// 重置辅助变量，用于下一位学生的信息处理
			isWarning = false;
			warningDates.clear();
			lastStu = stu;
			cnt = 0;
		}
		// 2. 统计当前学生各个异常日期区间
		if (!stu.healthyState && stu.date != lastUsDate) {	// 遇到异常数据且非同一天的异常数据
			if (cnt == 0 || !lastDate.isAdjacent(stu.date)) {		// 新区间起始
				if (cnt > 0) {		// 上一个区间加入列表
					warningDates.push_back({ startDate, lastDate });
				}
				startDate = stu.date;	// 更新滑动窗口起始位置
				cnt = 1;	// 长度置1
			}
			else {		// 日期相邻
				++cnt;
				if (cnt >= 3) {		// 达到连续3天，该生标记为预警
					isWarning = true;
				}

			}
			lastUsDate = stu.date;
		} else if (lastDate != stu.date && cnt > 0) {		// 遇到非异常、非同一天数据，且存在未加入列表的区间
			warningDates.push_back({ startDate, lastDate });		// 写入上一个异常区间
			cnt = 0;	// 长度置0
		}
		lastDate = stu.date;
	}
	// 输出最后一位学生的预警信息（若存在）（代码与循环中的一致，此处不再重复注释）
	if (isWarning) {
		if (!hasData) {
			hasData = true;
			printf("----------------\n以下学生已连续三天出现身体健康状态异常:\n");
			file << "以下学生已连续三天出现身体健康状态异常:\n";
		}
		printf("--------\n学号: %s\n姓名: %s\n学院: %s\n异常日期: ", lastStu.id.c_str(), lastStu.name.c_str(), faculties[lastStu.fctId].c_str());
		file << "--------\n学号: " << lastStu.id << "\n姓名: " << lastStu.name << "\n学院: " << faculties[lastStu.fctId] << "\n异常日期: ";
		int n = warningDates.size();
		for (int i = 0; i < n; ++i) {
			if (i) {
				printf(", ");
				file << ", ";
			}
			printf("%d.%d.%d", warningDates[i][0].year, warningDates[i][0].month, warningDates[i][0].day);
			file << warningDates[i][0].year << "." << warningDates[i][0].month << "." << warningDates[i][0].day;
			if (warningDates[i][0] != warningDates[i][1]) {
				printf("~%d.%d.%d", warningDates[i][1].year, warningDates[i][1].month, warningDates[i][1].day);
				file << "~" << warningDates[i][1].year << "." << warningDates[i][1].month << "." << warningDates[i][1].day;
			}
		}
		printf("\n");
		file << "\n";
	}
	if (hasData) {
		printf("----------------\n");	// 愉快的分界线
		file << "--------\n";
	}
	file.flush();
	file.close();
}

int main() {
	// 初始化
	init();
	warningDataDetect();	// 检测预警数据
	// 用户界面
	int op = 0;		// 功能编号
	char stuId[10];
	while (op != -1) {
		cout << "\n----学生返校健康管理系统----\n"
			<< "|       01.添加数据        |\n"
			<< "|       02.修改数据        |\n"
			<< "|       03.删除数据        |\n"
			<< "|       04.查询数据        |\n"
			<< "|       05.异常统计        |\n"
			<< "|       -1.退出            |\n"
			<< "----------------------------\n";
		op = -2;
		scanf("%d", &op);
		system("cls");		// 使用新功能前先清屏
		switch (op) {
		case 1:
			addData();
			sort(stuList.begin(), stuList.end());	// 实时排序
			warningDataDetect();	// 实时监测
			break;
		case 2:
			printf("请输入需要修改信息的学生学号：");
			scanf("%s", stuId);
			changeData(stuId);
			sort(stuList.begin(), stuList.end());
			warningDataDetect();
			break;
		case 3:
			printf("请输入需要删除的学生学号：");
			scanf("%s", stuId);
			deleteData(stuId);
			warningDataDetect();
			break;
		case 4:
			inquireData();
			break;
		case 5:
			unusualDataDetect();	// 同时检测异常数据和预警数据
			warningDataDetect();
			break;
		default:
			break;
		}
		// while (getchar() != '\n');	// 过滤无效输入（防止输入非数字字符造成死亡鬼畜循环（可以试试注释这条语句然后输入字母？））
	}
	warningDataDetect();
	quit();
	return 0;
}