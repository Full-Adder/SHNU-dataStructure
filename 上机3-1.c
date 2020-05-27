/*����ͷ����βָ��ָʾ��ѭ��������*/

/*����ͷ�ļ�*/
#include <stdio.h>
#include <stdlib.h>
/*���峣��*/
#define		TRUE	1
#define		FALSE	0
#define		OK		1
#define		ERROR	0

/*����ElemType���ͺ�ʹ�õ���������������*/
typedef char QueueElementType;
/*����ѭ��������,ʹ����βָ������βָ��*/
typedef struct CLinkQueueNode
{
	QueueElementType data;     /*������*/
	struct CLinkQueueNode *next;     /*ָ����*/
}CLinkQueueNode,*CLQueue;


/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/
/*��ʼ������*/
int InitQueue(CLQueue *Q);
/*��Ӳ���*/
int EnterQueue(CLQueue *Q, QueueElementType x); 
/*���Ӳ���*/
int DeleteQueue(CLQueue *Q,QueueElementType *x);
/*����������*/
int DestroyQueue(CLQueue *Q);


/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/
/*��ʼ������*/
int InitQueue(CLQueue *Q){
	if(*Q=(CLQueue)malloc(sizeof(CLinkQueueNode))){
		(*Q)->next=*Q;
		return OK;
	}
	else{
		printf("error!\n");
		return ERROR; 
	}
	
}



/*��Ӳ���*/
int EnterQueue(CLQueue *Q, QueueElementType x){
	CLQueue s=(CLQueue)malloc(sizeof(CLinkQueueNode));
	if(s){
		s->data=x;
		s->next=(*Q)->next;
		(*Q)->next=s;
		*Q=s;
		return OK;
	}
	else{
		printf("error!/n");
		return ERROR;
	}
}



/*���Ӳ�����ע�⣺��ֻ��һ��Ԫ��ʱ����βָ��Ҳ�ᱻ�޸�*/
int DeleteQueue(CLQueue *Q,QueueElementType *x){
	CLinkQueueNode *p,*q;
	if((*Q)->next==*Q){
		return ERROR;
	}
	else{
		p=(*Q)->next;
		q=p->next;
		if(p==q->next)
			*Q=(*Q)->next;
		p->next=q->next;
		*x=q->data;
		free(q);
		return OK;
	}
}



/*����������*/
int DestroyQueue(CLQueue *Q){
	CLinkQueueNode *s,*r;
	s=(*Q)->next;
	while(s!=(*Q)){
		r=s;
		s=s->next;
		free(r);
	}
	free(s);
	return OK;
}

/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/

/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/

/*������������ͨ�����������ø������������͵Ĳ����͹��ܺ���*/

int main(){
	QueueElementType c;
	CLQueue Q;
	if(!InitQueue(&Q)){
		printf("OVERFLOW!\n");
		return 1;
	}

	while((c=getchar())!='\n')
		if(!EnterQueue(&Q,c)){
			DestroyQueue(&Q);
			return 1;
		}

	while(DeleteQueue(&Q,&c))
		putchar(c);	
	putchar('\n');
	DestroyQueue(&Q);
	return 0;

}
