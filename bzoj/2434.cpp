#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
const int maxn=100010;
using namespace std;
int m, len, num, preq[maxn], nowq[maxn], sonq[maxn];
int l[maxn], r[maxn], bit[maxn], pos[maxn],fa[maxn];
int cnt, pre[maxn], now[maxn], son[maxn], ans[maxn];
int sz, ch[maxn][26], q[maxn], hed, tal, fail[maxn];
char s[maxn];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void add(int x,int val){
	for(;x<=cnt;x+=x&-x) bit[x]+=val;
}
int ask(int x){
	int res=0;
	for(;x;x-=x&-x) res+=bit[x];
	return res;
}
void ins(int a, int b){
	pre[++num] = now[a];
	son[now[a]=num] = b;
}
void build(){
	int p = 0, id = 0;
	for(int i = 0; i < len; i++)
		if(s[i] == 'B') p = fa[p];
		else if(s[i] == 'P') pos[++id] = p;
		else{
			if(!ch[p][s[i]-'a']) ch[p][s[i]-'a'] = ++sz, fa[sz] = p;
			p = ch[p][s[i]-'a'];
		}
}
void getfail(){
	hed=0,q[tal=1]=0,fail[0]=-1;
	while (hed!=tal){
		int x=q[++hed];
		for(int i = 0; i < 26; i++)
			if(!ch[x][i])
				ch[x][i] = ch[fail[x]][i];
			else{
				if(x) fail[ch[x][i]] = ch[fail[x]][i];
				q[++tal] = ch[x][i];
			}
	}
}
void dfs(int x){
	l[x] = ++cnt;
	for(int i = now[x]; i; i = pre[i])
		dfs(son[i]);
	r[x] = cnt;
}
void work(){
	int p = 0, id = 0;
	add(l[0], 1);
	for(int i = 0; i < len; i++)
		if(s[i]=='P')
			for(int y = nowq[++id]; y; y = preq[y]){
				int t = pos[sonq[y]];
				ans[y] = ask(r[t])-ask(l[t]-1);
			}
		else if(s[i]=='B') add(l[p],-1), p = fa[p];
		else p = ch[p][s[i]-'a'], add(l[p],1);
}
int main(){
	scanf("%s", s);m=read();len=strlen(s);
	for(int i = 1, x, y; i <= m; i++){
		x=read(); y=read();
		preq[i] = nowq[y];
		sonq[nowq[y] = i] = x;
	}
	build(); getfail();
	for(int i = 1; i <= sz; i++) ins(fail[i],i);
	dfs(0); work();
	for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}