#include <bits/stdc++.h>
#define ll long long
using namespace std;
// ll phi(ll x){
// 	ll temp = x;
// 	for(ll i = 2,_s=sqrt(x); i <= _s; ++i)
// 		if(!(x%i)){
// 			temp/=i; temp*=i-1;
// 			while(!(x%i)) x /= i;
// 		}
// 	if(x != 1){temp/=x; temp*=x-1;}
// 	return temp;
// }
ll Pow(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b&1)ans*=a;
		a=a*a;
		b >>= 1;
	}
	return ans;
}
ll phi(ll x, ll y){
	printf("In:%d %d\n", x, y);
	ll api = Pow(x, y-1);
	return api*(x-1);
}
ll phi(ll x){
	ll pri = 2, ans = 1;
	while(x != 1){
		if(x%pri==0){
			ll k = 0;
			while(x%pri==0)x/=pri,++k;
			ans = ans * phi(pri, k);
		}
		++pri;
	}
	return
}
int main(){
	ll x;
	scanf("%lld", &x);
	printf("%lld", phi(x));
}
