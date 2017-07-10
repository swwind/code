#include <bits/stdc++.h>
#define N 100007
#define zyy 1000000007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int fa[N][20], vis[N];
int find(int x, int p){return fa[x][p]==x?x:fa[x][p]=find(fa[x][p], p);}
int log(int x){int sum=0;for(;x>1;x/=2)sum++;return sum;}
void solve(int l, int r, int p){
	if(find(l, p) == find(r, p)) return;
	fa[fa[l][p]][p] = fa[r][p];
	if(!p) return;
	solve(l, r, p-1);
	solve(l+(1<<p-1), r+(1<<p-1), p-1);
}
int main(){
	int n = read(), m = read();
	for(int j = 0; (1<<j) <= n; j++)
		for(int i = 1; i+(1<<j)-1 <= n; i++)
			fa[i][j] = i;
	for(int i = 1; i <= m; i++){
		int l1 = read(), r1 = read(), l2 = read(), r2 = read();
		int p = log(r1-l1+1);
		solve(l1, l2, p);
		solve(r1-(1<<p)+1, r2-(1<<p)+1, p);
	}
	int ans = 9;
	vis[find(1, 0)] = 1;
	for(int i = 2; i <= n; i++)
		if(!vis[find(i, 0)]){
			vis[find(i, 0)] = 1;
			ans = 10ll*ans%zyy;}
	printf("%d\n", ans);
}