#include<iostream>
using namespace std;
int* a;


#include"paixu.h"
int main1() 
{
	int n = 0;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	insertsort(a,n);

	return 0;
}