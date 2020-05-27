//4. �ö���˳�򴮱�д�����㷨��
#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 15

/*˳�򴮽ṹ����*/
typedef struct {          
    char ch[MAXLEN];
    int len;
}SString;

//(1)��˳��s������ֵΪch1���ַ�ת����ch2���ַ������в���ch1��ch2����ľ�Ϊ�ַ�����
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

 

//(2)��˳��s�������ַ������෴�Ĵ����Դ����s�У���ʵ���ַ��������á�
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

 

//(3)��˳��s��ɾ����ֵ����ch�������ַ������в���ch�����Ϊ�ַ�����
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
	Scanf(&a);		//���� i like apple 
	Print(a);
	charReplace(&a,'i','I');
	Print(a);
	charDelete(&a,'l');
	Print(a);
	strInverse(&a);
	Print(a);
}
