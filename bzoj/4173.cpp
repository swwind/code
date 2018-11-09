#include <bits/stdc++.h>
#define ll long long
#define zyy 998244353
using namespace std;
ll get(ll x){
	ll temp = x;
	for(ll i = 2; i*i <= x; ++i)
		if(!(x%i)){
			temp/=i; temp*=i-1;
			while(!(x%i)) x /= i;
		}
	if(x != 1){temp/=x; temp*=x-1;}
	return temp;
}
ll n, m;
int main(){
	scanf("%lld%lld", &n, &m);
	printf("%lld\n", get(n)%zyy*(get(m)%zyy)%zyy*(n%zyy)%zyy*(m%zyy)%zyy);
}