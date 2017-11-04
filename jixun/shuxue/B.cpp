#include <bits/stdc++.h>
#define N 20
#define mod 2004
#define ll long long
using namespace std;
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return f?x:-x;
}
int n = read(), misaka[N], ans;
int c(int n, int m) {
	int a2 = 0, a3 = 0, a5 = 0, a7 = 0;
	ll sum = 1;
	for (int i = 1; i <= m; i++) {
		int j = i;
		for (; j % 2 == 0; j /= 2) a2 ++;
		for (; j % 3 == 0; j /= 3) a3 ++;
		for (; j % 5 == 0; j /= 5) a5 ++;
		for (; j % 7 == 0; j /= 7) a7 ++;
	}
	for (int i = n - m + 1; i <= n; i++) {
		int j = i;
		for (; a2 && j % 2 == 0; j /= 2) a2 --;
		for (; a3 && j % 3 == 0; j /= 3) a3 --;
		for (; a5 && j % 5 == 0; j /= 5) a5 --;
		for (; a7 && j % 7 == 0; j /= 7) a7 --;
		sum = sum * j % mod;
	}
	return sum;
}
void dfs(int x, int s, int m) {
	if (m < 0) return;
	if (x > n) {
		if (s & 1) ans = (ans - c(m + n, n) + mod) % mod;
		else ans = (ans + c(m + n, n)) % mod;
		return;
	}
	dfs(x + 1, s, m);
	dfs(x + 1, s + 1, m - misaka[x] - 1);
}
int main(int argc, char const *argv[]) {
	int a = read(), b = read();
	for (int i = 1; i <= n; i++)
		misaka[i] = read();
	dfs(1, 0, b);
	dfs(1, 1, a - 1);
	printf("%d\n", ans);
	return 0;
}