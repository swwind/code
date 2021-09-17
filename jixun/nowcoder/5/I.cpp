#include <bits/stdc++.h>
#define N 100020
#define mod 998244353

using namespace std;

int a[N];

struct Query {
  int l, r, k, id;
} q[N];

int bk[N], block;

int cnt[N], mx[N], top;
int r[N], l[N];
void add(int x) {
  int mxx = mx[top];
  if (!cnt[x]) {
    if (cnt[x-1] && cnt[x+1]) {
      r[l[x-1]] = r[x+1];
      l[r[x+1]] = l[x-1];
      mxx = max(mxx, r[x+1] - l[x-1] + 1);
    } else if (cnt[x-1]) {
      r[l[x-1]] = x;
      l[x] = l[x-1];
      mxx = max(mxx, x - l[x-1] + 1);
    } else if (cnt[x+1]) {
      l[r[x+1]] = x;
      r[x] = r[x+1];
      mxx = max(mxx, r[x+1] - x + 1);
    } else {
      l[x] = x;
      r[x] = x;
      mxx = max(mxx, 1);
    }
  }
  ++ cnt[x];
  // printf("added %d, mx: %d -> %d\n", x, mx[top], mxx);
  mx[++ top] = mxx;
}
void dec(int x) {
  -- cnt[x];
  if (!cnt[x]) {
    if (cnt[x-1]) {
      r[l[x-1]] = x-1;
    }
    if (cnt[x+1]) {
      l[r[x+1]] = x+1;
    }
  }
  -- top;
}

int ans[N];

vector<int> spj;

int main() {
  int n, Q;
  scanf("%d%d", &n, &Q);

  for (int i = 1; i <= n; ++ i) {
    scanf("%d", &a[i]);
  }

  for (int i = 1; i <= Q; ++ i) {
    scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].k);
    q[i].id = i;
  }

  block = sqrt(n);
  for (int i = 1; i <= n; ++ i) {
    bk[i] = (i - 1) / block + 1;
  }

  sort(q + 1, q + Q + 1, [&] (const Query &a, const Query &b) {
    return bk[a.l] == bk[b.l] ? a.r < b.r : bk[a.l] < bk[b.l];
  });

  for (int st = 1, ed = 1; st <= Q; st = ++ ed) {
    while (ed + 1 <= n && bk[q[ed + 1].l] == bk[q[st].l]) {
      ++ ed;
    }
    while (st <= ed && bk[q[st].l] == bk[q[st].r]) {
      spj.push_back(st ++);
    }

    int fuck = 0;
    for (int i = st; i <= ed; ++ i) {
      fuck = max(fuck, q[i].l);
    }

    int ql = fuck, qr = fuck - 1;
    for (int i = st; i <= ed; ++ i) {
      // now ql = fuck, qr = somewhere else
      int l = q[i].l, r = q[i].r, k = q[i].k;
      
      while (qr < r) add(a[++ qr]);
      while (ql > l) add(a[-- ql]);
      // printf("fucking [%d, %d, %d]\n", l, r, k);
      int sum = mx[top];
      int mul = 1;
      // printf("[%d, %d] ans = %d\n", ql, qr, sum);
      for (int j = 1; j < k; ++ j) {
        add(a[-- ql]);
        add(a[++ qr]);
        mul = (long long) mul * (n + 1) % mod;
        sum = (sum + (long long) mx[top] * mul % mod) % mod;
        // printf("[%d, %d] ans += %d * %d\n", ql, qr, mx[top], mul);
      }
      ans[q[i].id] = sum;
      for (int j = 1; j < k; ++ j) {
        dec(a[qr --]);
        dec(a[ql ++]);
      }

      while (ql < fuck) dec(a[ql ++]);
    }
    while (qr > fuck-1) dec(a[qr --]);

    assert(top == 0);
  }

  for (int i : spj) {
    int l = q[i].l, r = q[i].r, k = q[i].k;
    int ql = l, qr = l-1, mul = 1;
    while (qr < r) add(a[++ qr]);
    int sum = mx[top];
    for (int j = 1; j < k; ++ j) {
      add(a[-- ql]);
      add(a[++ qr]);
      mul = (long long) mul * (n + 1) % mod;
      sum = (sum + (long long) mx[top] * mul % mod) % mod;
    }
    ans[q[i].id] = sum;
    for (int j = 1; j < k; ++ j) {
      dec(a[qr --]);
      dec(a[ql ++]);
    }
    while (qr > l-1) dec(a[qr --]);
    assert(top == 0);
  }

  for (int i = 1; i <= Q; ++ i) {
    printf("%d\n", ans[i]);
  }
}
