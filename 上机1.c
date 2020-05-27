#include <stdio.h>
#include <math.h>

/*定义常量*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAXSIZE 100

/*定义ElemType类型和使用到的物理数据类型*/
typedef int ElemType;
typedef struct{//有理数结构体
ElemType num;//分子
ElemType den;//分母
}Rational;

/*声明物理数据类型的操作（函数）和使用到的其他功能函数*/
void InitRational(Rational *a);//有理数初始化
void RSum(Rational a,Rational b,Rational *c);//有理数加法
void RSub(Rational a,Rational b,Rational *c);//有理数减法
void RMul(Rational a,Rational b,Rational *c);//有理数乘法
int RDiv(Rational a,Rational b,Rational *c);//有理数除法，函数返回值表示是否完成除法，注意被0除 
void RND(Rational a,ElemType *b,ElemType *c);//求有理数分子分母
void RPrint(Rational a);//有理数打印
void RNorm(Rational *a);//分子分母约分

/*定义物理数据类型的操作（函数）和使用到的其他功能函数*/
void RNorm(Rational *a){
	int i;
	if(a->num==0) a->den=1;
	for(i=2;i<abs(a->den/2)||i<abs(a->num/2);i++){
		if(a->den%i==0&&a->num%i==0){
			a->den/=i;
			a->num/=i;
			i=2;
		}
	}
}



void InitRational(Rational *a){
	printf("please input 'num/num'\n"); 
	scanf("%d/%d",&a->num,&a->den);
	while(a->den==0) {
		printf("ERROR!Please try again!\n");
		scanf("%d/%d",&a->num,&a->den);
	}
	if(a->den<0) {
		a->den=-a->den;
		a->num=-a->num;
	}
	RNorm(a);
}



void RSum(Rational a,Rational b,Rational *c){
	c->den=a.den*b.den;
	c->num=a.den*b.num+b.den*a.num;
	RNorm(c);
}



void RSub(Rational a,Rational b,Rational *c){
	c->den=a.den*b.den;
	c->num=-a.den*b.num+b.den*a.num;
	RNorm(c);
}



void RMul(Rational a,Rational b,Rational *c){
	c->den=a.den*b.den;
	c->num=a.num*b.num;
	RNorm(c);
}



int RDiv(Rational a,Rational b,Rational *c){
	if(b.num==0) 
		return ERROR;
	else{	
		c->den=a.den*b.num;
		c->num=a.num*b.den;
	} 
	RNorm(c);
	return OK;
}



void RND(Rational a,ElemType *b,ElemType *c){
	*c=a.den;
	*b=a.num;
}



void RPrint(Rational a){
	printf("结果是：%d/%d\n",a.num,a.den);	
}



/*定义主函数，通过主函数调用各物理数据类型的操作和功能函数*/

void main(){
	int a,b;
	Rational m,n,s;
	printf("请输入除数：\n");
	InitRational(&m);
	RPrint(m);
	RND(m,&a,&b);
	printf("分子：%d,分母：%d\n",a,b);
	
	printf("请输入被除数：\n");
	InitRational(&n);
	RPrint(n);
	RSum(m,n,&s);

	RSub(m,n,&s);
	RMul(m,n,&s);
	if(!RDiv(m,n,&s)){
		puts("Error!");
		return ;
	}  
	printf("除法结果：\n");
	RPrint(s);
}


