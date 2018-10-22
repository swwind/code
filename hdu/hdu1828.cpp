#include <cstdio>
#include <algorithm>
#define N 20020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

namespace __segment_tree {

int lz[N<<2], zs[N<<2];

void push_up(int x) {
  if (!lz[x]) {
    zs[x] = zs[x << 1] + zs[x << 1 | 1];
  } else {
    zs[x] = 0;
  }
}

void build(int x, int l, int r) {
  zs[x] = r - l + 1;
  lz[x] = 0;
  if (l != r) {
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
  }
}

int queryZeros(int x, int l, int r, int L, int R) {
  // if (x == 1) printf("Query (%d, %d)\n", l, r);
  if (lz[x]) return 0;
  if (l == L && r == R) {
    // printf("Ans [%d, %d] = %d\n", l, r, zs[x]);
    // printf(" |- ls = %d\n", zs[x << 1]);
    // printf(" `- rs[%d, %d] = %d\n", (L+R)/2+1, R,zs[x << 1 | 1]);
    return zs[x];
  }
  int mid = (L + R) >> 1;
  if (r <= mid) return queryZeros(x << 1, l, r, L, mid);
  else if (l > mid) return queryZeros(x << 1 | 1, l, r, mid + 1, R);
  return queryZeros(x << 1, l, mid, L, mid) + queryZeros(x << 1 | 1, mid + 1, r, mid + 1, R);
}
void addOne(int x, int l, int r, int L, int R) {
  // if (x == 1) printf("Add One (%d, %d)\n", l, r);
  if (l == L && r == R) {
    ++ lz[x];
    zs[x] = 0;
    // printf("++ [%d, %d]\n", l, r);
    return;
  }
  int mid = (L + R) >> 1;
  if (r <= mid) addOne(x << 1, l, r, L, mid);
  else if (l > mid) addOne(x << 1 | 1, l, r, mid + 1, R);
  else addOne(x << 1, l, mid, L, mid), addOne(x << 1 | 1, mid + 1, r, mid + 1, R);
  push_up(x);
}
void delOne(int x, int l, int r, int L, int R) {
  // if (x == 1) printf("Del One (%d, %d)\n", l, r);
  if (l == L && r == R) {
    if (! -- lz[x]) {
      zs[x] = l == r ? 1 : zs[x << 1] + zs[x << 1 | 1];
    }
    return;
  }
  int mid = (L + R) >> 1;
  if (r <= mid) delOne(x << 1, l, r, L, mid);
  else if (l > mid) delOne(x << 1 | 1, l, r, mid + 1, R);
  else delOne(x << 1, l, mid, L, mid), delOne(x << 1 | 1, mid + 1, r, mid + 1, R);
  push_up(x);
}

} // namespace __segment_tree

using namespace __segment_tree;

struct Query {
  int l, r, v, id;
  Query(){}
  Query(int l, int r, int v, int id):l(l),r(r),v(v),id(id){}
} qx[N], qy[N];
int xnt, ynt;

bool cmp(const Query &a, const Query &b) {
  return a.id < b.id;
}

const int offset = 1e4 + 1;
const int maxsiz = 2e4 + 1;

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  for (int n; ~scanf("%d", &n);) {

    xnt = ynt = 0;
    for (int i = 1; i <= n; ++ i) {
      int x1 = read(), y1 = read();
      int x2 = read(), y2 = read();

      qx[++ xnt] = Query(x1 + offset, x2 + offset, 1, y1);
      qx[++ xnt] = Query(x1 + offset, x2 + offset,-1, y2);

      qy[++ ynt] = Query(y1 + offset, y2 + offset, 1, x1);
      qy[++ ynt] = Query(y1 + offset, y2 + offset,-1, x2);
    }

    sort(qx + 1, qx + xnt + 1, cmp);
    sort(qy + 1, qy + ynt + 1, cmp);

    int ans = 0;

    build(1, 1, maxsiz);

    for (int i = 1; i <= xnt; ++ i) {
      Query &q = qx[i];
      // printf("%d %d %d\n", q.l, q.r - 1, q.v);
      if (q.v == 1) {
        ans += queryZeros(1, q.l, q.r - 1, 1, maxsiz);
        addOne(1, q.l, q.r-1, 1, maxsiz);
      } else {
        delOne(1, q.l, q.r-1, 1, maxsiz);
        ans += queryZeros(1, q.l, q.r - 1, 1, maxsiz);
      }
      // printf("%d\n", ans);
    }

    // printf("%d\n", ans);

    build(1, 1, maxsiz);

    for (int i = 1; i <= ynt; ++ i) {
      Query &q = qy[i];
      if (q.v == 1) {
        ans += queryZeros(1, q.l, q.r - 1, 1, maxsiz);
        addOne(1, q.l, q.r-1, 1, maxsiz);
      } else {
        delOne(1, q.l, q.r-1, 1, maxsiz);
        ans += queryZeros(1, q.l, q.r - 1, 1, maxsiz);
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
