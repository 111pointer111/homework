#include<iostream>
#include<ctime>//有rand函数
#include<cstdlib>//有time函数
#include<string>
#include"paixu.h"
#include<fstream>
using namespace std;
#include"text.h";

int main()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "打开失败";
		return 0;
	}
	int* arr;
	clock_t start, end;//记录始末时间
	double time_used;
	srand(time(nullptr));
	string type;
	int type1 = 0;
	cout << "请输入要测试什么排序(插入排序等)：";
	cin >> type;
	cout << "\n" << "请输入要读取多少数据量:";
	cin >> type1;
	const int size = type1;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		if (!(ifs >> arr[i])) {
			cout << "数据不够";
		}
		
	}
	start = clock();
	panduan(type, arr, size);
	end = clock();
	time_used = end - start;
	cout << "\n" << "花费时间为：" << time_used / CLOCKS_PER_SEC << "秒"<<"\n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	ifs.close();
	return 0;
}
