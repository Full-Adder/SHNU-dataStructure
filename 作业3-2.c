//实习题1. 回文判断。称正读与反读都相同的字符序列为“回文”序列。
//试写一算法，判断依次读入的一个以@为结束符的字符序列，
//是否为形如“序列1&序列2”模式的字符序列。其中序列1和序列2中都不含字符“&”，
//且序列2是序列1的逆序列。例如“a+b&b+a”是属于该模式的字符序列，而“1+3&3-1”则不是。
//函数原型如下所示


/*序列从终端读入*/
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
