#include<iostream>
#include<ctime>//��rand����
#include<cstdlib>//��time����
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
	for (int i = 0; i < size; i++) {
		ofs << arr[i] << " ";
	}
	time_used = end - start;
	cout << "\n" << "����ʱ��Ϊ��" << time_used*1.0 / CLOCKS_PER_SEC << "��";
	
	ofs.close();
	return 0;
}




