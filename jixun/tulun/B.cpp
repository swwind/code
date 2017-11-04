#include <bits/stdc++.h>
#define N 3020
#define M 10020
#define ll long long
#define EPS 1e-9
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int head[N], nxt[M], to[M], cnt;
double val[M];
void insert(int x, int y, double z) {
	to[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
	val[cnt] = z;
}
double ans = 1e10, s[M], dis[N];
int n = read(), m = read();
int x[M], y[M], vis[N];
bool spfa(int x) {
	vis[x] = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		if (dis[to[i]] > dis[x] + val[i]) {
			if (vis[to[i]]) return true;
			dis[to[i]] = dis[x] + val[i];
			if (spfa(to[i])) return true;
		}
	}
	vis[x] = 0;
	return false;
}
bool check(double mid) {
	memset(head, 0, sizeof head);
	memset(vis, 0, sizeof vis);
	memset(dis, 0, sizeof dis);
	cnt = 0;
	for (int i = 1; i <= m; i++)
		insert(x[i], y[i], s[i] - mid);
	for (int i = 1; i <= n; i++)
		if (spfa(i)) return true;
	return false;
}
int main(int argc, char const *argv[]) {
	for (int i = 1; i <= m; i++) {
		x[i] = read(), y[i] = read();
		scanf("%lf", s + i);
	}
	double l = - 1e10, r = 1e10;
	while (r - l > EPS) {
		double mid = (l + r) / 2;
		if (check(mid)) ans = r = mid;
		else l = mid;
	}
	printf("%.8lf\n", ans);
	return 0;
}