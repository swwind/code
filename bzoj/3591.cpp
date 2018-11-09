// Time Limit Exceed

#include <bits/stdc++.h>
#define N 15
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int pre[N], a[1<<N], bit[1<<N], pow3[N];
int g[1<<N][N], f[14348910];
int main(int argc, char const *argv[]) {
  int n = read(), k = read();
  memset(pre, -1, sizeof pre);
  for (int i = 1, last = -1; i <= k; ++ i) {
    int x = read() - 1;
    pre[x] = last;
    last = x;
  }
  int ns = 1 << n;
  for (int i = 1; i < ns; ++ i) {
    bit[i] = bit[i >> 1] + (i & 1);
  }
  for (int i = pow3[0] = 1; i < n; ++ i) {
    pow3[i] = pow3[i - 1] * 3;
  }
  for (int i = 0; i < ns; ++ i) {
    for (int j = 0; j < n; ++ j) {
      if (!(i >> j & 1)) {
        if (bit[i] > k) {
          continue;
        }
        g[i][j] = i | (1 << j);
        for (int l = j + 1; l < n; ++ l) {
          if (i >> l & 1) {
            g[i][j] ^= (1 << l);
            break;
          }
        }
      } else {
        a[i] += pow3[j];
      }
    }
  }
  for (int i = 0; i < n; ++ i) {
    if (pre[i] < 0) {
      f[pow3[i] << 1] = 1;
    }
  }
  for (int i = 1; i < ns; ++ i) {
    for (int j = 0; j < n; ++ j) {
      if (i >> j & 1) {
        continue;
      }
      if (pre[j] >= 0 && !(i >> pre[j] & 1)) {
        continue;
      }
      for (int l = i; l; l = (l - 1) & i) {
        if (bit[l] > k) continue;
        if (f[a[l] + a[i]]) {
          f[a[i | (1 << j)] + a[g[l][j]]] += f[a[l] + a[i]];
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < ns; ++ i) {
    if (bit[i] == k) {
      ans += f[a[ns - 1] + a[i]];
    }
  }
  printf("%d\n", ans);
  return 0;
}