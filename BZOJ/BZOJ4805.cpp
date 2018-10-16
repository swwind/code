#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5000010;
ll phi[maxn], pri[maxn];
int v[maxn], n, cnt;
map<int, ll> mp;
ll sumphi(ll n){
	if(n < maxn) return phi[n];
	if(mp[n]) return mp[n];
	ll tmp = n*(n+1)/2;
	for(int i = 2, last; i <= n; i=last+1){
		last = n/(n/i);
		tmp -= sumphi(n/i)*(last-i+1);
	}
	return mp[n] = tmp;
}
int main(){
	phi[1] = 1;
	for(int i = 2; i < maxn; i++){
		if(!v[i]) pri[++cnt] = i, phi[i] = i-1;
		for(int j = 1; j <= cnt && i*pri[j] < maxn; j++){
			v[i*pri[j]] = 1;
			if(i%pri[j] == 0){phi[i*pri[j]] = phi[i]*pri[j]; break;}
			phi[i*pri[j]] = phi[i]*(pri[j]-1); 
		}
	}
	for(int i = 2; i < maxn; i++)
		phi[i] += phi[i-1];
	scanf("%d", &n);
	printf("%lld\n", sumphi(n));
	return 0;
}