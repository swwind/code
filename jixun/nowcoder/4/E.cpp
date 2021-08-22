#include <bits/stdc++.h>
#define N 100020

using namespace std;

namespace swwind {

int n;

int ls[N], rs[N];

int head[N], to[N<<1], nxt[N<<1], cnt, ws[N<<1];
void insert(int x, int y, int w) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; ws[cnt] = w;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; ws[cnt] = w;
}

int b[N];

void dfs(int x, int f, int v) {
  b[x] = v;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f) continue;
    dfs(to[i], x, v ^ ws[i]);
  }
}

struct Pair {
  int p, v;
};

vector<Pair> vec;

void add_segment(int l, int r) {
  // printf("add [%d, %d]\n", l, r);
  vec.push_back({ l, 1 });
  vec.push_back({ r+1, -1 });
}

void add_segment_with_xor(int l, int r, int L, int R, int k, int d) {
  /// if l <=  [L, R] ^ k  <= r
  /// then we add [L, R] to our answer
  // printf("dfs %d, %d, %d, %d, %d, %d\n", l, r, L, R, k, d);
  int bits = ((1<<30)-1) - ((1<<d)-1);
  int kk = k & bits;
  int nl = L ^ kk;
  int nr = R ^ kk;
  // printf("calculated [%d, %d]\n", nl, nr);

  if (l <= nl && nr <= r) {
    add_segment(L, R);
    return;
  }

  if (nl > r || nr < l) return;

  int mid = L + R >> 1;
  add_segment_with_xor(l, r, L, mid, k, d-1);
  add_segment_with_xor(l, r, mid+1, R, k, d-1);
}

bool cmp(const Pair &a, const Pair &b) {
  return a.p == b.p ? a.v < b.v : a.p < b.p;
}

int calc_ans() {
  sort(vec.begin(), vec.end(), cmp);

  int cnt = 0;
  int ans = 0;
  for (size_t i = 0, j = i; i < vec.size(); i = ++ j) {
    cnt += vec[i].v;
    while (j + 1 < vec.size() && vec[j + 1].p == vec[i].p) {
      cnt += vec[++ j].v;
    }
    if (cnt == n) {
      ans += vec[j+1].p - vec[j].p;
    }
  }


  return ans;
}

}

using namespace swwind;

int main() {
  scanf("%d", &n);

  for (int i = 1; i <= n; ++ i) {
    scanf("%d%d", ls + i, rs + i);
  }

  for (int i = 1; i < n; ++ i) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);

    insert(x, y, w);
  }

  dfs(1, 1, 0);

  // for (int i = 1; i <= n; ++ i) {
  //   printf("%d\n", b[i]);
  // }

  add_segment(ls[1], rs[1]);
  for (int i = 2; i <= n; ++ i) {
    // printf("trying suit %d into [%d, %d] with xor %d\n", i, ls[i], rs[i], b[i]);
    add_segment_with_xor(ls[i], rs[i], 0, ((1<<30)-1), b[i], 30);
  }

  printf("%d\n", calc_ans());

}
