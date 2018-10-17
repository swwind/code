#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
void exgcd(ll a, ll b, ll &x, ll &y){
	if(!b){x=1;y=0;return;}
	exgcd(b, a%b, x, y);
	ll t=x;x=y;y=t-a/b*y;
}
int main(){
	ll x=read(),y=read(),m=read(),n=read(),l=read(),a=n-m,b=x-y,t=gcd(a,l);
	if(b%t)return puts("Impossible")&0;
	a/=t,b/=t,l/=t;exgcd(a, l, x, y);
	ll ans = ((x*b)%l+l)%l; if(!ans) ans=l;
	printf("%lld\n", ans);
}