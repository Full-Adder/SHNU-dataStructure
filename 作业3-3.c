//一般性回文判断。称正读与反读都相同的字符序列为“回文”序列。
//试写一算法，判断依次读入的一个字符序列，是否为形如“序列1序列2”模式的字符序列。
//其中序列2是序列1的逆序列。例如“a+bb+a”是属于该模式的字符序列，而“1+33-1”则不是。
//（提示：同时使用栈和队列实现）函数原型如下所示

/*序列从终端读入*/
#define ElementType char
#define MAXSIZE 30
#define NO		0
#define YES		1
#define ERROR	0
#define OK		1
#include<stdio.h>

typedef struct{
	ElementType elem[MAXSIZE];
	int top;
}SeqStack;

typedef struct {
	ElementType  element[MAXSIZE];  /* 队列的元素空间*/
	int front;  /*头指针指示器*/
	int rear;  /*尾指针指示器*/
	int tag;/*结合front和rear表示当前栈空或满*/
	/*front==rear &&tag==1表示满，front==rear &&tag==0表示空*/
}SeqQueue;

void InitStack(SeqStack *S){
	S->top=-1;
}

void InitQueue(SeqQueue *Q){
	Q->front=Q->rear=Q->tag=0;
} 

int Push(SeqStack *S,ElementType x){
	if(S->top==MAXSIZE-1)
		return ERROR;
	else{
		S->top++;
		S->elem[S->top]=x;
		return OK;
	}
}

int Pop(SeqStack *S,ElementType *x){
	if(S->top==-1)
		return ERROR;
	else{
		*x=S->elem[S->top];
		S->top--;
		return OK;
	}
}

/*入队操作*/
int EnterQueue(SeqQueue *Q,ElementType x){
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
int DeleteQueue(SeqQueue *Q,ElementType *x){
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


int Palindrome_Test(){
	int i;
	SeqQueue a;
	SeqStack b;
	InitQueue(&a);
	InitStack(&b);
	char p,q,r=getchar();
	while(r!='\n'){
		EnterQueue(&a,r);
		Push(&b,r);
		r=getchar();
	}
	for(i=0;i<=b.top+1;i++){
		DeleteQueue(&a,&p);
		Pop(&b,&q);
		if(p!=q){
			printf("No\n");
			return NO;
		}
	}
	printf("Yes\n");
	return YES;
}

int main(){
	Palindrome_Test();
}
