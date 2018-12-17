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
int ans, n, k, a[N];
vector<int> son[N];
int dfs(int x, int d) {
  int mxd = d;
  for (int to : son[x]) {
    mxd = max(mxd, dfs(to, d + 1));
  }
  if (a[x] != 1 && mxd - d >= k - 1) {
    ++ ans;
    return 0;
  }
  return mxd;
}
int main(int argc, char const *argv[]) {
  n = read(); k = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
  }
  if (a[1] != 1) {
    ++ ans;
    a[1] = 1;
  }
  for (int i = 2; i <= n; ++ i) {
    son[a[i]].push_back(i);
  }
  dfs(1, 0);
  printf("%d\n", ans);
  return 0;
}
/*
直接贪心把子树连到根即可。
*/