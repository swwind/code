#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int mx[N<<2];
void build(int x, int l, int r) {
  if (l == r) {
    mx[x] = read();
    return;
  }
  int mid = l + r >> 1;
  build(x << 1, l, mid);
  build(x<<1|1, mid + 1, r);
  mx[x] = max(mx[x << 1], mx[x<<1|1]);
}
int query(int x, int l, int r, int L, int R) {
  if (l == L && r == R)
    return mx[x];
  int mid = L + R >> 1;
  if (r <= mid) return query(x << 1, l, r, L, mid);
  if (l > mid) return query(x<<1|1, l, r, mid + 1, R);
  return max(query(x << 1, l, mid, L, mid), query(x<<1|1, mid + 1, r, mid + 1, R));
}
void update(int x, int k, int L, int R, int v) {
  if (L == R) {
    mx[x] = max(mx[x], v);
    return;
  }
  int mid = L + R >> 1;
  if (k <= mid) update(x << 1, k, L, mid, v);
  else update(x<<1|1, k, mid + 1, R, v);
  mx[x] = max(mx[x << 1], mx[x<<1|1]);
}
char ch[5];
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  build(1, 1, n);
  while (m --) {
    scanf("%s", ch);
    int x = read(), y = read();
    if (ch[0] == 'Q') printf("%d\n", query(1, x, y, 1, n));
    else update(1, x, 1, n, y);
  }
  return 0;
}