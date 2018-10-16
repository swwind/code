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
char a[N], b[N];
char c[N];
int f[1020][1020], g[1020][1020];
int print(int x, int y) {
	if (g[x][y] == 2) print(x - 1, y);
	else if (g[x][y] == 3) print(x, y - 1);
	else if (g[x][y] == 1) print(x - 1, y - 1), putchar(a[x]);
	return 0;
}
int main(int argc, char const *argv[]) {
	scanf("%s%s", a + 1, b + 1);
	int n = strlen(a + 1);
	int m = strlen(b + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				ans = max(ans, f[i][j] = f[i - 1][j - 1] + 1);
				g[i][j] = 1;
			} else {
				if (f[i - 1][j] > f[i][j - 1]) {
					f[i][j] = f[i - 1][j];
					g[i][j] = 2;
				} else {
					f[i][j] = f[i][j - 1];
					g[i][j] = 3;
				}
			}
		}
	}
	// printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (f[i][j] == ans)
				return print(i, j);
	return 0;
}