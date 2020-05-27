//12. Ҫ��ѭ�����в���ʧһ���ռ�ȫ�����ܵõ����ã�����һ����־��tag��
//��tagΪ0��1������ͷβָ����ͬʱ�Ķ���״̬�����д��˽ṹ��Ӧ�����������㷨��
//ѭ�����е����������뺯��ԭ��������ʾ
#define  QueueElementType int
#define MAXSIZE 5
#define ERROR	0
#define OK		1

#include<stdio.h>

typedef struct SeqQueue{
	QueueElementType  element[MAXSIZE];  /* ���е�Ԫ�ؿռ�*/
	int front;  /*ͷָ��ָʾ��*/
	int rear;  /*βָ��ָʾ��*/
	int tag;/*���front��rear��ʾ��ǰջ�ջ���*/
	/*front==rear &&tag==1��ʾ����front==rear &&tag==0��ʾ��*/
}SeqQueue;

//��ʼ��
void InitQueue(SeqQueue *Q){
	Q->front=Q->rear=Q->tag=0;
} 

/*��Ӳ���*/
int EnterQueue(SeqQueue *Q, QueueElementType x){
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
int DeleteQueue(SeqQueue *Q, QueueElementType *x){
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
			printf("ɾ��%d\n",x);
		}
		PrintSeq(a);
		scanf("%d",&x);
	}
} 
