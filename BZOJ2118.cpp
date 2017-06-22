#include <bits/stdc++.h>
#define N 500020
#define ll long long
#define pr pair<ll, int>
#define mk(a, b) make_pair(a, b)
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int mn, a[20], n;
ll dis[N], l, r;
priority_queue<pr, vector<pr>, greater<pr> > q;
inline ll ask(ll x){
	ll ans = 0;
	for(int i = 0; i < mn; i++) if(dis[i] <= x)
		ans += (x-dis[i])/mn+1;
	return ans;
}
int main(){
	int n = read();
	l = read(); r = read();
	for(int i = 1; i <= n; i++) (a[i] = read()) || n-- && i--;
	mn = *min_element(a+1, a+n+1);
	memset(dis, 127/3, sizeof(ll)*N);
	dis[0] = 0; q.push(mk(0, 0));
	while(!q.empty()){
		pr x = q.top(); q.pop();
		if(x.first > dis[x.second]) continue;
		for(int i = 1; i <= n; i++)
			if(dis[(x.second+a[i])%mn] > dis[x.second]+a[i])
				q.push(mk(dis[(x.second+a[i])%mn] = dis[x.second]+a[i], (x.second+a[i])%mn));
	}
	printf("%lld\n", ask(r)-ask(l-1));
}