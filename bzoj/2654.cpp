#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct node{
	int x, y, c, t;
	friend bool operator < (const node &a, const node &b){
		return a.c < b.c;
	}
}a[100020];
int vis[100020], fa[50020], ans, tot;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	int n = read(), m = read(), need = read();
	for(int i = 1; i <= m; i++){
		a[i].x = read(); a[i].y = read();
		a[i].c = read(); a[i].t = read();
	}
	for(int i = 1; i <= n; i++) fa[i] = i;
	sort(a+1, a+m+1);
	for(int i = 1; i <= m; i++){
		if(a[i].t) continue; vis[i] = 1;
		int x = find(a[i].x), y = find(a[i].y);
		if(x == y) continue; fa[x] = y;
		ans += a[i].c; tot++;
		if(!--need) break;
	}
	for(int i = 1; i <= m; i++)if(!vis[i]){
		int x = find(a[i].x), y = find(a[i].y);
		if(x == y) continue; fa[x] = y;
		ans += a[i].c; if(++tot == n-1) break;
	}
	printf("%d\n", ans);
}