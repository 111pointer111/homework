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
	ofstream ofs;
	ofs.open("text.txt", ios::out);
	int* arr;
	clock_t start, end;//记录始末时间
	double time_used;
	srand(time(nullptr));
	string type;
	int type1 = 0;
	cout << "请输入要测试什么排序(插入排序等)：";
	cin >> type;
	cout << "\n" << "请输入有多少数据量:";
	cin >> type1;
	const int size = type1;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand();
	}
	start = clock();
	panduan(type, arr, size);
	end = clock();
	for (int i = 0; i < size; i++) {
		ofs << arr[i] << " ";
	}
	time_used = end - start;
	cout << "\n" << "花费时间为：" << time_used*1.0 / CLOCKS_PER_SEC << "秒";
	
	ofs.close();
	return 0;
}




