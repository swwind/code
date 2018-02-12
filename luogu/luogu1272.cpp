#include <bits/stdc++.h>
#define N 160
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
std::vector<int> son[N], szs[N];
int p, f[N][N]; // the i-th point, contains j points, kill the min edges.
// Of course that f[i][j] = min(f[i][j], f[i][j - k] + f[son[i]][k] - 1)
int dfs(int x) {
}
int main(int argc, char const *argv[]) {
  int n = read(); p = read();
  for (int i = 1; i < n; i++) {
    int x = read();
    son[x].push_back(read());
  }
  dfs(1);
  return 0;
}