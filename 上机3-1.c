/*带有头结点的尾指针指示的循环链队列*/

/*包含头文件*/
#include <stdio.h>
#include <stdlib.h>
/*定义常量*/
#define		TRUE	1
#define		FALSE	0
#define		OK		1
#define		ERROR	0

/*定义ElemType类型和使用到的物理数据类型*/
typedef char QueueElementType;
/*定义循环链队列,使用链尾指针代表队尾指针*/
typedef struct CLinkQueueNode
{
	QueueElementType data;     /*数据域*/
	struct CLinkQueueNode *next;     /*指针域*/
}CLinkQueueNode,*CLQueue;


/*声明物理数据类型的操作（函数）和使用到的其他功能函数*/
/*初始化队列*/
int InitQueue(CLQueue *Q);
/*入队操作*/
int EnterQueue(CLQueue *Q, QueueElementType x); 
/*出队操作*/
int DeleteQueue(CLQueue *Q,QueueElementType *x);
/*销毁链队列*/
int DestroyQueue(CLQueue *Q);


/*定义物理数据类型的操作（函数）和使用到的其他功能函数*/
/*初始化操作*/
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



/*入队操作*/
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



/*出队操作，注意：当只有一个元素时，队尾指针也会被修改*/
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



/*销毁链队列*/
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

/*声明物理数据类型的操作（函数）和使用到的其他功能函数*/

/*定义物理数据类型的操作（函数）和使用到的其他功能函数*/

/*定义主函数，通过主函数调用各物理数据类型的操作和功能函数*/

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
