#include<iostream>
using namespace std;
#include"paixu.h"
int main() {
	int n = 0;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	qsort(a, 0, n - 1);
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}