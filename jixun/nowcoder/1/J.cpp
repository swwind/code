#include <bits/stdc++.h>
#define N 1000020

using namespace std;

struct Node {
  int a, b, c;

  friend Node operator + (const Node &a, const Node &b) {
    // int c1 = a.c, c2 = a.b - a.a + a.c;
    if (a.c >= b.b) {
      return {0, 0, 0};
    }
    if (a.c >= b.a) {
      Node ret;
      ret.a = a.a;
      ret.b = min(b.b - a.c + a.a, a.b);
      ret.c = a.c - b.a + b.c;
      return ret;
    }
    if (a.b - a.a + a.c <= b.a) {
      Node ret;
      ret.a = a.b;
      ret.b = a.b;
      ret.c = b.c;
      return ret;
    }
    Node ret;
    ret.a = b.a - a.c + a.a;
    ret.b = min(b.b - a.c + a.a, a.b);
    ret.c = b.c;
    return ret;
  }

  static Node from(int u, int v, int t) {
    if (t > v) return {0, 0, 0};
    if (t > u) return {0, v-t, u};
    return Node{u-t, v-t, u};
  }
} node[N<<2];

int u[N], v[N], t[N];

Node query(int x, int L, int R, int l, int r) {
  if (l == L && r == R) {
    return node[x];
  }
  int mid = (L + R) >> 1;
  if (r <= mid) return query(x << 1, L, mid, l, r);
  if (l > mid) return query(x << 1 | 1, mid + 1, R, l, r);
  return query(x << 1, L, mid, l, mid) + query(x << 1 | 1, mid + 1, R, mid + 1, r);
}

void update(int x, int l, int r, int k) {
  if (l == r) {
    node[x] = Node::from(u[k], v[k], t[k]);
    return;
  }
  int mid = (l + r) >> 1;
  if (k <= mid) update(x << 1, l, mid, k);
  else update(x << 1 | 1, mid + 1, r, k);
  node[x] = node[x << 1] + node[x << 1 | 1];
}

void build(int x, int l, int r) {
  if (l == r) {
    node[x] = Node::from(u[l], v[l], t[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  node[x] = node[x << 1] + node[x << 1 | 1];
  // printf("[%d, %d], a=%d, b=%d, c=%d\n", l, r, node[x].a, node[x].b, node[x].c);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
  
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &u[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &v[i]);
    }
    for (int i = 2; i <= n; ++i) {
      scanf("%d", &t[i]);
    }

    build(1, 1, n);

    int m;
    scanf("%d", &m);

    for (int i = 1; i <= m; ++ i) {
      int op;
      scanf("%d", &op);

      if (op == 0) {
        int l, r;
        scanf("%d%d", &l, &r);
        Node node = query(1, 1, n, l+1, r);
        // printf("%d, %d, %d\n", node.a, node.b, node.c);
        puts(u[l] <= node.b ? "YES" : "NO");
      } else if (op == 1) {
        int k, t;
        scanf("%d%d", &k, &t);
        ++ k;
        ::t[k] = t;
        update(1, 1, n, k);
      } else if (op == 2) {
        int k, u, v;
        scanf("%d%d%d", &k, &u, &v);
        ::u[k] = u;
        ::v[k] = v;
        update(1, 1, n, k);
      }
    }

  }
}
