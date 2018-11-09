#include <bits/stdc++.h>
using namespace std;
int D, S, N, d, s, w, x, y, fuck;
struct TreeA{
	int all[5050], hav[5050];
	void change(int id, int l, int r, int L, int R, int val){
		hav[id] = max(hav[id], val);
		if(l == L && r == R){
			all[id] = max(all[id], val);
			return;
		}
		int mid = l + r >> 1;
		if(R <= mid) return change(id<<1, l, mid, L, R, val);
		if(L > mid) return change(id<<1|1, mid+1, r, L, R, val);
		change(id<<1, l, mid, L, mid, val);
		change(id<<1|1, mid+1, r, mid+1, R, val);
	}
	int ask(int id, int l, int r, int L, int R){
		if(l == L && r == R) return hav[id];
		int mid = l + r >> 1;
		if(R <= mid) return max(all[id], ask(id<<1, l, mid, L, R));
		if(L > mid) return max(all[id], ask(id<<1|1, mid+1, r, L, R));
		else return max(all[id], max(ask(id<<1, l, mid, L, mid), ask(id<<1|1, mid+1, r, mid+1, R)));
	}
};
struct TreeB{
	TreeA all[5050], hav[5050];
	void change(int id, int l, int r, int L, int R, int LL, int RR, int val){
		hav[id].change(1, 0, S, LL, RR, val);
		if(L <= l && R >= r)
			return all[id].change(1, 0, S, LL, RR, val);
		int mid = l + r >> 1;
		if(R <= mid) return change(id<<1, l, mid, L, R, LL, RR, val);
		if(L > mid) return change(id<<1|1, mid+1, r, L, R, LL, RR, val);
		change(id<<1, l, mid, L, mid, LL, RR, val);
		change(id<<1|1, mid+1, r, mid+1, R, LL, RR, val);
	}
	int ask(int id, int l, int r, int L, int R, int LL, int RR){
		if(L <= l && R >= r)
			return hav[id].ask(1, 0, S, LL, RR);
		int mid = l + r >> 1;
		if(R <= mid) return max(all[id].ask(1, 0, S, LL, RR), ask(id<<1, l, mid, L, R, LL, RR));
		if(L > mid) return max(all[id].ask(1, 0, S, LL, RR), ask(id<<1|1, mid+1, r, L, R, LL, RR));
		return max(all[id].ask(1, 0, S, LL, RR), max(ask(id<<1, l, mid, L, mid, LL, RR), ask(id<<1|1, mid+1, r, mid+1, R, LL, RR)));
	}
}tree;
int main(){
	scanf("%d%d%d", &D, &S, &N);
	while(N--)
		scanf("%d%d%d%d%d", &d, &s, &w, &x, &y),
		fuck = tree.ask(1, 0, D, x+1, x+d, y+1, y+s),
		tree.change(1, 0, D, x+1, x+d, y+1, y+s, fuck+w);
	printf("%d", tree.ask(1, 0, D, 0, D, 0, S));
	return 0;
}

