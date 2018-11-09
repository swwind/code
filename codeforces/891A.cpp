#include <bits/stdc++.h>
#define N 2020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int a[N];
int ak[N][20];

inline int query(int l, int r) {
  int lg = log2(r - l + 1);
  return __gcd(ak[l][lg], ak[r - (1 << lg) + 1][lg]);
}

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  int n = read();
  int one = 0;

  for (int i = 1; i <= n; ++ i) {
    ak[i][0] = read();
    if (ak[i][0] == 1) ++ one;
  }

  if (one) {
    return printf("%d\n", n - one), 0;
  }

  for (int i = 1; i < 20; ++ i) {
    for (int j = 1; j <= n; ++ j) {
      if (j + (1 << (i - 1)) <= n) {
        ak[j][i] = __gcd(ak[j][i - 1], ak[j + (1 << (i - 1))][i - 1]);
      }
    }
  }

  for (int i = 2; i <= n; ++ i) {
    for (int j = i; j <= n; ++ j) {
      if (query(j - i + 1, j) == 1) {
        return printf("%d\n", n + (i - 2)), 0;
      }
    }
  }

  printf("%d\n", -1);

  return 0;
}