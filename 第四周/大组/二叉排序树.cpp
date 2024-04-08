#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<queue>
#include<stack>
using namespace std;
typedef struct tree {
	int date;
	struct tree* lt;
	struct tree* rt;

}tree, * ptree;
char MenuText[][30] = {
"[A] Menu1(��������)",
"[B] Menu2(��ѯ����)",
"[Q] Menu3(ɾ������)",
"[W] Exit(�˳�)"
};
ptree treefind(ptree t1, int date);
void insert(ptree& tptr, int date) {
	if (treefind(tptr, date)) {
		cout << "���д�����" << "\n";
		return;
	}
	if (tptr == NULL) {
		tptr = new tree;
		tptr->lt = NULL;
		tptr->rt = NULL;
		tptr->date = date;
	}
	else
	{
		if (date >= tptr->date) {
			if (tptr->rt == NULL)
			{
				ptree t = new tree;
				t->lt = NULL;
				t->rt = NULL;
				t->date = date;
				tptr->rt = t;
			}
			else insert(tptr->rt, date);
		}
		if (date < tptr->date) {
			if (tptr->lt == NULL)
			{
				ptree t = new tree;
				t->lt = NULL;
				t->rt = NULL;
				t->date = date;
				tptr->lt = t;
			}
			else insert(tptr->lt, date);
		}
	}
}
void visit(ptree pt) {							//�鿴����
	cout << pt->date << " ";
}
void Inordertraverse(ptree pt) {				//�������
	if (pt == NULL) return;
	Inordertraverse(pt->lt);
	visit(pt);
	Inordertraverse(pt->rt);
}
void preordertraverse(ptree pt) {				//ǰ�����
	if (pt == NULL) return;
	visit(pt);
	preordertraverse(pt->lt);
	preordertraverse(pt->rt);
}
void postordertraverse(ptree pt) {				//�������
	if (pt == NULL) return;
	postordertraverse(pt->lt);
	postordertraverse(pt->rt);
	visit(pt);
}

void levelordertraverse(ptree pt) {				//�������
	queue<ptree> p;
	p.push(pt);
	while (!p.empty()) {
		visit(p.front());
		if (p.front()->lt != NULL) {
			p.push(p.front()->lt);
		}
		if (p.front()->rt != NULL) {
			p.push(p.front()->rt);
		}
		p.pop();
	}


}
void fiepre(ptree pt) {							//�ǵݹ�ǰ��
	stack<ptree>p;
	p.push(pt);
	while (!p.empty()) {
		if (p.top()->rt != NULL) {
			p.push(p.top()->rt);
		}
		if (p.top()->lt != NULL) {
			p.push(p.top()->lt);
		}
		p.pop();

	}
}
void fiein(ptree pt) {
	if (pt == NULL)return;
	stack<ptree>p;
	p.push(pt);
	while (pt->lt != NULL) {
		fiein(pt->lt);
	}
	visit(pt);
	p.pop();
	if (p.top()->rt != NULL) {
		p.push(p.top()->rt);
		fiein(p.top());
		visit(p.top());
		p.pop();
	}
}
void feipost(ptree pt) {
	if (pt == NULL)
		return;

	stack<ptree> stk;
	ptree prev = NULL;
	while (pt != NULL || !stk.empty()) {
		while (pt != NULL) {
			stk.push(pt);
			pt = pt->lt;
		}
		pt = stk.top();
		if (pt->rt == NULL || pt->rt == prev) {
			visit(pt);
			stk.pop();
			prev = pt;
			pt = NULL;
		}
		else {
			pt = pt->rt;
		}

	}



}
ptree treefind(ptree t1, int date) {			//�����Ƿ��������
	static int a = 0;
	ptree pt = new tree;
	if (t1 == NULL) {
		return NULL;
	}
	if (t1->date == date) {
		a = 1;
		return t1;
	}
	else {
		if (date >= t1->date) {
			return pt = treefind(t1->rt, date);
		}
		if (date < t1->date) {
			return pt = treefind(t1->lt, date);
		}
	}
	return NULL;
}
ptree searchf(ptree t1) {							//����ֱ��ǰ��Ԫ�صĵ�ַ
	if (t1->lt == NULL) {
		cout << "��ǰ��Ԫ��" << "\n";
	}
	else {
		t1 = t1->lt;
		while (t1->rt != NULL) {
			t1 = t1->rt;
		}

	}
	return t1;
}
ptree deleted(ptree t1, int date) {				//ɾ������
	if (t1 == NULL) return NULL;
	if (date > t1->date) {
		t1->rt = deleted(t1->rt, date);
	}
	else {
		if (date < t1->date) {
			t1->lt = deleted(t1->lt, date);
		}
		else {
			if (t1->lt != NULL && t1->rt == NULL) {
				return t1->lt;
			}
			if (t1->lt == NULL && t1->rt != NULL) {
				return t1->rt;
			}
			if (t1->lt == NULL && t1->rt == NULL) {
				return NULL;
			}
			if (t1->lt != NULL && t1->rt != NULL) {
				int x = searchf(t1)->date;
				t1->date = x;
				t1->lt = deleted(t1->lt, x);
				return t1;
			}


		}
	}
	return t1;
}
void displaymenu(int hilight) {						//��ʼ���˵�
	int i;
	printf("\n==========�˵�==========\n");
	for (i = 0; i < 4; i++) {
		if (i == hilight - 1)printf("<<%s>>\n", MenuText[i]);
		else printf(" %s\n", MenuText[i]);
	}
	printf("==========�˵�==========\n");
}
int main()
{
	int sel = 1;
	int y = 0;
	char c;
	int n = 0;
	int g = 0;
	ptree t1 = NULL;
	displaymenu(1);
	for (;;) {
		if (_kbhit()) {
			//�ж��Ƿ��а������
			if (GetAsyncKeyState(VK_UP)) { //�ж��Ƿ�<��>�������
				sel = (sel > 1) ? sel - 1 : sel;
				system("cls");//����
				displaymenu(sel); //��ʾ�˵�
			}
			if (GetAsyncKeyState(VK_DOWN)) {//�ж��Ƿ�<��>�������
				sel = (sel < 4) ? sel + 1 : sel;
				system("cls");
				displaymenu(sel);
			}
			c = _getch();
			Sleep(200);
			if (c == '\r') {
				system("cls");
				switch (sel)
				{
				case 1:
					cout << "������Ҫ���뼸λ����";

					cin >> n;
					cout << "��Ҫ��������У�";
					for (int i = 0; i < n; i++) {
						int x = 0;
						cin >> x;
						insert(t1, x);

					}
					cout << "\n" << "ok";
					break;
				case 2:

					cout << "�����������ʽ��ǰ����1����2����3����4����";
					cin >> y;
					if (y == 1) preordertraverse(t1);
					if (y == 2) Inordertraverse(t1);
					if (y == 3) postordertraverse(t1);
					if (y == 4) levelordertraverse(t1);
					while (1) {
						if (_kbhit()) {
							c = _getch();
							if (c == '\r') {
								break;
							}
						}
					}
					break;
				case 3:
					cout << "������Ҫɾ��������";
					cin >> g;
					t1 = deleted(t1, g);
					cout << "ok";
					Sleep(500);
					break;
				case 4:
					return 0;
				}
				system("cls");
				displaymenu(sel);

			}
		}
	}





}