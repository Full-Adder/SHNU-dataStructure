//15. 编写递归函数，删除二叉链表中所有元素值为x的结点以及以其为根的子树，并释放相应空间。程序的框架如下所示：
/*删除子树的关键有两步1.销毁子树自身2.设置被销毁子树根节点的双亲的lchild或rchild为空*/
/*包含头文件*/
#include <stdio.h>
#include <stdlib.h>
/*定义常量*/
#define		TRUE	1
#define		FALSE	0
#define		OK		1
#define		ERROR	0

/*定义ElemType类型和使用到的物理数据类型*/
typedef char ElemType;
typedef struct Node{
	ElemType data;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode, *BiTree;

/*声明物理数据类型的操作（函数）和使用到的其他功能函数*/
/*创建二叉树*/
BiTree CreateBiTree();
//void CreateBiTree(BiTree bt);
/*销毁二叉树*/
void DestroyBiTree(BiTree bt);
/*先序遍历二叉树, root为指向二叉树(或某一子树)根结点的指针*/
void  PreOrder(BiTree root); 
/*递归删除二叉链表中所有值为x的子树*/
BiTNode * DelXTree(BiTree bt,ElemType x);


/*定义物理数据类型的操作（函数）和使用到的其他功能函数*/
/*创建二叉树*/
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


/*销毁二叉树*/
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

/*先序遍历二叉树, root为指向二叉树(或某一子树)根结点的指针*/
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


/*递归删除二叉链表中所有值为x的子树*/
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


/*定义主函数，通过主函数调用各物理数据类型的操作和功能函数*/

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
