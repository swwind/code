#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll sum[N<<2], mx[N<<2];
void build(int x, int l, int r){
	if(l == r){sum[x]=mx[x]=read();return;}
	int mid = l + r >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	sum[x] = sum[x<<1]+sum[x<<1|1];
	mx[x] = max(mx[x<<1], mx[x<<1|1]);
}
void change(int x, int k, int L, int R, ll v){
	if(L == R){sum[x]=mx[x]=v;return;}
	int mid = L + R >> 1;
	if(k <= mid) change(x<<1, k, L, mid, v);
	else change(x<<1|1, k, mid+1, R, v);
	sum[x] = sum[x<<1]+sum[x<<1|1];
	mx[x] = max(mx[x<<1], mx[x<<1|1]);
}
void mod(int x, int l, int r, int L, int R, ll md){
	if(mx[x] < md) return;
	if(L == R){sum[x]=mx[x]=sum[x]%md;return;}
	int mid = L + R >> 1;
	if(r <= mid) mod(x<<1, l, r, L, mid, md);
	else if(l > mid) mod(x<<1|1, l, r, mid+1, R, md);
	else mod(x<<1, l, mid, L, mid, md), mod(x<<1|1, mid+1, r, mid+1, R, md);
	sum[x] = sum[x<<1]+sum[x<<1|1];
	mx[x] = max(mx[x<<1], mx[x<<1|1]);
}
ll ask(int x, int l, int r, int L, int R){
	if(l == L && r == R) return sum[x];
	int mid = L + R >> 1;
	if(r <= mid) return ask(x<<1, l, r, L, mid);
	if(l > mid) return ask(x<<1|1, l, r, mid+1, R);
	return ask(x<<1, l, mid, L, mid)+ask(x<<1|1, mid+1, r, mid+1, R);
}
int main(int argc, char const *argv[]){
	int n = read(), m = read();
	build(1, 1, n);
	while(m--){
		ll op = read(), l = read(), r = read();
		if(op == 1) printf("%lld\n", ask(1, l, r, 1, n));
		if(op == 2) mod(1, l, r, 1, n, read());
		if(op == 3) change(1, l, 1, n, r);
	}
	return 0;
}