// 线性筛欧拉函数

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
int phi[N], pri[N], cnt;
bool mark[N];
void phi_filter(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!mark[i])
      pri[++cnt] = i, phi[i] = i - 1;
    for (int j = 1; j <= cnt && i * pri[j] <= n; j++) {
      mark[i * pri[j]] = 1;
      if (i % pri[j]) {
        phi[i * pri[j]] = phi[i] * (pri[j] - 1);
      } else {
        phi[i * pri[j]] = phi[i] * pri[j];
        break;
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  // int n = read(), ans = 0;
  // if (n == 1) return puts("0"), 0;
  // phi_filter(n);
  // for (int i = 1; i < n; i++)
  //   ans += phi[i];
  // printf("%d\n", ans * 2 + 1);
  phi_filter(200);
  for (int i = 1; i <= cnt; ++ i) {
    printf("%d\n", pri[i]);
  }
  return 0;
}
