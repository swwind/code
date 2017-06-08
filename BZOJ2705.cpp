#include <bits/stdc++.h>
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define ll long long
using namespace std;
ll n, ans;
double s;
ll phi(ll x){
	ll t = x;
	for(ll i = 2; i <= s; i++) if(x%i==0){
		t=t/i*(i-1);
		while(x%i==0)x/=i;
	}
	if(x>1)t=t/x*(x-1);
	return t;
}
int main(){
	scanf("%lld", &n);s=sqrt(n);
	ll i = 1;
	for(; i < s; i++)if(n%i==0) ans += i*phi(n/i)+n/i*phi(i);
	i++; if(i*i==n) ans += i*phi(n/i);
	printf("%lld", ans);
}

