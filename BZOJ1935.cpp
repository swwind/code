#include <bits/stdc++.h>
#define N 10000007
#define M 500020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int c[N], n, m, cnt, ans[M];
int ask(int x){int ans=0;for(;x;x^=x&-x)ans+=c[x];return ans;}
void add(int x, int v){for(;x<=n;x+=x&-x)c[x]+=v;}
struct tree{
	int x, y;
	tree(int x=0, int y=0):x(x),y(y){}
}tr[M];
bool operator < (const tree &a, const tree &b) {
	return a.x < b.x;
}
struct asks{
	int x, y, id, f;
	asks(){}
	asks(int x, int y, int id, int f):x(x),y(y),id(id),f(f){}
}ak[M<<2];
bool operator < (const asks &a, const asks &b) {
	return a.x < b.x;
}
int main(){
	n = read(); m = read();
	for(int i = 1; i <= n; i++)
		tr[i].x = read()+1, tr[i].y = read()+1;
	for(int i = 1; i <= m; i++){
		int a = read(), b = read(), c = read()+1, d = read()+1;
		ak[++cnt] = asks(c, d, i, 1);
		ak[++cnt] = asks(c, b, i,-1);
		ak[++cnt] = asks(a, d, i,-1);
		ak[++cnt] = asks(a, b, i, 1);
	}
	sort(tr+1, tr+n+1);
	sort(ak+1, ak+cnt+1);
	for(int i = 1, j = 1; i <= cnt; i++){
		while(j <= n && tr[j].x <= ak[i].x) add(tr[j++].y, 1);
		ans[ak[i].id] += ask(ak[i].y)*ak[i].f;
	}
	for(int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
}