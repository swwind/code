#include <bits/stdc++.h>
#define N 100020
#define lch o << 1
#define rch o << 1 | 1
#define mid ((l + r) >> 1)
using namespace std; inline int read(){ int x=0,f=1;char ch=getchar();
while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar(); return f?x:-x; }
int c, r1, c1, r2, c2; char op; bool ru[N], rd[N]; struct Data { int l, r;
bool luru, ldrd, luld, rurd, lurd, ldru; } tree[N << 2]; inline Data
merge(const Data &ls, const Data &rs) { Data rt; rt.l = ls.l; rt.r = rs.r;
rt.luru = (ls.luru && ru[ls.r] && rs.luru) || (ls.lurd && rd[ls.r] &&
rs.ldru); rt.lurd = (ls.luru && ru[ls.r] && rs.lurd) || (ls.lurd && rd[ls.r]
&& rs.ldrd); rt.ldru = (ls.ldru && ru[ls.r] && rs.luru) || (ls.ldrd &&
rd[ls.r] && rs.ldru); rt.ldrd = (ls.ldru && ru[ls.r] && rs.lurd) || (ls.ldrd
&& rd[ls.r] && rs.ldrd); rt.luld = ls.luld || (ls.luru && ru[ls.r] && rs.luld
&& rd[ls.r] && ls.ldrd); rt.rurd = rs.rurd || (rs.luru && ru[ls.r] && ls.rurd
&& rd[ls.r] && rs.ldrd); return rt; } inline void build(int o, int l, int r) {
if (l == r) { tree[o].l = tree[o].r = l; tree[o].luru = tree[o].ldrd = true;
return; } build(lch, l, mid); build(rch, mid + 1, r); tree[o] =
merge(tree[lch], tree[rch]); } inline void modify1(int o, int l, int r, int x,
bool comm) { if (l == r) { tree[o].luld = tree[o].rurd = tree[o].lurd =
tree[o].ldru = comm; return; } if (x <= mid) modify1(lch, l, mid, x, comm); if
(x > mid) modify1(rch, mid + 1, r, x, comm); tree[o] = merge(tree[lch],
tree[rch]); } inline void modify2(int o, int l, int r, int x, bool up, bool
comm) { if (mid == x) { if(up) ru[x] = comm; else rd[x] = comm; tree[o] =
merge(tree[lch], tree[rch]); return; } if (x <= mid) modify2(lch, l, mid, x,
up, comm); if (x > mid) modify2(rch, mid + 1, r, x, up, comm); tree[o] =
merge(tree[lch], tree[rch]); } inline Data query(int o, int l, int r, int ll,
int rr) { if (l >= ll && r <= rr) { return tree[o]; } if (rr <= mid) { return
query(lch, l, mid, ll, rr); } else if (ll > mid) { return query(rch, mid + 1,
r, ll, rr); } else { return merge(query(lch, l, mid, ll, mid), query(rch, mid
+ 1, r, mid + 1, rr)); } } char str[10]; int main() { c = read(); build(1, 1,
c); for (;;) { scanf("%s", str); char op = str[0]; if (op == 'E') break; r1 =
read(); c1 = read(); r2 = read(); c2 = read(); if (c1 > c2) { std::swap(r1,
r2); std::swap(c1, c2); } if (op == 'O') { if (r1 == r2) { modify2(1, 1, c,
c1, r1 == 1, true); } else { modify1(1, 1, c, c1, true); } } if (op == 'C') {
if (r1 == r2) { modify2(1, 1, c, c1, r1 == 1, false); } else { modify1(1, 1,
c, c1, false); } } if (op == 'A') { Data rm = query(1, 1, c, c1, c2), rl =
query(1, 1, c, 1, c1),  rr = query(1, 1, c, c2, c); bool b1, b2, b3, b4; if
(r1 == 1 && r2 == 1) { b1 = rm.luru; b2 = rl.rurd && rm.ldru; b3 = rr.luld &&
rm.lurd; b4 = rl.rurd && rm.ldrd && rr.luld; if(b1 || b2 || b3 || b4)
printf("Y\n"); else printf("N\n"); } else if (r1 == 1 && r2 == 2) { b1 =
rm.lurd; b2 = rl.rurd && rm.ldrd; b3 = rr.luld && rm.luru; b4 = rl.rurd &&
rm.ldru && rr.luld; if(b1 || b2 || b3 || b4) printf("Y\n"); else
printf("N\n"); } else if (r1 == 2 && r2 == 1) { b1 = rm.ldru; b2 = rl.rurd &&
rm.luru; b3 = rr.luld && rm.ldrd; b4 = rl.rurd && rm.lurd && rr.luld; if(b1 ||
b2 || b3 || b4) printf("Y\n"); else printf("N\n"); } else { b1 = rm.ldrd; b2 =
rl.rurd && rm.lurd; b3 = rr.luld && rm.ldru; b4 = rl.rurd && rm.luru &&
rr.luld; if(b1 || b2 || b3 || b4) printf("Y\n"); else printf("N\n"); } } }
return 0; }
