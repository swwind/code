#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct ask {
	int x, y, z;
	friend bool operator < (const ask &a, const ask &b) {
		return a.z > b.z;
	}
}a[N];
int fa[N], hc[N]; ll ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		a[i].x = read();
		a[i].y = read();
		a[i].z = read();
	}
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int x = find(a[i].x), y = find(a[i].y);
		if (x == y) {
			if (hc[x]) continue;
			hc[x] ++; ans += a[i].z;
		} else {
			if (hc[x] && hc[y]) continue;
			hc[y] |= hc[x];
			fa[x] = y;
			ans += a[i].z;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
