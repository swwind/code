#include <bits/stdc++.h>
#define N 30020

using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

const int kMaxPoints = 200020;
const int kMaxEdges = 100000020;

// WARN: N is the size of the points
int to[kMaxEdges], nxt[kMaxEdges], head[kMaxPoints], val[kMaxEdges], dep[kMaxPoints], cnt = 1, st, ed, q[kMaxPoints];
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

int dinic() {
  int ans = 0;
  while (bfs()) {
    ans += dfs(st, 1<<30);
  }
  return ans;
}

int pt[N<<2];
int now;

int les[N];

void build(int x, int l, int r) {
  if (l == r) {
    pt[x] = l;
    return;
  }
  pt[x] = ++ now;
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x<<1|1, mid+1, r);
  insert(pt[x], pt[x << 1], 1<<30);
  insert(pt[x], pt[x<<1|1], 1<<30);
}

void query_link(int x, int L, int R, int l, int r, int s) {
  if (l == L && r == R) {
    insert(s, pt[x], 1);
    return;
  }
  int mid = (L + R) >> 1;
  if (r <= mid) query_link(x<<1, L, mid, l, r, s);
  else if (l > mid) query_link(x<<1|1, mid+1, R, l, r, s);
  else {
    query_link(x<<1, L, mid, l, mid, s);
    query_link(x<<1|1, mid+1, R, mid+1, r, s);
  }
}
int tmp[105];
int n;

int seek(int x, int f) {
  // printf("%d, %d\n", x, f);
  if (x <= n) {
    return x;
  }
  for (int i = head[x]; i; i = nxt[i]) {
    if (f == to[i]) continue;
    if (i % 2 == 0 && val[i^1] > 0) {
      int res = seek(to[i], x);
      if (res) {
        -- val[i^1];
        return res;
      }
    }
  }
  return 0;
}

int main() {

  n=read();
  now = n;
  for (int i = 1; i <= n; ++ i) les[i] = ++ now;
  st = ++ now;
  ed = ++ now;

  for (int i = 1; i <= n; ++ i) {
    insert(st, les[i], 1);
    insert(i, ed, 1);
  }
  build(1, 1, n);

  for (int i = 1; i <= n; ++ i) {
    int k = read();
    for (int j = 1; j <= k; ++ j) {
      tmp[j] = read();
    }
    sort(tmp + 1, tmp + k + 1);
    int st = 1;
    for (int j = 1; j <= k; ++ j) {
      if (st < tmp[j]) {
        query_link(1, 1, n, st, tmp[j] - 1, les[i]);
      }
      st = tmp[j] + 1;
    }
    if (st <= n) {
      query_link(1, 1, n, st, n, les[i]);
    }
  }
  cerr << clock() << endl;

  int ans = dinic();
  if (ans < n) {
    return puts("-1")&0;
  }

  cerr << clock() << endl;

  for (int i = 1; i <= n; ++ i) {
    printf("%d%c", seek(les[i], 0), " \n"[i == n]);
  }

}
