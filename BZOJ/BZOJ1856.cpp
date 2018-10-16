#include <bits/stdc++.h>
#define ll long long
#define MOD 20100403
using namespace std;
ll n, m, f[2000050];
ll inv(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ans;
}
ll C(ll a, ll b){
	return f[a] * inv(f[b], MOD-2) % MOD * inv(f[a-b], MOD-2) % MOD;
}
int main(){
	scanf("%lld%lld", &n, &m);
	f[0] = 1;
	for(ll i = 1; i < 2000050; i++)
	f[i] = f[i-1] * i % MOD;
	printf("%lld", (C(n+m, m) - C(n+m, m-1) + MOD) % MOD);
	return 0;
}

