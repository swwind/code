#include <bits/stdc++.h>
#define N 2020
using namespace std;

int n, m, k;
int a[N], b[N];

namespace dinic {
#define N_NODE 3000020
int to[N_NODE<<1], nxt[N_NODE<<1], head[N_NODE], val[N_NODE<<1], dep[N_NODE], cnt = 1, st, ed, q[N_NODE];
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
}

int px[N], py[N];
int st[1000020], ed[1000020];
int cx[1000020], cy[1000020];
int now;

int mp[2020][2020];

// pair<int, int> ppx[2020], ppy[2020];
// int okx[2020], oky[2020];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  memset(mp, -1, sizeof mp);

  for (int i = 1; i <= k; ++ i) {
    st[i] = ++ now;
    ed[i] = ++ now;
  }
  for (int i = 1; i <= n; ++ i) {
    scanf("%d", &a[i]);
    cx[a[i]] ++;
    px[i] = ++ now;
    dinic::insert(st[a[i]], px[i], 1);
  }
  for (int i = 1; i <= n; ++ i) {
    scanf("%d", &b[i]);
    cy[b[i]] ++;
    py[i] = ++ now;
    dinic::insert(py[i], ed[b[i]], 1);
  }

  int start_cnt = dinic::cnt + 1;

  for (int i = 1; i <= m; ++ i) {
    int x, y;
    scanf("%d%d", &x, &y);
    mp[x][y] = 0;
    if (a[x] == b[y]) {
      dinic::insert(px[x], py[y], 1);
    }
    // else if (a[x] < b[y]) {
    //   ppx[x] = make_pair(x, y);
    // } else {
    //   ppy[y] = make_pair(x, y);
    // }
  }

  long long res = 0;

  for (int i = 1; i <= k; ++ i) {
    if (cx[i] + cy[i] == 0) continue;
    int ans = 0;
    dinic::st = st[i]; dinic::ed = ed[i];
    while (dinic::bfs()) {
      ans += dinic::dfs(st[i], 1e9);
    }
    long long number = cx[i] + cy[i] - ans;
    res += number * i;
    // printf("k = %d, v = %d\n", i, ans);
  }

  printf("%lld\n", res);

  // for (int cnt = start_cnt; cnt <= dinic::cnt; cnt += 2) {
  //   int x = dinic::to[cnt^1] - px[1] + 1;
  //   int y = dinic::to[cnt]   - py[1] + 1;
  //   // printf("%d, %d\n", x, y);
  //   if (dinic::val[cnt] == 0) {
  //     mp[x][y] = a[x];
  //     // okx[x] = 1;
  //     // oky[y] = 1;
  //     // printf("used\n");
  //   }
  // }

  // for (int i = 1; i <= n; ++ i) {
  //   if (!okx[i]) {
  //     int x = ppx[i].first;
  //     int y = ppx[i].second;
  //     mp[x][y] = a[x];
  //   }
  //   if (!oky[i]) {
  //     int x = ppy[i].first;
  //     int y = ppy[i].second;
  //     mp[x][y] = b[y];
  //   }
  // }

  // for (int i = 1; i <= n; ++ i) {
  //   for (int j = 1; j <= n; ++ j) {
  //     if (mp[i][j] == -1) {
  //       printf("-%c", " \n"[j == n]);
  //     } else {
  //       printf("%d%c", mp[i][j], " \n"[j == n]);
  //     }
  //   }
  // }
}