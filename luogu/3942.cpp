#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int head[N], to[N<<1], nxt[N<<1], cnt;
void insert(int x, int y) {
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
int n = read(), k = read(), t = read();
int ans;
void dfs(int x, int f) {
	
}
int main(int argc, char const *argv[]) {
	if (!k) return printf("%d\n", n)&0;
	for (int i = 1; i < n; i++)
		insert(read(), read());
	dfs(1, 0);
	return 0;
}