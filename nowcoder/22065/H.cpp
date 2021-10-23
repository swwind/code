#include <bits/stdc++.h>
#define N 520
#define M 100020
#define Q 300020
using namespace std;

inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int d[N], k[N], c[N];

struct Query {
  int p, q;
  friend bool operator < (const Query &a, const Query &b) {
    return a.p < b.p;
  }
} qs[M];
int s[M];

long long f[Q];
int a[N];
int Mn[Q];
int main() {
  int n = read();
  int m = read();
  int r = read();

  for (int i = 1; i <= n; ++ i) {
    d[i] = read();
    k[i] = read();
    c[i] = read();
  }

  for (int i = 1; i <= m; ++ i) {
    qs[i].p = read();
    qs[i].q = read();
  }
  sort(qs + 1, qs + m + 1);
  for (int i = 1; i <= m; ++ i) {
    s[i] = s[i-1] + qs[i].q;
    a[i] = 1;
  }

  int now = 1, cnt = 0;
  while (!s[now]) ++ now;
  for (int i = 1; i <= s[m]; ++ i) {
    for (int j = 1; j <= n; ++ j) {
      while (qs[a[j]].p < qs[now].p - d[j] + 1) {
        ++ a[j];
      }
    }

    f[i] = f[i-1] + r;
    for (int j = 1; j <= n; ++ j) {
      // printf("f[%d] min = f[%d] + %d\n", i, max(s[a[j]-1], i - k[j]), c[j]);
      f[i] = min(f[i], f[max(s[a[j]-1], i - k[j])] + c[j]);
    }
    // printf("f[%d] = %d\n", i, f[i]);

    while (i == s[now]) ++ now;
  }
  
  printf("%lld\n", f[s[m]]);
}