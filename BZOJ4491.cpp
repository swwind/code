#include <bits/stdc++.h>
#define N 50020
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct tree{
	int val[50020];
	struct node{
		int lx, rx, l, r, mx;
	}tr[N<<2];
	node merge(const node &a, const node &b){
		node c; c.l = a.l, c.r = b.r;
		c.lx = a.lx, c.rx = b.rx; c.mx = max(a.mx, b.mx);
		if(c.lx == a.r-a.l+1 && val[a.r] <= val[a.r+1]) c.lx += b.lx;
		if(c.rx == b.r-b.l+1 && val[a.r] <= val[a.r+1]) c.rx += a.rx;
		if(val[a.r] <= val[a.r+1]) c.mx = max(c.mx, a.rx+b.lx);
		return c;
	}
	void build(int x, int l, int r){
		if(l == r){
			tr[x].l = l, tr[x].r = r;
			tr[x].mx = tr[x].lx = tr[x].rx = 1;
			return;
		}
		int mid = l + r >> 1;
		build(x<<1, l, mid); build(x<<1|1, mid+1, r);
		tr[x] = merge(tr[x<<1], tr[x<<1|1]);
	}
	node ask(int x, int l, int r){
		if(tr[x].l == l && tr[x].r == r) return tr[x];
		int mid = tr[x].l + tr[x].r >> 1;
		if(r <= mid) return ask(x<<1, l, r);
		else if(l > mid) return ask(x<<1|1, l, r);
		else return merge(ask(x<<1, l, mid), ask(x<<1|1, mid+1, r));
	}
}up,down;
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) down.val[i]=-(up.val[i]=read());
		down.build(1, 1, n), up.build(1, 1, n);
	int m = read();
	for(int i = 1, l, r; i <= m; i++){
		l = read(); r = read();
		printf("%d\n", max(down.ask(1, l, r).mx, up.ask(1, l, r).mx));
	}
}