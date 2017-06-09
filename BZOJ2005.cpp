#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, f[500005];
int main(){
	scanf("%lld%lld", &n, &m);
	if(n > m) swap(n, m);
	ll ans = 0;
	for(int i = n; i; i--){
		f[i] = (ll)(m/i)*(n/i);
		for(int j = i << 1; j <= n; j += i)
			f[i] -= f[j];
		ans += f[i]*(2*i-1);
	}
	printf("%lld\n", ans);
	return 0;
}