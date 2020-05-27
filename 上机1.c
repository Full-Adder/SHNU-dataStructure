#include <stdio.h>
#include <math.h>

/*���峣��*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAXSIZE 100

/*����ElemType���ͺ�ʹ�õ���������������*/
typedef int ElemType;
typedef struct{//�������ṹ��
ElemType num;//����
ElemType den;//��ĸ
}Rational;

/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/
void InitRational(Rational *a);//��������ʼ��
void RSum(Rational a,Rational b,Rational *c);//�������ӷ�
void RSub(Rational a,Rational b,Rational *c);//����������
void RMul(Rational a,Rational b,Rational *c);//�������˷�
int RDiv(Rational a,Rational b,Rational *c);//��������������������ֵ��ʾ�Ƿ���ɳ�����ע�ⱻ0�� 
void RND(Rational a,ElemType *b,ElemType *c);//�����������ӷ�ĸ
void RPrint(Rational a);//��������ӡ
void RNorm(Rational *a);//���ӷ�ĸԼ��

/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/
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
	printf("����ǣ�%d/%d\n",a.num,a.den);	
}



/*������������ͨ�����������ø������������͵Ĳ����͹��ܺ���*/

void main(){
	int a,b;
	Rational m,n,s;
	printf("�����������\n");
	InitRational(&m);
	RPrint(m);
	RND(m,&a,&b);
	printf("���ӣ�%d,��ĸ��%d\n",a,b);
	
	printf("�����뱻������\n");
	InitRational(&n);
	RPrint(n);
	RSum(m,n,&s);

	RSub(m,n,&s);
	RMul(m,n,&s);
	if(!RDiv(m,n,&s)){
		puts("Error!");
		return ;
	}  
	printf("���������\n");
	RPrint(s);
}


