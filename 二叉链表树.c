//10. ��֪���������ö��������ţ���ʹ�õݹ��ջ���Ҷ������ĺ��������еĵ�һ������ָ�롣����Ŀ��������ʾ��
/*10.��ʹ�õݹ��ջ���Ҷ�������������ĵ�һ�����*/
/*����ͷ�ļ�*/
#include <stdio.h>
#include <stdlib.h>

/*���峣��*/
#define TRUE    1
#define FALSE   0
#define OK      1
#define ERROR   0

/*����ElemType���ͺ�ʹ�õ���������������*/
typedef char ElemType;
typedef struct Node{
    ElemType data;
    struct Node *LChild;
    struct Node *RChild;
}BiTNode, *BiTree;

/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/
/*����������*/
void CreateBiTree(BiTree *bt); 
/*���ٶ�����*/
void DestroyBiTree(BiTree bt);
/*��ʹ�õݹ��ջ���Ҷ�������������ĵ�һ�����*/
BiTNode * FNPostTraverse(BiTree bt);


/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/
/*����������*/
void CreateBiTree(BiTree *bt){
	char a=getchar();
	if(a=='.') *bt=NULL;
	else{
		*bt=(BiTree)malloc(sizeof(BiTNode));
		(*bt)->data=a;
		CreateBiTree(&((*bt)->LChild));
		CreateBiTree(&((*bt)->RChild));
	}
	return;
}

/*���ٶ�����*/
void DestroyBiTree(BiTree bt){
	if(bt==NULL){
		return;
	}
	else{
		DestroyBiTree(bt->LChild);
		DestroyBiTree(bt->RChild);
		free(bt);
		return;
	}
}

/*��ʹ�õݹ��ջ���Ҷ�������������ĵ�һ�����*/
BiTNode * FNPostTraverse(BiTree bt){
	BiTNode *D=bt;
	while(D->LChild!=NULL||D->RChild!=NULL){
		if(D->LChild!=NULL){
			D=D->LChild;
		}
		else{
			D=D->RChild;
		}
	}
	return D;
}



/*������������ͨ�����������ø������������͵Ĳ����͹��ܺ���*/
int main(){
    BiTree bt,fn=NULL;
    CreateBiTree(&bt);
    fn=FNPostTraverse(bt);
    if(!fn)
        printf("bt is NULL Tree!\n");
    else
        printf("The first node of posttraverse is %c\n",fn->data);
    DestroyBiTree(bt);
    return 0;
} 
