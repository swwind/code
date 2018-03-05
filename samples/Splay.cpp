// splay（好像会WA

#include <bits/stdc++.h>
#define ll long long
#define N 100000
using namespace std;
int sz[N], rev[N], tag[N], sum[N], ch[N][2], fa[N], val[N];
int n, m, rt, x;
void push_up(int x){
	sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
	sum[x] = sum[ch[x][1]] + sum[ch[x][0]] + val[x];
}
void push_down(int x){
	if(rev[x]){
		swap(ch[x][0], ch[x][1]);
		if(ch[x][1]) rev[ch[x][1]] ^= 1;
		if(ch[x][0]) rev[ch[x][0]] ^= 1;
		rev[x] = 0;
	}
	if(tag[x]){
		if(ch[x][1]) tag[ch[x][1]] += tag[x], sum[ch[x][1]] += tag[x];
		if(ch[x][0]) tag[ch[x][0]] += tag[x], sum[ch[x][0]] += tag[x];
		tag[x] = 0;
	}
}
void rotate(int x, int &k){
	int y = fa[x], z = fa[fa[x]];
	int kind = ch[y][1] == x;
	if(y == k) k = x;
	else ch[z][ch[z][1]==y] = x;
	fa[x] = z; fa[y] = x; fa[ch[x][!kind]] = y;
	ch[y][kind] = ch[x][!kind]; ch[x][!kind] = y;
	push_up(y); push_up(x);
}
void splay(int x, int &k){
	while(x != k){
		int y = fa[x], z = fa[fa[x]];
		if(y != k) if(ch[y][1] == x ^ ch[z][1] == y) rotate(x, k);
		else rotate(y, k);
		rotate(x, k);
	}
}
int kth(int x, int k){
	push_down(x);
	int r = sz[ch[x][0]]+1;
	if(k == r) return x;
	if(k < r) return kth(ch[x][0], k);
	else return kth(ch[x][1], k-r);
}
void split(int l, int r){
	int x = kth(rt, l), y = kth(rt, r+2);
	splay(x, rt); splay(y, ch[rt][1]);
}
void rever(int l, int r){
	split(l, r);
	rev[ch[ch[rt][1]][0]] ^= 1;
}
void add(int l, int r, int v){
	split(l, r);
	tag[ch[ch[rt][1]][0]] += v;
	val[ch[ch[rt][1]][0]] += v;
	push_up(ch[ch[rt][1]][0]);
}
int build(int l, int r, int f){
	if(l > r) return 0;
	if(l == r){
		fa[l] = f;
		sz[l] = 1;
		return l;
	}
	int mid = l + r >> 1;
	ch[mid][0] = build(l, mid-1, mid);
	ch[mid][1] = build(mid+1, r, mid);
	fa[mid] = f;
	push_up(mid);
	return mid;
}
int asksum(int l, int r){
	split(l, r);
	return sum[ch[ch[rt][1]][0]];
}
int main(){
	n = 5;
	rt = build(1, n+2, 0);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		add(i, i, x);
	}
	rever(1, n);
	printf("%d\n", asksum(1, n));
	return 0;
}
