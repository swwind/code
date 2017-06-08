#include <bits/stdc++.h>
#define N 100050
#define ll long long
using namespace std;
int n, m, x, y, z;
int le[N<<2], ri[N<<2], lazy[N<<2];
ll a[N<<2];
void build_tree(int id, int l, int r){
	le[id] = l, ri[id] = r;
	if(l == r){
		scanf("%lld", &a[id]);
		if(a[id] == 1 || a[id] == 0) lazy[id] = 1;
		return;
	}
	int mid = l + r >> 1;
	build_tree(id<<1, l, mid);
	build_tree(id<<1|1, mid+1, r);
	a[id] = a[id<<1] + a[id<<1|1];
	lazy[id] = lazy[id<<1] & lazy[id<<1|1];
}
ll ask(int id, int l, int r){
	if(le[id] == l && ri[id] == r) return a[id];
	int mid = le[id] + ri[id] >> 1;
	if(r <= mid) return ask(id<<1, l, r);
	else if(l > mid) return ask(id<<1|1, l, r);
	else return ask(id<<1, l, mid) + ask(id<<1|1, mid+1, r);
}
void Sqrt(int id, int l, int r){
	if(lazy[id]) return;
	if(le[id] == ri[id]){
		a[id] = (int)sqrt(a[id]);
		if(a[id] == 1 || a[id] == 0) lazy[id] = 1;
		return;
	}
	int mid = le[id] + ri[id] >> 1;
	if(r <= mid) Sqrt(id<<1, l, r);
	else if(l > mid) Sqrt(id<<1|1, l, r);
	else Sqrt(id<<1, l, mid), Sqrt(id<<1|1, mid+1, r);
	a[id] = a[id<<1] + a[id<<1|1];
	lazy[id] = lazy[id<<1] & lazy[id<<1|1];
}
int main(){
	scanf("%d", &n);
	build_tree(1, 1, n);
	scanf("%d", &m);
	while(m-- && scanf("%d%d%d", &x, &y, &z) != EOF)
		if(x == 1)
			printf("%lld\n", ask(1, y, z));
		else
			Sqrt(1, y, z);
	return 0;
}

