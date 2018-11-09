#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll pow(ll x, ll y, ll p){
	ll ans = 1;
	for(;y;y>>=1,x=x*x%p)if(y&1)ans=ans*x%p;
	return ans;
}
ll mul(ll x, ll y, ll p){
	ll ans = 0;
	for(;y;y>>=1,x=(x<<1)%p)if(y&1)ans=(ans+x)%p;
	return ans;
}
int main(int argc, char const *argv[]){
	ll n = read(), m = read(), l = read();
	printf("%lld\n", mul(pow(n/2+1, m, n+1), l, n+1));
	return 0;
}