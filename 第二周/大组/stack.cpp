#include"stack.h"

 void initstack(char*c,int i, linkstack& l1t) {
	 
	 stackptr top1 = new stacknode;
	 top1->a = c[i];
	 top1->x = 0;
	 top1->next = NULL;
	 l1t.top = top1;
	 l1t.count++;

 }
 void pushstack(char a, linkstack& l1t) {
	 stackptr top1 = new stacknode;
	 top1->x = 0;
	 top1->a = a;
	 top1->next = l1t.top;
	 l1t.top = top1;
	 l1t.count++;
	 return;
 }
 void popstack(char*c1,int& k1, linkstack& l1t) {
	 if (l1t.top->a != '(') {
		 c1[k1++] = l1t.top->a;
		 stackptr term = l1t.top;
		 l1t.top = l1t.top->next;
		 delete term;
		 l1t.count--;
	 }
 }

 void calculate(linkstack& l1t, char a,int& n,double& t) {
	 if (n == 0) {
		 double x = l1t.top->a - '0';
		 l1t.top = l1t.top->next;
		 double y = l1t.top->a - '0';
		 if (a == '*') {
			 t = x * y;
		 }
		 if (a == '/') {
			 t = y * 1.0 / x;
		 }
		 if (a == '+') {
			 t = x + y;
		 }
		 if (a == '-') {
			 t = y - x;
		 }
		 l1t.top->x = t;
		 n++;
	 }
	 else {
		 double x = 0, y = 0;
		 if (l1t.top->x != 0) {
			 x = l1t.top->x;
			 l1t.top = l1t.top->next;
		 }
		 else {
			 x = l1t.top->a - '0';
			 l1t.top = l1t.top->next;
		 }
		 if (l1t.top->x != 0) {
			 y = l1t.top->x;
		 }
		 else {
			 y = l1t.top->a - '0';
		 }

		 if (a == '*') {
			 t = x * y;
		 }
		 if (a == '/') {
			 t = y * 1.0 / x;
		 }
		 if (a == '+') {
			 t = x + y;
		 }
		 if (a == '-') {
			 t = y - x;
		 }
		 l1t.top->x = t;
	 }
	 return;

 }