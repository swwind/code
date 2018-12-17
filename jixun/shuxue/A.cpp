#include <bits/stdc++.h>
#define N 100020
#define mod 8388608
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll c[N][30];
int main(int argc, char const *argv[]) {
	int T = read();
	for (int i = 0; i <= 100000; i++) {
		c[i][0] = 1;
		for (int j = 1, j_end = min(i, 25); j <= j_end; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
	for (int i = 0; i <= 100000; i++)
		for (int j = 1; j <= 25; j++)
			c[i][j] = (c[i][j] * (1 << j) % mod + c[i][j - 1]) % mod;
	while (T --) {
		int n = read(), m = min(read(), 24);
		printf("%lld\n", n * c[n - 1][m - 1] % mod);
	}
	return 0;
}
