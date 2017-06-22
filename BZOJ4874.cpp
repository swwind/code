#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int fa[N], sz[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= m; i++) fa[i] = i;
	for(int i = 1; i <= n; i++){
		int x = find(read()), y = find(read());
		if(x == y) sz[x]++;
		else fa[x] = y, sz[y] += sz[x]+1;
	}
	int ans = 0;
	for(int i = 1; i <= m; i++)
		if(fa[i] == i && (sz[i]&1)) ans++;
	printf("%d\n", ans);
	return 0;
}