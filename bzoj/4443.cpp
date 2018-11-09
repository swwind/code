#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int mn[300], n, m, k, head[300], mx, cnt, p[300], f[300], a[300][300];
struct node{
	int to, nxt;
}e[70000];
void ins(int x, int y){
	e[++cnt] = (node){y, head[x]};
	head[x] = cnt;
}
int dfs(int x, int st){
	for(int i = head[x]; i; i = e[i].nxt){
		int to = e[i].to;
		if(p[to] != st){
			p[to] = st;
			if(!f[to] || dfs(f[to], st)){
				f[to] = x;
				return 1;
			}
		}
	}
	return 0;
}
int solve(int l, int r){
	if(l > r) return l; cnt = 0;
	int mid = l + r >> 1, ans = 0;
	memset(head, 0, sizeof head);
	memset(p, 0, sizeof p);
	memset(f, 0, sizeof f);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i][j] <= mid) ins(i, j);
	for(int i = 1; i <= n; i++)
		ans += dfs(i, i);
	if(ans < n-k+1) return solve(mid+1, r);
	else return solve(l, mid-1);
}
int main(){
	n = read(); m = read(); k = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			mx = max(mx, a[i][j] = read());
	printf("%d\n", solve(1, mx));
}