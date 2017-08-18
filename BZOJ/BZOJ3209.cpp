#include <bits/stdc++.h>
#define N 100020
#define mod 10000007
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll pows(ll x, ll y){
	ll ans = 1;
	for(;y;y>>=1,x=x*x%mod)if(y&1)ans=ans*x%mod;
	return ans;
}
ll get(ll x){ll ans=0;for(;x;x>>=1)ans++;return ans;}
ll c[100][100], sum[100], now;
int main(int argc, char const *argv[]){
	ll n = read();
	for(ll i = 0; i < 100; i++) c[i][0] = 1;
	for(ll i = 1; i < 100; i++) for(ll j = 1; j <= i; j++) c[i][j] = c[i-1][j]+c[i-1][j-1];
	ll len = get(n);
	for(ll i = len-1; ~i; i--)if(n>>i&1){
		for(ll j = 0; j <= i; j++)
			sum[now+j] += c[i][j];
		sum[now]--; sum[++now]++;
	}
	ll ans = 1;
	for(ll i = 1; i < 100; i++)
		ans = ans*pows(i, sum[i])%mod;
	printf("%lld\n", ans);
	return 0;
}