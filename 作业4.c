//4. 用定长顺序串编写下列算法。
#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 15

/*顺序串结构定义*/
typedef struct {          
    char ch[MAXLEN];
    int len;
}SString;

//(1)将顺序串s中所有值为ch1的字符转换成ch2的字符，其中参数ch1和ch2传入的均为字符量。
int charReplace(SString *s, char ch1, char ch2){
	if(!s) return 0;
	int i;
	for(i=0;i<s->len;i++){
		if(s->ch[i]==ch1){
			s->ch[i]=ch2;
		}
	}
	return 1;
}

 

//(2)将顺序串s中所有字符按照相反的次序仍存放在s中，即实现字符串的逆置。
int  strInverse(SString *s){
	if(!s) return 0;
	int i;
	char x;
	for(i=0;i<s->len/2;i++){
		x=s->ch[i];
		s->ch[i]=s->ch[s->len-i-1];
		s->ch[s->len-i-1]=x;
	}
	return 1;
}

 

//(3)从顺序串s中删除其值等于ch的所有字符，其中参数ch传入的为字符量。
int charDelete(SString *s, char ch){
	if(!s) return 0;
	int i,n;
	for(i=n=0;i<s->len;i++){
		if(s->ch[i]==ch){
			n++;
		}
		else if(n==0)
				continue;
		else {
			s->ch[i-n]=s->ch[i];
		}
	}
	s->len=s->len-n; 
	return 1;
}

void Scanf(SString *s){
	char x;
	while((x=getchar())!='\n'&&s->len<=MAXLEN-1){
		s->ch[s->len++]=x;
	}
}

void Print(SString s){
	int i;
	for(i=0;i<s.len;i++){
		putchar(s.ch[i]);
	}
	putchar('\n');
}

int main(){
	SString a;
	Scanf(&a);		//输入 i like apple 
	Print(a);
	charReplace(&a,'i','I');
	Print(a);
	charDelete(&a,'l');
	Print(a);
	strInverse(&a);
	Print(a);
}
