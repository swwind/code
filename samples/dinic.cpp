// 网络流

#include <bits/stdc++.h>
#define N 10020
#define M 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
// WARN: N is the size of the points
int to[M<<1], nxt[M<<1], head[N], val[M<<1], dep[N], cnt = 1, st, ed, q[N];
void insert(int x, int y, int z) {
	to[++cnt] = y; nxt[cnt] = head[x]; val[cnt] = z; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; val[cnt] = 0; head[y] = cnt;
}
int bfs() {
	memset(dep, 0, sizeof dep);
	int l = 0, r = 1; q[1] = st; dep[st] = 1;
	while (l < r){
		int x = q[++l];
		for (int i = head[x]; i; i = nxt[i])
			if (val[i] && !dep[to[i]]){
				q[++r] = to[i];
				dep[to[i]] = dep[x]+1;
			}
	}
	return dep[ed];
}
int dfs(int x, int f) {
	if (x == ed) return f;
	int sum = 0;
	for (int i = head[x]; i; i = nxt[i]){
		if (val[i] && dep[to[i]] == dep[x]+1){
			int w = dfs(to[i], min(f-sum, val[i]));
			val[i] -= w; val[i^1] += w;
			sum += w; if(sum == f) return f;
		}
	}
	if (!sum) dep[x] = 0;
	return sum;
}
int main() {
	int n = read(), m = read();
	st = read(), ed = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		insert(x, y, read());
	}
	int ans = 0;
	while (bfs())
		ans += dfs(st, 1<<30);
	cout << ans << endl;
}