#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int l, r;
	ll val, lazy;
} a[400000];
int n, m, x, y, tot;
ll z;
queue<int> q;
void build_tree(int id, int l, int r){
	a[id].l = l, a[id].r = r;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build_tree(id*2, l, mid);
	build_tree(id*2+1, mid+1, r);
}
void add(int id, int l, int r, ll val){
//	printf("Add:%d %d %d %lld\n", id, l, r, val);
	if(a[id].l == l && a[id].r == r){
		a[id].lazy += val;
		return;}
	a[id].val += (r - l + 1) * val;
//	printf("A[%d].val Added %d * val\n", id, r-l+1);
	int mid = (a[id].l + a[id].r) >> 1;
	if(r <= mid) add(id*2, l, r, val);
	else if(l > mid) add(id*2+1, l, r, val);
	else add(id*2, l, mid, val), add(id*2+1, mid+1, r, val);
}
ll get(int id, int l, int r){
//	printf("Ask:%d %d %d\n", id, l, r);
	if(a[id].l == a[id].r){
		a[id].val += a[id].lazy;
		a[id].lazy = 0;
		return a[id].val;
	}
	if(a[id].lazy)
		a[id*2].lazy += a[id].lazy,
		a[id*2+1].lazy += a[id].lazy,
		a[id].val += (a[id].r - a[id].l + 1) * a[id].lazy,
		a[id].lazy = 0;
	if(a[id].l == l && a[id].r == r) return a[id].val;
	int mid = (a[id].l + a[id].r) >> 1;
	if(r <= mid) return get(id*2, l, r);
	else if(l > mid) return get(id*2+1, l, r);
	else return get(id*2, l, mid) + get(id*2+1, mid+1, r);
}
void pr(int id){
	printf("No.%d[l=%d, r=%d, lazy=%lld, val=%lld]\n", id, a[id].l, a[id].r, a[id].lazy, a[id].val);
	if(a[id].l != a[id].r)
		pr(id*2), pr(id*2+1);
}
int main(){
	scanf("%d%d", &n, &m);
	build_tree(1, 1, n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &x),
		add(1, i, i, x);
//	pr(1);
	while(m--){
		scanf("%d", &x);
		if(x == 1)
			scanf("%d%d%lld", &x, &y, &z),
			add(1, x, y, z);
		else
			scanf("%d%d", &x, &y),
			printf("%lld\n", get(1, x, y));
//		pr(1);
	}
	return 0;
}

