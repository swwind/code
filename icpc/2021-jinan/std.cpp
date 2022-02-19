#include <bits/stdc++.h>
#define N 1020

using namespace std;

char str[N];
int a[50];
int cnt, n;

struct solution {
  int v[20];

  friend bool operator < (const solution &a, const solution &b) {
    for (int i = 0; i < 20; ++ i) {
      if (b.v[i] > a.v[i]) return true;
      if (b.v[i] < a.v[i]) return false;
    }
    return false;
  }
}now,mxs;

void dfs(int x, int dep) {
  if (dep == cnt) {
    if (mxs < now) {
      mxs = now;
    }
    return;
  }
  // printf("dfs %d %d\n", x, dep);
  vector<int> vis(20), occ(20), pos(20);
  int last = n, tot = 0;
  for (int i = n; i >= x; -- i) {
    if (a[str[i]] && !vis[str[i]]) {
      vis[str[i]] = 1;
      if (++ tot == cnt - dep) {
        last = i;
        break;
      }
    }
  }
  for (int i = last; i >= x; -- i) {
    if (!a[str[i]]) continue;
    if (vis[str[i]]) {
      pos[str[i]] = i;
      vis[str[i]] = 0;
    }
    ++ occ[str[i]];
  }

  int mx_occ = 0;
  for (int i = 0; i < 20; ++ i) {
    if (a[i]) {
      mx_occ = max(mx_occ, occ[i]);
    }
  }
  now.v[dep] = mx_occ;
  for (int k = 0; k < 20; ++ k) {
    if (a[k] && occ[k] == mx_occ) {
      a[k] = 0;
      // printf("chose %c\n", 'a'+k);
      dfs(pos[k] + 1, dep + 1);
      a[k] = 1;
    }
  }
}

int b[50];

int main() {

  scanf("%d", &n);
  scanf("%s", str+1);

  for (int i = 1; i <= n; ++ i) {
    str[i] -= 'a';
    if (!a[str[i]]) {
      a[str[i]] = 1;
      ++ cnt;
    }
  }

  dfs(1, 0);

  for (int i = 0; i < cnt; ++ i) {
    for (int j = 0; j < mxs.v[i]; ++ j) {
      putchar('a'+cnt-i-1);
    }
  }
  puts("");

}
