#include <bits/stdc++.h>
#define N 3000020
#define ll long long
using namespace std;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
char str[N];
int mask;
void decode(int len){
	int mask = ::mask;
	for(int i = 0; i < len; i++){
		mask = (mask*131+i) % len;
		swap(str[i], str[mask]);
	}
}
class LCT{
	#ifndef N
	#define N 50
	#endif
public:
	int c[N][2], fa[N], st[N], val[N], tag[N];
	bool isroot(int x){
		return c[fa[x]][0] != x && c[fa[x]][1] != x;
	}
	void add(int x, int v){
		if(x) val[x] += v, tag[x] += v;
	}
	void push_down(int x){
		if(tag[x]){
			add(c[x][1], tag[x]);
			add(c[x][0], tag[x]);
			tag[x] = 0;
		}
	}
	void rotate(int x){
		int y = fa[x], z = fa[y];
		int r = c[y][0] == x, l = r^1;
		if(!isroot(y)) c[z][c[z][0]!=y] = x;
		fa[x] = z; fa[y] = x; fa[c[x][r]] = y;
		c[y][l] = c[x][r]; c[x][r] = y;
	}
	void splay(int x){
		int top = 0; st[++top]=x;
		for(int i = x; !isroot(i); i=fa[i])
			st[++top] = fa[i];
		for(int i = top; i; i--)
			push_down(st[i]);
		while(!isroot(x)){
			int y = fa[x], z = fa[y];
			if(!isroot(y))if(c[y][0]==x^c[z][0]==y)rotate(x);
			else rotate(y);
			rotate(x);
		}
	}
	void access(int x){
		for(int t = 0; x; t = x, x = fa[x])
			splay(x), c[x][1] = t;
	}
	void link(int x, int y){
		fa[x] = y;
		access(y); splay(y);
		add(y, val[x]);
	}
	void cut(int x){
		access(x); splay(x);
		add(c[x][0], -val[x]);
		c[x][0] = fa[c[x][0]] = 0;
	}
}lct;
class SAM{
public:
	int ch[N][30], fa[N], l[N], p, np, last, cnt, q, nq;
	SAM(){last = ++cnt;}
	void extend(int c){
		p = last; l[last=np=++cnt]=l[p]+1; lct.val[np] = 1;
		for(;p&&!ch[p][c];p=fa[p]) ch[p][c] = np;
		if(!p) fa[np] = 1, lct.link(np, 1);
		else{
			q = ch[p][c];
			if(l[q] == l[p]+1) fa[np] = q, lct.link(np, q);
			else{
				l[nq=++cnt] = l[p]+1;
				memcpy(ch[nq], ch[q], sizeof ch[p]);
				fa[nq] = fa[q]; lct.link(nq, fa[q]);
				fa[q] = fa[np] = nq;
				lct.cut(q); lct.link(q, nq); lct.link(np, nq);
				for(;ch[p][c]==q;p=fa[p]) ch[p][c] = nq;
			}
		}
	}
	int ask(int len){
		int x = 1;
		for(int i = 0; i < len; i++)
			if(!(x=ch[x][str[i]-'A'])) return 0;
		lct.splay(x); return lct.val[x];
	}
}sam;
char op[50];
int main(){
	int n = read();
	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < len; i++)
		sam.extend(str[i]-'A');
	while(n--){
		scanf("%s", op);
		if(op[0] == 'A'){
			scanf("%s", str); decode(len=strlen(str));
			for(int i = 0; i < len; i++)
				sam.extend(str[i]-'A');
		}
		else{
			scanf("%s", str); decode(len=strlen(str));
			int ans = sam.ask(len);
			printf("%d\n", ans);
			mask ^= ans;
		}
	}
}