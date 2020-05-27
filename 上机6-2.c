//15. ��д�ݹ麯����ɾ����������������Ԫ��ֵΪx�Ľ���Լ�����Ϊ�������������ͷ���Ӧ�ռ䡣����Ŀ��������ʾ��
/*ɾ�������Ĺؼ�������1.������������2.���ñ������������ڵ��˫�׵�lchild��rchildΪ��*/
/*����ͷ�ļ�*/
#include <stdio.h>
#include <stdlib.h>
/*���峣��*/
#define		TRUE	1
#define		FALSE	0
#define		OK		1
#define		ERROR	0

/*����ElemType���ͺ�ʹ�õ���������������*/
typedef char ElemType;
typedef struct Node{
	ElemType data;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode, *BiTree;

/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/
/*����������*/
BiTree CreateBiTree();
//void CreateBiTree(BiTree bt);
/*���ٶ�����*/
void DestroyBiTree(BiTree bt);
/*�������������, rootΪָ�������(��ĳһ����)������ָ��*/
void  PreOrder(BiTree root); 
/*�ݹ�ɾ����������������ֵΪx������*/
BiTNode * DelXTree(BiTree bt,ElemType x);


/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/
/*����������*/
BiTree CreateBiTree(){
	BiTree bt;
	char a=getchar();
	if(a=='.') bt=NULL;
	else{
		bt=(BiTree)malloc(sizeof(BiTNode));
		(bt)->data=a;
		((bt)->LChild)=CreateBiTree();
		((bt)->RChild)=CreateBiTree();
	}
	return bt;
}

//void CreateBiTree(BiTree *bt){
//	char a=getchar();
//	if(a=='.') *bt=NULL;
//	else{
//		*bt=(BiTree)malloc(sizeof(BiTNode));
//		(*bt)->data=a;
//		CreateBiTree(&((*bt)->LChild));
//		CreateBiTree(&((*bt)->RChild));
//	}
//	return;
//}
//
//void CreateBiTree(BiTree bt){
//	char a=getchar();
//	if(a=='.') bt=NULL;
//	else{
//		bt=(BiTree)malloc(sizeof(BiTNode));
//		(bt)->data=a;
//		CreateBiTree(((bt)->LChild));
//		CreateBiTree(((bt)->RChild));
//	}
//	return;
//}


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

/*�������������, rootΪָ�������(��ĳһ����)������ָ��*/
void  PreOrder(BiTree root){
	if(root==NULL){
//		printf(".");
		return;
	} 
	else{
		printf("%c",root->data);
		PreOrder(root->LChild);
		PreOrder(root->RChild);
	}
}


/*�ݹ�ɾ����������������ֵΪx������*/
BiTNode * DelXTree(BiTree bt,ElemType x){
	if(bt==NULL) return NULL;
	
	if(bt->data==x) {
		DestroyBiTree(bt);
		return NULL;
	}
	
	if(bt->LChild&&bt->LChild->data==x){
		DestroyBiTree(bt->LChild);
		bt->LChild=NULL;
	}
	
	if(bt->RChild&&bt->RChild->data==x){
		DestroyBiTree(bt->RChild);
		bt->RChild=NULL;
	}		
	
	DelXTree(bt->LChild,x);
	DelXTree(bt->RChild,x);
	
	return bt;
}


/*������������ͨ�����������ø������������͵Ĳ����͹��ܺ���*/

int main(){
	BiTree bt;
	bt=CreateBiTree();/*BCD.Q..AF...DCA...M..*/
//	CreateBiTree(bt);/*BCD.Q..AF...DCA...M..*/
//	PreOrder(bt);
	bt=DelXTree(bt,'A');
	if(!bt)
		printf("The tree is NULL!\n");
	else{
		printf("The tree is<");/*BCDQDCM*/
		PreOrder(bt);
		printf(">\n");
	}
	DestroyBiTree(bt);
	return 0;
}
