#include <bits/stdc++.h>
#define N 1000020

using namespace std;

char str[N<<1];
int st[N], top, now;

int head[N], nxt[N<<1], to[N<<1], cnt;

void link(int x, int y) {
  to[++ cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;

  to[++ cnt] = x;
  nxt[cnt] = head[y];
  head[y] = cnt;
}

int fa[N];
int sz[N];

int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx == fy) return;
  fa[fx] = fy;
}

int k[N];

struct Color {
  int color, number;
  friend bool operator < (const Color &a, const Color &b) {
    return a.number < b.number;
  }
};
priority_queue<Color> c;

void dfs(int x, int fa) {
  st[++ top] = x;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = to[i];
    if (y == fa) continue;
    dfs(y, x);
  }
}

int ans[N];

int main() {
  int n; scanf("%d", &n);
  scanf("%s", str + 1);

  for (int i = 1; i <= n; ++ i) {
    int color;
    scanf("%d", &color);
    k[color] ++;
  }
  for (int i = 1; i <= n; ++ i) {
    if (k[i]) {
      c.push({i, k[i]});
    }
  }

  for (int i = 1; i <= n; ++ i) {
    fa[i] = i;
  }

  for (int i = 1; i <= (n<<1); ++i) {
    if (str[i] == '(') {
      ++ top;
      int id = ++ now;
      if (st[top]) {
        merge(st[top], id);
        link(st[top], id);
        // printf("%d %d\n", st[top], id);
      }
      st[top] = id;
    }
    if (str[i] == ')') {
      -- top;
      st[top + 2] = 0;
    }
  }

  vector<int> fas;
  for (int i = 1; i <= now; ++ i) {
    if (fa[i] == i) {
      fas.push_back(i);
    }
  }

  vector<Color> colors;
  for (int fa : fas) {
    top = 0;
    dfs(fa, fa);

    if (c.size() < top) {
      puts("NO");
      return 0;
    }

    colors.clear();
    for (int i = 1; i <= top; ++ i) {
      Color color = c.top();
      c.pop();
      ans[st[i]] = color.color;
      if (-- color.number) {
        colors.push_back(color);
      }
    }
    for (Color color : colors) {
      c.push(color);
    }
  }

  puts("YES");
  for (int i = 1; i <= n; ++ i) {
    printf("%d%c", ans[i], " \n"[i == n]);
  }

}