#pragma GCC optimize 2
#include <bits/stdc++.h>
#define N 1020
#define mul1 11677
#define mul2 101833
#define ull unsigned long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

ull hsh1[N][N], hsh2[N][N], h[N];
char str[N];
ull pw1[N], pw2[N];

set<ull> st;

inline ull get_hash(int x1, int y1, int x2, int y2) {
  ull ans = hsh2[x2][y2];
  ans -= hsh2[x2][y1] * pw2[y2 - y1];
  ans -= hsh2[x1][y2] * pw1[x2 - x1];
  ans += hsh2[x1][y1] * pw1[x2 - x1] * pw2[y2 - y1];
  return ans;
}

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  int n = read(), m = read();
  int a = read(), b = read();

  for (int i = pw1[0] = 1; i < N; ++ i) {
    pw1[i] = pw1[i - 1] * mul1;
  }
  for (int i = pw2[0] = 1; i < N; ++ i) {
    pw2[i] = pw2[i - 1] * mul2;
  }

  for (int i = 1; i <= n; ++ i) {
    scanf("%s", str + 1);
    for (int j = 1; j <= m; ++ j) {
      hsh1[i][j] = str[j] + hsh1[i - 1][j] * mul1;
      hsh2[i][j] = hsh2[i][j - 1] * mul2 + hsh1[i][j];
    }
  }

  for (int i = a; i <= n; ++ i) {
    for (int j = b; j <= m; ++ j) {
      st.insert(get_hash(i - a, j - b, i, j));
    }
  }

  int q = read();
  while (q --) {
    memset(h, 0, sizeof h);
    for (int i = 1; i <= a; ++ i) {
      scanf("%s", str + 1);
      for (int j = 1; j <= b; ++ j) {
        h[j] = h[j] * mul1 + str[j];
      }
    }
    for (int i = 1; i <= b; ++ i) {
      h[i] = h[i - 1] * mul2 + h[i];
    }
    puts(st.find(h[b]) == st.end() ? "0" : "1");
  }

  return 0;
}