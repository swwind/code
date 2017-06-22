#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int to[N<<1], nxt[N<<1], head[N], cnt, pos[N], ans[N], vis[N];
void ins(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
}
int find(int x, int f){
	for(int i = head[x]; i; i = nxt[i]) if(vis[to[i]] != f){
		vis[to[i]] = f;
		if(!pos[to[i]] || find(pos[to[i]], f)){
			pos[to[i]] = x;
			return 1;
		}
	}
	return 0;
}
int main(){
	int n = read();
	for(int i = 0; i < n; i++){
		int x = read();
		ins(i, max((i+x)%n, (i-x+n)%n));
		ins(i, min((i+x)%n, (i-x+n)%n));
	}
	for(int i = n-1; ~i; i--)
		if(!find(i, n-i))
			return puts("No Answer")&0;
	for(int i = 0; i < n; i++) ans[pos[i]] = i;
	printf("%d", ans[0]);
	for(int i = 1; i < n; i++) printf(" %d", ans[i]);
	return 0;
}