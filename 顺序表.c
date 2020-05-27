#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef  int ElemType;

typedef struct{
	ElemType elem[MaxSize];								//�����������󳤶� 
	int last;											//���һ��Ԫ�ص��±� 
}SeqList,*PointSeqList;

SeqList* NewSeqList();

int ScanfSeqList(SeqList *L);							//β�巨����˳���

void PrintfSeqList(SeqList *L);								//��ӡ˳��� 

int AdjustSqlist(SeqList  *L);							//��L�е�����Ԫ�ض�����ǰ�棬ż��Ԫ�ض����ں���

int Locate(SeqList *L,ElemType e);

int GetData(SeqList *L,ElemType e);

int InsList(SeqList *L,int i,ElemType e);

int DelList(SeqList *L,int i,ElemType *e);

void mergeList(SeqList *LA,SeqList *LB,SeqList *LC);

int SListDelXY(SeqList *L,ElemType x, ElemType y);		//˳���L��ɾ������Ԫ��ֵ����x��y֮�������Ԫ��


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
			printf("�����ַ���������\n");
			return 0;
		}
		L->elem[++L->last]=c;
		scanf("%d",&c); 
	}
	return 1;
}


int SListDelXY(SeqList *L,ElemType x, ElemType y){		//˳���L��ɾ������Ԫ��ֵ����x��y֮�������Ԫ��
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

int AdjustSqlist(SeqList  *L){			//��L�е�����Ԫ�ض�����ǰ�棬ż��Ԫ�ض����ں���
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
