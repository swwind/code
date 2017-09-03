#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int n, l, m;
struct zero{
	int a[120];
	zero(){memset(a, 0, sizeof(int)*120);}
	zero(bool flag){memset(a, 0, sizeof a);a[0]=1;}
	int& operator [] (int i){return a[i];}
	friend zero operator * (zero a, zero b) {
		zero c;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < m; j++)
				c[(i+j)%m] += a[i]*b[j];
		return c;
	}
	friend zero operator ^ (zero a, int b) {
		zero c(true);
		for(;b;b>>=1,a=a*a)if(b&1)c=a*c;
		return c;
	}
	void print(){
		for(int i = 0; i < m; i++)
			printf("%d ", a[i]);
		puts("");
	}
};
int a[N], b[N], c[N];
int main(int argc, char const *argv[]){
	n = read(), l = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) b[i] = read();
	for(int i = 1; i <= n; i++) c[i] = read();
	zero ans;
	for(int i = 1; i <= n; i++) ans[b[i]%m] += n;
	ans.print();
	ans = ans^(l-1);
	ans.print();
	return 0;
}
