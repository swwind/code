#include <bits/stdc++.h>
#define N 1000020
using namespace std;
int szb, n, m;
const int inf = 1<<30;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
struct node{
	int d[2], mn[2], mx[2], l, r;
	int& operator[] (int b){
		return d[b];
	}
	friend bool operator < (node a, node b){
		return a[szb] < b[szb];
	}
	friend int dis(node a, node b){
		return abs(a[0]-b[0])+abs(a[1]-b[1]);
	}
}p[N];
struct kdtree{
	node t[N], Q;
	int ans, rt;
	void update(int x){
		int l = t[x].l, r = t[x].r;
		if(l){
			t[x].mn[0] = min(t[x].mn[0], t[l].mn[0]);
			t[x].mn[1] = min(t[x].mn[1], t[l].mn[1]);
			t[x].mx[0] = max(t[x].mx[0], t[l].mx[0]);
			t[x].mx[1] = max(t[x].mx[1], t[l].mx[1]);
		}
		if(r){
			t[x].mn[0] = min(t[x].mn[0], t[r].mn[0]);
			t[x].mn[1] = min(t[x].mn[1], t[r].mn[1]);
			t[x].mx[0] = max(t[x].mx[0], t[r].mx[0]);
			t[x].mx[1] = max(t[x].mx[1], t[r].mx[1]);
		}
	}
	int build(int l, int r, int now){
		szb = now;
		int mid = l + r >> 1;
		nth_element(p+l, p+mid, p+r+1);
		t[mid] = p[mid];
		t[mid].mn[0] = t[mid].mx[0] = t[mid][0];
		t[mid].mn[1] = t[mid].mx[1] = t[mid][1];
		if(l < mid) t[mid].l = build(l, mid-1, now^1);
		if(mid < r) t[mid].r = build(mid+1, r, now^1);
		update(mid); return mid;
	}
	int getmn(node a){
		return
			max(Q[0]-a.mx[0], 0)+max(a.mn[0]-Q[0], 0)+
			max(Q[1]-a.mx[1], 0)+max(a.mn[1]-Q[1], 0);
	}
	int askmn(int x){
		ans = min(ans, dis(t[x], Q));
		int l = t[x].l, r = t[x].r;
		int dl = l ? getmn(t[l]) : inf;
		int dr = r ? getmn(t[r]) : inf;
		if(dl < dr){
			if(dl < ans) askmn(l);
			if(dr < ans) askmn(r);
		}
		else{
			if(dr < ans) askmn(r);
			if(dl < ans) askmn(l);
		}
	}
	int ask(int x, int y){
		Q[0] = x; Q[1] = y; ans = inf;
		askmn(rt); return ans;
	}
	void ins(int x, int now){
		if(Q[now] > t[x][now])
			if(t[x].r) ins(t[x].r, now^1);
			else{
				t[x].r = ++n; t[n] = Q;
				t[n].mn[0] = t[n].mx[0] = t[n][0];
				t[n].mn[1] = t[n].mx[1] = t[n][1];
			}
		else
			if(t[x].l) ins(t[x].l, now^1);
			else{
				t[x].l = ++n; t[n] = Q;
				t[n].mn[0] = t[n].mx[0] = t[n][0];
				t[n].mn[1] = t[n].mx[1] = t[n][1];
			}
		update(x);
	}
	void add(int x, int y){
		Q[0] = x; Q[1] = y;
		ins(rt, 0);
	}
}kd;
int main(){
	n = read(); m = read();
	for(int i = 1; i <= n; i++)
		p[i][0] = read(), p[i][1] = read();
	kd.rt = kd.build(1, n, 0);
	while(m--){
		int op = read(), x = read(), y = read();
		if(op == 1) kd.add(x, y);
		else printf("%d\n", kd.ask(x, y));
	}
	return 0;
}