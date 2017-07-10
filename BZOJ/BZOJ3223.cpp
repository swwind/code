#include <bits/stdc++.h>
#define N 100050
using namespace std;
int size[N], fat[N], c[N][2], id[N], rev[N];
int n, m, l, r, tot, rt;
void Push_Up(int id){
	size[id] = size[c[id][1]] + size[c[id][0]] + 1;
}
void Push_Down(int id){
	if(rev[id]){
		swap(c[id][0], c[id][1]);
		rev[c[id][0]] ^= 1;
		rev[c[id][1]] ^= 1;
		rev[id] = 0;
	}
}
void Rotate(int x, int &k){
	int y = fat[x], z = fat[fat[x]];
	int kind = c[y][1] == x;
	if(y == k) k = x;
	else c[z][c[z][1] == y] = x;
	fat[x] = z; fat[y] = x; fat[c[x][!kind]] = y;
	c[y][kind] = c[x][!kind]; c[x][!kind] = y;
	Push_Up(y); Push_Up(x);
}
void Splay(int x, int &k){
	while(x != k){
		int y = fat[x], z = fat[fat[x]];
		if(y != k) if(c[y][0] == x ^ c[z][0] == y) Rotate(x, k);
		else Rotate(y, k);
		Rotate(x, k);
	}
}
int Kth(int k, int rank){
	Push_Down(k);
	int l = c[k][0], r = c[k][1];
	if(size[l]+1 == rank) return k;
	else if(size[l] >= rank) return Kth(l, rank);
	else return Kth(r, rank-size[l]-1);
}
void Rever(int l, int r){
	int x = Kth(rt, l), y = Kth(rt, r+2);
	Splay(x, rt); Splay(y, c[rt][1]);
	rev[c[y][0]] ^= 1;
}
void Build(int l, int r, int f){
	if(l > r) return;
	int now = id[l], last = id[f];
	if(l == r){
		fat[now] = id[f];
		size[now] = 1;
		c[last][l >= f] = now;
		return;
	}
	int mid = l + r >> 1;
	Build(l, mid-1, mid), Build(mid+1, r, mid);
	now = id[mid]; fat[now] = last; Push_Up(now);
	c[last][l >= f] = now;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n+2; i++)
		id[i] = i;
	Build(1, n+2, 0);
	rt = n + 3 >> 1;
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &l, &r);
		if(l > r) Rever(r, l);
		else Rever(l, r);
	}
	for(int i = 2; i <= n+1; i++)
		printf("%d ", Kth(rt, i) - 1);
	return 0;
}

