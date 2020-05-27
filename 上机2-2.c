/*ɾ���������������е��ظ�Ԫ��*/

/*����ͷ�ļ�*/

#include <stdio.h>

#include <stdlib.h>

#define TRUE 1

#define FALSE 0

#define OK 1

#define ERROR 0

#define MAXSIZE 100



/*����ElemType���ͺ�ʹ�õ���������������*/

typedef char ElemType;



typedef struct Node    /* ������Ͷ��� */

{ ElemType data;

  struct Node  *next;

}Node, *LinkList;



/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/

/*β�巨����������*/

LinkList  CreateFromTail();

/*��ӡ����*/

void LListPrint(LinkList L);

/*ɾ���������������е��ظ�Ԫ��*/

void  LListDelElem(LinkList L);

/*���ٵ�����*/

void ListDestroy(LinkList L);





/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/

/*β�巨����������*/

LinkList  CreateFromTail(){
	Node *L,*s,*r;
	char c;
	L=(Node*)malloc(sizeof(Node));			//	ͷ��� 
	L->next=NULL;
	r=L;
	while((c=getchar())!='\n'){
		s=(Node*)malloc(sizeof(Node));		//s���½ڵ� 
		s->data=c;							//rָ��ǰ����ĩβ��� 
		r->next=s;							//�����½ڵ� 
		r=s;								//rָ���µ�ĩβ��� 
	}
	r->next=NULL;
	return L;
}



/*��ӡ����*/

void LListPrint(LinkList L){
	Node *p=L->next;
	while(p->next!=NULL){
		printf("%c",p->data);
		p=p->next;
	}
	printf("%c\n",p->data);
}





/*ɾ���������������е��ظ�Ԫ��*/

void  LListDelElem(LinkList L){
	Node *p=L->next,*q=p->next;		//p��ǰָ�룬q�Ǻ�ָ�� 
	while(q->next!=NULL){
		if(p->data==q->data){		//������һ�� 
			p->next=q->next;		//ǰ���ָ���ظ�Ԫ�صĺ�һ���ڵ� (ɾ���ظ����) 
			free(q);
			q=p->next;				//��ָ��ָ����һ����� 
		}
		else {						//�����ظ� 
			p=p->next;				//ǰ��ָ��ֱ�����ƶ�һλ 
			q=q->next;
		}	
	}
	if(p->data==q->data){			//�����һ�����ֵ�ظ� 
			free(q);				
			p->next=NULL;			// ǰָ��nextΪ�� 
	}
}



/*���ٵ�����*/

void ListDestroy(LinkList L){
	Node *p=L,*q=p->next;
	while(q!=NULL){
		free(p);
		p=q;
		q=q->next;
	} 
	free(p);
	printf("������\n");
}



/*������������ͨ�����������ø������������͵Ĳ����͹��ܺ���*/



int main(){

LinkList a;

a=CreateFromTail();

LListPrint(a);

LListDelElem(a);

LListPrint(a);

ListDestroy(a);

return 0;

}
