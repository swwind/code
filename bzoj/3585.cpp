#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, a[200050], cnt[200050], ans[200050], bl[200050], now;
struct node{
	int l, r, id;
	bool operator < (const node &b) const {
		return bl[l] == bl[b.l] ? r < b.r : bl[l] < bl[b.l];
	}
}t[200050];
void cal(int x,int f){
	if(x>n) return;
	cnt[x]+=f;
	if(x<now){
		if(!cnt[x]) now=x;
	}
	else if(now==x){
		while(cnt[now]) now++;
	}
}
void del(int x){
	cal(x,-1);
}
void add(int x){
	cal(x,1);
}
int main(){
	scanf("%d%d", &n, &m);
	int block = sqrt(n);
	for(int i = 1; i <= n; i++) scanf("%d", a+i);
	for(int i = 1; i <= m; i++) scanf("%d%d", &t[i].l, &t[i].r), t[i].id = i;
	for(int i = 1; i <= n; i++) bl[i] = (i-1) / block + 1;
	sort(t+1, t+m+1);
	int l=t[1].l, r=t[1].l;
	add(a[t[1].l]);
	for(int i = 1; i <= m; i++){
		while(l < t[i].l) del(a[l++]);
		while(l > t[i].l) add(a[--l]);	
		while(r < t[i].r) add(a[++r]);
		while(r > t[i].r) del(a[r--]);
		ans[t[i].id] = now;
	}
	for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}

