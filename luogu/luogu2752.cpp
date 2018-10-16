#include <bits/stdc++.h>
#define N 60
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[N][N], del, n, ans1[N], ans2[N], vis[N], ntr[N];
bool dfs(int x){
	if(x == n) return 1;
	if(vis[x]) return 0;
	vis[x] = 1;
	for(int i = 1; i <= n; i++)
		if(i != del && a[x][i] && dfs(i)) return 1;
	return 0;
}
void bfs(int x){
	if(x == n) return;
	ntr[x] = 1;
	for(int i = 1; i <= n; i++)
		if(a[x][i] && !ntr[i]) bfs(i);
}
int main(int argc, char const *argv[]){
	int x, y;
	while((x = read()) != -1 && ++n){
		if(x == -2) continue;
		a[n][x+1] = 1;
		while((y = read()) != -2)
			a[n][y+1] = 1;
	}
	// printf("%d\n", n);
	for(int i = 2; i < n; i++){
		del = i;
		memset(vis, 0, sizeof(int)*N);
		if(!dfs(1)){
			ans1[++ans1[0]] = i;
			memset(ntr, 0, sizeof(int)*N);
			bfs(i); bool flag = 0;
			for(int j = 1; j <= n && !flag; j++)
				if(vis[j] && ntr[j] && j != i)
					flag = 1;
			if(!flag) ans2[++ans2[0]] = i;
		}
	}
	for(int i = 0; i <= ans1[0]; i++) printf("%d%c", ans1[i]-!!i, " \n"[i == ans1[0]]);
	for(int i = 0; i <= ans2[0]; i++) printf("%d%c", ans2[i]-!!i, " \n"[i == ans2[0]]);
	return 0;
}