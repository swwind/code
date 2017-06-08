#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int head[N], cnt, tot, fa[N], sz[N], top[N], son[N], ls[N], rs[N], to[N], nxt[N];
void ins(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
}
void dfs(int x){
	sz[x] = 1;
	for(int i = head[x]; i; i = nxt[i]){
		dfs(to[i]); sz[x] += sz[to[i]];
		if(sz[to[i]] > sz[son[x]])
			son[x] = to[i];
	}
}
void build(int x, int tp){
	top[x] = tp; ls[x] = ++tot;
	if(son[x]) build(son[x], tp);
	for(int i = head[x]; i; i = nxt[i])
		if(to[i] != son[x]) build(to[i], to[i]);
	rs[x] = tot;
}
int sum[N<<2], tag[N<<2], n;
int add(int x, int l, int r, int L, int R, int tp){
	int ans = 0;
	if(L <= l && r <= R){
		ans = tp ? r-l+1-sum[x] : sum[x];
		tag[x] = tp; sum[x] = (r-l+1)*tp;
	}
	else{
		int mid = l + r >> 1, lc = x<<1, rc = x<<1|1;
		if(tag[x] >= 0){
			tag[rc] = tag[lc] = tag[x];
			sum[lc] = tag[x]*(mid-l+1);
			sum[rc] = tag[x]*(r-mid);
			tag[x] = -1;
		}
		if(L <= mid) ans += add(lc, l, mid, L, R, tp);
		if(R > mid) ans += add(rc, mid+1, r, L, R, tp);
		sum[x] = sum[lc]+sum[rc];
	}
	return ans;
}
int ask(int x){
	int f = top[x], ans = 0;
	while(f != 1){
		ans += add(1, 1, n, ls[f], ls[x], 1);
		x = fa[f]; f = top[x];
	}
	return ans+add(1, 1, n, 1, ls[x], 1);
}
char str[20];
int main(){
	memset(tag, -1, sizeof tag);
	n = read();
	for(int i = 2; i <= n; i++)
		ins(fa[i]=read()+1, i);
	dfs(1);build(1, 1);
	int T = read();
	while(T--){
		scanf("%s", str);int x = read()+1;
		if(str[0] == 'u') printf("%d\n", add(1, 1, n, ls[x], rs[x], 0));
		else printf("%d\n", ask(x));
	}
	return 0;
}