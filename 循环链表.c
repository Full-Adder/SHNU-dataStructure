//假设有一个循环链表的长度大于1，且表中既无头结点也无头指针。
//已知s为指向链表某个结点的指针，试编写算法在链表中删除指针s所指结点的前驱结点.
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


int DelPrior(Node *s){					//删除s的前驱结点 
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
	printf("尾插法建循环链表,输入999结束\n");
	CLinkList L;
	Node *p,*r;
	int c;
	L=(Node*)malloc(sizeof(Node));					//L指向头节点 
	r=L;
	scanf("%d",&c);
	while(c!=999){
		p=(Node*)malloc(sizeof(Node));
		p->data=c;
		r->next=p;
		r=p; 
		scanf("%d",&c);
	}
	r->next=L->next;								//最后一个结点的next指向第一个结点（不是头节点） 
	free(L);										//释放头节点 
	return r->next;									//返回指向第一个结点的指针 
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
	printf("删除第3个结点的前驱\n");			 
	DelPrior(p);				
	PrintfCLinkList(p); 
	PrintfCLinkList(p); 
}
