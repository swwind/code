#include <bits/stdc++.h>
#define N 10020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int d[N], f[N][520];
int main(int argc, char const *argv[]) {
	// freopen("test.in", "r", stdin);
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
		d[i] = read();
	for (int i = 1; i <= n; i++) {
		f[i][0] = f[i-1][0];
		for (int j = 1; j <= m; j++) {
			if (i-j > 0) f[i][0] = max(f[i-j][j], f[i][0]);
			f[i][j] = f[i-1][j-1]+d[i];
		}
	}
	printf("%d\n", f[n][0]);
	return 0;
}
