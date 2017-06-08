#include <bits/stdc++.h>
#define ll long long
#define N 50050
using namespace std;
int x, y, m, n, l[N<<2], r[N<<2], a[N<<2], lazy[N<<2];
void build(int id, int x, int y){
	if(x == y){
		scanf("%d%d", &l[id], &a[id]);
		r[id] = l[id];
		lazy[id] = 1;
		return;
	}
	int mid = x + y >> 1;
	build(id<<1, x, mid);
	build(id<<1|1, mid+1, y);
	lazy[id] = (lazy[id<<1] && lazy[id<<1|1]);
	if(r[id<<1] + 1 != l[id<<1|1]) lazy[id] = 0;
	l[id] = l[id<<1];
	r[id] = r[id<<1|1];
	a[id] = max(a[id<<1], a[id<<1|1]);
}
int ask(int id, int x, int y, int val){
	int f = 0;
	if(x < l[id])
		f = 1, x = l[id];
	if(l[id] == x && r[id] == y)
		if(a[id] >= val) return 0;
		else if(lazy[id] && !f) return 1;
		else return 2;
	if(y <= r[id<<1])
		return ask(id<<1, x, y, val);
	if(x >= l[id<<1|1])
		return ask(id<<1|1, x, y, val);
	int t1 = ask(id<<1, x, r[id<<1], val),
		t2 = ask(id<<1|1, l[id<<1|1], y, val);
	if(!t1 || !t2) return 0;
	if(r[id<<1] + 1 != l[id<<1|1]) return 2;
	return 1;
}
int get(int id, int x){
	if(l[id] == r[id]) return ((l[id] == x)? a[id] : 0);
	if(x <= r[id<<1]) return get(id<<1, x);
	if(x >= l[id<<1|1]) return get(id<<1|1, x);
	return 0;
}
int getNext(int id, int x){
	if(l[id] == r[id]) return l[id];
	if(x < r[id<<1]) return getNext(id<<1, x);
	else return getNext(id<<1|1, x);
}
int getLast(int id, int x){
	if(l[id] == r[id]) return l[id];
	if(x > l[id<<1|1]) return getLast(id<<1|1, x);
	else return getLast(id<<1, x);
}
int work(int x, int y){
	if(y < x) return 0;
	int lnum = get(1, x), rnum = get(1, y),
		s = getNext(1, x), t = getLast(1, y);
	if(!lnum && !rnum) return 1;
	if(!lnum)
		if(s > t || y == t) return 1;
		else return ask(1, s, t, rnum) ? 1 : 0;
	if(!rnum)
		if(s > t || x == s) return 1;
		else return ask(1, s, t, lnum) ? 1 : 0;
	if(rnum > lnum) return 0;
	if(s > t) return ((x + 1 == y) ? 2 : 1);
	int f = ask(1, s, t, rnum);
	if(!f) return 0;
	if(f == 1)
		if(x + 1 == s && y - 1 == t) return 2;
		else return 1;
	if(ask(1, s, t, rnum) == 2) return 2;
	return 0;
}
int main(){
	scanf("%d", &n);
	build(1, 1, n);
	scanf("%d", &m);
	while(m-- && scanf("%d%d", &x, &y) != EOF){
		int ans = work(x, y);
		if(ans == 0) puts("false");
		else if(ans == 1) puts("maybe");
		else puts("true");
	}
	return 0;
}

