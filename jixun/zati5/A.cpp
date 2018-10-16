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
ll a[N], b[N], c[N], f[N], g[N];
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
		b[i] = read();
	for (int i = 1; i <= n; i++)
		c[i] = read();
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1);
	for (int i = 1; i <= n; i++)
		f[i] = lower_bound(a + 1, a + n + 1, b[i]) - a - 1 + f[i - 1];
	for (int i = 1; i <= n; i++)
		g[i] = f[lower_bound(b + 1, b + n + 1, c[i]) - b - 1] + g[i - 1];
	printf("%lld\n", g[n]);
	return 0;
}