#include <bits/stdc++.h>
#define N 2020
#define mod 1000000007
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int f[N], g[N];
vector <int> son[N];
int main(int argc, char const *argv[]) {
  int n = read(), q = read();
  // f[i] -> the end with i
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i)
      son[j].push_back(i);
  f[1] = 1;
  while (q --) {
    memset(g, 0, sizeof g);
    for (int i = 1; i <= n; i++)
      for (int k : son[i])
        g[i] = (g[i] + f[k]) % mod;
    memcpy(f, g, sizeof g);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = (ans + f[i]) % mod;
  cout << ans << endl;
  return 0;
}
// https://www.bilibili.com/video/av13662970