//补充题：借助于栈实现整数数值的转换输出，
//例如将十进制数327转换为对应二进制数101000111并输出。
//程序框架如下所示：
/*数制转换*/
/*包含头文件*/
#include <stdio.h>
#include <stdlib.h>
/*定义常量*/
#define		TRUE	1
#define		FALSE	0
#define		OK		1
#define		ERROR	0
#define		Stack_Size 100/*顺序栈空间大小*/

/*定义ElemType类型和使用到的物理数据类型*/
/*定义顺序栈部分*/
typedef int StackElementType;
typedef struct
{
	StackElementType elem[Stack_Size]; /*用来存放栈中元素的一维数组*/
	int top;          		/*用来存放栈顶元素的下标，top为-1表示空栈*/
}SeqStack;

/*声明物理数据类型的操作（函数）和使用到的其他功能函数*/
/*---------------------------顺序栈部分---------------*/
/*初始化*/
void InitStack(SeqStack *S);
/*判栈空*/
int IsEmpty(SeqStack *S); /*判断栈S为空栈时返回值为真，反之为假*/
int Push(SeqStack *S,StackElementType x);
int Pop(SeqStack *S,StackElementType *x);
/*将m转换为NS数制并打印输出*/
void NumConv (int m,int NS);

/*定义物理数据类型的操作（函数）和使用到的其他功能函数*/
/*---------------------------顺序栈部分---------------*/
/*初始化*/
void InitStack(SeqStack *S){
	S->top=-1;
}



/*判栈空*/

int IsEmpty(SeqStack *S){ 	/*判断栈S为空栈时返回值为真，反之为假*/
	if(S->top==-1)
		return TRUE;
	else
		return FALSE;
}

int Push(SeqStack *S,StackElementType x){
	if(S->top==Stack_Size-1){
		printf("表满/n");
		return ERROR;
	}
	else{
		S->top++;
		S->elem[S->top]=x;
		return OK;
	}
}



int Pop(SeqStack *S,StackElementType *x){
	if(S->top==-1){
		printf("表空/n");
		return ERROR;
	}  
	else{
		*x=S->elem[S->top];
		S->top--;
	}
}

void NumConv (int m,int NS) {
	if(m<0){
		m=-m;
		putchar('-');
	}
	SeqStack a;
	InitStack(&a);
	while(m>0){
		Push(&a,m%NS);
		m=m/NS;
	}
	while(!IsEmpty(&a)){
		Pop(&a,&m);
		printf("%d",m);
	}
	putchar('\n');
}





/*定义主函数，通过主函数调用各物理数据类型的操作和功能函数*/

int main(){
	int n;
	printf("Pls enter a decimal number:\n");
	scanf("%d",&n);
	NumConv(n,2);
	NumConv(n,8);
	return 0;
}
