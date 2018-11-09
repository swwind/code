// TLE 松松松不出来了啊QAQ
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, k1, k2, ans=(1LL<<60);
ll a[4] = {0, 0, 1,-1};
ll b[4] = {1,-1, 0, 0};
ll vis[60][60], nm, nm_;
struct node{
	ll x, y;
}p[2000];
inline ll calc(ll x, ll y, ll j){
	return k1*abs(x-p[j].x)+k2*abs(y-p[j].y);
}
inline void dfs(ll x, ll y, ll dep, ll faq){
	if(dep > nm_) faq = max(faq, calc(x, y, dep-nm_));
	else p[dep].x = x, p[dep].y = y;
	// prllf("in:%d %d %d %d\n", x, y, dep, faq);
	if(faq > ans) return;
	if(dep == nm){
		ans = faq;
		return;
	}
	if((vis[x+1][y]&&vis[x-1][y]&&!vis[x][y+1]&&!vis[x][y-1])
		||(vis[x][y+1]&&vis[x][y-1]&&!vis[x+1][y]&&!vis[x-1][y])) return;
	// puts("Continued!");
			vis[x][y] = 1;
	for(ll i = 0; i < 4; ++i)
		if(!vis[x+a[i]][y+b[i]]&&x+a[i]&&x+a[i]<=n&&y+b[i]&&y+b[i]<=m){
			dfs(x+a[i], y+b[i], dep+1, faq);
		}
			vis[x][y] = 0;
}
int main(){
	scanf("%lld%lld%lld%lld", &n, &m, &k1, &k2);
	nm = n*m; nm_ = nm>>1;
	dfs(1, m, 1, 0);
	printf("%lld\n", ans);
}