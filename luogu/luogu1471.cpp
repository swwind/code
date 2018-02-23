#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int readint(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
inline double read(){
  double x;
  cin >> x;
  return x;
}
double sum[N<<2], tag[N<<2], sm2[N<<2];
void build(int x, int l, int r) {
  if (l == r) {
    sum[x] = read();
    sm2[x] = sum[x] * sum[x];
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x<<1|1, mid + 1, r);
  sum[x] = sum[x << 1] + sum[x<<1|1];
  sm2[x] = sm2[x << 1] + sm2[x<<1|1];
}
void push_down(int x, int l, int r) {
  if (tag[x]) {
    int mid = (l + r) >> 1;
    tag[x << 1] += tag[x];
    sm2[x << 1] += 2 * tag[x] * sum[x << 1] + (mid - l + 1) * tag[x] * tag[x];
    sum[x << 1] += (mid - l + 1) * tag[x];
    tag[x<<1|1] += tag[x];
    sm2[x<<1|1] += 2 * tag[x] * sum[x<<1|1] + (r - mid) * tag[x] * tag[x];
    sum[x<<1|1] += (r - mid) * tag[x];
    tag[x] = 0;
  }
}
void push_up(int x) {
  sm2[x] = sm2[x << 1] + sm2[x<<1|1];
  sum[x] = sum[x << 1] + sum[x<<1|1];
}
void update(int x, int l, int r, int L, int R, double k) {
  if (l == L && r == R) {
    tag[x] += k;
    sm2[x] += 2 * k * sum[x] + (r - l + 1) * k * k;
    sum[x] += (r - l + 1) * k;
    return;
  }
  push_down(x, L, R);
  int mid = (L + R) >> 1;
  if (r <= mid) update(x << 1, l, r, L, mid, k);
  else if (l > mid) update(x<<1|1, l, r, mid + 1, R, k);
  else update(x << 1, l, mid, L, mid, k), update(x<<1|1, mid + 1, r, mid + 1, R, k);
  push_up(x);
}
double asksum(int x, int l, int r, int L, int R) {
  if (l == L && r == R)
    return sum[x];
  push_down(x, L, R);
  int mid = (L + R) >> 1;
  if (r <= mid) return asksum(x << 1, l, r, L, mid);
  if (l > mid) return asksum(x<<1|1, l, r, mid + 1, R);
  return asksum(x << 1, l, mid, L, mid) + asksum(x<<1|1, mid + 1, r, mid + 1, R);
}
double asksm2(int x, int l, int r, int L, int R) {
  if (l == L && r == R)
    return sm2[x];
  push_down(x, L, R);
  int mid = (L + R) >> 1;
  if (r <= mid) return asksm2(x << 1, l, r, L, mid);
  if (l > mid) return asksm2(x<<1|1, l, r, mid + 1, R);
  return asksm2(x << 1, l, mid, L, mid) + asksm2(x<<1|1, mid + 1, r, mid + 1, R);
}
int main(int argc, char const *argv[]) {
  int n = readint(), q = readint();
  build(1, 1, n);
  while (q --) {
    int op = readint();
    if (op == 1) {
      int l = readint(), r = readint();
      double k = read();
      // printf("%.8lf\n", k);
      update(1, l, r, 1, n, k);
    }
    if (op == 2) {
      int l = readint(), r = readint();
      double sum = asksum(1, l, r, 1, n);
      printf("%.4lf\n", sum / (r - l + 1));
    }
    if (op == 3) {
      int l = readint(), r = readint();
      double sum = asksum(1, l, r, 1, n);
      double a = sum / (r - l + 1);
      double sm2 = asksm2(1, l, r, 1, n) - 2 * a * sum + (r - l + 1) * a * a;
      printf("%.4lf\n", sm2 / (r - l + 1));
    }
  }
  return 0;
}
/*
                           _   _
s^2 * n = \sum{ai^2 - 2*ai*a + a^2}
                         _              _
s^2 * n = \sum{ai^2} - 2*a*\sum{ai} + n*a^2

sm2[x] = \sum{ai^2} => \sum{(ai+k)^2}
= \sum{ai^2}+2*k*\sum{ai}+n*k^2

*/