//2. 设计一个算法，将一维数组A(下标从1开始）中的元素循环右移k位，
//要求只用一个元素大小的附加存储空间。给出算法的时间复杂度。函数原型如下所示：
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

void RMove(ElemType A[],int n, int k){		//n是从1算起的数组大小 ，即最后一个元素的下标 
	int i;
	if(k>=n)
		k=k%n;
	Swap(A,1,n);
	Swap(A,1,k);
	Swap(A,k+1,n);
}
//赋值语句执行3(k+n+1)<6n次，所以算法复杂度为O(n) 

int main(){
	int i;
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	for(i=1;i<20;i++){
		printf("%d ",a[i]);
	}
	puts("\n后移8位");
	RMove(a,19,8);
	for(i=1;i<20;i++){
		printf("%d ",a[i]);
	}
} 


