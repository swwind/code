#include <bits/stdc++.h>
#define zyy 1000000007
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n, m, ans[30020][3];
int dfs(int x, int y, int t){
	int cnt = n;
	while(cnt > 0){
		if(x == y) return cnt == t+1;
		if(x > y){
			y = x-y; x = x-y;
			cnt -= 2; t = (t+1)%3;
		}
		else{
			x = y-x; y = y-x;
			cnt --; t = (t+2)%3;
		}
	}
	return 0;
}
int main(){
	for(n=read(),m=read();~n|~m;n=read(),m=read()){
		int t1 = n%3, t0 = (t1+2)%3, t2 = (t1+1)%3, tot = 0;
		for(int i = 1; i < m; i++) if(dfs(i, m-i, t0))
			ans[++tot][t0] = m, ans[tot][t1] = i, ans[tot][t2] = m-i;
		printf("%d\n", tot);
		if(t0 != 1) for(int i = 1; i <= tot; i++)
			printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
		else for(int i = tot; i; i--)
			printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
	}
}