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
int a[30], n, m, b[5];
ll jc[30], ans, sum;
void dfs(int x, ll f, int j) {
	// printf("%d %lld\n", x, f);
	if (f && f == b[1] || f == b[2])
		return;
	if (f > b[1] && f > b[2] || !x){
		ans = (ans+jc[n-x]*jc[x])%1000000007;
		return;
	}
	for (int i = j+1; i <= n; i++)
		dfs(x-1, f+a[i], i);
}
int main(int argc, char const *argv[]) {
	jc[0] = 1;
	for (int i = 1; i < 30; i++)
		jc[i] = jc[i-1]*i%1000000007;
	n = read();
	for (int i = 1; i <= n; i++)
		sum += a[i] = read();
	sort(a+1, a+n+1);
	m = read();
	for (int i = 1; i <= m; i++)
		b[i] = read();
	sort(b+1, b+m+1);
	if (!m) return printf("%lld\n", jc[n])&0;
	dfs(n, 0, 0);
	printf("%lld\n", ans);
	return 0;
}
