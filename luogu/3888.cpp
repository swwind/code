#include <bits/stdc++.h>
#define N 100020
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}

int f[55][1<<7][1<<7];
int g[55][1<<7][1<<7];
int a[55][8];

inline int calc(int line, int x) {
  int ans = 0;
  for (int i = 0; i < 8; ++ i) {
    if ((x >> i) & 1) {
      ans += a[line][i + 1];
    }
  }
  return ans;
}
inline int tsukasa(int x, int mst) {
  return (x | (x << 1) | (x >> 1)) & mst;
}

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  int n = read(), m = read();
  int ms = (1 << m), mst = ms - 1;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      a[i][j] = read();
    }
  }
  memset(f, 0x3f, sizeof f);
  f[0][0][mst] = 0;
  for (int i = 1; i <= n; ++ i) {
    for (int ps = 0; ps < ms; ++ ps) {
      for (int pps = 0; pps < ms; ++ pps) {
        for (int ns = 0; ns < ms; ++ ns) {
          if ((tsukasa(ps, mst) | pps | ns) != mst) {
            continue;
          }
          int zhuanyi = f[i - 1][ps][pps] + calc(i, ns);
          int gzhuan = g[i - 1][ps][pps] + __builtin_popcount(ns);
          if (zhuanyi < f[i][ns][ps]) {
            f[i][ns][ps] = zhuanyi;
            g[i][ns][ps] = gzhuan;
          } else if (zhuanyi == f[i][ns][ps]) {
            g[i][ns][ps] = min(g[i][ns][ps], gzhuan);
          }
        }
      }
    }
  }

  // printf("%d\n", f[1][0][0]);
  // printf("%d\n", f[2][7][0]);
  // printf("%d\n", f[3][0][7]);

  int ans = 2147483647;
  int gns = 0;
  for (int i = 0; i < ms; ++ i) {
    for (int j = 0; j < ms; ++ j) {
      if ((tsukasa(j, mst) | i) == mst) {
        if (f[n][j][i] < ans) {
          ans = f[n][j][i];
          gns = g[n][j][i];
        } else if (f[n][j][i] == ans) {
          gns = min(gns, g[n][j][i]);
        }
      }
    }
  }
  printf("%d %d\n", gns, ans);

  return 0;
}

