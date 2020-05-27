//ͨ��һά����ģ���ά�Գ������ѹ���洢����ʵ����Ӧ�Ķ�ά�Գ�����Ķ�д����
//�������߼��ϵĶ�ά���鰴����������ѹ���洢������һά�����У�ͨ��Ϊ��Ӧ�Ķ�д�����ṩ�����±꣬
//ʵ�ֶ�ѹ������һά�����еĶ�ά�Գ�����Ԫ�صķ��ʣ���������������ʾ��

/*�Գ�����ѹ���洢�ķ���*/

/*����ͷ�ļ�*/
#include <stdio.h>
#include <stdlib.h>
#define		OK		1
#define		ERROR	0
#define		ORDER	5   /*�Գƶ�ά����Ľ��������Գƶ�ά�������order��order��*/
#define		DIMM	ORDER*(ORDER+1)/2   /*��Ӧһά����Ĵ�СΪDIMM*/

/*����ElemType���ͺ�ʹ�õ���������������*/
typedef int	ElemType;

/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/
/*��order*order��ģ�ĶԳƶ�ά����Ԫ��ֵ������ֵ���ɣ��洢��Matһά������*/
int MatrixInit(ElemType Mat[], int order);
/*��ȡ�Գƶ�ά������߼����±�i�����±�j��Ԫ�أ���ͨ������m���ظ�Ԫ��ֵ*/
int ReadElem(ElemType Mat[],int i,int j,int order,ElemType *m);
/*д�Գƶ�ά������߼����±�i�����±�j��Ԫ�أ�Ԫ��ֵ�ɲ���m����*/
int WriteElem(ElemType Mat[],int i,int j,int order,ElemType m);

/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/
/*��order*order��ģ�ĶԳƶ�ά����Ԫ��ֵ������ֵ���ɣ��洢��Matһά������*/
int MatrixInit(ElemType Mat[], int order){
	int i;
	for(i=0;i<DIMM;i++){
		Mat[i]=i;
	}
	return OK;
}


/*��ȡ�Գƶ�ά������߼����±�i�����±�j��Ԫ�أ���ͨ������m���ظ�Ԫ��ֵ*/
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



/*д�Գƶ�ά������߼����±�i�����±�j��Ԫ�أ�Ԫ��ֵ�ɲ���m����*/

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
    /*����DIMM��С��һά����洢ORDER*ORDER��ģ�ĶԳƶ�ά����*/
	ElemType	Mat[DIMM];
	int	i,j;
	ElemType m;
    /*��ʼ���Գƶ�ά����*/
	MatrixInit(Mat,ORDER);
	
    /*����׼����д�Գƶ�ά����Ԫ�ص��߼����±�i�����±�j*/
	scanf("%d%d",&i,&j);
	
    /*�ӶԳƶ�ά�����ж�ȡ�߼����±�i�����±�jλ�õ�Ԫ��*/
	if(ReadElem(Mat,i,j,ORDER,&m))
		printf("Mat[%d][%d]=%d\n",i,j,m);
	else
		printf("Subscript ERROR!\n");
		
    /*��ֵm+1д��Գƶ�ά�������߼����±�i�����±�jλ��*/
	if(WriteElem(Mat,i,j,ORDER,m+1))
		printf("Mat[%d][%d]=%d\n",i,j,m+1);
	else
		printf("Subscript ERROR!\n");

    /*�ٴδӶԳƶ�ά�����ж�ȡ�߼����±�i�����±�jλ�õ�Ԫ��*/
	if(ReadElem(Mat,i,j,ORDER,&m))
		printf("Mat[%d][%d]=%d\n",i,j,m);
	else
		printf("Subscript ERROR!\n");
    system("PAUSE");
	return 0;

}
