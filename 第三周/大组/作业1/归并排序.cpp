#include<iostream>
using namespace std;
#include"paixu.h"
int main12() {

	int n = 0;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	merge_sort(a, n);
	



	return 0;
}