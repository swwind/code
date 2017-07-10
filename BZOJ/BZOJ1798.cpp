#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
int ls[N<<2], rs[N<<2], sum[N<<2], mtg[N<<2], atg[N<<2];
int zyy, n, m;
void push_downadd(int);
void push_downmul(int x){
	if(!mtg[x]) return;
	sum[x]=(ll)sum[x]*mtg[x]%zyy;
	if(ls[x]!=rs[x]){
		push_downadd(x<<1);
		push_downadd(x<<1|1);
		mtg[x<<1]+=mtg[x];
		mtg[x<<1|1]+=mtg[x];
	}
	mtg[x] = 0;
}
void push_downadd(int x){
	if(!atg[x]) return;
	sum[x]=((ll)sum[x]+1ll*(rs[x]-ls[x]+1)*atg[x])%zyy;
	if(ls[x]!=rs[x]){
		push_downmul(x<<1);
		push_downmul(x<<1|1);
		atg[x<<1]+=atg[x];
		atg[x<<1|1]+=atg[x];
	}
	atg[x] = 0;
}
void build(int x, int l, int r){
	ls[x] = l; rs[x] = r;
	if(l == r){
		scanf("%d\n", sum+x);
		return;
	}
	int mid = l + r >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	sum[x] = sum[x<<1]+sum[x<<1|1];
}
void add(int x, int l, int r, int val){
	push_downmul(x);
	if(ls[x]==l && rs[x]==r){
		atg[x] += val;
		return;
	}
	sum[x] = (sum[x]+(ll)val*(r-l+1))%zyy;
	int mid = ls[x]+rs[x]>>1;
	if(l > mid) return add(x<<1|1, l, r, val);
	if(r <= mid) return add(x<<1, l, r, val);
	add(x<<1, l, mid, val); add(x<<1|1, mid+1, r, val);
}
int mul(int x, int l, int r, int val){
	push_downadd(x);
	if(ls[x]==l && rs[x]==r){
		mtg[x] += val;
		return (1ll*sum[x]*(val-1))%zyy;
	}
	int mid = ls[x]+rs[x]>>1, afk = 0;
	if(r <= mid) afk = mul(x<<1, l, r, val);
	else if(l > mid) afk = mul(x<<1|1, l, r, val);
	else afk = (mul(x<<1, l, mid, val)+mul(x<<1|1, mid+1, r, val))%zyy;
	sum[x] = ((ll)sum[x]+afk)%zyy; return afk;
}
int ask(int x, int l, int r){
	push_downadd(x); push_downmul(x);
	if(ls[x]==l&&rs[x]==r) return sum[x];
	int mid = ls[x]+rs[x]>>1;
	if(r <= mid) return ask(x<<1, l, r);
	if(l > mid) return ask(x<<1|1, l, r);
	return (ask(x<<1, l, mid)+ask(x<<1|1, mid+1, r))%zyy;
}
int main(){
	scanf("%d%d", &n, &zyy);
	build(1, 1, n);
	scanf("%d", &m);
	int a,b,c,d;
	while(m--){
		scanf("%d%d%d", &a, &b, &c);
		if(a==3){printf("%d\n", ask(1, b, c));continue;}
		scanf("%d", &d);
		if(a==1)mul(1, b, c, d);
		else add(1, b, c, d);
	}
}