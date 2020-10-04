//12. 要求循环队列不损失一个空间全部都能得到利用，设置一个标志量tag，
//以tag为0或1来区分头尾指针相同时的队列状态，请编写与此结构相应的入队与出队算法。
//循环队列的类型声明与函数原型如下所示
#define  QueueElementType int
#define MAXSIZE 5
#define ERROR	0
#define OK		1

#include<stdio.h>

typedef struct SeqQueue{
	QueueElementType  element[MAXSIZE];  /* 队列的元素空间*/
	int front;  /*头指针指示器*/
	int rear;  /*尾指针指示器*/
	int tag;/*结合front和rear表示当前栈空或满*/
	/*front==rear &&tag==1表示满，front==rear &&tag==0表示空*/
}SeqQueue;

//初始化
void InitQueue(SeqQueue *Q){
	Q->front=Q->rear=Q->tag=0;
} 

/*入队操作*/
int EnterQueue(SeqQueue *Q, QueueElementType x){
	  if(Q->front==Q->rear&&Q->tag==1){
	  	printf("表满，无法入队\n");
	  	return ERROR;
	  }
	  else{
	  	Q->element[Q->rear]=x;
	  	Q->rear=(Q->rear+1)%MAXSIZE;
	  	if(Q->rear==Q->front)
	  		Q->tag=1;
	  	return OK;
	  }
}

/*出队操作*/ 
int DeleteQueue(SeqQueue *Q, QueueElementType *x){
	if(Q->front==Q->rear&&Q->tag==0){
		printf("空表，无法出队\n");
		return ERROR; 
	}
	else{
		*x=Q->element[Q->front];
		Q->front=(Q->front+1)%MAXSIZE;
		if(Q->front==Q->rear)
			Q->tag=0;
		return OK;
	}
}

void PrintSeq(SeqQueue Q){
	int i;
	for(i=0;i<MAXSIZE;i++){
			printf("%d\t",Q.element[i]);
		}
		putchar('\n');
}

int main(){
	int i;
	SeqQueue a;
	QueueElementType x;
	InitQueue(&a);
	scanf("%d",&x);
	while(x!=999){
		if(x>0){
			EnterQueue(&a,x);
		}
		else{
			if(DeleteQueue(&a,&x))
			printf("删除%d\n",x);
		}
		PrintSeq(a);
		scanf("%d",&x);
	}
} 
