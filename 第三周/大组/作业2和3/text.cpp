#include<iostream>
#include<ctime>//��rand����
#include<cstdlib>//��time����
#include<string>
#include"paixu.h"

using namespace std;
void panduan(string type, int* arr, int n) {
	if (type == "��������") {
		insertsort(arr, n);
	}
	if (type == "�鲢����") {
		merge_sort(arr, n);
	}
	if (type == "��������") {
		countsort(arr, n);
	}
	if (type == "��������") {
		qsort(arr, 0, n - 1);
	}
	if (type == "������������") {
		radixcountsort(arr, n);
	}

}

void text1()
{
	int* arr;
	clock_t start, end;//��¼ʼĩʱ��
	double time_used;
	srand(time(nullptr));
	string type;
	int k = 0;
	cout << "������Ҫ����ʲô����(���������)��";
	cin >> type;
	cout << "\n" << "������Ϊ100,����Ϊ100k��k=";
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
	cout << "\n" << "����ʱ��Ϊ��" << time_used / CLOCKS_PER_SEC << "��";

	
}





void text2()
{
	int* arr;
	clock_t start, end;//��¼ʼĩʱ��
	double time_used;
	srand(time(nullptr));
	string type;
	int type1 = 0;
	cout << "������Ҫ����ʲô����(���������)��";
	cin >> type;
	cout << "\n" << "�������ж���������:";
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
	cout << "\n" << "����ʱ��Ϊ��" << time_used / CLOCKS_PER_SEC << "��";

	
}
