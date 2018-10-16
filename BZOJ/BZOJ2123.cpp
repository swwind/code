#include <bits/stdc++.h>
#define ll long long
#define inf (1LL<<60)
using namespace std;
ll n, l = inf, r = -inf, u = -inf, d = inf;
ll len, pnt, cc;
struct node{
	ll x, y;
}f[1050];
ll get(ll x, ll y){
	if(!x || !y) return 0;
	if(!(x&1) && !(y&1)) return get(x>>1, y>>1)<<1;
	return x+y-1;
}
int cmp(ll a, ll b){
	if(a < b) return -1;
	if(a == b) return 0;
	return 1;
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld%lld", &f[i].x, &f[i].y);
		l = min(l, f[i].x);
		r = max(r, f[i].x);
		u = max(u, f[i].y);
		d = min(d, f[i].y);
		if(!i) continue;
		ll k = get(abs(f[i].x - f[i-1].x), abs(f[i].y - f[i-1].y));
		pnt += (abs(f[i].x - f[i-1].x) * abs(f[i].y - f[i-1].y) - k) / 2;
		len += k;
	}
	ll k = get(abs(f[n-1].x - f[0].x), abs(f[n-1].y - f[0].y));
	pnt += (abs(f[n-1].x - f[0].x) * abs(f[n-1].y - f[0].y) - k) / 2;
	len += k;
	for(int i = 0; i < n; i++){
		int j = (i-1+n)%n;
		int k = (i+1)%n;
		if(cmp(f[i].x, f[j].x) == cmp(f[i].x, f[k].x) && cmp(f[i].y, f[j].y) == cmp(f[i].y, f[k].y)) cc++;
	}
	printf("%lld", max(0LL,(r-l)*(u-d) - len - pnt + cc));
	return 0;
}

