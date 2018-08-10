#include <bits/stdc++.h>
#define N 55
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
char str[N];
bool mp[N][N], vis[N];
int main(int argc, char const *argv[]) {
  freopen("../temp/input.in", "r", stdin);
  int n = read();
  for (int i = 1; i <= n; ++ i) {
    scanf("%s", str + 1);
    for (int j = 1; j <= n; ++ j) {
      mp[i][j] = str[j] == '1';
    }
  }
  queue<int> que;
  que.push(1);
  vis[1] = 1;
  int ans = 0;
  while (!que.empty()) {
    int x = que.front(); que.pop();
    for (int i = 1; i < n; ++ i) {
      if (mp[x][i] && !vis[i]) {
        que.push(i);
        vis[i] = 1;
      }
    }
    if (mp[x][n]) ++ ans;
  }
  cout << ans << endl;
  return 0;
}