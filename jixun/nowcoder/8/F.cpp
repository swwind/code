#include <bits/stdc++.h>
#define N 505
#define Q 500020

#define mod 998244353

using namespace std;

bitset<N*N> f[N];
int a[N][N], b[N][N], c[N][N];
int ans[Q];

bool work1(int x1, int y1, int x2, int y2) {
  if (y1 > y2) return false;
  if (x1 > x2) return false;

  if (y1 != y2) return false;
  if (x1 == 0) return c[x2][y2] == 0;
  else return c[x2][y2] == c[x1-1][y1];
}

bool work2(int x1, int y1, int x2, int y2) {
  if (y1 > y2) return false;
  if (x1 > x2) return false;

  if (x1 != x2) return false;
  if (y1 == 0) return b[x2][y2] == 0;
  else return b[x2][y2] == b[x1][y1-1];
}

struct Query {
  int x1, y1;
  int id;
};

vector<Query> qs[N][N];

int top;

char str[N];

int main() {

  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++ i) {
    scanf("%s", str);
    for (int j = 0; j < m; ++ j) {
      a[i][j] = str[j] - '0';
      b[i][j] = a[i][j];
      c[i][j] = a[i][j];
    }
  }
  for (int i = 0; i < n; ++ i) {
    for (int j = 1; j < m; ++ j) {
      b[i][j] += b[i][j - 1];
    }
  }
  for (int i = 1; i < n; ++ i) {
    for (int j = 0; j < m; ++ j) {
      c[i][j] += c[i - 1][j];
    }
  }

  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++ i) {
    int t, x1, y1, x2, y2;
    scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
    -- x1; -- y1; -- x2; -- y2;
    if (t == 1) {
      ans[i] = work1(x1, y1, x2, y2);
    } else if (t == 2) {
      ans[i] = work2(x1, y1, x2, y2);
    } else if (t == 3) {
      qs[x2][y2].push_back(Query{x1, y1, i});
    }
  }

  for (int i = 0; i < n; ++ i) {
    if (a[i][0]) {
      // a[i][0] is wall
      f[0].reset();
    } else {
      // a[i][0] is empty
      f[0][i*N] = 1;
    }

    for (auto q : qs[i][0]) {
      ans[q.id] = f[0][q.x1*N+q.y1];
    }

    for (int j = 1; j < m; ++ j) {
      if (a[i][j]) {
        // a[i][j] is wall
        f[j].reset();
      } else {
        f[j] |= f[j-1];
        f[j][i*N+j] = 1;
      }

      for (auto q : qs[i][j]) {
        ans[q.id] = f[j][q.x1*N+q.y1];
      }
    }
  }

  for (int i = 0; i < q; ++ i) {
    puts(ans[i] ? "yes" : "no");
  }
}
