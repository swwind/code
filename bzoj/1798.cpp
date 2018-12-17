#include <bits/stdc++.h>
#define N 100020
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int ls[N<<2], rs[N<<2], sum[N<<2], mtg[N<<2], atg[N<<2];
int zyy, n, m;
void push_down(int x){
	mtg[x<<1] = (mtg[x<<1]*mtg[x])%zyy;
	atg[x<<1] = (atg[x<<1]*mtg[x])%zyy;
	sum[x<<1] = (sum[x<<1]*mtg[x])%zyy;
	atg[x<<1] = (atg[x<<1]+atg[x])%zyy;
	mtg[x<<1|1] = (mtg[x<<1|1]*mtg[x])%zyy;
	atg[x<<1|1] = (atg[x<<1|1]*mtg[x])%zyy;
	sum[x<<1|1] = (sum[x<<1|1]*mtg[x])%zyy;
	atg[x<<1|1] = (atg[x<<1|1]+atg[x])%zyy;
	int mid = ls[x]+rs[x] >> 1;
	sum[x<<1] = (sum[x<<1]+(mid-ls[x]+1)*atg[x]%zyy)%zyy;
	sum[x<<1|1] = (sum[x<<1|1]+(rs[x]-mid)*atg[x]%zyy)%zyy;
	mtg[x] = 1; atg[x] = 0;
}
void build(int x, int l, int r){
	ls[x] = l; rs[x] = r;
	mtg[x] = 1; atg[x] = 0;
	if(l == r){sum[x] = read()%zyy; return;}
	int mid = l + r >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	sum[x] = (sum[x<<1]+sum[x<<1|1])%zyy;
}
void add(int x, int l, int r, int val){
	if(ls[x] == l && rs[x] == r){
		atg[x] = (atg[x]+val)%zyy;
		sum[x] = (sum[x]+(r-l+1)*val%zyy)%zyy;
		return;
	}
	int mid = ls[x]+rs[x] >> 1;
	if(mtg[x] != 1 || atg[x]) push_down(x);
	if(l > mid) add(x<<1|1, l, r, val);
	else if(r <= mid) add(x<<1, l, r, val);
	else add(x<<1, l, mid, val), add(x<<1|1, mid+1, r, val);
	sum[x] = (sum[x<<1]+sum[x<<1|1])%zyy;
}
void mul(int x, int l, int r, int val){
	if(ls[x] == l && rs[x] == r){
		mtg[x] = mtg[x]*val%zyy;
		atg[x] = atg[x]*val%zyy;
		sum[x] = sum[x]*val%zyy;
		return;
	}
	int mid = ls[x]+rs[x] >> 1;
	if(mtg[x] != 1 || atg[x]) push_down(x);
	if(r <= mid) mul(x<<1, l, r, val);
	else if(l > mid) mul(x<<1|1, l, r, val);
	else mul(x<<1, l, mid, val), mul(x<<1|1, mid+1, r, val);
	sum[x] = (sum[x<<1]+sum[x<<1|1])%zyy;
}
int ask(int x, int l, int r){
	if(ls[x] == l && rs[x] == r) return sum[x]%zyy;
	int mid = ls[x]+rs[x] >> 1;
	if(mtg[x] != 1 || atg[x]) push_down(x);
	if(r <= mid) return ask(x<<1, l, r);
	if(l > mid) return ask(x<<1|1, l, r);
	return (ask(x<<1, l, mid)+ask(x<<1|1, mid+1, r))%zyy;
}
signed main(){
	n = read(); zyy = read();
	build(1, 1, n); m = read();
	while(m--){
		int a = read(), b = read(), c = read();
		if(a == 3) printf("%lld\n", ask(1, b, c));
		else if(a == 1) mul(1, b, c, read());
		else add(1, b, c, read()%zyy);
	}
}