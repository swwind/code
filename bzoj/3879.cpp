#include <bits/stdc++.h>
#define N 500020
#define ll long long
#define mod 23333333333333333ll
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
char str[N];
int ch[N], rk[N], sa[N];
int cnt[N], tmp[N], rk1[N], rk2[N];
int height[N];
void buildSuffixArray(int n, int m) {
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; ++ i) cnt[ch[i]] = 1;
  for (int i = 1; i <= m; ++ i) cnt[i] += cnt[i - 1];
  for (int i = 1; i <= n; ++ i) rk[i] = cnt[ch[i]];
  for (int t = 1; t <= n; t <<= 1) {
    for (int i = 1; i <= n; ++ i) {
      rk1[i] = rk[i];
      rk2[i] = i + t <= n ? rk[i + t] : 0;
    }
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; ++ i) ++ cnt[rk2[i]];
    for (int i = 1; i <= n; ++ i) cnt[i] += cnt[i - 1];
    for (int i = n; i; -- i) tmp[cnt[rk2[i]] --] = i;
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; ++ i) ++ cnt[rk1[i]];
    for (int i = 1; i <= n; ++ i) cnt[i] += cnt[i - 1];
    for (int i = n; i; -- i) sa[cnt[rk1[tmp[i]]] --] = tmp[i];
    bool unique = true;
    rk[sa[1]] = 1;
    for (int i = 2; i <= n; ++ i) {
      rk[sa[i]] = rk[sa[i - 1]];
      if (rk1[sa[i]] == rk1[sa[i - 1]] && rk2[sa[i]] == rk2[sa[i - 1]]) unique = false;
      else ++ rk[sa[i]];
    }
    if (unique) break;
  }
  int k = 0;
  for (int i = 1; i <= n; ++ i) {
    if (k) -- k;
    if (rk[i] == 1) continue;
    int j = sa[rk[i] - 1];
    while (ch[j + k] == ch[i + k]) ++ k;
    height[rk[i]] = k;
  }
}
int lg2[N], f[N][20];
int query(int l, int r) {
  if (l > r) swap(l, r); ++ l;
  // printf("query %d %d\n", l, r);
  int lg = lg2[r - l + 1];
  return min(f[l][lg], f[r - (1 << lg) + 1][lg]);
}
int stk[N*6], tot[N*6];
int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);
  // freopen("3879.in", "r", stdin);
  // freopen("3879.out", "w", stdout);
  int n = read(), m = read();
  scanf("%s", str + 1);
  for (int i = 1; i <= n; ++ i) {
    ch[i] = str[i] - 'a' + 1;
  }
  buildSuffixArray(n, 26);
  for (int i = 1; i <= n; ++ i) {
    f[i][0] = height[i];
    // printf("height[%d] = %d\n", i, height[i]);
  }
  for (int i = 1; i < 20; ++ i) {
    for (int j = 1; j <= n; ++ j) {
      if (j + (1 << i) - 1 <= n) {
        f[j][i] = min(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
      }
    }
  }
  for (int i = 2; i <= n; ++ i) {
    lg2[i] = lg2[i >> 1] + 1;
  }
  for (int i = 1; i <= m; ++ i) {
    int x = read();
    vector<int> arr, val;
    for (int j = 1; j <= x; ++ j) {
      arr.push_back(rk[read()]);
    }
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    for (size_t j = 1; j < arr.size(); ++ j) {
      val.push_back(query(arr[j - 1], arr[j]));
    }
    int top = 0;
    ll sum = 0, ans = 0;
    for (size_t j = 0; j < val.size(); ++ j) {
      int num = 0;
      while (top && val[j] < stk[top]) {
        sum = (sum + (ll) (val[j] - stk[top]) * tot[top] % mod) % mod;
        num += tot[top];
        -- top;
      }
      stk[++ top] = val[j];
      tot[top] = num + 1;
      sum = (sum + val[j]) % mod;
      ans = (ans + sum) % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}