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
int a[N], b[N], c[N], d[N], e[N];

int k[N];
void update(int x) {
  for (; x < N; x += x & -x)
    k[x] ++;
}
int query(int x) {
  int ans = 0;
  for (; x; x -= x & -x)
    ans += k[x];
  return ans;
}
bool cmpa(int x, int y) {
  return a[x] < a[y];
}
bool cmpb(int x, int y) {
  return b[x] < b[y];
}
int main(int argc, char const *argv[]) {
  // freopen("F:/testdata.in", "r", stdin);
  int n = read();
  
  for (int i = 1; i <= n; i++)
    a[i] = read(), c[i] = i;
  for (int i = 1; i <= n; i++)
    b[i] = read(), d[i] = i;

  sort(c + 1, c + n + 1, cmpa);
  sort(d + 1, d + n + 1, cmpb);

  for (int i = 1; i <= n; i++)
    e[c[i]] = d[i];

  int ans = 0;
  for (int i = n; i; i--) {
    ans = (ans + query(e[i] - 1)) % 99999997;
    update(e[i]);
  }
  cout << ans << endl;
  return 0;
}