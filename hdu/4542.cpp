#include <bits/stdc++.h>
#define N 60020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll ans, k, head[N];
const ll inf = 1ll << 62;
int pri[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
void dfs(int x, ll num, ll sum, int last){
	// printf("%d %lld %lld %d\n", x, num, sum, last);
	if(sum > k) return;
	if(sum == k) ans = min(ans, num);
	else for(int i = 1; i <= last; i++){
		if(ans/pri[x] < num || sum*(i+1) > k) break;
		num *= pri[x];
		if(k%(sum*(i+1)) == 0)
			dfs(x+1, num, sum*(i+1), i);
	}
}
int main(int argc, char const *argv[]){
	for(int i = 0; i < N; i++) head[i] = i;
	for(int i = 1; i < N; i++){
		for(int j = i; j < N; j += i) head[j]--;
		if(!head[head[i]]) head[head[i]] = i;
		head[i] = 0;
	}
	int T = read(), cs = 0;
	while(T--){
		int op = read(); k = read();
		printf("Case %d: ", ++cs);
		if(op) ans = head[k];
		else{
			ans = inf;
			dfs(0, 1, 1, 62);
		}
		if(ans >= inf) puts("INF");
		else if(!ans) puts("Illegal");
		else printf("%lld\n", ans);
	}
	return 0;
}