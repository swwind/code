#include <bits/stdc++.h>
#define N 20020
#define M 50020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int t[N], vis[N];
int n = read(), m = read();
int mp[220][220];
int main(int argc, char const *argv[]) {
	for (int i = 1; i <= n; i++)
		t[i] = read();
	memset(mp, 63, sizeof mp);
	for (int i = 1; i <= n; i++)
		mp[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int x = read()+1, y = read()+1;
		mp[x][y] = mp[y][x] = read();
	}
	int q = read();
	while (q--) {
		int x = read()+1, y = read()+1, ts = read();
		for (int k = 1; k <= n; k++) {
			if (vis[k] || t[k] > ts)
				continue;
			vis[k] = 1;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					mp[i][j] = min(mp[i][j], mp[i][k]+mp[k][j]);
		}
		printf("%d\n", mp[x][y] == mp[0][0] || !vis[x] || !vis[y] ? -1 : mp[x][y]);
	}
	return 0;
}
