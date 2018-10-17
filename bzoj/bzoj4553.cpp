#include <bits/stdc++.h>
#define N 100010
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int n, m, f[N], c[N], mn[N], mx[N], a[N];
struct node{
	int x, y, id;
	bool operator < (const node &b) const {
		return x == b.x ? (y == b.y ? id < b.id : y < b.y) : x < b.x;
	}
}p[N];
void clean(int x){
	for(;x<N;x+=x&-x) c[x]=0;
}
void add(int x, int v){
	for(;x<N;x+=x&-x) c[x]=max(c[x],v);
}
int ask(int x){
	int ans = 0;
	for(;x;x-=x&-x) ans=max(ans, c[x]);
	return ans;
}
void solve(int l, int r){
	if(l == r){
		f[l] = max(f[l], 1);
		return;
	}
	int mid = l + r >> 1;
	solve(l, mid);
	for(int i = l; i <= r; i++){
		if(i <= mid) p[i].x = a[i], p[i].y = mx[i];
		else p[i].x = mn[i], p[i].y = a[i];
		p[i].id = i;
	}
	sort(p+l, p+r+1);
	for(int i = l; i <= r; i++)
		if(p[i].id <= mid) add(p[i].y, f[p[i].id]);
		else f[p[i].id] = max(f[p[i].id], ask(p[i].y)+1);
	for(int i = l; i <= r; i++)
		if(p[i].id <= mid) clean(p[i].y);
	solve(mid+1, r);
}
int main(){
	n = read(); m = read();
	for(int i = 1; i <= n; i++)
		mx[i] = mn[i] = a[i] = read();
	for(int i = 1, x, y; i <= m; i++){
		x = read(); y = read();
		mx[x] = max(mx[x], y);
		mn[x] = min(mn[x], y);
	}
	solve(1, n); int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}