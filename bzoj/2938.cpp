#include <bits/stdc++.h>
#define N 30020
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int q[N], vis[N], check[N];
int tr[N][2], flag[N], cnt = 1, nxt[N];
char ch[N];
void insert(char *ch) {
  int l = strlen(ch), now = 1;
  for (int i = 0; i < l; ++ i) {
    int k = ch[i] - '0';
    if (!tr[now][k]) {
      tr[now][k] = ++ cnt;
    }
    now = tr[now][k];
  }
  flag[now] = 1;
}
bool dfs(int x) {
  vis[x] = 1;
  for (int i = 0; i < 2; ++ i) {
    int k = tr[x][i];
    if (vis[k]) {
      return true;
    }
    if (flag[k] || check[k]) {
      continue;
    }
    if (dfs(k)) {
      return true;
    }
    check[k] = 1;
  }
  vis[x] = 0;
  return false;
}
int main() {
  int n = read();
  tr[0][0] = tr[0][1] = 1;
  for (int i = 1; i <= n; ++ i) {
    scanf("%s", ch);
    insert(ch);
  }
  // calc fail
  int l = 0, r = 1;
  q[1] = 1; nxt[1] = 0; 
  while (l < r) {
    int x = q[++ l];
    for (int i = 0; i < 2; ++ i) {
      if (!tr[x][i]) {
        tr[x][i] = tr[nxt[x]][i];
        continue;
      }
      int k = nxt[x];
      while (!tr[k][i]) {
        k = nxt[k];
      }
      nxt[tr[x][i]] = tr[k][i];
      if (flag[tr[k][i]]) {
        flag[tr[x][i]] = 1;
      }
      q[++ r] = tr[x][i];
    }
  }
  puts(dfs(1) ? "TAK" : "NIE");
  return 0;
}