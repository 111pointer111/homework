#include<iostream>
using namespace std;
#include"text.h"
int main()
{
	int x = 0;
	cout << "请输入要演示测试1还是2：";
	cin >> x;
	if (x == 1) {
		text2();
	}
	else text1();

	return 0;
}