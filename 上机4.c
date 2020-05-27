//��ƺ���������������˳���ַ����Ĳ�ַ���
//���������ַ���A��B�Ĳ�ַ���A-B��
//�а�����������д�����A�е�����B�е��ַ����ɵ��ַ����У�
//ע���ַ����е��ַ���Ӧ�ظ�����
//�����ַ���"abcadecfge"���ַ���"bmqgxvwf"�Ĳ�ַ���Ϊ"acde"��
//������������ʾ��


/*������˳���ַ����Ĳ*/
/*����ͷ�ļ�*/
#include <stdio.h>
#include <stdlib.h>
/*���峣��*/
#define	TRUE	1
#define	FALSE	0
#define	OK		1
#define	ERROR	0
#define MAXLEN 100/*��󴮳���*/

/*˳�򴮽ṹ����*/
typedef struct {          
    char ch[MAXLEN];
    int len;
}SString;


/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/
/*���������*/
void output(SString *s);
/*�Ѵ�����chars��ֵ����s*/
int strAssign(SString *s,char chars[]);
/*�����а����ڴ�s�ж�t��û�е��ַ����ɵ��´�r*/
int strDifference(SString s,SString t,SString *r);
/*���������������͵Ĳ�������������ʹ�õ����������ܺ���*/

/*���������*/
void output(SString *s){
	int i;
	for(i=0;i<s->len;i++){
		printf("%c",s->ch[i]);
	} 
	putchar('\n');
}


/*�Ѵ�����chars��ֵ����s*/
int strAssign(SString *s,char chars[]){
	int i;
	for(i=0;chars[i]!='\0'&&i<MAXLEN;i++){
		s->ch[i]=chars[i];
	}
	s->len=s->len+i;
	return 0;
}


/*�����а����ڴ�s�ж�t��û�е��ַ����ɵ��´�r*/
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
	
	for(i=0;i<s.len;i++){			//i��s���±� ����0��ʼ 
		for(j=i+1;j<s.len;j++){		// jʱ��s����һ���±꣬ÿ�δ�i+i��ʼ 
			if(s.ch[i]==s.ch[j]){	//���αȶ�s[i]��s[j]�����ȼ����Ƚ�s[i]��s[j+1]... 
				break;				//����ȣ�����jѭ��������ͨ���Ƚ�j�ǲ��ǵ����s.len�� 
			}						//s[i]��s[i]�����Ԫ����û���ظ� 
		}							//��j==s.len,˵��s[i]�ͺ��涼����һ��û���ظ� 
		if(j==s.len){				//������û���ظ� 
			for(k=0;k<t.len;k++){	// s[i]û�������ظ�����������t��û���ظ� 
				if(s.ch[i]==t.ch[k])//�����������˼һ�� 
					break;
			}
			if(k==t.len)			//s[i]��t���е�û���ظ� 
				strInsert(&x,s.ch[i]);	 //��s[i]����x�� 
		}
	}
	*r=x;							//���r 
	return 1;
}


/*������������ͨ�����������ø������������͵Ĳ����͹��ܺ���*/
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
