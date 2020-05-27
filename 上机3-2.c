//�����⣺������ջʵ��������ֵ��ת�������
//���罫ʮ������327ת��Ϊ��Ӧ��������101000111�������
//������������ʾ��
/*����ת��*/
/*����ͷ�ļ�*/
#include <stdio.h>
#include <stdlib.h>
/*���峣��*/
#define		TRUE	1
#define		FALSE	0
#define		OK		1
#define		ERROR	0
#define		Stack_Size 100/*˳��ջ�ռ��С*/

/*����ElemType���ͺ�ʹ�õ���������������*/
/*����˳��ջ����*/
typedef int StackElementType;
typedef struct
{
	StackElementType elem[Stack_Size]; /*�������ջ��Ԫ�ص�һά����*/
	int top;          		/*�������ջ��Ԫ�ص��±꣬topΪ-1��ʾ��ջ*/
}SeqStack;

/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/
/*---------------------------˳��ջ����---------------*/
/*��ʼ��*/
void InitStack(SeqStack *S);
/*��ջ��*/
int IsEmpty(SeqStack *S); /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
int Push(SeqStack *S,StackElementType x);
int Pop(SeqStack *S,StackElementType *x);
/*��mת��ΪNS���Ʋ���ӡ���*/
void NumConv (int m,int NS);

/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/
/*---------------------------˳��ջ����---------------*/
/*��ʼ��*/
void InitStack(SeqStack *S){
	S->top=-1;
}



/*��ջ��*/

int IsEmpty(SeqStack *S){ 	/*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
	if(S->top==-1)
		return TRUE;
	else
		return FALSE;
}

int Push(SeqStack *S,StackElementType x){
	if(S->top==Stack_Size-1){
		printf("����/n");
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
		printf("���/n");
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





/*������������ͨ�����������ø������������͵Ĳ����͹��ܺ���*/

int main(){
	int n;
	printf("Pls enter a decimal number:\n");
	scanf("%d",&n);
	NumConv(n,2);
	NumConv(n,8);
	return 0;
}
