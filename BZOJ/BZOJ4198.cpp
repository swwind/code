#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
const int inf = 0x3f3f3f3f;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct node{
	ll x, y;
	node(ll x = 0, ll y = 0):x(x),y(y){}
	friend bool operator < (const node &a, const node &b){
		return a.x == b.x ? a.y > b.y : a.x > b.x;
	}
};
priority_queue<node> q;
int main(int argc, char const *argv[]){
	int n = read(), k = read(), top = 0;
	for(int i = 1; i <= n; i++) q.push(node(read(), 0));
	if((n-1)%(k-1)) top = k-1-(n-1)%(k-1);
	for(int i = 1; i <= top; i++)q.push(node());
	ll ans = 0;
	for(top += n; top != 1; top -= k-1){
		ll x = 0, y = 0;
		for(int i = 1; i <= k; i++){
			node now = q.top(); q.pop();
			x += now.x; y = max(y, now.y);
		}
		ans += x; q.push(node(x, y+1));
	}
	printf("%lld\n%lld\n", ans, q.top().y);
	return 0;
}