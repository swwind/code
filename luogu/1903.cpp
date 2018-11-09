#include <bits/stdc++.h>
#define N 400020
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
struct nodejs {
  ll pos, w;
} ask[N];
struct webpack {
  ll l, r, id, cur;
} w[N];
ll ctc, q, n, Q, a[N], lbc[N], sum[N], answ[N], zyy;
map <ll, ll> mp;
bool cmp(webpack a, webpack b) {
  return a.l / 3000 == b.l / 3000
    ? (a.r / 3000 == b.r / 3000
      ? a.cur < b.cur
      : a.r / 3000 < b.r / 3000)
    : a.l < b.l;
}
ll ans;
void add(int x) {
  if (!sum[x]) ans ++;
  sum[x] ++;
}
void del(int x) {
  sum[x] --;
  if (!sum[x]) ans --;
}
void change(ll x, ll l, ll r) {
  if (ask[x].pos >= l && ask[x].pos <= r)
    del(a[ask[x].pos]);
  swap(a[ask[x].pos], ask[x].w);
  if (ask[x].pos >= l && ask[x].pos <= r)
    add(a[ask[x].pos]);
}
void solve() {
  ll l = 1, r = 1, k = 0;
  add(a[1]);
  for (int i = 1; i <= q; i++) {
    while (r > w[i].r) del(a[r--]);
    while (r < w[i].r) add(a[++r]);
    while (l > w[i].l) add(a[--l]);
    while (l < w[i].l) del(a[l++]);
    while (k < w[i].cur) change(++k, l, r);
    while (k > w[i].cur) change(k--, l, r);
    answ[w[i].id] = ans;
  }
}
char op[2];
int main(int argc, char const *argv[]) {
  n = read(), Q = read();
  for (int i = 1; i <= n; i++) {
    int x = read();
    a[i] = mp[x] ? mp[x] : (mp[x] = ++ctc);
  }
  for (int i = 1; i <= Q; i++) {
    scanf("%s", op);
    if (op[0] == 'R') {
      ask[++zyy].pos = read();
      ask[zyy].w = read();
      ask[zyy].w = mp[ask[zyy].w]
        ? mp[ask[zyy].w]
        : (mp[ask[zyy].w] = ++ctc);
    } else {
      w[++q].l = read();
      w[q].r   = read();
      w[q].id  = q;
      w[q].cur = zyy;
    }
  }
  sort(w + 1, w + q + 1, cmp);
  solve();
  for (int i = 1; i <= q; i++)
    cout << answ[i] << endl;
  return 0;
}