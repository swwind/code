#include <bits/stdc++.h>
#define ll long long
#define mod 989381
#define N 500020
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int d[N], fa[N], sz[N];
map<int, bool>vis[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(int argc, char const *argv[]){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
	for(int i = 1; i <= m; i++){
		int x = read(), y = read(); vis[x][y] = 1;
		int xx = find(x), yy = find(y);
		if(xx != yy){
			fa[xx] = yy, sz[yy] += sz[xx], d[x]++, d[y]++;
			if(d[x] > 2 || d[y] > 2) exit(puts("0")&0);
		}
		else if(!vis[y][x]) exit(puts("0")&0);
	}
	ll cnt = 0, tot = 1, faq = 1;
	for(int i = 1; i <= n; i++)
		if(fa[i] == i){
			cnt++;
			if(sz[i] > 1) tot = tot*2%mod;
		}
	for(int i = 2; i <= cnt; i++) faq = faq*i%mod;
	printf("%lld\n", tot*faq%mod);
	return 0;
}