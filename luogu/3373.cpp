#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
ll n, m, mod, a, b, c, d;
struct nate{
	ll l, r, s, flag, lazy;
}t[800000];
void heritage(ll k){
	if(t[k].lazy == 1 && t[k].flag == 0)
		return;
	if(t[k].l == t[k].r){
		t[k].flag = 0;
		t[k].lazy = 1;
		return;
	}
	t[k*2].s = ((t[k*2].s*t[k].lazy) % mod + (t[k].flag*(t[k*2].r-t[k*2].l+1)) % mod) % mod;
	t[k*2].flag = ((t[k*2].flag*t[k].lazy) % mod + t[k].flag) % mod;
	t[k*2].lazy = (t[k*2].lazy*t[k].lazy) % mod;
	t[k*2+1].s = ((t[k*2+1].s*t[k].lazy) % mod + (t[k].flag*(t[k*2+1].r-t[k*2+1].l+1)) % mod) % mod;
	t[k*2+1].flag = ((t[k*2+1].flag*t[k].lazy) % mod + t[k].flag) % mod;
	t[k*2+1].lazy = (t[k*2+1].lazy*t[k].lazy) % mod;
	t[k].flag = 0;
	t[k].lazy = 1;
}
void make_tree(ll k, ll l, ll r){
	t[k].l = l;
	t[k].r = r;
	t[k].lazy = 1;
	if(l == r){
		scanf("%lld", &t[k].s);
		t[k].s %= mod;
		return;
	}
	ll mid = (l + r) >> 1;
	make_tree(k*2, l, mid);
	make_tree(k*2+1, mid+1, r);
	t[k].s = (t[k*2].s + t[k*2+1].s) % mod;
}
void interval_add(ll k, ll l, ll r, ll v){
	heritage(k);
	if(t[k].l == l && t[k].r == r){
		t[k].flag = v;
		t[k].s = (t[k].s + ((t[k].r-t[k].l + 1) * v) % mod) % mod;
		return;
	}
	ll mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid)
		interval_add(k*2, l, min(r, mid), v);
	if(r > mid)
		interval_add(k*2+1, max(l, mid+1), r, v);
	t[k].s = (t[k*2].s + t[k*2+1].s) % mod;
}
void interval_ride(ll k, ll l, ll r, ll v){
	heritage(k);
	if(t[k].l == l && t[k].r == r){
		t[k].lazy = v;
		t[k].s = (t[k].s*v) % mod;
		return;
	}
	ll mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid)
		interval_ride(k*2, l, min(r, mid), v);
	if(r > mid)
		interval_ride(k*2+1, max(l, mid+1), r, v);
	t[k].s = (t[k*2].s + t[k*2+1].s) % mod;
}
ll interval_query(ll k, ll l, ll r){
	heritage(k);
	if(t[k].l == l && t[k].r == r)
		return t[k].s;
	ll mid = (t[k].l + t[k].r) >> 1, ans = 0;
	if(l <= mid)
		ans += interval_query(k*2, l, min(r, mid));
	if(r > mid)
		ans += interval_query(k*2+1, max(l, mid+1), r);
	return ans % mod;
}
int main(){
	scanf("%lld%lld%lld", &n, &m, &mod);
	make_tree(1, 1, n);
	for(int i = 1; i <= m; i++){
		scanf("%lld", &a);
		if(a==1)
			scanf("%lld%lld%lld",&b,&c,&d),
			interval_ride(1,b,c,d%mod);
		else if(a==2)
			scanf("%lld%lld%lld",&b,&c,&d),
			interval_add(1,b,c,d%mod);
		else
			scanf("%lld%lld",&b,&c),
			printf("%lld\n",interval_query(1,b,c));
	}
	return 0;
}
