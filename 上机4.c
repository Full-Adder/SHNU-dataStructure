//设计函数计算两个定长顺序字符串的差集字符串
//（即对于字符串A与B的差集字符串A-B，
//中按次序包含所有存在于A中但不在B中的字符构成的字符序列，
//注意差集字符串中的字符不应重复），
//例如字符串"abcadecfge"与字符串"bmqgxvwf"的差集字符串为"acde"。
//程序框架如下所示：


/*两定长顺序字符串的差集*/
/*包含头文件*/
#include <stdio.h>
#include <stdlib.h>
/*定义常量*/
#define	TRUE	1
#define	FALSE	0
#define	OK		1
#define	ERROR	0
#define MAXLEN 100/*最大串长度*/

/*顺序串结构定义*/
typedef struct {          
    char ch[MAXLEN];
    int len;
}SString;


/*声明物理数据类型的操作（函数）和使用到的其他功能函数*/
/*串输出函数*/
void output(SString *s);
/*把串常量chars赋值给串s*/
int strAssign(SString *s,char chars[]);
/*求所有包含在串s中而t中没有的字符构成的新串r*/
int strDifference(SString s,SString t,SString *r);
/*定义物理数据类型的操作（函数）和使用到的其他功能函数*/

/*串输出函数*/
void output(SString *s){
	int i;
	for(i=0;i<s->len;i++){
		printf("%c",s->ch[i]);
	} 
	putchar('\n');
}


/*把串常量chars赋值给串s*/
int strAssign(SString *s,char chars[]){
	int i;
	for(i=0;chars[i]!='\0'&&i<MAXLEN;i++){
		s->ch[i]=chars[i];
	}
	s->len=s->len+i;
	return 0;
}


/*求所有包含在串s中而t中没有的字符构成的新串r*/
int strInsert(SString *s,char c){
	if(s->len>=MAXLEN)
		return 0;
	else{
		s->ch[s->len++]=c;
	}
	return 1;
}


int strDifference(SString s,SString t,SString *r){
	int i,j,k=0;
	SString x;
	
	for(i=0;i<s.len;i++){			//i是s的下标 ，从0开始 
		for(j=i+1;j<s.len;j++){		// j时是s的另一个下标，每次从i+i开始 
			if(s.ch[i]==s.ch[j]){	//依次比对s[i]和s[j]，不等继续比较s[i]和s[j+1]... 
				break;				//若相等，跳出j循环，下面通过比较j是不是到最后s.len看 
			}						//s[i]和s[i]后面的元素有没有重复 
		}							//若j==s.len,说明s[i]和后面都比了一遍没有重复 
		if(j==s.len){				//与自身没有重复 
			for(k=0;k<t.len;k++){	// s[i]没有自身重复，继续看和t有没有重复 
				if(s.ch[i]==t.ch[k])//这句和上面的意思一样 
					break;
			}
			if(k==t.len)			//s[i]和t所有的没有重复 
				strInsert(&x,s.ch[i]);	 //将s[i]插入x中 
		}
	}
	*r=x;							//输出r 
	return 1;
}


/*定义主函数，通过主函数调用各物理数据类型的操作和功能函数*/
int main(){
SString a,b,c;
strAssign(&a,"abcadecfgeb");
output(&a);
strAssign(&b,"mqgxvwf");
output(&b);
strDifference(a,b,&c);
output(&c);
system("PAUSE");
return 0;
}
