//通过一维数组模拟二维对称数组的压缩存储，并实现相应的二维对称数组的读写函数
//（即将逻辑上的二维数组按照行序优先压缩存储于物理一维数组中，通过为相应的读写函数提供行列下标，
//实现对压缩存于一维数组中的二维对称数组元素的访问）。程序框架如下所示：

/*对称数组压缩存储的仿真*/

/*包含头文件*/
#include <stdio.h>
#include <stdlib.h>
#define		OK		1
#define		ERROR	0
#define		ORDER	5   /*对称二维数组的阶数，即对称二维数组具有order行order列*/
#define		DIMM	ORDER*(ORDER+1)/2   /*对应一维数组的大小为DIMM*/

/*定义ElemType类型和使用到的物理数据类型*/
typedef int	ElemType;

/*声明物理数据类型的操作（函数）和使用到的其他功能函数*/
/*将order*order规模的对称二维数组元素值（任意值均可）存储在Mat一维数组中*/
int MatrixInit(ElemType Mat[], int order);
/*读取对称二维数组的逻辑行下标i和列下标j的元素，并通过参数m返回该元素值*/
int ReadElem(ElemType Mat[],int i,int j,int order,ElemType *m);
/*写对称二维数组的逻辑行下标i和列下标j的元素，元素值由参数m传递*/
int WriteElem(ElemType Mat[],int i,int j,int order,ElemType m);

/*定义物理数据类型的操作（函数）和使用到的其他功能函数*/
/*将order*order规模的对称二维数组元素值（任意值均可）存储在Mat一维数组中*/
int MatrixInit(ElemType Mat[], int order){
	int i;
	for(i=0;i<DIMM;i++){
		Mat[i]=i;
	}
	return OK;
}


/*读取对称二维数组的逻辑行下标i和列下标j的元素，并通过参数m返回该元素值*/
int ReadElem(ElemType Mat[],int i,int j,int order,ElemType *m){
	int k;
	if(i<=order&&j<=order&&i>0&&j>0){
		if(i<j){
			k=i;
			i=j;
			j=k;
		}
		*m=Mat[i*(i-1)/2+j-1];
		return OK;
	}
	else return ERROR;
}



/*写对称二维数组的逻辑行下标i和列下标j的元素，元素值由参数m传递*/

int WriteElem(ElemType Mat[],int i,int j,int order,ElemType m){
	int k;
	if(i<=order&&j<=order&&i>0&&j>0){
		if(i<j){
			k=i;
			i=j;
			j=k;
		}
		Mat[i*(i-1)/2+j-1]=m;
		return OK;
	}
	else return ERROR;
}



int main(){
    /*定义DIMM大小的一维数组存储ORDER*ORDER规模的对称二维数组*/
	ElemType	Mat[DIMM];
	int	i,j;
	ElemType m;
    /*初始化对称二维数组*/
	MatrixInit(Mat,ORDER);
	
    /*读入准备读写对称二维数组元素的逻辑行下标i和列下标j*/
	scanf("%d%d",&i,&j);
	
    /*从对称二维数组中读取逻辑行下标i和列下标j位置的元素*/
	if(ReadElem(Mat,i,j,ORDER,&m))
		printf("Mat[%d][%d]=%d\n",i,j,m);
	else
		printf("Subscript ERROR!\n");
		
    /*将值m+1写入对称二维数组中逻辑行下标i和列下标j位置*/
	if(WriteElem(Mat,i,j,ORDER,m+1))
		printf("Mat[%d][%d]=%d\n",i,j,m+1);
	else
		printf("Subscript ERROR!\n");

    /*再次从对称二维数组中读取逻辑行下标i和列下标j位置的元素*/
	if(ReadElem(Mat,i,j,ORDER,&m))
		printf("Mat[%d][%d]=%d\n",i,j,m);
	else
		printf("Subscript ERROR!\n");
    system("PAUSE");
	return 0;

}
