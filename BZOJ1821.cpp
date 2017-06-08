#include <bits/stdc++.h>
#define N 2005
#define ll double
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct node{
	int x, y;
	ll dis;
	bool operator < (const node &b) const {
		return dis < b.dis;
	}
}a[N*N];
int x[N], y[N], cnt, fa[N];
ll sqr(ll a){return a*a;}
ll dis(int i, int j){
	return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++){
		x[i] = read(); y[i] = read(); fa[i] = i;
		for(int j = 1; j < i; j++)
			a[++cnt] = (node){i, j, dis(i, j)};
	}
	sort(a+1, a+cnt+1); int s = 0;
	for(int i = 1; i <= cnt; i++){
		int fx = find(a[i].x);
		int fy = find(a[i].y);
		if(fx == fy) continue;
		fa[fx] = fy;
		if(n < m+(++s))
			return printf("%.2lf\n", a[i].dis);
	}
}