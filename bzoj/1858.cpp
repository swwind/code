#include <bits/stdc++.h>
#define N 100050
#define ll long long
using namespace std;
int n, m, x, y, z;
struct node{
	int l, r, l0, r0, l1, r1;
	int mx0, mx1, sum0, sum1;
	int rev, c, full;
} t[N<<2];
void rev(int id){
	swap(t[id].l0, t[id].l1);
	swap(t[id].r0, t[id].r1);
	swap(t[id].mx0, t[id].mx1);
	swap(t[id].sum0, t[id].sum1);
	if(t[id].full != -1) t[id].full ^= 1;
}
void color(int id, int v){
	t[id].rev = 0;
	if(v)
		t[id].sum0 = t[id].l0 = t[id].r0 = t[id].mx0 = 0,
		t[id].sum1 = t[id].l1 = t[id].r1 = t[id].mx1 = t[id].r - t[id].l + 1;
	else
		t[id].sum0 = t[id].l0 = t[id].r0 = t[id].mx0 = t[id].r - t[id].l + 1,
		t[id].sum1 = t[id].l1 = t[id].r1 = t[id].mx1 = 0;
	t[id].full = v;
}
node merge(node a, node b){
	node tmp;
	tmp.l = a.l;
	tmp.r = b.r;
	tmp.rev = 0;
	tmp.c = -1;
	tmp.l0 = a.l0;
	tmp.l1 = a.l1;
	tmp.r0 = b.r0;
	tmp.r1 = b.r1;
	tmp.mx0 = max(a.mx0, b.mx0);
	tmp.mx1 = max(a.mx1, b.mx1);
	tmp.mx0 = max(tmp.mx0, a.r0 + b.l0);
	tmp.mx1 = max(tmp.mx1, a.r1 + b.l1);
	tmp.sum0 = a.sum0 + b.sum0;
	tmp.sum1 = a.sum1 + b.sum1;
	if(!a.full)
		tmp.l0 = a.mx0 + b.l0;
	else if(a.full == 1)
		tmp.l1 = a.mx1 + b.l1;
	if(!b.full)
		tmp.r0 = b.mx0 + a.r0;
	else if(b.full == 1)
		tmp.r1 = b.mx1 + a.r1;
	if(a.full == b.full)
	   tmp.full = a.full;
	else tmp.full = -1;
	return tmp;
}
void pushup(int id){
	t[id] = merge(t[id<<1], t[id<<1|1]);
}
void pushdown(int id){
	if(t[id].l == t[id].r) return;
	if(t[id].c != -1)
		t[id<<1].c = t[id<<1|1].c = t[id].c,
		color(id<<1, t[id].c),
		color(id<<1|1, t[id].c),
		t[id].c = -1;
	if(t[id].rev)
		t[id<<1].rev ^= 1,
		t[id<<1|1].rev ^= 1,
		rev(id<<1),
		rev(id<<1|1),
		t[id].rev = 0;
}
void build(int id, int l, int r){
	t[id].l = l;
	t[id].r = r;
	if(l == r){
		scanf("%d", &t[id].full);
		if(t[id].full)
			t[id].l1 = t[id].r1 = t[id].mx1 = t[id].sum1 = 1;
		else
			t[id].l0 = t[id].r0 = t[id].mx0 = t[id].sum0 = 1;
		return;
	}
	int mid = l + r >> 1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
	pushup(id);
}
void change(int id, int l, int r, int v){
	pushdown(id);
	if(t[id].l == l && t[id].r == r){
		color(id, v);
		t[id].c = v;
		return;
	}
	int mid = t[id].l + t[id].r >> 1;
	if(r <= mid) change(id<<1, l, r, v);
	else if(l > mid) change(id<<1|1, l, r, v);
	else change(id<<1, l, mid, v), change(id<<1|1, mid+1, r, v);
	pushup(id);
}
void rever(int id, int l, int r){
	pushdown(id);
	if(t[id].l == l && t[id].r == r){
		rev(id);
		t[id].rev = 1;
		return;
	}
	int mid = t[id].l + t[id].r >> 1;
	if(r <= mid) rever(id<<1, l, r);
	else if(l > mid) rever(id<<1|1, l, r);
	else rever(id<<1, l, mid), rever(id<<1|1, mid+1, r);
	pushup(id);
}
node ask(int id, int l, int r){
	pushdown(id);
	if(t[id].l == l && t[id].r == r) return t[id];
	int mid = t[id].l + t[id].r >> 1;
	if(r <= mid) return ask(id<<1, l, r);
	else if(l > mid) return ask(id<<1|1, l, r);
	else return merge(ask(id<<1, l, mid), ask(id<<1|1, mid+1, r));
}
int asksum(int id, int l, int r){
	pushdown(id);
	if(t[id].l == l && t[id].r == r) return t[id].sum1;
	int mid = t[id].l + t[id].r >> 1;
	if(r <= mid) return asksum(id<<1, l, r);
	else if(l > mid) return asksum(id<<1|1, l, r);
	else return asksum(id<<1, l, mid) + asksum(id<<1|1, mid+1, r);
}
int main(){
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	while(m-- && scanf("%d%d%d", &x, &y, &z) != EOF){
		z++, y++;
		switch(x){
			case 0: case 1: change(1, y, z, x); break;
			case 2: rever(1, y, z); break;
			case 3: printf("%d\n", asksum(1, y, z));break;
			case 4: printf("%d\n", ask(1, y, z).mx1);
		}
	}
	return 0;
}

