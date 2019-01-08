#include <bits/stdc++.h>
#define N 3000020
#define M 100020
#define mul 131ll
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

char str[N];
int bks[N];
struct query {
  int l, r, id;
  friend bool operator < (const query &a, const query &b) {
    return bks[a.l] == bks[b.l] ? bks[a.r] > bks[b.r] : bks[a.l] < bks[b.l];
  }
} qs[M];

ll hsh[N], val[N], pwk;

inline ll query_hsh(int l, int r) {
  return hsh[r] - hsh[l - 1] * pwk;
}

int times[N];
ll now, ans[N];

inline void add(int x) {
  if (!x) return;
  now += times[x] ++;
}
inline void del(int x) {
  if (!x) return;
  now -= -- times[x];
}

int main(int argc, char const *argv[]) {
  freopen("../tmp/.in", "r", stdin);

  int n = read(), m = read(), k = read();
  scanf("%s", str + 1);
  for (int i = 1; i <= m; ++ i) {
    qs[i].l = read();
    qs[i].r = read();
    qs[i].id = i;
  }
  int block = sqrt(m);
  for (int i = 1; i <= m; ++ i) {
    bks[i] = (i - 1) / block;
  }
  sort(qs + 1, qs + m + 1);

  // calc hash
  for (int i = 1; i <= n; ++ i) {
    // hsh[i] = (hsh[i - 1] * 1171ll % mod + str[i]) % mod;
    hsh[i] = hsh[i - 1] * mul + str[i];
  }
  pwk = 1;
  for (int i = 1; i <= k; ++ i) {
    pwk = pwk * mul;
  }
  vector<ll> vals;
  for (int i = 1; i <= n - k + 1; ++ i) {
    val[i] = query_hsh(i, i + k - 1);
    vals.push_back(val[i]);
  }
  sort(vals.begin(), vals.end());
  vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
  for (int i = 1; i <= n - k + 1; ++ i) {
    val[i] = lower_bound(vals.begin(), vals.end(), val[i]) - vals.begin() + 1;
    // printf("%d%c", val[i], " \n"[i == n - k]);
  }

  // modui
  int l = 1, r = 0;
  for (int i = 1; i <= m; ++ i) {
    while (l < qs[i].l) del(val[l ++]);
    while (l > qs[i].l) add(val[-- l]);
    while (r < qs[i].r) add(val[++ r]);
    while (r > qs[i].r) del(val[r --]);
    // printf("%d %d\n", l, r);
    ans[qs[i].id] = now;
  }

  for (int i = 1; i <= m; ++ i) {
    printf("%lld\n", ans[i]);
  }

  return 0;
}