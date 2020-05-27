/*删除递增有序单链表中的重复元素*/

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



typedef struct Node    /* 结点类型定义 */

{ ElemType data;

  struct Node  *next;

}Node, *LinkList;



/*声明物理数据类型的操作（函数）和使用到的其他功能函数*/

/*尾插法创建单链表*/

LinkList  CreateFromTail();

/*打印链表*/

void LListPrint(LinkList L);

/*删除递增有序单链表中的重复元素*/

void  LListDelElem(LinkList L);

/*销毁单链表*/

void ListDestroy(LinkList L);





/*定义物理数据类型的操作（函数）和使用到的其他功能函数*/

/*尾插法创建单链表*/

LinkList  CreateFromTail(){
	Node *L,*s,*r;
	char c;
	L=(Node*)malloc(sizeof(Node));			//	头结点 
	L->next=NULL;
	r=L;
	while((c=getchar())!='\n'){
		s=(Node*)malloc(sizeof(Node));		//s是新节点 
		s->data=c;							//r指向当前链表末尾结点 
		r->next=s;							//连接新节点 
		r=s;								//r指向新的末尾结点 
	}
	r->next=NULL;
	return L;
}



/*打印链表*/

void LListPrint(LinkList L){
	Node *p=L->next;
	while(p->next!=NULL){
		printf("%c",p->data);
		p=p->next;
	}
	printf("%c\n",p->data);
}





/*删除递增有序单链表中的重复元素*/

void  LListDelElem(LinkList L){
	Node *p=L->next,*q=p->next;		//p是前指针，q是后指针 
	while(q->next!=NULL){
		if(p->data==q->data){		//若内容一样 
			p->next=q->next;		//前结点指向重复元素的后一个节点 (删除重复结点) 
			free(q);
			q=p->next;				//后指针指向下一个结点 
		}
		else {						//若不重复 
			p=p->next;				//前后指针分别向后移动一位 
			q=q->next;
		}	
	}
	if(p->data==q->data){			//若最后一个结点值重复 
			free(q);				
			p->next=NULL;			// 前指针next为空 
	}
}



/*销毁单链表*/

void ListDestroy(LinkList L){
	Node *p=L,*q=p->next;
	while(q!=NULL){
		free(p);
		p=q;
		q=q->next;
	} 
	free(p);
	printf("清除完成\n");
}



/*定义主函数，通过主函数调用各物理数据类型的操作和功能函数*/



int main(){

LinkList a;

a=CreateFromTail();

LListPrint(a);

LListDelElem(a);

LListPrint(a);

ListDestroy(a);

return 0;

}
