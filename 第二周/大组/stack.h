#pragma once
#include<iostream>
#include<string>
using namespace std;
typedef struct stacknode {
	char a;
	double x;
	struct stacknode* next;
}stacknode, * stackptr;
typedef struct linkstack {
	stackptr top;//ջ��ָ��
	int count;//Ԫ�ظ���
}linkstack;



void initstack(char* c, int i,linkstack& l1t);
void pushstack(char a, linkstack& l1t);
void popstack(char* c1, int& k1, linkstack& l1t);
void calculate(linkstack& l1t, char a,int& n,double& t);