#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct huge{
	#define N_huge 2000
	#define base 100000000
	static char s[N_huge*10];
	ll a[N_huge];int len;
	void clear(){memset(a,0,sizeof a);len=1;a[len]=0;}
	huge(){clear();}
	inline bool odd(){return a[1]&1;}
	inline void split(){
		int d = 0;
		for(register int i = len; i; --i){
			if(d) a[i]+=base;
			d=a[i]&1;
			a[i]>>=1;
		}
		if(len > 1 && !a[len])len--;
	}
	inline void db(){
		for(register int i = 1; i <= len; i++)
			a[i] <<= 1;
		for(register int i = 1; i <= len; i++) {
			if (a[i] >= base) {
				a[i + 1] ++;
				a[i] -= base;
			}
		}
		if(a[len+1])len++;
	}
	friend bool operator < (const huge &a, const huge &b) {
		if (a.len < b.len) return true;
		if (b.len < a.len) return false;
		for (int i = a.len; i; i--) {
			if (a.a[i] < b.a[i]) return true;
			if (b.a[i] < a.a[i]) return false;
		}
		return false;
	}
	huge(int x){clear();a[1]=x;}
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
		printf("%d", a[len]);
		for (int i = len-1; i; i--)
			printf("%08d", a[i]);
		puts("");
	}
};char huge::s[N_huge*10];
int main(int argc, char const *argv[]) {
	huge a, b;
	a.read();
	b.read();
	int cnt = 0, tot = 0;
	while (!b.isEmpty()) {
		if (b.odd()) cnt++;
		tot++;
		b.split();
	}
	if (a < tot) puts("0");
	else {
		a = 1;
		while (cnt--)
			a.db();
		a.print();
	}
	return 0;
}