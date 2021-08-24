#include <bits/stdc++.h>
#define N 100020

using namespace std;

int n, d;

struct Rectangle {
  int x1, y1, x2, y2;
  friend bool operator < (const Rectangle &a, const Rectangle &b) {
    return a.x2 > b.x2;
  }
} rec[N<<2];

bool cmp(const Rectangle &a, const Rectangle &b) {
  return a.x1 < b.x1;
}

int top;

inline void insert_rectangle(int x1, int y1, int x2, int y2) {
  // printf("[ %d, %d, %d, %d ]\n", x1, y1, x2, y2);
  rec[++ top] = { x1, y1, x2, y2 };
}

priority_queue<Rectangle> q;

int val[N<<2], delta[N<<2], pos[N<<2];

void push_up(int x) {
  val[x] = min(val[x<<1], val[x<<1|1]);
  if (val[x<<1] < val[x<<1|1]) {
    pos[x] = pos[x<<1];
  } else {
    pos[x] = pos[x<<1|1];
  }
}
void push_down(int x) {
  delta[x << 1] += delta[x];
  delta[x<<1|1] += delta[x];
  val[x << 1] += delta[x];
  val[x<<1|1] += delta[x];
  delta[x] = 0;
}
void build(int x, int l, int r) {
  if (l == r) {
    pos[x] = l;
    return;
  }
  int mid = l + r >> 1;
  build(x << 1, l, mid);
  build(x<<1|1, mid+1, r);
  push_up(x);
}

void update(int x, int L, int R, int l, int r, int v) {
  // printf("(%d, %d), (%d, %d)\n", L, R, l, r);
  if (l == L && r == R) {
    delta[x] += v;
    val[x] += v;
    // fuck_down(x, L, R);
    return;
  }
  push_down(x);
  int mid = L + R >> 1;
  if (l > mid) update(x<<1|1, mid+1, R, l, r, v);
  else if (r <= mid) update(x << 1, L, mid, l, r, v);
  else {
    update(x << 1, L, mid, l, mid, v);
    update(x<<1|1, mid+1, R, mid+1, r, v);
  }
  push_up(x);
  // printf("[%d, %d] has zero: %d\n", L, R, ans[x].has_zero);
}

int ansx, ansy;
inline bool scan() {
  sort(rec + 1, rec + top + 1, cmp);
  build(1, 0, d-1);

  int now = 1;
  for (int i = 0; i < d; ++ i) {
    while (now <= top && rec[now].x1 <= i) {
      q.push(rec[now]);
      // printf("update %d %d +1\n", rec[now].y1, rec[now].y2);
      update(1, 0, d-1, rec[now].y1, rec[now].y2, 1);
      ++ now;
    }
    while (!q.empty() && q.top().x2 < i) {
      auto r = q.top(); q.pop();
      // printf("update %d %d -1\n", r.y1, r.y2);
      update(1, 0, d-1, r.y1, r.y2, -1);
    }
    if (val[1] == 0) {
      ansx = i;
      ansy = pos[1];
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &d);

  for (int i = 1; i <= n; ++ i) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    int x1d = (x1 % d + d) % d;
    int y1d = (y1 % d + d) % d;
    int x2d = (x2 % d + d) % d; if (!x2d) x2d = d;
    int y2d = (y2 % d + d) % d; if (!y2d) y2d = d;

    vector<pair<int, int>> xx, yy;

    // d = 3
    //     |     |     |
    //      0 1 2 3 4 5 6
    // x1d: 0 1 2 0 1 2 0
    // x2d: 3 1 2 3 1 2 3
    if (x2 - x1 >= d) {
      xx.push_back(make_pair(0, d - 1));
    } else if (x2d > x1d) {
      xx.push_back(make_pair(x1d, x2d - 1));
    } else {
      xx.push_back(make_pair(0, x2d - 1));
      xx.push_back(make_pair(x1d, d - 1));
    }

    if (y2 - y1 >= d) {
      yy.push_back(make_pair(0, d - 1));
    } else if (y2d > y1d) {
      yy.push_back(make_pair(y1d, y2d - 1));
    } else {
      yy.push_back(make_pair(0, y2d - 1));
      yy.push_back(make_pair(y1d, d - 1));
    }

    for (auto xp : xx) {
      for (auto yp : yy) {
        insert_rectangle(xp.first, yp.first, xp.second, yp.second);
      }
    }
  }

  if (scan()) {
    printf("YES\n%d %d\n", ansx, ansy);
  } else {
    puts("NO");
  }

}