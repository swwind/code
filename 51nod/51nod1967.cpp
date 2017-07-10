#include <bits/stdc++.h>
#define N 400020
#define M 1200020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int head[N], to[M<<1], nxt[M<<1], cnt = 1, flag[M], in[N];
void ins(int x, int y){ in[x]++, in[y]++;
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
int st[N], tot;
void dfs(int x){
	for(int i = head[x]; i; i = nxt[i]){
		if(flag[i>>1]) continue;
		flag[i>>1] = (i&1)+1;
		dfs(to[i]);
	}
}
int main(int argc, char const *argv[]){
	int n = read(), m = read();
	for(int i = 1; i <= m; i++) ins(read(), read());
	for(int i = 1; i <= n; i++) if(in[i]&1) st[++tot] = i;
	for(int i = 1; i <= tot; i+=2) ins(st[i], st[i+1]);
	for(int i = 1; i <= n; i++) dfs(i);
	printf("%d\n", n-tot);
	for(int i = 1; i <= m; i++)
		putchar(flag[i] == 1 ? '0' : '1');
	return 0;
}
