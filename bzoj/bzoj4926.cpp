#include <bits/stdc++.h>
#define N 10000020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll g[N];
int main(){
	ll n = read(), m = read(), pos, ans = 0;
	for(int i = 0; i <= m; i++) g[i] = 1;
	for(int i = m+1; i; i++)
		if((g[i]=g[i-1]+g[i-m]) > n){
			pos = i; break;
		}
	for(int i = pos-1; n; i--)
		if(g[i] <= n)
			ans += g[i-1], n -= g[i];
	printf("%lld\n", ans);
}