#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[N], n, ans[N], c[N], pos[N], nxt[N], vis[N];
struct node{
	int l, r, id;
	bool operator <(const node &b) const {
		return l < b.l;
	}
}asks[N];
void add(int x, int v){
	if(!x) return;
	for(;x<N;x+=x&-x)c[x]+=v;
}
int ask(int x){
	int ans = 0;
	for(;x;x^=x&-x)ans+=c[x];
	return ans;
}
int main(){
	n = read();
	int c = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = n; i; i--) nxt[i] = pos[a[i]], pos[a[i]] = i;
	for(int i = 1; i <= n; i++) if(!vis[a[i]]) add(nxt[i], vis[a[i]]=1);
	for(int i = 1; i <= m; i++){
		asks[i].id = i;
		asks[i].l = read();
		asks[i].r = read();
	}
	sort(asks+1, asks+m+1);
	for(int i = 1, now = 0; i <= m; i++){
		while(now < asks[i].l){
			if(nxt[now]){
				add(nxt[now], -1);
				add(nxt[nxt[now]], 1);
			}
			now++;
		}
		ans[asks[i].id] = ask(asks[i].r);
	}
	for(int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
}