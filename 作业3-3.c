//һ���Ի����жϡ��������뷴������ͬ���ַ�����Ϊ�����ġ����С�
//��дһ�㷨���ж����ζ����һ���ַ����У��Ƿ�Ϊ���硰����1����2��ģʽ���ַ����С�
//��������2������1�������С����硰a+bb+a�������ڸ�ģʽ���ַ����У�����1+33-1�����ǡ�
//����ʾ��ͬʱʹ��ջ�Ͷ���ʵ�֣�����ԭ��������ʾ

/*���д��ն˶���*/
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
	ElementType  element[MAXSIZE];  /* ���е�Ԫ�ؿռ�*/
	int front;  /*ͷָ��ָʾ��*/
	int rear;  /*βָ��ָʾ��*/
	int tag;/*���front��rear��ʾ��ǰջ�ջ���*/
	/*front==rear &&tag==1��ʾ����front==rear &&tag==0��ʾ��*/
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

/*��Ӳ���*/
int EnterQueue(SeqQueue *Q,ElementType x){
	  if(Q->front==Q->rear&&Q->tag==1){
	  	printf("�������޷����\n");
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

/*���Ӳ���*/ 
int DeleteQueue(SeqQueue *Q,ElementType *x){
	if(Q->front==Q->rear&&Q->tag==0){
		printf("�ձ��޷�����\n");
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
