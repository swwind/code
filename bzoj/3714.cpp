#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct node{
	int x, y, v;
	bool operator < (const node &b) const {
		return v < b.v;
	}
}e[4000020];
int cnt, fa[2020];
long long ans;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	int n = read();
	for(int i = 0; i < n; i++)
		for(int j = i+1; j <= n; j++)
			e[++cnt] = (node){i, j, read()};
	sort(e+1, e+cnt+1);
	for(int i = 0; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= cnt; i++){
		int a = find(e[i].x), b = find(e[i].y);
		if(a == b) continue;
		ans += e[i].v; fa[a] = b;
	}
	printf("%lld\n", ans);
}