// lct 模板（指针型

#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define REP(i, x, y) for(int i = (int)x; i <= (int)y; i ++)
using namespace std;
const	int N = 100005;

struct node{
	node *s[2], *f;
	int sum, val, rev;
	void set(node *c, int d){
		s[d] = c;
		if(c) c -> f = this;
	}
	int isr(){
		return !f || f -> s[0] != this && f -> s[1] != this;
	}
	int dir(){
		return f -> s[1] == this;
	}
	void rot(){
		node *y = f; int d = dir();
		if(!f) f = NULL;else{
			if(y -> f -> s[0] == y) y -> f -> s[0] = this;
			if(y -> f -> s[1] == y) y -> f -> s[1] = this;
			f = y -> f;
		}
		y -> set(s[!d], d);
		set(y, !d);
		y -> upd();
	}
	void upd(){
		sum = val;
		REP(i, 0, 1) if(s[i]) sum += s[i] -> sum;
	}
	int rever(){
		rev ^= 1;
		swap(s[0], s[1]);
	}
	void sep(){
		if(rev){
			REP(i, 0, 1) if(s[i]) s[i] -> rever();
			rev = 0;
		}
	}
}ex[N], *stk[N]; int top;

void splay(node *w){
	for(node *k = w; ; k = k -> f){
		stk[++top] = k;
		if(k -> isr()) break;
	}
	for(; top; top --) stk[top] -> sep();
	while(!w -> isr()){
		node *y = w -> f;
		if(y -> isr()){
			w -> rot();
			break;
		}
		(y -> dir() == w -> dir()) ? y -> rot() : w -> rot();
		w -> rot();
	}
	w -> upd();
}

void access(node *w){
	node *v = NULL;
	for(; w; v = w, w = w -> f){
		splay(w);
		w -> set(v, 1);
		w -> upd();
	}
}

void evert(node *u){
	access(u);
	splay(u);
	u -> rever();
}

void Link(node *u, node *v){
	evert(u);
	evert(v);
	v -> f = u;
}

void Cut(node *u, node *v){
	evert(u);
	access(u);
	splay(v);
	v -> f = NULL;
}

int Ask(node *u, node *v){
	evert(u);
	access(v);
	splay(v);
	return v -> sum;
}

void Mod(node *w, int val){
	splay(w);
	w -> val = val;
	w -> upd();
}

struct edge{
	int v, pre;
}e[N]; int dex, adj[N];

int n, m;

int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1){
			Link(ex + x, ex + y);
		}
		if(op == 2){
			Cut(ex + x, ex + y);
		}
		if(op == 3){
			Mod(ex + x, y);
		}
		if(op == 4){
			printf("%d\n", Ask(ex + x, ex + y));
		}
	}
	return 0;
}
