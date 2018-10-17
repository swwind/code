#include <bits/stdc++.h>
#define N 20
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll mp[N][N], ans = 1ll<<60;
int n, m, r, s;
int id[N];
bool check(ll x){
	ll last = 0, res = 0, i = 1;
	while(i <= n){
		int flag = 1;
		for(int j = 1; j <= ::s+1 && flag; j++)
			if(mp[i][id[j]]-mp[i][id[j-1]]-mp[last][id[j]]+mp[last][id[j-1]] > x)
				flag = 0;
		if(!flag) last = i-1, res++;
		else i++;
		if(res > r) return 0;
	}
	return 1;
}
void dfs(int r, int s){
	if(s == ::s+1){
		id[s] = m;
		ll l = 0, r = mp[n][m]+1, ans = 0;
		while(l <= r){
			ll mid = l + r >> 1;
			if(check(mid)) ans = mid, r = mid-1;
			else l = mid+1;
		}
		::ans = min(ans, ::ans);
		return;
	}
	for(int i = r; i <= m-(::s-s+1); i++)
		dfs((id[s] = i)+1, s+1);
}
int main(int argc, char const *argv[]){
	n = read(); m = read(); r = read(); s = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			mp[i][j] = mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1]+read();
	dfs(1, 1);
	printf("%d\n", ans);
	return 0;
}