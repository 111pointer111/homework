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
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "��ʧ��";
		return 0;
	}
	int* arr;
	clock_t start, end;//��¼ʼĩʱ��
	double time_used;
	srand(time(nullptr));
	string type;
	int type1 = 0;
	cout << "������Ҫ����ʲô����(���������)��";
	cin >> type;
	cout << "\n" << "������Ҫ��ȡ����������:";
	cin >> type1;
	const int size = type1;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		if (!(ifs >> arr[i])) {
			cout << "���ݲ���";
		}
		
	}
	start = clock();
	panduan(type, arr, size);
	end = clock();
	time_used = end - start;
	cout << "\n" << "����ʱ��Ϊ��" << time_used / CLOCKS_PER_SEC << "��"<<"\n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	ifs.close();
	return 0;
}
