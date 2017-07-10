#include <bits/stdc++.h>
#define N 10000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll nog[N], tag[N], sum[N];
void build(int x, int l, int r){
	if(l == r){sum[x] = read(); return;}
	int mid = l + r >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
}
void push_down(int x, int l, int r){
	int mid = l + r >> 1;
	if(tag[x]){
		tag[x<<1] += tag[x];
		tag[x<<1|1] += tag[x];
		sum[x<<1] += tag[x]*(mid-l+1);
		sum[x<<1|1] += tag[x]*(r-mid);
		if(sum[x<<1] > 1) nog[x<<1] = 0;
		if(sum[x<<1|1] > 1) nog[x<<1|1] = 0;
		tag[x] = 0;
	}
}
void sqrt(int x, int l, int r, int L, int R){
	if(nog[x]) return;
	if(L == R){sum[x] = sqrt(sum[x]); if(sum[x] <= 1) nog[x] = 1; return;}
	push_down(x, L, R);
	int mid = L + R >> 1;
	if(r <= mid) sqrt(x<<1, l, r, L, mid);
	else if(l > mid) sqrt(x<<1|1, l, r, mid+1, R);
	else sqrt(x<<1, l, mid, L, mid), sqrt(x<<1|1, mid+1, r, mid+1, R);
	sum[x] = sum[x<<1]+sum[x<<1|1];
	if(sum[x] <= 1) nog[x] = 1;
}
ll ask(int x, int l, int r, int L, int R){
	if(l == L && r == R) return sum[x];
	int mid = L + R >> 1;
	if(r <= mid) return ask(x<<1, l, r, L, mid);
	else if(l > mid) return ask(x<<1|1, l, r, mid+1, R);
	else return ask(x<<1, l, mid, L, mid)+ask(x<<1|1, mid+1, r, mid+1, R);
}
void add(int x, int l, int r, int L, int R, int v){
	if(l == L && r == R){tag[x] += v; sum[x] += v*(R-L+1); if(sum[x] > 1) nog[x] = 0; return;}
	push_down(x, L, R);
	int mid = L + R >> 1;
	if(r <= mid) add(x<<1, l, r, L, mid, v);
	else if(l > mid) add(x<<1|1, l, r, mid+1, R, v);
	else add(x<<1, l, mid, L, mid, v), add(x<<1|1, mid+1, r, mid+1, R, v);
	sum[x] += sum[x<<1]+sum[x<<1|1];
	if(sum[x] > 1) nog[x] = 0;
}
int main(int argc, char const *argv[]){
	int n = read(), m = read();
	build(1, 1, n);
	while(m--){
		int op = read(), l = read(), r = read();
		if(op == 1) add(1, l, r, 1, n, read());
		if(op == 2) sqrt(1, l, r, 1, n);
		if(op == 3) printf("%lld\n", ask(1, l, r, 1, n));
	}
	return 0;
}