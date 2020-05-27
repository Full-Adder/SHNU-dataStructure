/*����˳�������Ԫ�ء�˳���͵����ò���ӡ*/
/*����ͷ�ļ�*/

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAXSIZE 100

/*����ElemType���ͺ�ʹ�õ���������������*/

typedef char ElemType;



typedef  struct{ 
     ElemType  elem[MAXSIZE];  /* ���Ա�ռ�õ�����ռ�*/ 
     int  last;    /*��¼���Ա������һ��Ԫ��������elem�е�λ�ã��±�ֵ�����ձ���Ϊ-1*/
} SeqList;



/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/

/*β�巨����˳���*/

int  CreateSList(SeqList *L);

/*˳���͵�����*/

int SListRev(SeqList *L);

/*��ӡ˳���*/

void SListPrint(SeqList L);





/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/

/*β�巨����˳���*/

int  CreateSList(SeqList *L){
	int i = 0;
	while((L->elem[i++]=getchar())!='\n')
		if(i>MAXSIZE){
			printf("�����ַ���������\n");
			return ERROR;
		}
	L->last=i-2;
	return OK;
}



/*˳���͵�����*/

int SListRev(SeqList *L){
	if(L->last==-1){
		printf("��գ�\n");
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



/*��ӡ˳���*/

void SListPrint(SeqList L){
	int i;
	for(i=0;i<=L.last;i++){
		printf("%c",L.elem[i]);
	}
	putchar('\n');
}



/*������������ͨ�����������ø������������͵Ĳ����͹��ܺ���*/
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


