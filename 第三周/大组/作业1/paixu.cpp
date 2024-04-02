#include<iostream>
using namespace std;
void insertsort(int* a, int n) {

	for (int j = 1; j < n; j++) {
		int k = j;
		while (k != 0 && a[k] < a[k - 1]) {
			int t = a[k];
			a[k] = a[k - 1];
			a[k - 1] = t;
			k--;
		}

	}

}



void countsort1(int** ar, int n) {
	int max = ar[0][1];
	for (int i = 1; i < n; i++) {
		if (ar[i][1] > max) {
			max = ar[i][1];
		}
	}
	int* count1 = new int[max + 1];
	int* count = new int[max + 1];

	memset(count, 0, sizeof(int) * (max + 1));
	for (int i = 0; i < n; i++) {
		count[ar[i][1]]++;
	}
	for (int i = 0; i < max + 1; i++) {//记录一个一样的计数数组
		count1[i] = count[i];
	}
	for (int i = 1; i < max + 1; i++) {
		count[i] += count[i - 1];
	}
	int* out = new int[n];

	for (int j = 0; j < n; j++) {
		out[count[ar[j][1]] - count1[ar[j][1]]] = ar[j][0];
		count1[ar[j][1]]--;
	}

	for (int i = 0; i < n; i++) {
		ar[i][0] = out[i];

	}


}
void radixcountsort(int arr[], int n) {
	int** radix = new int* [n];
	for (int i = 0; i < n; i++) {
		*(radix + i) = new int[2];
	}
	for (int i = 0; i < n; i++) {
		radix[i][0] = 0;
		radix[i][1] = 0;
	}
	int max1 = arr[0];	//用来计算最高有几位
	for (int i = 1; i < n; i++) {
		if (arr[i] > max1) {
			max1 = arr[i];
		}
	}
	int cn = 0;			//用来计算最高有几位
	while (max1 != 0) {
		max1 /= 10;
		cn++;
	}
	for (int i = 0; i < n; i++) {
		radix[i][0] = arr[i];
	}
	for (int j = 0; j < cn; j++) {
		for (int i = 0; i < n; i++) {

			if (radix[i][0] / (int)pow(10, j) == 0) { radix[i][1] = 0; }
			else radix[i][1] = (radix[i][0] % ((int)pow(10, j + 1)) - radix[i][0] % (int)pow(10, j)) / (int)pow(10, j);

		}
		countsort1(radix, n);
	}
	for (int i = 0; i < n; i++) {
		arr[i] = radix[i][0];
	}
	
	

}


void countsort(int arr[], int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	int* count = new int[max + 1];
	memset(count, 0, sizeof(int) * (max + 1));
	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}
	for (int i = 1; i < max + 1; i++) {
		count[i] += count[i - 1];
	}
	int* out = new int[n];

	for (int j = 0; j < n; j++) {
		out[count[arr[j]] - 1] = arr[j];
		count[arr[j]]--;
	}
	for (int i = 0; i < n; i++) {
		arr[i] = out[i];
	}

	


}

void  qsort(int arr[], int low, int high) {
	if (low < high) {
		int i = low;
		for (int j = low; j < high; j++) {
			if (arr[j] < arr[high]) {
				int t = arr[j];
				arr[j] = arr[i];
				arr[i++] = t;
			}
		}
		int t = arr[high];
		arr[high] = arr[i];
		arr[i] = t;
		qsort(arr, low, i - 1);
		qsort(arr, i + 1, high);
	}
	
}


	void merge(int arr[], int temparr[], int left, int mid, int right) {

		int lpos = left;
		int y = left;
		int rpos = mid + 1;
		while (lpos <= mid && rpos <= right) {
			if (arr[lpos] <= arr[rpos]) {
				temparr[y++] = arr[lpos++];
			}
			else temparr[y++] = arr[rpos++];

		}
		while (lpos <= mid) {
			temparr[y++] = arr[lpos++];
		}
		while (rpos <= right) {
			temparr[y++] = arr[rpos++];
		}
		while (left <= right) {
			arr[left] = temparr[left];
			left++;
		}
	}
	void msort(int arr[], int temparr[], int left, int right) {
		if (left < right) {
			int mid = (right + left) / 2;
			msort(arr, temparr, left, mid);//左半侧的分化
			msort(arr, temparr, mid + 1, right);//右半侧的分化
			merge(arr, temparr, left, mid, right);

		}
	}
	void merge_sort(int arr[], int n) {
		int left = 0;
		int right = n - 1;
		int* temparr = new int[n];
		for (int i = 0; i < n; i++) {
			temparr[i] = 0;
		}
		msort(arr, temparr, left, right);
		cout << "\n";
		
	}