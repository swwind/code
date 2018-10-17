#include <bits/stdc++.h>
#define N 4000020
#define ll long long
using namespace std;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
class SAM{
public:
	int ch[N][10], fa[N], l[N], p, np, last, cnt, q, nq;
	char s[N], c;
	int extend(int p, int c){
		l[last=np=++cnt] = l[p]+1;
		for(;p&&!ch[p][c];p=fa[p]) ch[p][c] = np;
		if(!p) fa[np] = 1;
		else{
			q = ch[p][c];
			if(l[q] == l[p]+1) fa[np] = q;
			else{
				l[nq=++cnt] = l[p]+1;
				memcpy(ch[nq], ch[q], sizeof ch[p]);
				fa[nq] = fa[q];
				fa[q] = fa[np] = nq;
				for(;ch[p][c]==q;p=fa[p]) ch[p][c] = nq;
			}
		}
		return np;
	}
	SAM(){last = ++cnt;}
}sam;
int a[N], head[N], to[N<<1], nxt[N<<1], cnt, in[N];
void ins(int x, int y){
	in[x]++; in[y]++;
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
void dfs(int x, int f, int p){
	int t = sam.extend(p, a[x]);
	for(int i = head[x]; i; i = nxt[i])
		if(to[i] != f) dfs(to[i], x, t);
}
int main(){
	int n = read(), c = read();
	ll ans = 0;
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i < n; i++) ins(read(), read());
	for(int i = 1; i <= n; i++) if(in[i] == 1) dfs(i, 0, 1);
	for(int i = 1; i <= sam.cnt; i++) ans += sam.l[i]-sam.l[sam.fa[i]];
	printf("%lld\n", ans);
}