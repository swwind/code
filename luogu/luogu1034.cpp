#include <bits/stdc++.h>
#define N 60
#define pii pair<int,int>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
const int inf = 1<<30;
int n = read(), k = read(), ans = 1<<30, c[N];
pii a[N];
int calc() {
	int pos = 1, sum = 0;
	int l = inf, r = 0;
	int u = 0, d = inf;
	int lu = -1, ld = -1;
	for (int i = 1; i <= n; i++) {
		l = min(a[i].first, l);
		r = max(a[i].second, r);
		u = max(a[i].first, u);
		d = min(a[i].second, d);
		if (i == c[pos]) {
			if (l <= lu && r >= ld)
				return inf;
			sum += (r-d)*(u-l);
			lu = u;
			ld = d;
			l = d = inf;
			r = u = 0;
			++pos;
		}
	}
	return sum; 
}
void dfs(int x, int y) {
	if (x == k) {
		c[x] = n;
		ans = min(ans, calc());
		return;
	}
	for (int i = y; i <= n-k+x; i++) {
		c[x] = i;
		dfs(x+1, i+1);
	}
}
int main(int argc, char const *argv[]) {
	for (int i = 1; i <= n; i++) {
		int x = read(), y = read();
		a[i] = pii(x, y);
	}
	sort(a+1, a+n+1);
	dfs(1, 1);
	for (int i = 1; i <= n; i++)
		swap(a[i].first, a[i].second);
	sort(a+1, a+n+1);
	dfs(1, 1);
	printf("%d\n", ans);
	return 0;
}
