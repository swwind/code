#include <bits/stdc++.h>
#define N 100020
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int a[N], n, m, ans[N], block, cnt[N];
const int KOTOMI = 1e5;
bitset<KOTOMI+1> f, g;
struct node{
	int l, r, id, op, x;
	bool operator < (const node &b) const {
		int x = l/block, y = b.l/block;
		return x == y ? r < b.r : x < y;
	}
}ask[N];
void add(int x){
	if(!cnt[x])
		f[x] = g[KOTOMI-x] = 1;
	cnt[x]++;
}
void del(int x){
	cnt[x]--;
	if(!cnt[x])
		f[x] = g[KOTOMI-x] = 0;
}
int main(){
	n = read(); m = read();
	block = sqrt(n);
	for(int i = 1; i <= n; i++)
		a[i] = read();
	for(int i = 1,x,y,z,h; i <= m; i++){
		x = read(); y = read(); z = read(); h = read();
		ask[i] = (node){y, z, i, x, h};
	}
	sort(ask+1, ask+m+1);
	int l = 1, r = 1; add(a[1]);
	for(int i = 1; i <= m; i++){
		while(l < ask[i].l) del(a[l++]);
		while(l > ask[i].l) add(a[--l]);
		while(r < ask[i].r) add(a[++r]);
		while(r > ask[i].r) del(a[r--]);
		if(ask[i].op == 1)
			ans[ask[i].id] = ((f>>ask[i].x)&f).any();
		if(ask[i].op == 2)
			ans[ask[i].id] = ((g>>(KOTOMI-ask[i].x))&f).any();
		if(ask[i].op == 3)
			for(int k = 1; k*k <= ask[i].x; k++)
				if(!(ask[i].x%k)&&f[k]&&f[ask[i].x/k]){
					ans[ask[i].id] = 1;
					break;
				}
	}
	for(int i = 1; i <= m; i++)
		puts(ans[i]?"hana":"bi");
}