#include <bits/stdc++.h>
#define ll long long
#define N 20000020
using namespace std;
int n, m;
int sz, rt[1000010], ls[N], rs[N], tag[N];
ll sum[N];
void pushdown(int x, int L, int R){
	if(!ls[x]) ls[x] = ++sz;
	if(!rs[x]) rs[x] = ++sz;
	int mid = L + R >> 1;
	if(tag[x]){
		tag[ls[x]] += tag[x];
		sum[ls[x]] += tag[x]*(mid-L+1);
		tag[rs[x]] += tag[x];
		sum[rs[x]] += tag[x]*(R-mid);
		tag[x] = 0;
	}
}
void insert(int &x, int L, int R, int l, int r){
	if(!x) x = ++sz;
	if(L==l&&R==r){
		sum[x] += R-L+1;
		tag[x]++;
		return;
	}
	pushdown(x, L, R);
	int mid = L + R >> 1;
	if(r<=mid) insert(ls[x], L, mid, l, r);
	else if(l>mid) insert(rs[x], mid+1, R, l, r);
	else insert(ls[x], L, mid, l, mid), insert(rs[x], mid+1, R, mid+1, r);
	sum[x] = sum[ls[x]]+sum[rs[x]];
}
ll ask(int x, int L, int R, int l, int r){
	if(!x) return 0;
	if(L==l && R==r) return sum[x];
	pushdown(x, L, R);
	int mid = L + R >> 1;
	if(r<=mid) return ask(ls[x], L, mid, l, r);
	else if(l>mid) return ask(rs[x], mid+1, R, l, r);
	else return ask(ls[x], L, mid, l, mid)+ask(rs[x], mid+1, R, mid+1, r);
}
void insert(int x, int L, int R, int l, int r, int val){
	insert(rt[x], 1, n, l, r);
	if(L==R) return;
	int mid = L + R >> 1;
	if(val<=mid) insert(x<<1, L, mid, l, r, val);
	else insert(x<<1|1, mid+1, R, l, r, val);
}
ll ask(int x, int L, int R, int l, int r, ll k){
	if(L==R) return L;
	int mid = L + R >> 1;
	ll lefts = ask(rt[x<<1|1], 1, n, l, r);
	if(k>lefts) return ask(x<<1, L, mid, l, r, k-lefts);
	else return ask(x<<1|1, mid+1, R, l, r, k);
}
ll K;
int main(){
	cin>>n>>m;
	for(int i = 1, t, l, r; i <= m; i++){
		cin>>t>>l>>r>>K;
		if(t==1)insert(1, 0, n<<1, l, r, K+n);
		else cout<<ask(1, 0, n<<1, l, r, K)-n<<endl;
	}
}