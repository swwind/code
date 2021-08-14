#include <bits/stdc++.h>
using namespace std;

char str[50];

// 1 -> space, 0 -> wall
int a[25][25];
int b[25][25];

#define id(a, b, c, d) (((a)-1)*8000 + ((b)-1)*400 + ((c)-1)*20 + (d))

struct Route {
  vector<char> route;  
  friend bool operator < (const Route &a, const Route &b) {
    if (a.route.size() > 0 && b.route.size() == 0) return true;
    if (a.route.size() == 0 && b.route.size() > 0) return false;
    if (a.route.size() == 0 && b.route.size() == 0) return false;
    if (a.route.size() < b.route.size()) return true;
    if (a.route.size() > b.route.size()) return false;
    for (int i = 0; i < a.route.size(); ++ i) {
      if (a.route[i] < b.route[i]) return true;
      if (a.route[i] > b.route[i]) return false;
    }
    return false;
  }
  Route push_back(char s) {
    Route r;
    r.route = vector<char>(route);
    r.route.push_back(s);
    return r;
  }
};

#define NODE_N 160020
#define EDGE_N 640020

int head[NODE_N], nxt[EDGE_N], to[EDGE_N], cnt;
char type[EDGE_N];

void insert(int x, int y, char t) {
  to[++ cnt] = y;
  type[cnt] = t;
  nxt[cnt] = head[x];
  head[x] = cnt;
}

struct Fuck {
  int x;
  Route s;
  friend bool operator < (const Fuck &a, const Fuck &b) {
    return b.s < a.s;
  }
};

Route dist[NODE_N];
priority_queue<Fuck> q;

int main() {
  for (int i = 1; i <= 20; ++ i) {
    scanf("%s", str + 1);
    for (int j = 1; j <= 20; ++ j) {
      a[i][j] = str[j] == '.';
    }
    scanf("%s", str + 1);
    for (int j = 1; j <= 20; ++ j) {
      b[i][j] = str[j] == '.';
    }
  }
  // debug
  // for (int i = 1; i <= 20; ++ i) {
  //   for (int j = 1; j <= 20; ++ j) {
  //     putchar("#."[a[i][j]]);
  //   }
  //   putchar(' ');
  //   for (int j = 1; j <= 20; ++ j) {
  //     putchar("#."[b[i][j]]);
  //   }
  //   putchar('\n');
  // }

  int cnt = 0;
  for (int i = 1; i <= 20; ++ i) {
    for (int j = 1; j <= 20; ++ j) {
      for (int k = 1; k <= 20; ++ k) {
        for (int l = 1; l <= 20; ++ l) {
          int from = id(i, j, k, l);
          assert(from == ++ cnt);
          if (a[i+1][j] || b[k+1][l]) {
            int into = id(i + a[i+1][j], j, k + b[k+1][l], l);
            insert(from, into, 1);
          }
          if (a[i][j-1] || b[k][l+1]) {
            int into = id(i, j - a[i][j-1], k, l + b[k][l+1]);
            insert(from, into, 2);
          }
          if (a[i][j+1] || b[k][l-1]) {
            int into = id(i, j + a[i][j+1], k, l - b[k][l-1]);
            insert(from, into, 3);
          }
          if (a[i-1][j] || b[k-1][l]) {
            int into = id(i - a[i-1][j], j, k - b[k-1][l], l);
            insert(from, into, 4);
          }
        }
      }
    }
  }

  q.push(Fuck { id(20, 20, 20, 1), { } });
  while (!q.empty()) {
    Fuck damn = q.top();
    q.pop();

    if (dist[damn.x] < damn.s) {
      continue;
    }

    for (int i = head[damn.x]; i; i = nxt[i]) {
      int y = to[i];
      char t = type[i];

      Route s = damn.s.push_back(t);
      if (s < dist[y]) {
        dist[y] = s;
        q.push(Fuck { y, s });
      }
    }
  }

  Route ans = dist[id(1, 20, 1, 1)];
  printf("%d\n", (int) ans.route.size());

  int x1 = 20, y1 = 20;
  int x2 = 20, y2 = 1;
  
  a[x1][y1] = 2;
  b[x2][y2] = 2;
  for (char c : ans.route) {
    putchar("DLRU"[c-1]);
    // putchar('\n');

    // D
    if (c == 1) {
      if (a[x1+1][y1]) x1 ++;
      if (b[x2+1][y2]) x2 ++;
    }
    // L
    if (c == 2) {
      if (a[x1][y1-1]) y1 --;
      if (b[x2][y2+1]) y2 ++;
    }
    // R
    if (c == 3) {
      if (a[x1][y1+1]) y1 ++;
      if (b[x2][y2-1]) y2 --;
    }
    // U
    if (c == 4) {
      if (a[x1-1][y1]) x1 --;
      if (b[x2-1][y2]) x2 --;
    }
    a[x1][y1] = 2;
    b[x2][y2] = 2;
    // printf("%d %d, %d %d\n", x1, y1, x2, y2);
  }
  putchar('\n');

  for (int i = 1; i <= 20; ++ i) {
    for (int j = 1; j <= 20; ++ j) {
      putchar("#.A"[a[i][j]]);
    }
    putchar(' ');
    for (int j = 1; j <= 20; ++ j) {
      putchar("#.A"[b[i][j]]);
    }
    putchar('\n');
  }

  return 0;
}
