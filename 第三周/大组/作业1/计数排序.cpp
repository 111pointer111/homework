#include<iostream>
#include<stdlib.h>
using namespace std;
#include"paixu.h"
int main()
{
	int n = 0;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	countsort(a, n);
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}