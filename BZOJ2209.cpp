#include <bits/stdc++.h>
#define abs(x) (x>0?x:-x)
#define N 100050
#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
using namespace std;
int fa[N], ch[N][2], sz[N], lmx[N], rmx[N], n, m, op, a, b;
int lmi[N], rmi[N], val[N], sum[N], rt, inv[N], rev[N];
char s[N];
void Push_Up(int x){
	sz[x] = sz[ls(x)] + sz[rs(x)] + 1;
	sum[x] = sum[ls(x)] + sum[rs(x)] + val[x];
	lmx[x] = max(lmx[ls(x)], sum[ls(x)] + lmx[rs(x)] + val[x]);
	rmx[x] = max(rmx[rs(x)], sum[rs(x)] + rmx[ls(x)] + val[x]);
	lmi[x] = min(lmi[ls(x)], sum[ls(x)] + lmi[rs(x)] + val[x]);
	rmi[x] = min(rmi[rs(x)], sum[rs(x)] + rmi[ls(x)] + val[x]);
}
void Make_Inv(int x){
	inv[x] ^= 1;
	swap(lmx[x], lmi[x]); lmx[x] *= -1; lmi[x] *= -1;
	swap(rmx[x], rmi[x]); rmx[x] *= -1; rmi[x] *= -1;
	val[x] *= -1; sum[x] *= -1;
}
void Make_Rev(int x){
	rev[x] ^= 1;
	swap(lmx[x], rmx[x]); swap(lmi[x], rmi[x]);
	swap(ls(x), rs(x));
}
void Push_Down(int x){
	if(inv[x]){
		inv[x] ^= 1;
		Make_Inv(ls(x)), Make_Inv(rs(x));
	}
	if(rev[x]){
		rev[x] ^= 1;
		Make_Rev(ls(x)), Make_Rev(rs(x));
	}
}
void Rotate(int x, int &k){
	int y = fa[x], z = fa[fa[x]], kind = ls(fa[x]) == x;
	if(y == k) k = x;
	else ch[z][ch[z][1] == y] = x;
	fa[x] = z; fa[y] = x; fa[ch[x][kind]] = y;
	ch[y][!kind] = ch[x][kind]; ch[x][kind] = y;
	Push_Up(y); Push_Up(x);
}
void Splay(int x, int &k){
	while(x != k){
		int y = fa[x], z = fa[fa[x]];
		if(y != k) if(ch[y][1] == x ^ ch[z][1] == y) Rotate(x, k);
		else Rotate(y, k);
		Rotate(x, k);
	}
}
int Kth(int x, int k){
	Push_Down(x);
	int mid = sz[ls(x)] + 1;
	if(k == mid) return x;
	else if(k < mid) return Kth(ls(x), k);
	else return Kth(rs(x), k - mid);
}
int Split(int l, int r){
	int x = Kth(rt, l), y = Kth(rt, r+2);
	Splay(x, rt); Splay(y, rs(x));
	return ls(rs(rt));
}
void Invert(int l, int r){
	return Make_Inv(Split(l, r));
}
void Rever(int l, int r){
	return Make_Rev(Split(l, r));
}
int Ask(int l, int r){
	int x = Split(l, r);
	return (abs(lmi[x])+1>>1)+(rmx[x]+1>>1);
}
int Build(int l, int r){
	if(l > r) return 0;
	if(l == r){
		lmi[l] = rmi[l] = min(0, val[l]);
		lmx[l] = rmx[l] = max(0, val[l]);
		sz[l] = 1; sum[l] = val[l];
		return l;
	}
	int mid = l + r >> 1;
	ls(mid) = Build(l, mid-1);
	rs(mid) = Build(mid+1, r);
	fa[ls(mid)] = fa[rs(mid)] = mid;
	Push_Up(mid);
	return mid;
}
int main(){
	scanf("%d%d%s", &n, &m, s+2);
	for(int i = 1; i <= n+2; i++)
	if(s[i] == '(') val[i] = 1;
	else if(s[i] == ')') val[i] = -1;
	rt = Build(1, n+2);
	while(m--){
		scanf("%d%d%d", &op, &a, &b);
		if(!op) printf("%d\n", Ask(a, b));
		else if(op == 1) Invert(a, b);
		else Rever(a, b);
	}
	return 0;
}

