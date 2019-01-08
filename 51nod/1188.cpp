#include <bits/stdc++.h>
#define N 5000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
ll ans[N], pri[N], phi[N], cnt;
bool mark[N];
inline void sieve() {
  phi[1] = 1;
  for (int i = 2; i < N; ++ i) {
    if (!mark[i]) pri[++ cnt] = i, phi[i] = i - 1;
    for (int j = 1; j <= cnt && i * pri[j] < N; ++ j) {
      mark[i * pri[j]] = 1;
      if (i % pri[j] == 0) {
        phi[i * pri[j]] = phi[i] * pri[j];
        break;
      }
      phi[i * pri[j]] = phi[i] * (pri[j] - 1);
    }
  }
}
int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  sieve();
  for (int i = 2; i < N; ++ i) {
    for (int j = 1; i * j < N; ++ j) {
      ans[i * j] += phi[i] * j;
    }
  }
  for (int i = 2; i < N; ++ i) {
    ans[i] += ans[i - 1];
  }
  int T = read();
  while (T --) {
    printf("%lld\n", ans[read()]);
  }
  return 0;
}
