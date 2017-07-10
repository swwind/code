#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline void write(int x){
	if(9<x) write(x/10);
	putchar(x%10+'0');
}
struct huge{
	#define N_huge 2000
	#define base 100000000
	static char s[N_huge*10];
	int a[N_huge];int len;
	void clear(){len=1;a[len]=0;}
	huge(){clear();}
	inline void del(huge b){
		for(register int i=1;i<=len;++i){
			a[i]-=b.a[i];
			if(a[i] < 0)
				a[i] += base,
				a[i+1]--;
		}
		while (len>1&&!a[len])len--;
	}
	inline bool odd(){return !(a[1]&1);}
	inline void split(){
		int d = 0;
		for(register int i = len; i; --i){
			if(d) a[i]+=base;
			d=a[i]&1;
			a[i]>>=1;
		}
		if(!a[len])len--;
	}
	inline void db(){
		for(register int i = 1; i <= len; i++){
			a[i]<<=1;
			if(base<a[i])a[i+1]++,a[i]-=base;
		}
		if(a[len+1])len++;
	}
	inline bool operator <(huge b){
		if (len<b.len)return 1;
		if (len>b.len)return 0;
		for (register int i=len;i;--i){
			if (a[i]<b.a[i])return 1;
			if (a[i]>b.a[i])return 0;
		}
		return 0;
	}
	inline huge str(char s[]){
		int l=strlen(s);
		int x=0,y=1;len=0;
		for (register int i=l-1;i>=0;--i){
			x+=(s[i]-'0')*y;
			y*=10;
			if(y==base)a[++len]=x,x=0,y=1;
		}
		if (!len||x)a[++len]=x;
	}
	inline void read(){
		scanf("%s",s);this->str(s);
	}
	inline bool isEmpty(){
		return len==1&&!a[len];
	}
	inline void print(){
		write(a[len]);
		for (register int i=len-1;i;--i){
			for (register int j=base/10;j>=10;j/=10)
				if (a[i]<j)putchar('0');
					else break;
			write(a[i]);
		}
		putchar('\n');
	}
};char huge::s[N_huge*10];
inline void swap(huge &a, huge &b){
	huge x = a;a = b;b = x;
}
int main(){
	huge a, b, c;
	a.read(); b.read();int g = 0;
	while(!b.isEmpty()){
		if(a < b) swap(a, b);
		while(a.odd() && b.odd()) g++, a.split(), b.split();
		while(a.odd()) a.split();
		while(b.odd()) b.split();
		a.del(b);
		swap(a, b);
	}
	while(g--)a.db();
	a.print();
	return 233;
}
/*
m = (int)(input())
n = (int)(input())
c = m % n
while c != 0L:
	m = n
	n = c
	c = m % n
print n
*/
