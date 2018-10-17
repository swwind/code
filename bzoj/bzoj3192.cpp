#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll v,k;
	bool operator < (const node &b) const {
		return v < b.v;
	}
}a[100020];
ll ans, c[100020], sum;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
void add(ll x){
	for(;x<=sum+1;x+=x&-x)c[x]++;
}
ll ask(ll x){
	ll ans = 0;
	for(;x;x-=x&-x)ans+=c[x];
	return ans;
}
int main(){
	ll n1 = read(), n2 = read(); sum = n1+n2;
	for(ll i = 1; i <= n1; ++i)a[n2+i+1].v=read();
	for(ll i = 1; i <= n2; ++i)a[n2-i+1].v=read();
	a[n2+1].v=1e9;for(ll i = 1; i <= sum+1; i++)a[i].k=i;
	sort(a+1, a+sum+2);
	add(a[1].k);
	for(ll i = 2; i <= sum+1; i++){
		ans += ask(max(a[i].k, a[i-1].k))-ask(min(a[i].k, a[i-1].k)-1)-1;
		add(a[i].k);
	}
	printf("%lld\n", ans);
	return 0;
}
