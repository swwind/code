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
int a[N][N], b[N], c[1000020];
ll ans;
int main(int argc, char const *argv[]) {
	int n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = (read() + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]) % k;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			memset(c, 0, sizeof c);
			for (int l = 0; l <= m; l++) {
				int x = (a[j][l] - a[i][l] + k) % k;
				ans += c[x]; c[x] ++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}