#include <cstdio>
#include <algorithm>
#define N 2000020
#define M 100020
using namespace std;
int ls[N], rs[N], sz[N], lk[N], rk[N];
int a[M], b[M], rt[M], cnt;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int build(int l, int r){
	int k = ++cnt;
	lk[k] = l, rk[k] = r;
	if(l == r) return k;
	int mid = l + r >> 1;
	ls[k] = build(l, mid);
	rs[k] = build(mid+1, r);
	return k;
}
int insert(int fa, int pos){
	int k = ++cnt;
	ls[k] = ls[fa], rs[k] = rs[fa];
	lk[k] = lk[fa], rk[k] = rk[fa];
	sz[k] = sz[fa]+1;
	if(lk[k] == rk[k]) return k;
	int mid = lk[k] + rk[k] >> 1;
	if(mid >= pos) ls[k] = insert(ls[fa], pos);
	else rs[k] = insert(rs[fa], pos);
	return k;
}
int ask(int fa, int x, int k){
	if(ls[x] == rs[x]) return b[lk[x]];
	int cmp = sz[ls[x]]-sz[ls[fa]];
	if(cmp >= k) return ask(ls[fa], ls[x], k);
	else return ask(rs[fa], rs[x], k-cmp);
}
int main(){
	int n=read(), m=read();
	for(int i = 1; i <= n; i++)
		a[i] = b[i] = read();
	sort(b+1, b+n+1);
	rt[0] = build(1, n);
	// 先离散化一下
	for(int i = 1; i <= n; i++)
		rt[i] = insert(rt[i-1], lower_bound(b+1, b+n+1, a[i])-b);
	for(int i = 1,x,y,z; i <= m; i++){
		x=read(); y=read(); z=read();
		printf("%d\n", ask(rt[x-1], rt[y], z));
	}
}
// 求区间第k小（不带修改）