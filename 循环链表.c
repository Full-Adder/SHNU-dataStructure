//������һ��ѭ������ĳ��ȴ���1���ұ��м���ͷ���Ҳ��ͷָ�롣
//��֪sΪָ������ĳ������ָ�룬�Ա�д�㷨��������ɾ��ָ��s��ָ����ǰ�����.
#include<stdio.h>
#include<stdlib.h>
typedef int Element; 

typedef struct Node{
	Element data;
	struct Node *next;
}Node,*CLinkList;

int DelPrior(Node *s);
CLinkList CreateCLinkList();
int PrintfCLinkList(CLinkList L);


int DelPrior(Node *s){					//ɾ��s��ǰ����� 
	if(s->next==NULL) return 0;
	Node *p=s,*q;
	while(p->next->next!=s){
		p=p->next;
	}
	q=p->next;
	p->next=s;
	free(q);
	return 1;
}

CLinkList CreateCLinkList(){
	printf("β�巨��ѭ������,����999����\n");
	CLinkList L;
	Node *p,*r;
	int c;
	L=(Node*)malloc(sizeof(Node));					//Lָ��ͷ�ڵ� 
	r=L;
	scanf("%d",&c);
	while(c!=999){
		p=(Node*)malloc(sizeof(Node));
		p->data=c;
		r->next=p;
		r=p; 
		scanf("%d",&c);
	}
	r->next=L->next;								//���һ������nextָ���һ����㣨����ͷ�ڵ㣩 
	free(L);										//�ͷ�ͷ�ڵ� 
	return r->next;									//����ָ���һ������ָ�� 
}

int PrintfCLinkList(CLinkList L){
	Node *b=L;
	while(b->next!=L){
		printf("%d ",b->data);
		b=b->next;
	}
	printf("%d\n",b->data);
	return 1; 
}

int main(){
	CLinkList a;	
	Node *p;	 
	a=CreateCLinkList();
	PrintfCLinkList(a); 
	p=a->next->next;
	printf("ɾ����3������ǰ��\n");			 
	DelPrior(p);				
	PrintfCLinkList(p); 
	PrintfCLinkList(p); 
}
