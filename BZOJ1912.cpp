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
int to[N<<1], nxt[N<<1], head[N], val[N<<1], cnt = 1;
int sum, mx, s1[N], s2[N];
void ins(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; val[cnt] = 1;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; val[cnt] = 1;
}
int dfs(int x, int fa){
	int mx1 = 0, mx2 = 0;
	for(int i = head[x]; i; i = nxt[i])if(to[i]!=fa){
		int v = val[i]+dfs(to[i], x);
		if(v > mx1) mx2 = mx1, mx1 = v, s2[x] = s1[x], s1[x] = i;
		else if(v > mx2) mx2 = v, s2[x] = i;
	}
	if(mx1+mx2 > sum) sum = mx1+mx2, mx = x;
	return mx1;
}
int main(){
	int n = read(), k = read(), ans = n-1<<1;
	for(int i = 1; i < n; i++) ins(read(), read());
	dfs(1, 0); ans = ans-sum+1;
	if(k > 1){
		sum = 0;
		for(int i = s1[mx]; i; i = s1[to[i]]) val[i] = val[i^1] = -1;
		for(int i = s2[mx]; i; i = s1[to[i]]) val[i] = val[i^1] = -1;
		dfs(1, 0); ans = ans-sum+1;
	}
	printf("%d\n", ans);
}