#include <bits/stdc++.h>
#define N 100020
#define ll long long
#define mod 1000000007
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll phi(ll x){
	ll t = x;
	for(int i = 2; i*i <= x; i++) if(x%i == 0){
		t = t/i*(i-1);
		while(x%i == 0) x /= i;
	}
	if(x>1) t = t/x*(x-1);
	return t;
}
int main(int argc, char const *argv[]){
	ll n, k;
	while(cin >> n >> k){
		if(k > 2){puts("0"); continue;}
		if(k == 2){puts("1"); continue;}
		ll ans = 0;
		for(int i = 1; i*i <= n; i++) if(n%i == 0)
			ans = (ans+phi(n/i)*phi(i)%mod*(i*i == n ? 1 : 2))%mod;
		printf("%lld\n", ans);
	}
	return 0;
}