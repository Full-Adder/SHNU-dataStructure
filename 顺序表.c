#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef  int ElemType;

typedef struct{
	ElemType elem[MaxSize];								//设置数组的最大长度 
	int last;											//最后一个元素的下标 
}SeqList,*PointSeqList;

SeqList* NewSeqList();

int ScanfSeqList(SeqList *L);							//尾插法创建顺序表

void PrintfSeqList(SeqList *L);								//打印顺序表 

int AdjustSqlist(SeqList  *L);							//将L中的奇数元素都排在前面，偶数元素都排在后面

int Locate(SeqList *L,ElemType e);

int GetData(SeqList *L,ElemType e);

int InsList(SeqList *L,int i,ElemType e);

int DelList(SeqList *L,int i,ElemType *e);

void mergeList(SeqList *LA,SeqList *LB,SeqList *LC);

int SListDelXY(SeqList *L,ElemType x, ElemType y);		//顺序表L中删除所有元素值介于x和y之间的所有元素


SeqList* NewSeqList(){
	PointSeqList a = (SeqList*)malloc(sizeof(SeqList));
	a->last=-1;
	return a;
} 

int  ScanfSeqList(SeqList *L){
	ElemType c; 
	scanf("%d",&c); 
	while(c!=999){
		if(L->last>=MaxSize){
			printf("超过字符限制数量\n");
			return 0;
		}
		L->elem[++L->last]=c;
		scanf("%d",&c); 
	}
	return 1;
}


int SListDelXY(SeqList *L,ElemType x, ElemType y){		//顺序表L中删除所有元素值介于x和y之间的所有元素
	int i,j;
	for(i=j=0;i<=L->last;i++){
		if(i!=j)
			L->elem[j]=L->elem[i];
		if(L->elem[i]<=x||L->elem[i]>=y) 
			j++;
	}
	L->last=--j;
	return 1;
}

int AdjustSqlist(SeqList  *L){			//将L中的奇数元素都排在前面，偶数元素都排在后面
	int i=0,j=L->last,x;
	for(i;i<L->last/2;i++){
		if(L->elem[i]%2!=0)
			continue;
		else {
			for(j;j>L->last/2;j--){
				if(L->elem[j]%2==0)
					continue;
				else{
					x=L->elem[i];
					L->elem[i]=L->elem[j];
					L->elem[j]=x;
					break;
				}
			}
		}
	}
	return 1;
}


 void PrintfSeqList(SeqList *L){
	int i;
	for(i=0;i<=L->last;i++){
		printf("%d ",L->elem[i]);
	}
	putchar('\n');
}


int main() {
	PointSeqList x=NewSeqList();
	ScanfSeqList(x);
	PrintfSeqList(x);
	AdjustSqlist(x);
	PrintfSeqList(x);
	SListDelXY(x,3,8);
	PrintfSeqList(x);
	return 0;
}
