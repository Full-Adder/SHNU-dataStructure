/*创建顺序表、插入元素、顺序表就地逆置并打印*/
/*包含头文件*/

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAXSIZE 100

/*定义ElemType类型和使用到的物理数据类型*/

typedef char ElemType;



typedef  struct{ 
     ElemType  elem[MAXSIZE];  /* 线性表占用的数组空间*/ 
     int  last;    /*记录线性表中最后一个元素在数组elem中的位置（下标值），空表置为-1*/
} SeqList;



/*声明物理数据类型的操作（函数）和使用到的其他功能函数*/

/*尾插法创建顺序表*/

int  CreateSList(SeqList *L);

/*顺序表就地逆置*/

int SListRev(SeqList *L);

/*打印顺序表*/

void SListPrint(SeqList L);





/*定义物理数据类型的操作（函数）和使用到的其他功能函数*/

/*尾插法创建顺序表*/

int  CreateSList(SeqList *L){
	int i = 0;
	while((L->elem[i++]=getchar())!='\n')
		if(i>MAXSIZE){
			printf("超过字符限制数量\n");
			return ERROR;
		}
	L->last=i-2;
	return OK;
}



/*顺序表就地逆置*/

int SListRev(SeqList *L){
	if(L->last==-1){
		printf("表空！\n");
		return ERROR;
	}
	char x;
	int i;
	for(i=0;i<L->last/2;i++){
		x=L->elem[i];
		L->elem[i]=L->elem[L->last-i];
		L->elem[L->last-i]=x;
	}
	return OK;
} 



/*打印顺序表*/

void SListPrint(SeqList L){
	int i;
	for(i=0;i<=L.last;i++){
		printf("%c",L.elem[i]);
	}
	putchar('\n');
}



/*定义主函数，通过主函数调用各物理数据类型的操作和功能函数*/
int main(){

SeqList a;

if(!CreateSList(&a))

exit(ERROR);

SListPrint(a);

if(!SListRev(&a))

exit(ERROR);

SListPrint(a);

return 0;

}


