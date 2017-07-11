#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define clr(x, c) memset(x, c, sizeof(x))
#define REP(x) for(edge* e = head[x]; e; e = e->next)
#define foreach(e, x) for(__typeof(x.begin()); e != x.end(); e++)
#define mod(x) ((x) %= MOD)
using namespace std;
const int maxn = 1509, maxm = 5009;
const int MOD = 1000000007;
struct edge {
	int to, w, num;
	edge* next;
} E[maxm], *pt = E, *head[maxn];
inline void addedge(int u, int v, int d, int _) {
	pt->to = v, pt->w = d, pt->num = _;
	pt->next = head[u];
	head[u] = pt++;
}
struct node {
	int x, w;
	bool operator < (const node &t) const {
		return w > t.w;
	}
};
int d[maxn], cnt[maxn], ans[maxm], A[maxn], B[maxn], n;
void dijkstra(int S) {
	rep(i, n) d[i] = MOD;
	d[S] = 0;
	priority_queue<node> Q;
	Q.push( (node) {S, 0} );
	while(!Q.empty()) {
		node t = Q.top(); Q.pop();
		if(d[t.x] != t.w) continue;
		REP(t.x) if(d[t.x] + e->w < d[e->to]) {
			d[e->to] = d[t.x] + e->w;
			Q.push( (node) {e->to, d[e->to]} );
		}
	}
}
// get B
int dp(int x) {
	if(B[x]) return B[x];
	REP(x) if(d[e->to] == d[x] + e->w)
	    mod(B[x] += dp(e->to));
	return ++B[x];
}
//get A
void DFS(int x) {
	REP(x) if(d[e->to] == d[x] + e->w) {
		mod(A[e->to] += A[x]);
		if(!--cnt[e->to]) DFS(e->to);
	}
}
void dfs(int x) {
	REP(x) if(d[e->to] == d[x] + e->w)
		if(!cnt[e->to]++) dfs(e->to);
}
void work(int x) {
	dijkstra(x);
	clr(cnt, 0), clr(A, 0), clr(B, 0);
	dfs(x), dp(x), A[x] = 1, DFS(x);
	rep(i, n)
	    REP(i) if(d[i] + e->w == d[e->to])
	        mod(ans[e->num] += 1LL * A[i] * B[e->to] % MOD);
}
inline int read() {
	char c = getchar();
	for(; !isdigit(c); c = getchar());
	int ans = 0;
	for(; isdigit(c); c = getchar())
	    ans = ans * 10 + c - '0';
	return ans;
}
int main() {
	freopen("test.in", "r", stdin);
	int m;
	clr(head, 0), clr(ans, 0);
	cin >> n >> m;
	rep(i, m) {
		int u = read() - 1, v = read() - 1, w = read();
		addedge(u, v, w, i);
	}
	rep(i, n) work(i);
	for(int* t = ans; t != ans + m; t++)
	    printf("%d\n", *t);
	return 0;
}