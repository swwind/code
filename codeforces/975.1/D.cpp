#include <bits/stdc++.h>
#define N 200050

using namespace std;

int fa[N];
int a[N];
int odd[N], eve[N];
int omx[N], emx[N];

int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }

int sum = 0, gmx = 0;
int rs[N], vs[N];

void release(int x) {
  if (odd[x] > eve[x]) {
    sum -= odd[x];
    if (omx[x] == a[rs[1]]) {
      gmx--;
    }
  } else if (odd[x] < eve[x]) {
    sum -= eve[x];
    if (emx[x] == a[rs[1]]) {
      gmx--;
    }
  } else {
    sum -= odd[x];
    if (omx[x] == a[rs[1]] || emx[x] == a[rs[1]]) {
      gmx--;
    }
  }
}
void push(int x) {
  if (odd[x] > eve[x]) {
    sum += odd[x];
    if (omx[x] == a[rs[1]]) {
      gmx++;
    }
  } else if (odd[x] < eve[x]) {
    sum += eve[x];
    if (emx[x] == a[rs[1]]) {
      gmx++;
    }
  } else {
    sum += odd[x];
    if (omx[x] == a[rs[1]] || emx[x] == a[rs[1]]) {
      gmx++;
    }
  }
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b)
    return;
  release(a);
  release(b);
  fa[b] = a;
  odd[a] += odd[b];
  eve[a] += eve[b];
  omx[a] = max(omx[a], omx[b]);
  emx[a] = max(emx[a], emx[b]);
  push(a);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    sum = gmx = 0;
    for (int i = 1; i <= n; ++i) {
      fa[i] = rs[i] = i;
      vs[i] = 0;
      scanf("%d", a + i);
      odd[i] = (i & 1);
      eve[i] = 1 - odd[i];
      omx[i] = odd[i] * a[i];
      emx[i] = eve[i] * a[i];
    }
    sort(rs + 1, rs + n + 1,
         [&](const int &x, const int &y) { return a[x] > a[y]; });
    long long ans = 0;
    // printf(">> %d = %d\n", ans, n);
    for (int i = 1; i <= n; ++i) {
      int pos = rs[i];

      push(pos);
      if (pos > 1 && vs[pos - 1]) {
        merge(pos, pos - 1);
      }
      if (pos < n && vs[pos + 1]) {
        merge(pos, pos + 1);
      }

      // count result
      long long res = (long long)(gmx ? sum : (sum - 1)) + a[rs[1]] + a[pos];
      ans = max(ans, res);

      vs[pos] = 1;
    }
    printf("%lld\n", ans);
  }
}
