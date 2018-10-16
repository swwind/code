#include <bits/stdc++.h>
#define N 100020
#define ll long long
#define mk make_pair
#define pr pair<ll, int>
using namespace std;
const int inf = 0x3f3f3f3f;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
priority_queue<pr> q;
bool vis[N];
ll a[N], nxt[N], pre[N], ans;
int main(int argc, char const *argv[]){
	int n = read();
	for(int i = 1; i <= n; i++)
		a[i] = read(), nxt[i] = i+1, pre[i] = i-1;
	pre[1] = n; nxt[n] = 1;
	for(int i = 1; i <= n; i++) q.push(mk(a[i], i));
	for(int i = 1; i*3 <= n;){
		pr now = q.top(); q.pop();
		ll x = now.first;
		int k = now.second;
		if(x <= 0) break;
		if(vis[k]) continue;
		ans += x; i++;
		a[k] = a[nxt[k]]+a[pre[k]]-x;
		q.push(mk(a[k], k));
		vis[pre[k]] = 1; vis[nxt[k]] = 1;
		pre[nxt[nxt[k]]] = k;
		nxt[pre[pre[k]]] = k;
		pre[k] = pre[pre[k]];
		nxt[k] = nxt[nxt[k]];
	}
	printf("%lld\n", ans);
	return 0;
}