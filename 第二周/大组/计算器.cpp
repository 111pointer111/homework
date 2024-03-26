#include<iostream>
using namespace std;
#include<string>
#include"stack.h"
int fs = 0;
int k = 0;
char b;
char c[100];
char c1[100];
int i = 0, k1 = 0;
linkstack l1t{ NULL, 0 };
bool compare1(char a, char b) {
	if ((a == '*' || a == '/') && (b == '+' || b == '-')) {
		return 1;
	}
	return 0;

}
double t = 0;
int n = 0;

void compare(char a, char b) {//比较运算符优先级a为输入的符号
	
	if ((a == '*' || a == '/') && (b == '+' || b == '-')) {
		pushstack(a,l1t);
		return;
	}
	else {
		while (compare1(l1t.top->a, a)) {
			popstack(c1,k1,l1t);
			if (l1t.count == 0) { break; }
		}
		
		if (l1t.count != 0) {
			popstack(c1, k1, l1t);
		}
		pushstack(a,l1t);


	}

}

int main() {
	cout << "请输入式子：";
	b=getchar();
	
	while (b != '=') {
		c[k++] = b;
		b = getchar();
	}

	for (int i = 0; i < k; i++) {
		if (c[i] <= '9' && c[i] >= '0') {
			c1[k1++] = c[i];
		}
		else {
			
			if (l1t.count==0) {
				initstack(c,i,l1t);
				continue;
			}
			if (c[i] == '(') {
				pushstack(c[i],l1t);
				
				continue;
			}
			if (c[i] == ')') {
				while (l1t.top->a != '(') {
					popstack(c1,k1,l1t);
				}
				l1t.top = l1t.top->next;
				l1t.count--;
				
				continue;
			}
			compare(c[i], l1t.top->a);

			
		}
		
	}
	
		while (l1t.count!=0) {
			popstack(c1,k1,l1t);
		}
	
	//至此完成了前缀转后缀
	
		for (int j = 0; j < k1; j++) {
			
			if (c1[j] <= '9' && c1[j] >= '0') {
				pushstack(c1[j], l1t);
			}
			else {
				calculate(l1t, c1[j],n,t);

			}
		}
		cout <<"答案是:"<< t;
	return 0;
}