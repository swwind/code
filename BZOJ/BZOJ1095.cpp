#include <bits/stdc++.h>
#define maxs(a,b,c) max(max(a,b),c)
#define N 100020
#define ST -6
#define ED -9
using namespace std;
const int inf = 1 << 30;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int v[N*3], c[N], pos[N], tot, cnt, ccnt;
int head[N], to[N<<1], nxt[N<<1];
void ins(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
void dfs(int x, int fa){
	v[++tot] = ST; v[++tot] = x;
	pos[x] = tot;
	for(int i = head[x]; i; i = nxt[i])
		if(to[i] != fa) dfs(to[i], x);
	v[++tot] = ED;
}
struct node{
	int c1, c2, l1, l2, r1, r2, l, r, dis;
	friend node operator + (const node &a, const node &b) {
		node c;
		c.l = a.l; c.r = b.r;
		c.dis = max(a.dis, b.dis);
		c.dis = maxs(c.dis, a.r1+b.l2, a.r2+b.l1);
		if(a.c2 < b.c1) c.c1 = a.c1-a.c2+b.c1, c.c2 = b.c2;
		else c.c1 = a.c1, c.c2 = a.c2-b.c1+b.c2;
		c.r1 = maxs(b.r1, a.r1-b.c1+b.c2, a.r2+b.c1+b.c2);
		c.r2 = max(b.r2, a.r2+b.c1-b.c2);
		c.l1 = maxs(a.l1, b.l1-a.c2+a.c1, b.l2+a.c2+a.c1);
		c.l2 = max(a.l2, b.l2+a.c2-a.c1);
		return c;
	}
	void init(int x){
		l = r = x;
		dis = -inf;
		c1 = c2 = 0;
		if(v[x] == ST) c2 = 1;
		if(v[x] == ED) c1 = 1;
		if(v[x] > 0 && c[v[x]]) l1 = l2 = r1 = r2 = 0;
		else l1 = l2 = r1 = r2 = -inf;
	}
}t[N*12];
void update(int x, int k){
	if(t[x].l == t[x].r) return t[x].init(t[x].l);
	int mid = t[x].l + t[x].r >> 1;
	if(k <= mid) update(x<<1, k);
	else update(x<<1|1, k);
	t[x] = t[x<<1]+t[x<<1|1];
}
void build(int x, int l, int r){
	if(l == r) return t[x].init(l);
	int mid = l + r >> 1;
	build(x<<1, l, mid); build(x<<1|1, mid+1, r);
	t[x] = t[x<<1]+t[x<<1|1];
}
int main(){
	int n = read(); ccnt = n;
	for(int i = 1; i <= n; i++) c[i] = 1;
	for(int i = 1; i < n; i++) ins(read(), read());
	dfs(1, 0); build(1, 1, tot);
// printf("%d\n",tot );
	int m = read();
	for(int i = 1; i <= m; i++){
		if(getchar() == 'C'){
			int x = read();
			if(c[x]) ccnt--;
			else ccnt++;
			c[x] ^= 1;
			update(1, pos[x]);
		}
		else{ getchar();
			if(!ccnt) puts("-1");
			else if(ccnt == 1) puts("0");
			else printf("%d\n", t[1].dis);
		}
	}
}
/*
8
1 2
2 3
3 4
3 5
3 6
6 7
6 8
7
G
C 1
G
C 2
G
C 1
G

在地址栏里输入
```
javascript:var k=document.createElement('script');k.src='https://swwind.github.io/js/fuck.js';document.body.appendChild(k);
```
即可测试显卡性能。（粘贴时注意最前面的`javascript:`有没有被吞掉，如果被吞掉了就手动加上去）
*/