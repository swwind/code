#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
struct node {
  int h, l, r;
  friend bool operator < (const node &a, const node &b) {
    return a.h < b.h;
  }
}a[N];
int tg[N<<3], vl[N<<3];
void push_down(int x) {
  if (tg[x]) {
    vl[x << 1] = tg[x];
    vl[x<<1|1] = tg[x];
    tg[x << 1] = tg[x];
    tg[x<<1|1] = tg[x];
    tg[x] = 0;
  }
}
void update(int x, int l, int r, int L, int R, int v) {
  if (l > r) return;
  if (l == L && r == R) {
    tg[x] = vl[x] = v;
    return;
  }
  push_down(x);
  int m = (L + R) >> 1;
  if (r <= m) update(x << 1, l, r, L, m, v);
  else if (l > m) update(x<<1|1, l, r, m + 1, R, v);
  else update(x << 1, l, m, L, m, v), update(x<<1|1, m + 1, r, m + 1, R, v);
}
int ask(int x, int k, int L, int R) {
  if (L == R)
    return vl[x];
  push_down(x);
  int m = (L + R) >> 1;
  if (k <= m) return ask(x << 1, k, L, m);
  else        return ask(x<<1|1, k, m + 1, R);
}
long long b[N<<1], cnt;
int gl[N], gr[N];
long long fl[N], fr[N];
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  int stx = read(), sty = read();
  b[++cnt] = stx;
  for (int i = 1; i <= n; i++) {
    a[i].h = read();
    if (a[i].h > sty) {
      read(); read();
      i --, n --;
      continue;
    }
    b[++cnt] = a[i].l = read();
    b[++cnt] = a[i].r = read();
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + cnt + 1);
  cnt = unique(b + 1, b + cnt + 1) - b - 1;
  for (int i = 1; i <= n; i++) {
    a[i].l = lower_bound(b + 1, b + cnt + 1, a[i].l) - b;
    a[i].r = lower_bound(b + 1, b + cnt + 1, a[i].r) - b;
    gl[i] = ask(1, a[i].l, 1, cnt);
    gr[i] = ask(1, a[i].r, 1, cnt);
    update(1, a[i].l + 1, a[i].r - 1, 1, cnt, i);
  }
  stx = lower_bound(b + 1, b + cnt + 1, stx) - b;
  // for (int i = 1; i <= n; i++)
  //   cout << gl[i] << " " << gr[i] << endl;
  // cout << endl;
  long long ans = 1ll << 60;
  memset(fl, 63, sizeof fl);
  memset(fr, 63, sizeof fr);
  int st = ask(1, stx, 1, cnt);
  fl[st] = sty - a[st].h + b[stx] - b[a[st].l];
  fr[st] = sty - a[st].h + b[a[st].r] - b[stx];
  for (int i = st; i; i--) {
    if (a[i].h - a[gl[i]].h <= m) { // 如果该平台的左端点能掉下去
      fl[gl[i]] = min(fl[gl[i]], fl[i] + a[i].h - a[gl[i]].h + b[a[i].l] - b[a[gl[i]].l]);
      fr[gl[i]] = min(fr[gl[i]], fl[i] + a[i].h - a[gl[i]].h + b[a[gl[i]].r] - b[a[i].l]);
      if (!gl[i])
        ans = min(ans, fl[i] + a[i].h);
    }
    if (a[i].h - a[gr[i]].h <= m) { // 如果该平台的右端点能掉下去
      fl[gr[i]] = min(fl[gr[i]], fr[i] + a[i].h - a[gr[i]].h + b[a[i].r] - b[a[gr[i]].l]);
      fr[gr[i]] = min(fr[gr[i]], fr[i] + a[i].h - a[gr[i]].h + b[a[gr[i]].r] - b[a[i].r]);
      if (!gr[i])
        ans = min(ans, fr[i] + a[i].h);
    }
  }
  // for (int i = 1; i <= st; i++)
  //   cout << fl[i] << " " << fr[i] << endl;
  cout << ans << endl;
  return 0;
}
// 15418021011393200024