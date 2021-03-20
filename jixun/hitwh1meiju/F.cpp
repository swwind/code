#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int pri[N], mark[N], cnt;
void filter(int n) {
  for (int i = 2; i <= n; ++ i) {
    if (!mark[i]) pri[++ cnt] = i;
    for (int j = 1; j <= cnt && i * pri[j] <= n; ++ j) {
      mark[i * pri[j]] = 1;
    }
  }
}

int main() {
  int m, a, b;
  filter(100000);
  while (~scanf("%d%d%d", &m, &a, &b)) {
    if (!m && !a && !b) break;
    int mul = 0, p, q;
    for (int i = 1; i <= cnt && pri[i] <= m; ++ i) {
      for (int j = i; j && pri[j] * b >= a * pri[i]; -- j) {
        if (pri[i] * pri[j] <= m) {
          if (pri[i] * pri[j] > mul) {
            p = pri[i];
            q = pri[j];
            mul = p * q;
          }
        }
      }
    }
    printf("%d %d\n", q, p);
  }
}
