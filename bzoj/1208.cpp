#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000
#define N 80050
using namespace std;
int c[N][2], num[N], pre[N];
int n, t, x, ans, size, rt, kind, ans1, ans2;
void Rotate(int x, int &k){
	int y = pre[x], z = pre[pre[x]];
	int kind = c[y][1] == x;
	if(y == k) k = x;
	else c[z][c[z][1] == y] = x;
	pre[x] = z; pre[y] = x; pre[c[x][!kind]] = y;
	c[y][kind] = c[x][!kind]; c[x][!kind] = y;
}
void Splay(int x, int &k){
	while(x != k){
		int y = pre[x], z = pre[pre[x]];
		if(y != k) if(c[z][1] == y ^ c[y][1] == x) Rotate(x, k);
		else Rotate(y, k);
		Rotate(x, k);
	}
}
void Ins(int &k, int x, int fa){
	if(!k){
		k = ++size;
		num[k] = x;
		pre[k] = fa;
		Splay(k, rt);
		return;
	}
	if(x < num[k]) Ins(c[k][0], x, k);
	else Ins(c[k][1], x, k);
}
void Del(int x){
	Splay(x, rt);
	if(!c[x][0] || !c[x][1])
		rt = c[x][1] + c[x][0];
	else{
		int k = c[x][1];
		while(c[k][0]) k = c[k][0];
		c[k][0] = c[x][0];
		pre[c[x][0]] = k;
		rt = c[x][1];
	}
	pre[rt] = 0;
}
void Ask_Before(int k, int x){
	if(!k) return;
	if(num[k] <= x){ans1=k;Ask_Before(c[k][1],x);}
	else Ask_Before(c[k][0],x);
}
void Ask_After(int k, int x){
	if(!k)return;
	if(num[k]>=x){ans2=k;Ask_After(c[k][0],x);}
	else Ask_After(c[k][1],x);
}
int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &t, &x);
		if(!rt)
			kind = t, Ins(rt, x, 0);
		else if(kind == t) Ins(rt, x, 0);
		else{ans1=ans2=-1;
			Ask_Before(rt, x),
			Ask_After(rt, x);
			if(ans1==-1)
				(ans += num[ans2] - x) %= MOD, Del(ans2);
			else if(ans2==-1)
				(ans += x - num[ans1]) %= MOD, Del(ans1);
			else if(x - num[ans1] > num[ans2] - x)
				(ans += num[ans2] - x) %= MOD, Del(ans2);
			else
				(ans += x - num[ans1]) %= MOD, Del(ans1);
		}
	}
	printf("%d", ans);
	return 0;
}

