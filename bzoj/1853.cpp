#include <bits/stdc++.h>
#define N 10005
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll l, r;
ll a[N], cnt, tot, ans, b[N];
bool vis[N];
void dfs(ll x, ll y){
	if(y > r) return;
	if(x) a[++cnt] = y;
	dfs(x+1, y*10+6);
	dfs(x+1, y*10+8);
}
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
void dfs(ll x, ll y, ll z){
	if(x > tot){
		if(y&1)ans+=r/z-(l-1)/z;
		else if(y)ans+=(l-1)/z-r/z;
		return;
	}
	dfs(x+1, y, z);
	ll tmp = z/gcd(b[x], z);
	if((double)b[x]*tmp <= r)
		dfs(x+1, y+1, b[x]*tmp);
}
int main(){
	l = read(); r = read();
	dfs(0, 0); sort(a+1, a+cnt+1);
	for(int i = 1; i <= cnt; i++){
		if(vis[i]) continue;
		b[++tot] = a[i];
		for(int j = i+1; j <= cnt; j++)
			if(a[j]%a[i]==0) vis[j] = 1;
	}
	for(int i = 1; i <= tot/2; i++)
		swap(b[i], b[tot-i+1]);
	dfs(1, 0, 1);
	printf("%lld\n", ans);
	return 0;
}