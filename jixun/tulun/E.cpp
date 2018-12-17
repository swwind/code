#include <bits/stdc++.h>
#define N 100020
#define QUEUE_SIZE 500020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int n = read(), m = read(), q[QUEUE_SIZE];
ll dis[N], vis[N];
int head[N], val[N << 1], nxt[N << 1], to[N << 1], cnt;
void insert(int x, int y, int z) {
	to[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
	val[cnt] = z;
}
int main(int argc, char const *argv[]) {
	for (int i = 1; i <= m; i ++) {
		int op = read(), x = read(), y = read();
		switch (op) {
			case 1:
				insert(x, y, 0);
				insert(y, x, 0);
				break;
			case 2:
				if (x == y)
					return puts("-1") & 0;
				insert(x, y, 1);
				break;
			case 3:
				insert(y, x, 0);
				break;
			case 4:
				if (x == y)
					return puts("-1") & 0;
				insert(y, x, 1);
				break;
			case 5:
				insert(x, y, 0);
				break;
		}
	}
	for (int i = 1; i <= n; i++) {
		q[i] = i;
		dis[i] = vis[i] = 1;
	}
	int l = 0, r = n;
	while (l < r) {
		int x = q[(++ l) % QUEUE_SIZE];
		if (dis[x] > n)
			return puts("-1") & 0;
		for (int i = head[x]; i; i = nxt[i]) {
			if (dis[to[i]] < dis[x] + val[i]) {
				dis[to[i]] = dis[x] + val[i];
				if (!vis[to[i]]) {
					q[(++ r) % QUEUE_SIZE] = to[i];
					vis[to[i]] = true;
				}
			}
		}
		vis[x] = false;
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++)
		sum += dis[i];
	printf("%lld\n", sum);
	return 0;
}