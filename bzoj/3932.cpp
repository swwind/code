#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
typedef long long ll;
const int M = 1e5+5, N = M*40;
struct node{
	int end, val, tag;
	ll sum;
	bool operator < (const node &a) const {
		return end < a.end;
	}
}s[M<<1];
int cnt, cct, a[M], root[M*3], ls[N], rs[N];
ll sum[N], sz[N], ans=1;
void build(int &k, int l, int r){
	k = ++cnt;
	if(l==r)return;
	int mid = l + r >> 1;
	build(ls[k], l, mid);
	build(rs[k], mid+1, r);
}
void change(int &k, int last, int l, int r, int p, int tag){
	k = ++cnt;
	sum[k] = sum[last]+(ll)tag*a[p];
	sz[k] = sz[last]+(ll)tag;
	ls[k] = ls[last], rs[k] = rs[last];
	if(l==r)return;
	int mid = l + r >> 1;
	if(p <= mid) change(ls[k], ls[last], l, mid, p, tag);
	else change(rs[k], rs[last], mid+1, r, p, tag);
}
ll query(int k, int l, int r, int key){
	if(l==r) return sum[k]/sz[k]*(ll)key;
	int tot = sz[ls[k]], mid = l + r >> 1;
	if(key <= tot) return query(ls[k], l, mid, key);
	else return sum[ls[k]]+query(rs[k], mid+1, r, key-tot);
}
int main(){
	int n = read(), m = read();
	for(int i = 1, x, y, z; i <= n; i++){
		x = read(); y = read(); z = read();
		s[++cct].end = x; s[cct].val = z; s[cct].tag = 1;
		s[++cct].end = y+1; s[cct].val = z; s[cct].tag = -1;
		a[i] = z;
	}
	sort(a+1, a+n+1);
	sort(s+1, s+cct+1);
	build(root[0], 1, m);
	for(int i = 1, j = 1, p; i <= m; i++){
		root[i] = root[i-1];
		for(; j<=cct&&s[j].end==i; j++)
			change(root[i], root[i], 1, m,
				lower_bound(a+1, a+n+1, s[j].val)-a, s[j].tag);
	}
	for(int i = 1, t, a, b, c; i <= m; i++){
		t = read(); a = read(); b = read(); c = read();
		ll ki = ((ll)a*ans+(ll)b)%c+1;
		if(ki >= sz[root[t]]) ans = sum[root[t]];
		else ans = query(root[t], 1, m, ki);
		printf("%lld\n", ans);
	}
	return 0;
}