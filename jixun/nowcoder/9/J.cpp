#include <bits/stdc++.h>
using namespace std;

// N E S W
int a[4][4];
int b[12];

const int N = 0;
const int E = 1;
const int S = 2;
const int W = 3;

// WARN: N is the size of the points
int to[2000], nxt[2000], head[2000], val[2000], dep[2000], cnt = 1, st, ed, q[2000];
void insert(int x, int y, int z) {
	to[++cnt] = y; nxt[cnt] = head[x]; val[cnt] = z; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; val[cnt] = 0; head[y] = cnt;
}
int bfs() {
	memset(dep, 0, sizeof(dep));
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

void clear() {
  cnt = 1;
  memset(head, 0, sizeof(head));
}

int p[4][4];
const int inf = 1<<30;

int dinic() {
  int ans = 0;
	while (bfs())
		ans += dfs(st, inf);
  return ans;
}

#define add_edge(x, y) \
  insert(x, y + 16, inf), insert(y, x + 16, inf)

int main() {
  int T;
  scanf("%d", &T);

  for (int i = 0; i < 4; ++ i) {
    for (int j = 0; j < 4; ++ j) {
      p[i][j] = i * 4 + j;
    }
  }
  st = 32;
  ed = 33;

  while (T --) {
    clear();
    for (int i = 0; i < 4; ++ i) {
      for (int j = 0; j < 4; ++ j) {
        scanf("%d", &a[i][j]);
      }
    }
    int ans = 0;
    ans = max(ans, a[S][E]);
    ans = max(ans, a[E][N]);
    ans = max(ans, a[N][W]);
    ans = max(ans, a[W][S]);

    add_edge(p[N][S], p[S][N]);
    add_edge(p[W][E], p[E][W]);

    add_edge(p[S][N], p[W][N]);
    add_edge(p[E][W], p[S][W]);
    add_edge(p[N][S], p[E][S]);
    add_edge(p[W][E], p[N][E]);

    add_edge(p[S][N], p[S][W]);
    add_edge(p[E][W], p[E][S]);
    add_edge(p[N][S], p[N][E]);
    add_edge(p[W][E], p[W][N]);

    add_edge(p[S][W], p[N][E]);
    add_edge(p[E][S], p[W][N]);

    insert(st, p[S][N], a[S][N]);
    insert(st, p[S][W], a[S][W]);
    insert(st, p[E][W], a[E][W]);
    insert(st, p[E][S], a[E][S]);
    insert(st, p[N][S], a[N][S]);
    insert(st, p[N][E], a[N][E]);
    insert(st, p[W][E], a[W][E]);
    insert(st, p[W][N], a[W][N]);

    insert(p[S][N] + 16, ed, a[S][N]);
    insert(p[S][W] + 16, ed, a[S][W]);
    insert(p[E][W] + 16, ed, a[E][W]);
    insert(p[E][S] + 16, ed, a[E][S]);
    insert(p[N][S] + 16, ed, a[N][S]);
    insert(p[N][E] + 16, ed, a[N][E]);
    insert(p[W][E] + 16, ed, a[W][E]);
    insert(p[W][N] + 16, ed, a[W][N]);

    int sum = a[S][N] + a[S][W] + a[E][W] + a[E][S] + a[N][S] + a[N][E] + a[W][E] + a[W][N];

    printf("%d\n", max(ans, sum - dinic() / 2));

    // for (int i = 1; i <= cnt; i += 2) {
      // printf("? -> %d cost: %d/%d\n", to[i], val[i], val[i]+val[i^1]);
    // }

    // b[0] = a[N][S] + a[S][N]
    // b[1] = a[W][E] + a[E][W]

    // b[2] = a[S][N] + a[W][N]
    // b[3] = a[E][W] + a[S][W]
    // b[4] = a[N][S] + a[E][S]
    // b[5] = a[W][E] + a[N][E]

    // b[6] = a[S][N] + a[S][W]
    // b[7] = a[E][W] + a[E][S]
    // b[8] = a[N][S] + a[N][E]
    // b[9] = a[W][E] + a[W][N]

    // b[10] = a[S][W] + a[N][E]
    // b[11] = a[E][S] + a[W][N]

    // a[S][N] <= b[0] + b[2] + b[6]
    // a[S][W] <= b[3] + b[6] + b[10]
    // a[E][W] <= b[1] + b[3] + b[7]
    // a[E][S] <= b[4] + b[7] + b[11]
    // a[N][S] <= b[0] + b[4] + b[8]
    // a[N][E] <= b[5] + b[8] + b[10]
    // a[W][E] <= b[1] + b[5] + b[9]
    // a[W][N] <= b[2] + b[9] + b[11]
    
    // minimal sigma b[0..11]
  }
}
