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
int a[N];
ll s1[N], s2[N], ans, res = 1ll << 60;
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i < n; i++) {
		int x = a[i], y = a[i + 1];
		if (x > y) y += m;
		s1[x + 1] += x + 1;
		s1[y + 1] -= x + 1;
		s2[x + 1] ++;
		s2[y + 1] --;
	}
	for (int i = 1; i <= (m << 1); i++) {
		s1[i] += s1[i - 1];
		s2[i] += s2[i - 1];
	}
	for (int i = 1; i < n; i++)
		if (a[i] <= a[i + 1]) ans += a[i + 1] - a[i];
		else ans += a[i + 1] + m - a[i];
	for (int i = 1; i <= m; i++)
		res = min(res, ans - s2[i] * i - s2[i + m] * (i + m) + s1[i] + s1[i + m]);
	printf("%lld\n", res);
	return 0;
}
