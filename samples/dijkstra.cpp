// dijkstra 求最短路

#include <bits/stdc++.h>
#define N 100020
#define M 500020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int head[N], to[M], nxt[M], val[M], cnt;
void insert(int x, int y, int z) {
	to[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
	val[cnt] = z;
}
struct node {
	int to, len;
	friend bool operator < (const node &a, const node &b) {
		return a.len > b.len;
	}
};
priority_queue<node> q;
int dis[N];
void dijkstra(int x) {
	memset(dis, 63, sizeof dis);
	dis[x] = 0;
	q.push((node){x, 0});
	while (!q.empty()) {
		node p = q.top();
		q.pop();
		if (dis[p.to] != p.len) continue;
		x = p.to;
		for (int i = head[x]; i; i = nxt[i]) {
			if (dis[x] + val[i] < dis[to[i]]) {
				dis[to[i]] = dis[x] + val[i];
				q.push((node){to[i], dis[to[i]]});
			}
		}
	}
}
int main(int argc, char const *argv[]) {
	int n = read(), m = read(), st = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		insert(x, y, read());
	}
	dijkstra(st);
	for (int i = 1; i <= n; i++)
		printf("%d ", dis[i] == dis[0] ? 2147483647 : dis[i]);
	return 0;
}