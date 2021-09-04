#include <bits/stdc++.h>

using namespace std;

struct String {
  char c[101];
  int origin;
  int8_t length;
};
bool cmp(String a, String b) {
  return strcmp(a.c, b.c) < 0;
}

String str[100000];

int fa[500000];
int sz[500000];
int son[500000];
int used[500000];

int ed[100000];
int now = 0;

int dfs(int l, int r, int p) {
  // printf("%d %d %d\n", l, r, p);
  int x = ++ now;

  if (l == r) {
    ed[str[l].origin] = x;
    return x;
  }

  int8_t len = INT8_MAX;
  for (int i = l; i <= r; i ++) {
    len = min(len, str[i].length);
  }

  while (p < len) {
    bool all_same = true;
    for (int i = l+1; i <= r; ++ i) {
      if (str[i].c[p] != str[l].c[p]) {
        all_same = false;
        break;
      }
    }
    if (all_same) {
      p ++;
    } else {
      break;
    }
  }

  for (int i = l, j = l; i <= r; i = ++ j) {
    while (j+1 <= r && str[j+1].c[p] == str[i].c[p]) {
      j ++;
    }

    fa[dfs(i, j, p+1)] = x;
  }

  return x;
}

int main() { 
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str[i].c);
    str[i].length = strlen(str[i].c);
    str[i].origin = i;
  }

  sort(str, str + n, cmp);

  // dfs(0, n-1, 0);
  for (int i = 0, j = 0; i < n; i = ++ j) {
    while (j + 1 < n && str[j + 1].c[0] == str[i].c[0]) {
      j ++;
    }
    dfs(i, j, 1);
  }

  // for (int i = 1; i <= now; ++ i) {
  //   printf("fa[%d] = %d\n", i, fa[i]);
  // }
  // for (int i = 0; i < n; i++) {
  //   printf("ed[%d] = %d\n", i, ed[i]);
  // }

  for (int i = 0; i < n; i++) {
    sz[ed[i]] = 1;
  }
  for (int i = now; i >= 1; i--) {
    sz[fa[i]] += sz[i];
  }
  for (int i = 1; i <= now; ++ i) {
    son[fa[i]] ++;
  }

  int ans = 0;
  for (int i = 0; i < n; ++ i) {
    int x = ed[i];
    while (x) {
      -- sz[x];
      if (!sz[x]) {
        ans -= son[x];
        ans ++;
        // printf("when %d, ans -= %d += 1\n", x, son[x]);
      }
      x = fa[x];
    }
    printf("%d\n", ans);
  }

}
