#include<iostream>
#include<ctime>//有rand函数
#include<cstdlib>//有time函数
#include<string>
#include"paixu.h"

using namespace std;
void panduan(string type, int* arr, int n) {
	if (type == "插入排序") {
		insertsort(arr, n);
	}
	if (type == "归并排序") {
		merge_sort(arr, n);
	}
	if (type == "计数排序") {
		countsort(arr, n);
	}
	if (type == "快速排序") {
		qsort(arr, 0, n - 1);
	}
	if (type == "基数计数排序") {
		radixcountsort(arr, n);
	}

}

void text1()
{
	int* arr;
	clock_t start, end;//记录始末时间
	double time_used;
	srand(time(nullptr));
	string type;
	int k = 0;
	cout << "请输入要测试什么排序(插入排序等)：";
	cin >> type;
	cout << "\n" << "数据量为100,次数为100k，k=";
	cin >> k;
	const int size = 100;
	arr = new int[size];
	start = clock();
	for (int j = 0; j < 100*k; j++) {
		for (int i = 0; i < size; i++) {
			arr[i] = rand();
		}
		panduan(type, arr, size);
	}
	end = clock();
	time_used = end - start;
	cout << "\n" << "花费时间为：" << time_used / CLOCKS_PER_SEC << "秒";

	
}





void text2()
{
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
	time_used = end - start;
	cout << "\n" << "花费时间为：" << time_used / CLOCKS_PER_SEC << "秒";

	
}
