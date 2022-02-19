#include <bits/stdc++.h>
#define N 1020

using namespace std;

struct solution {
  int v[20];
  int pos;

  friend bool operator < (const solution &a, const solution &b) {
    for (int i = 0; i < 20; ++ i) {
      if (b.v[i] > a.v[i]) return true;
      if (b.v[i] < a.v[i]) return false;
    }
    return a.pos > b.pos;
  }
};
int n;
char str[N];
int last[20];
int pre[N];
int vis[20];
int cnt;

int f[1<<20];
int popcnt[1<<20];
solution g[1<<20];

int ccc[20][1020];
int ddd[20][1020];

int main() {

  scanf("%d", &n);
  scanf("%s", str + 1);

  for (int i = 1; i <= n; ++ i) {
    str[i] -= 'a';
    if (!vis[str[i]]) {
      vis[str[i]] = ++ cnt;
    }
    str[i] = vis[str[i]] - 1;
    pre[i] = last[str[i]];
    last[str[i]] = i;
    for (int j = 0; j < 20; ++ j) {
      ccc[j][i] = ccc[j][i - 1] + (str[i] == j);
      ddd[j][i] = str[i] == j ? i : ddd[j][i - 1];
    }
  }

  for (int j = 0; j < cnt; ++ j) {
    f[1<<j] = j;
  }
  for (int i = 1; i < (1 << cnt); ++ i) {
    popcnt[i] = popcnt[i>>1] + (i&1);
    for (int j = 0; j < cnt; ++ j) {
      if (!((i >> j) & 1)) {
        f[i|(1<<j)] = last[f[i]] < last[j] ? f[i] : j;
      } else break;
    }
  }

  // for (int i = 1; i < (1 << cnt); ++ i) {
  //   if (f[i]) printf("f[%d] = %d\n", i, f[i]);
  // }
  // printf("%d\n", last[2]);

  int full_bit = (1 << cnt) - 1;

  for (int i = 0; i < (1 << cnt); ++ i) {
    for (int j = 0; j < cnt; ++ j) {
      if (!((i>>j)&1)) {
        int s = full_bit ^ i;
        if (ccc[j][last[f[s]]] > ccc[j][g[i].pos]) {
          // otherwise we must choose some value
          solution nw = g[i];
          nw.pos = ddd[j][last[f[s]]];
          nw.v[popcnt[i]] = ccc[j][last[f[s]]] - ccc[j][g[i].pos];
          if (g[i|(1<<j)] < nw) {
            g[i|(1<<j)] = nw;
          }
        }
      }
    }
  }

    // printf("pos = %d\n", g[3].pos);
  for (int i = 0; i < cnt; ++ i) {
    for (int j = 0; j < g[full_bit].v[i]; ++ j) {
      putchar('a'+cnt-i-1);
    }
  }
  puts("");

}
