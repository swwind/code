#include <bits/stdc++.h>
#define N 1020
using namespace std;

int rr[N*N], dd[N*N], rd[N*N];
int br[N*N], bd[N*N], bl[N*N], bu[N*N];
int n, m;

int a[N][N];

void work(int x, int y) {
  for (int i = x; i <= n; i += 2) {
    for (int j = y; j <= m; j += 2) {
      if (i == x && j == y) continue;

      if (i == x) {
        a[i][j] = rr[a[i][j - 2]];
      } else {
        a[i][j] = dd[a[i - 2][j]];
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);

  int left_top_right = 0;
  int left_top_down = 0;
  for (int i = 1; i <= n*m; ++ i) {
    int u, d, l, r;
    scanf("%d%d%d%d", &u, &d, &l, &r);
    if (!u && !l) {
      // left top coner
      left_top_right = r;
      left_top_down = d;
    }
    dd[u] = d;
    rr[l] = r;
    ++ bu[u];
    ++ bd[d];
    ++ bl[l];
    ++ br[r];
    rd[l] = d;
  }
  int left_top = 0;
  int left_top_down_right = 0;
  for (int i = 1; i <= n*m; ++ i) {
    if (bl[i] == 1 && bu[i] == 1 && !br[i] && !bd[i]) {
      left_top = i;
      left_top_down_right = rd[i];
      break;
    }
  }
  // printf("%d %d\n", left_top, left_top_right);
  // printf("%d %d\n", left_top_down, left_top_down_right);

  a[1][1] = left_top;
  a[1][2] = left_top_right;
  a[2][1] = left_top_down;
  a[2][2] = left_top_down_right;
  work(1, 1);
  work(1, 2);
  work(2, 1);
  work(2, 2);

  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      printf("%d%c", a[i][j], " \n"[j == m]);
    }
  }
  
}
/*
3 3
0 8 0 4
4 9 8 7
7 0 9 0
0 7 4 0
8 0 0 9

0 2 5 6
5 3 0 2
6 1 2 0
2 0 3 1

0 1 0 1 0
1 0 1 0 1
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0

*/