#include<stdio.h>
#include<stdlib.h>
#include "second.h"
struct list{
	int num;            //num�ǽڵ�����
	struct list* next;

};
struct dlist{
	int num;
	struct dlist* next;
	struct dlist* before;
};
struct list* creat(struct list* head,int x) //��������Ĵ���
{    //x������ڵ����
	struct list* head1 = head;//����ͷ����ָ��
	head->num = 1;
	for (int i = 1; i < x; i++) {
		struct list* term = (struct list*)malloc(sizeof(struct list));
		term->num = i + 1;
		head->next = term;
		head = head->next;
	}
	head->next = NULL;
	return head1;
}
void shownum(struct list* head) //���ӻ����ݺ��ж��Ƿ�Ϊѭ������
{
	printf("\n");
	struct list* head1 = head;
	while (1) {
		if (head->next == NULL) {
			printf("%d ", head->num);
			printf("\n���������");
			break;
		}
		if (head->next == head1) {
			printf("%d ", head->num);
			printf("\nѭ���������");
			break;
		}
		printf("%d ", head->num);
		head = head->next;
	}
	return;
}
struct dlist* dcreat(struct dlist* dhead,int x) //˫������Ĵ���
{
	//x��˫������ڵ����
	struct dlist* dhead1 = dhead,*dhead2=dhead;//����ͷ����ָ��
	dhead->num = 1;
	for (int i = 1; i < x; i++) {
		struct dlist* term = (struct dlist*)malloc(sizeof(struct dlist));
		term->num = i + 1;
		dhead->next = term;
		dhead = dhead->next;
	}
	dhead->next = NULL;
	dhead->before = NULL;
	for (dhead2; dhead2->next != NULL; dhead2 = dhead2->next) {
		dhead2->next->before = dhead2;


	}
	
	return dhead1;
}
struct list* headbefore;
struct list* exchange(struct list* head) {//ʵ����ż��������
	struct list* first;
	if (head->next != NULL) {
		first = head->next;
	}
	else return head;
	int j = 1;
	for (head; head->next != NULL; head = head->next) {
		if (1) {
			struct list* head1 = head->next, * head2 = head->next->next;	
			head1->next = head;
			head->next = head2;
			if (j > 1) {
				headbefore->next = head1;
			}
			headbefore = head;
			
		}
		if (head->next == NULL) {
			break;
		}
		j++;
	}
	return first;
}
struct list* midpoint(struct list* head) {
	struct list* head1 = head;
	int j = 1;
	for (head; head->next != NULL; head = head->next) j++;
	int a = (j + 1) / 2;
	
	for (int i = 1; i < a; i++) {
		head1 = head1->next;
	}
	
	return head1;
}
struct list* reverse(struct list* head) {
	
	if (head->next != NULL) {
		struct list* head1 = head->next, * head2 = head1->next;
		head->next = NULL;
		while (head1 != NULL) {
			head1->next = head;
			head = head1;
			head1 = head2;
			if (head2 != NULL) {
				head2 = head2->next;
			}
		}
	}
	return head;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	struct list* head=(struct list*)malloc(sizeof(struct list)) ;
	head=creat(head, n);
	
	shownum(head);
	head=exchange(head);
	
	shownum(head);
	
	printf("%d", midpoint(head)->num);
	head = reverse(head);
	shownum(head);
	return 0;
}


