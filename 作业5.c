//2. ���һ���㷨����һά����A(�±��1��ʼ���е�Ԫ��ѭ������kλ��
//Ҫ��ֻ��һ��Ԫ�ش�С�ĸ��Ӵ洢�ռ䡣�����㷨��ʱ�临�Ӷȡ�����ԭ��������ʾ��
#include<stdio.h>
#define ElemType int
void Swap(ElemType A[],int start,int end){
	int i;
	ElemType x;
	for(i=start;i<=(start+end)/2;i++){
		x=A[i];
		A[i]=A[start+end-i];
		A[start+end-i]=x;
	}
}

void RMove(ElemType A[],int n, int k){		//n�Ǵ�1����������С �������һ��Ԫ�ص��±� 
	int i;
	if(k>=n)
		k=k%n;
	Swap(A,1,n);
	Swap(A,1,k);
	Swap(A,k+1,n);
}
//��ֵ���ִ��3(k+n+1)<6n�Σ������㷨���Ӷ�ΪO(n) 

int main(){
	int i;
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	for(i=1;i<20;i++){
		printf("%d ",a[i]);
	}
	puts("\n����8λ");
	RMove(a,19,8);
	for(i=1;i<20;i++){
		printf("%d ",a[i]);
	}
} 


