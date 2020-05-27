//ʵϰ��1. �����жϡ��������뷴������ͬ���ַ�����Ϊ�����ġ����С�
//��дһ�㷨���ж����ζ����һ����@Ϊ���������ַ����У�
//�Ƿ�Ϊ���硰����1&����2��ģʽ���ַ����С���������1������2�ж������ַ���&����
//������2������1�������С����硰a+b&b+a�������ڸ�ģʽ���ַ����У�����1+3&3-1�����ǡ�
//����ԭ��������ʾ


/*���д��ն˶���*/
#define StackElementType char
#define MAXSIZE 30
#define ERROR	0
#define OK		1

#include<stdio.h>

typedef struct{
	StackElementType elem[MAXSIZE];
	int top;
}SeqStack;

void InitStack(SeqStack *S){
	S->top=-1;
}

int Push(SeqStack *S,StackElementType x){
	if(S->top==MAXSIZE-1)
		return ERROR;
	else{
		S->top++;
		S->elem[S->top]=x;
		return OK;
	}
}

int Pop(SeqStack *S,StackElementType *x){
	if(S->top==-1)
		return ERROR;
	else{
		*x=S->elem[S->top];
		S->top--;
		return OK;
	}
}

int IsReverse(){
	SeqStack a;
	InitStack(&a);
	char b,c=getchar();
	while(c!='&'){
		if(c=='@')
			return ERROR;
		Push(&a,c);
		c=getchar();
	}
	c=getchar();
	while(c!='@'&&a.top!=-1){
		Pop(&a,&b);
		if(c!=b){
			puts("No!\n");
			return 0;
		}
		c=getchar();
	}
	if(c=='@'&&a.top==-1){
		puts("Yes!\n");
		return 1;
	}else{
		puts("No!\n");
		return 0;
	}
}

int main(){
	IsReverse();
}
