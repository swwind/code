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
int n = read(), m = read(), q[N], ax[N], ay[N];
struct node {
	ll x, y, z;
}a[N];
int calc(node a, node b, node c) {
	return a.x*b.y*c.z+a.y*b.z*c.x+a.z*b.x*c.y;
}
void dfs(int x, int k) {
	if (x <= m-k) {
		puts("YES");
		printf("%d\n", k+x);
		for (int i = 1; i <= k; i++)
			printf("%d %d\n", ax[i], ay[i]);
		for (int i = 1; i <= x; i++)
			printf("%d -1\n", q[i]);
		exit(0);
	}
	if (k == m)
		return;
	int r = m-k;
	int d[N];
	memcpy(d, q, 4*(x+1));
	for (int rr = r*r; rr; rr--) {
		int s = rand()%x+1, e = rand()%x+1, cnt = 0;
		if (s == e) e++;
		s = q[s]; e = q[e];
		if (a[s].x*a[e].y == a[e].x*a[s].y)
			continue;
		for (int i = 1; i <= x; i++)
			if (calc(a[s], a[e], a[d[i]]) != calc(a[s], a[d[i]], a[e]))
				q[++cnt] = d[i];
		if (cnt > max(r-1., x*(1-.5/r)))
			continue;
		ax[k+1] = s; ay[k+1] = e;
		dfs(cnt, k+1);
	}
}
int main(int argc, char const *argv[]) {
	srand(time(0));
	for (int i = 1; i <= n; i++) {
		a[i].x = read();
		a[i].y = read();
		a[i].z = read();
		q[i] = i;
	}
	dfs(n, 0);
	puts("NO");
	return 0;
}