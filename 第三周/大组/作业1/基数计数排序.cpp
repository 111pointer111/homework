#include<iostream>
#include<algorithm>
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
	radixcountsort(a, n);
	

	return 0;
}