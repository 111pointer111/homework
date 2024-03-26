#include<iostream>
#include<string>
using namespace std;
typedef struct qnode {
	void* a;
	const void* b;
	int x;
	struct qnode* next;

}qnode,*queueptr;
typedef struct qline {
	queueptr head;
	queueptr tail;

}*linkqueue;

linkqueue initqueue() {
	queueptr p = new qnode;
	p->next = NULL;
	linkqueue q = new struct qline;
	q->head = NULL;
	q->tail = NULL;
	return q;
}
linkqueue q = initqueue();
string type;

void destroyqueue(qline& q) {
	while (q.head != NULL) {
		queueptr t= q.head;
		q.head = q.head->next;
		delete t;
	}
}
void push(qline& q, void* a, int x,const void*b);
void pop(qline& q) {
	if (q.head == NULL) {
		return;
	}
	queueptr temp = new qnode;
	temp = q.head;
	q.head = q.head->next;
	delete temp;
}

void showq(qline& q) {
	static int count = 1;
	while (q.head != NULL) {
		int x = q.head->x;
		switch (x) {
		case 0: {
			int* t_a = new int;
			t_a = (int*)q.head->a;
			cout << "第" << count << "个数据是" << *t_a << "\n";
			count++;
			break;
		}
		case 1: {
			double* t_a = new double;
			t_a = (double*)q.head->a;
			cout << "第" << count << "个数据是" << *t_a << "\n";
			count++;
			break;
		}
		case 2: {
			const char* t_a = (const char*)q.head->b;
			
			cout << "第" << count << "个数据是";
			for (int j = 0; *(t_a + j) != '\0'; j++) {
				cout << *(t_a+j);
			}
			cout << "\n";
			break;
		}
		case 3: {
			char* t_a = new char;
			t_a = (char*)q.head->a;
			cout << "第" << count << "个数据是" << *t_a << "\n";
			count++;
			break;
		}

		}
		
		q.head = q.head->next;
	}
}
int pdtype(string type) {
	if (type == "int") {
		return 0;
	}
	if (type == "double")
	{
		return 1;
	}
	if (type == "string") {
		return 2;
	}
	if (type == "char") {
		return 3;
	}
	if (type == "over") {
		return 4;
	}
	return 5;
}
int main()
{
	int k = 1;
	while (k==1) {
		cout << "输入队列的类型是(可选择string，int，char，double,如果输入over则显示当前队列上的所有数据)：";
		cin >> type;
		int x=0;
		x = pdtype(type);
		switch (x) {
		case 0: {
			int* s=new int;
			cout << "好的，请输入：";
			cin >> *s;
			push(*q, (int*)s,x,NULL);
			break;
		}
		case 1: {
			double* s1=new double;
			cout << "好的，请输入：";
			cin >> *s1;
			push(*q,(double*)s1, x, NULL);
			break;
		}
		case 2: {
			char* s2 = new char[100];
			  cout << "好的，请输入：";
			  scanf("%s", s2);
			  push(*q, NULL, x, (const char*)s2);
			  break;
		}
		case 3: {
			char* s3=new char;
			cout << "好的，请输入：";
			cin >> *s3;
			push(*q, (char*)s3, x,NULL);
			break;
		}
		case 4: {
			k++;
			showq(*q);
			break;
		}


		}
	}

}
void push(qline& q, void* a, int x,const void*b) {
	queueptr temp = new qnode;
	switch (x) {
	case 0: {
		temp->a = (int*)a;

		break;
	}
	case 1: {
		temp->a = (double*)a;

		break;
	}
	case 2: {
		temp->b = (const char*)b;

		break;
	}
	case 3: {
		temp->a = (char*)a;

		break;
	}

	}

	temp->x = x;
	if (q.head == NULL) {
		q.head = temp;
		q.tail = temp;
		q.head->next = NULL;
		return;
	}
	q.tail->next = temp;
	q.tail = temp;
	q.tail->next = NULL;
}