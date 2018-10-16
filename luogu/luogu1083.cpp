#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
const int inf = 0x3f3f3f3f;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int tg[N<<2], mn[N<<2];
int build(int x, int l, int r){
	if(l == r) return mn[x] = read();
	int mid = l + r >> 1;
	build(x<<1, l, mid); build(x<<1|1, mid+1, r);
	mn[x] = min(mn[x<<1], mn[x<<1|1]);
}
void push_down(int x){
	if(tg[x]){
		tg[x<<1] += tg[x];
		tg[x<<1|1] += tg[x];
		mn[x<<1] += tg[x];
		mn[x<<1|1] += tg[x];
	}
	tg[x] = 0;
}
void change(int x, int l, int r, int L, int R, int v){
	if(l == L && r == R){tg[x] += v; mn[x] += v; return;}
	push_down(x);
	int mid = L + R >> 1;
	if(r <= mid) change(x<<1, l, r, L, mid, v);
	else if(l > mid) change(x<<1|1, l, r, mid+1, R, v);
	else change(x<<1, l, mid, L, mid, v), change(x<<1|1, mid+1, r, mid+1, R, v);
	mn[x] = min(mn[x<<1], mn[x<<1|1]);
}
int main(int argc, char const *argv[]){
	int n = read(), m = read();
	build(1, 1, n);
	for(int i = 1; i <= m; i++){
		int v = read(), l = read(), r = read();
		change(1, l, r, 1, n, -v);
		if(mn[1] < 0) return printf("-1\n%d\n", i);
	}
	puts("0");
	return 0;
}