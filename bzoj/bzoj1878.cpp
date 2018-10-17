#include <bits/stdc++.h>
#define N 50020
#define M 200020
using namespace std;
int a[N], k[1000020], ans, FAQ[M], n, m, block[N];
struct node{
	int l, r, id;
	bool operator < (const node &b) const{
		return block[l] == block[b.l] ?
			block[r] < block[b.r] : block[l] < block[b.l];
	}
}ask[M];
void add(int x){
	x = a[x];
	if(!k[x]) ans++;
	k[x]++;
}
void del(int x){
	x = a[x];
	k[x]--;
	if(!k[x]) ans--;
}
int main(){
	scanf("%d", &n);
	int bk = (int)sqrt(n);
	for(int i = 1; i <= n; i++)
		block[i] = i/bk;
	for(int i = 1; i <= n; i++)
		scanf("%d", a+i);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
		scanf("%d%d", &ask[i].l, &ask[i].r), ask[i].id = i;
	sort(ask+1, ask+m+1);
	int l = 1, r = 1;
	k[a[1]]++, ans = 1;
	for(int i = 1; i <= m; i++){
		int ls = ask[i].l, rs = ask[i].r;
		while(l < ls) del(l++);
		while(l > ls) add(--l);
		while(r < rs) add(++r);
		while(r > rs) del(r--);
		FAQ[ask[i].id] = ans;
	}
	for(int i = 1; i <= m; i++)
		printf("%d\n", FAQ[i]);
	return 0;
}
