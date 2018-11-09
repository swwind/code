#include <bits/stdc++.h>
#define ll long long
#define N 500050
using namespace std;
int sz[N], tag[N], mx[N], val[N], rev[N], fa[N], c[N][2];
int op, l, r, v, n, m, rt;
void Push_Up(int x){
	sz[x] = sz[c[x][1]] + sz[c[x][0]] + 1;
	mx[x] = max(val[x], max(mx[c[x][1]], mx[c[x][0]]));
}
void Push_Down(int x){
	if(tag[x]){
		if(c[x][0])
		tag[c[x][0]] += tag[x],
		val[c[x][0]] += tag[x],
		mx[c[x][0]] += tag[x];if(c[x][1])
		tag[c[x][1]] += tag[x],
		val[c[x][1]] += tag[x],
		mx[c[x][1]] += tag[x];
		tag[x] = 0;
	}
	if(rev[x]){
		swap(c[x][0], c[x][1]);
		rev[c[x][0]] ^= 1;
		rev[c[x][1]] ^= 1;
		rev[x] = 0;
	}
}
void Rotate(int x, int &k){
	int y = fa[x], z = fa[fa[x]];
	int kind = c[y][1] == x;
	if(y == k) k = x;
	else c[z][c[z][1] == y] = x;
	fa[y] = x; fa[c[x][!kind]] = y; fa[x] = z;
	c[y][kind] = c[x][!kind]; c[x][!kind] = y;
	Push_Up(y); Push_Up(x);
}
void Splay(int x, int &k){
	while(x != k){
		int y = fa[x], z = fa[fa[x]];
		if(y != k) if(c[y][1] == x ^ c[z][1] == y) Rotate(x, k);
		else Rotate(y, k);
		Rotate(x, k);
	}
}
int Kth(int x, int k){
	Push_Down(x);
	int r = sz[c[x][0]]+1;
	if(k == r) return x;
	if(k < r) return Kth(c[x][0], k);
	else return Kth(c[x][1], k-r);
}
void Split(int l, int r){
	int x = Kth(rt, l), y = Kth(rt, r+2);
//	printf("%d %d\n", x, y);
	Splay(x, rt); Splay(y, c[rt][1]);
}
void Rever(int l, int r){
	Split(l, r);
	rev[c[c[rt][1]][0]] ^= 1;
}
void Add(int l, int r, int v){
	Split(l, r);
	tag[c[c[rt][1]][0]] += v;
	val[c[c[rt][1]][0]] += v;
	mx[c[c[rt][1]][0]] += v;
}
int Ask(int l, int r){
	Split(l, r);
	return mx[c[c[rt][1]][0]];
}
int Build(int l, int r){
	if(l > r) return 0;
	if(l == r){
		sz[l] = 1;
		return l;
	}
	int mid = l + r >> 1;
	c[mid][0] = Build(l, mid-1);
	c[mid][1] = Build(mid+1, r);
	fa[c[mid][0]] = fa[c[mid][1]] = mid;
	Push_Up(mid);
	return mid;
}
int main(){
	scanf("%d%d", &n, &m);
	rt = Build(1, n+2);mx[0] = -(1<<30);
	while(m--){
		scanf("%d%d%d", &op, &l, &r);
		if(op == 1) scanf("%d", &v), Add(l, r, v);
		else if(op == 2) Rever(l, r);
		else printf("%d\n", Ask(l, r));
	}
	return 0;
}

