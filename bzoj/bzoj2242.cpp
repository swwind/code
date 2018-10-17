#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll power(ll x, ll y, ll p){
	ll ans = 1;x%=p;
	while(y){
		if(y&1) ans = ans*x%p;
		x = x*x%p;
		y >>= 1;
	}
	return ans;
}
ll work1(ll x, ll y, ll p){
	printf("%lld\n", power(x, y, p));
}
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
void exgcd(ll a, ll b, ll &x, ll &y){
	if(!b){ x = 1, y = 0; return;}
	exgcd(b, a%b, x, y);
	ll t = x; x = y; y = t-a/b*y;
}
ll work2(ll y, ll z, ll p){
	ll t = gcd(y, -p);
	if(z%t) return puts("Orz, I cannot find x!");
	y /= t, z /= t, p = -p/t;
	ll a, b; exgcd(y, p, a, b);
	a = a*z%p;
	if(a < 0) a += p;
	printf("%lld\n", a);
}
map<ll, ll> mp;
ll work3(ll y, ll z, ll p){
	mp.clear(); y %= p;
	if(!y&&!z)return puts("1");
	if(!y)return puts("Orz, I cannot find x!");
	ll m = ceil(sqrt(p)), t = 1;
	mp[1] = m+1;
	for(ll i = 1; i < m; i++){
		t = t*y%p;
		if(!mp[t])mp[t]=i;
	}
	ll tmp = power(y, p-m-1, p), ine = 1;
	for(ll k = 0; k < m; k++){
		ll i = mp[z*ine%p];
		if(i){
			if(i == m+1) i=0;
			return printf("%lld\n", k*m+i);
		}
		ine = ine*tmp%p;
	}
	puts("Orz, I cannot find x!");
}
int main(){
	ll T, k, x, y, z;
	scanf("%lld%lld", &T, &k);
	while(T--){
		scanf("%lld%lld%lld", &x, &y, &z);
		switch(k){
			case 1: work1(x, y, z); break;
			case 2: work2(x, y, z); break;
			case 3: work3(x, y, z); break;
		}
	}
}