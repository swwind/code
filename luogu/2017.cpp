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
int head[N], to[N<<2], nxt[N<<2], val[N<<2], cnt, fr[N<<2];
void insert(int x, int y, int v) {
	to[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
	val[cnt] = v;
	fr[cnt] = x;
}
queue<int>q;
int in[N];
int main(int argc, char const *argv[]) {
	int n = read(), m1 = read(), m2 = read();
	for (int i = 1; i <= m1; i++) {
		int x = read(), y = read();
		insert(x, y, 0); in[y]++;
	}
	if (~cnt&1) cnt++;
	for (int i = 1; i <= m2; i++) {
		int x = read(), y = read();
		insert(x, y, 1);
		insert(y, x, 1);
	}
	for (int i = 1; i <= n; i++)
		if (!in[i]) q.push(i);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i; i = nxt[i])
			if (!val[i] && !--in[to[i]])
				q.push(to[i]);
		for (int i = head[x]; i; i = nxt[i])
			if (val[i] == 1) val[i^1] = 2;
	}
	for (int i = 1; i <= cnt; i++)
		if (val[i] == 1) printf("%d %d\n", fr[i], to[i]);
	return 0;
}
