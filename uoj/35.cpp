#include <bits/stdc++.h>
#define N 100020
#define ll long long
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
int main(int argc, char const *argv[]) {
  freopen("../tmp/.in", "r", stdin);
  // int n = read(), m = read();
  scanf("%s", str + 1);
  int n = strlen(str + 1);
  for (int i = 1; i <= n; ++ i) {
    ch[i] = str[i] - 'a' + 1;
  }
  buildSuffixArray(n, 26);
  for (int i = 1; i <= n; ++ i) {
    printf("%d%c", sa[i], i == n ? '\n' : ' ');
  }
  for (int i = 2; i <= n; ++ i) {
    printf("%d%c", height[i], i == n ? '\n' : ' ');
  }
  return 0;
}