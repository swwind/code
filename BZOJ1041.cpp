#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans, r;
ll gcd(ll a, ll b){
   return a%b ? gcd(b, a%b) : b;
}
int check(ll y, double x){
	if(x == floor(x)){
		ll x1=(ll)floor(x);
		if(gcd(x1*x1,y*y) == 1 && x1*x1 != y*y)
			return 1;
	}
	return 0;
}
int main(){
	scanf("%lld", &r);
	double ds = sqrt(r<<1);
	for(ll d = 1; d <= ds; d++)
		if((r<<1) % d == 0){
			ll ss = (ll) sqrt((r<<1)/(d<<1));
			for(ll a = 1; a <= ss; a++)
				if(check(a, sqrt((r<<1)/d-a*a))) ans++;
			if(d != (r<<1)/d)
				for(ll a = 1; a <= (ll)sqrt(d>>1); a++)
					if(check(a, sqrt(d-a*a)))
						ans++;
		}
	printf("%lld", (ans<<2)+4);
	return 0;
}

