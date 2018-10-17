#include <bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
char ch[N];
int head[N], to[N], nxt[N], cnt;
struct pam{
	int cnt, last, ans;
	int a[N][26], fa[N], l[N], size[N], w[N];
	pam(){
		cnt = fa[0] = fa[1] = 1;
		l[1] = -1; ans = 0;
	}
	void extend(int c, int n){
		int p = last;
		while(ch[n-l[p]-1] != ch[n]) p = fa[p];
		if(!a[p][c]){
			int now = ++cnt, k = fa[p];
			l[now] = l[p]+2;
			while(ch[n-l[k]-1] != ch[n]) k = fa[k];
			fa[now] = a[k][c]; a[p][c] = now;
		}
		last = a[p][c];
		size[last]++;
	}
	void dfs(int x){
		if(~l[x]&1) w[l[x]] = 1;
		if(l[x]%4 == 0 && w[l[x]>>1]) ans = max(ans, l[x]);
		for(int i = head[x]; i; i = nxt[i]) dfs(to[i]);
		w[l[x]] = 0;
	}
}pam;
void ins(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
}
int main(){
	int len = read();
	scanf("%s", ch+1);
	for(int i = 1; i <= len; i++) pam.extend(ch[i]-'a', i);
	for(int i = pam.cnt; i > 1; i--) ins(pam.fa[i], i);
	pam.dfs(1); pam.dfs(0); printf("%d\n", pam.ans);
}