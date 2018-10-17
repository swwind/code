#include <bits/stdc++.h>
#define N 500020
#define M 1000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int to[M<<1], nxt[M<<1], head[N], cnt;
void ins(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
int fuck[N], pos[N], hash[N], vis[N], q[N], ans;
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= m; i++)
		ins(read(), read());
	for(int i = n; i; i--){
		int t = 0;
		for(int j = 1; j <= n; j++)
			if(!vis[j] && pos[t] <= pos[j]) t = j;
		vis[t] = 1; q[i] = t;
		for(int j = head[t]; j; j = nxt[j])
			pos[to[j]]++;
	}
	for(int i = n; i; i--){
		int t = q[i], k = 1;
		for(int j = head[t]; j; j = nxt[j])
			hash[fuck[to[j]]] = i;
		while(hash[k] == i) k++;
		fuck[t] = k;
		ans = max(ans, k);
	}
	printf("%d\n", ans);
	return 0;
}