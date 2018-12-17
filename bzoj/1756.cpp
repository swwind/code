#include <bits/stdc++.h>
#define ll long long
#define N 500050
using namespace std;
struct node{
	int mx, ls, rs, lmx, rmx, sum;
}tr[N<<2];
void push_up(int x){
	tr[x].sum = tr[x<<1].sum+tr[x<<1|1].sum;
	tr[x].lmx = max(tr[x<<1].lmx, tr[x<<1].sum+tr[x<<1|1].lmx);
	tr[x].rmx = max(tr[x<<1|1].rmx, tr[x<<1|1].sum+tr[x<<1].rmx);
	tr[x].mx = max(max(tr[x<<1].mx, tr[x<<1|1].mx), tr[x<<1].rmx+tr[x<<1|1].lmx);
}
node ask(int x, int l, int r){
	if(tr[x].ls == l && tr[x].rs == r) return tr[x];
	int mid = tr[x].ls + tr[x].rs >> 1;
	if(r <= mid) return ask(x<<1, l, r);
	if(l > mid) return ask(x<<1|1, l, r);
	node ls = ask(x<<1, l, mid), rs = ask(x<<1|1, mid+1, r), ans;
	ans.mx = max(max(ls.mx, rs.mx), ls.rmx+rs.lmx);
	ans.rmx = max(rs.rmx, rs.sum+ls.rmx);
	ans.lmx = max(ls.lmx, ls.sum+rs.lmx);
	return ans;
}
void add(int x, int l, int v){
	if(tr[x].ls==l&&tr[x].rs==tr[x].ls){tr[x].sum=tr[x].lmx=tr[x].rmx=tr[x].mx=v;return;}
	int mid = tr[x].ls + tr[x].rs >> 1;
	if(l <= mid) add(x<<1, l, v);
	else add(x<<1|1, l, v);
	push_up(x);
}
void build(int x, int l, int r){
	tr[x].ls = l, tr[x].rs = r;
	if(l == r){
		scanf("%d", &tr[x].mx);
		tr[x].lmx=tr[x].rmx=tr[x].sum=tr[x].mx;
		return;
	}
	int mid = l + r >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	push_up(x);
}
int n, m, op, l, r;
int main(){
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	while(m--){
		scanf("%d%d%d", &op, &l, &r);
		if(op == 1) printf("%d\n", ask(1, min(l, r), max(l, r)).mx);
		else add(1, l, r);
	}
	return 0;
}

