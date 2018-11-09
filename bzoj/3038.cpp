#include <bits/stdc++.h>
#define N 100050
#define ll long long
using namespace std;
int n, m, x, y, z;
int ls[N<<2], rs[N<<2], lazy[N<<2];
ll a[N<<2];
void push_up(int x){
	a[x] = a[x<<1] + a[x<<1|1];
	lazy[x] = lazy[x<<1] & lazy[x<<1|1];
}
void build(int x, int l, int r){
	ls[x] = l, rs[x] = r;
	if(l == r){
		scanf("%lld", &a[x]);
		if(a[x] == 1 || a[x] == 0) lazy[x] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	push_up(x);
}
ll ask(int x, int l, int r){
	if(ls[x] == l && rs[x] == r) return a[x];
	int mid = ls[x] + rs[x] >> 1;
	if(r <= mid) return ask(x<<1, l, r);
	else if(l > mid) return ask(x<<1|1, l, r);
	else return ask(x<<1, l, mid) + ask(x<<1|1, mid+1, r);
}
void Sqrt(int x, int l, int r){
	if(lazy[x]) return;
	if(ls[x] == rs[x]){
		a[x] = (int)sqrt(a[x]);
		if(a[x] == 1 || a[x] == 0) lazy[x] = 1;
		return;
	}
	int mid = ls[x] + rs[x] >> 1;
	if(r <= mid) Sqrt(x<<1, l, r);
	else if(l > mid) Sqrt(x<<1|1, l, r);
	else Sqrt(x<<1, l, mid), Sqrt(x<<1|1, mid+1, r);
	push_up(x);
}
int main(){
	scanf("%d", &n);
	build(1, 1, n);
	scanf("%d", &m);
	while(m-- && scanf("%d%d%d", &x, &y, &z) != EOF){
		if(y > z) swap(y, z);
		if(x == 1) printf("%lld\n", ask(1, y, z));
		else Sqrt(1, y, z);
	}
	return 0;
}
