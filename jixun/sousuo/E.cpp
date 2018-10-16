#include <bits/stdc++.h>
#define N 1020
#define ll long long
#define mod 1000000007
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll n, m, k, f[N][N], a[N][N], num[20];
ll dfs(ll x, ll y){
	if (x > n) return 1;
	int now = f[x-1][y] | f[x][y-1];
	int cnt = 0, flag = -1, ans = 0;
	for (int i = now; i; i ^= i & -i)
		++ cnt;
	if (n + m - x - y + 1 > k - cnt)
		return 0;
	for (int i = (~ now) & ((1 << k) - 1); i; i ^= i & -i){
		int t = log((i & -i) + .5) / log(2) + 1;
		if (!a[x][y] || a[x][y] == t) {
			++num[t];
			f[x][y] = now | (i & -i);
			if (num[t] == 1){
				if (flag == -1)
					flag = dfs(x + y / m, y % m + 1);
				ans += flag;
			} else {
				ans += dfs(x + y / m, y % m + 1);
			}
			ans %= mod;
			--num[t];
		}
	}
	return ans;
}
int main(int argc, char * argv[]) {
	cin >> n >> m >> k;
	if (n + m - 1 > k) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			++ num[a[i][j]];
		}
	cout << dfs(1, 1) << endl;
	return 0;
}