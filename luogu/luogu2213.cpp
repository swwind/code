#include <bits/stdc++.h>
#define N 420
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
/*
int a[N][N];
int baoli() {
	int n = read(), k = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x = read();
			for (int I = max(1, i - k); I <= min(n, i + k); I++)
				for (int J = max(1, j - k); J <= min(n, j + k); J++)
					if (abs(I - i) + abs(J - j) <= k) a[I][J] += x;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans = max(ans, a[i][j]);
	cout << ans << endl;
	return 0;
}
*/
long long ans, b[N << 1][N << 1];
int main(int argc, char const *argv[]) {
	// freopen("test.out", "w", stdout);
	int n = read(), k = read(), m = n * 2 - 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			b[n - j + i][i + j - 1] = read();
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] += b[i - 1][j];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] += b[i][j - 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x = n - j + i;
			int y = i + j - 1;

			int x1 = max(1, x - k);
			int y1 = max(1, y - k);
			int x2 = min(m, x + k);
			int y2 = min(m, y + k);
			ans = max(ans, b[x2][y2] - b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1]);
		}
	}
	cout << ans << endl;
	return 0;
}