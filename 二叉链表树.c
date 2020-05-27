//10. 已知二叉树采用二叉链表存放，不使用递归和栈查找二叉树的后序序列中的第一个结点的指针。程序的框架如下所示：
/*10.不使用递归和栈查找二叉树后序遍历的第一个结点*/
/*包含头文件*/
#include <stdio.h>
#include <stdlib.h>

/*定义常量*/
#define TRUE    1
#define FALSE   0
#define OK      1
#define ERROR   0

/*定义ElemType类型和使用到的物理数据类型*/
typedef char ElemType;
typedef struct Node{
    ElemType data;
    struct Node *LChild;
    struct Node *RChild;
}BiTNode, *BiTree;

/*声明物理数据类型的操作（函数）和使用到的其他功能函数*/
/*创建二叉树*/
void CreateBiTree(BiTree *bt); 
/*销毁二叉树*/
void DestroyBiTree(BiTree bt);
/*不使用递归和栈查找二叉树后序遍历的第一个结点*/
BiTNode * FNPostTraverse(BiTree bt);


/*定义物理数据类型的操作（函数）和使用到的其他功能函数*/
/*创建二叉树*/
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

/*不使用递归和栈查找二叉树后序遍历的第一个结点*/
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



/*定义主函数，通过主函数调用各物理数据类型的操作和功能函数*/
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
