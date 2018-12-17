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
int mp[420][420], q[420];
double c[420], f[420];
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	memset(mp, 63, sizeof mp);
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		mp[x][y] = mp[y][x] = 1;
	}
	for (int i = 1; i <= n; i++)
		mp[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				mp[i][j] = min(mp[i][j], mp[i][k]+mp[k][j]);
	double ans = 0;
	for (int i = 1; i <= n; i++) { // You first
		double res = 0;
		for (int j = 0; j < n; j++) {
			int cnt = 0, top = 0;
			double tmp = 0;
			memset(f, 0, sizeof f);
			for (int k = 1; k <= n; k++) {
				if (mp[i][k] == j) {
					cnt++;
					int tot = 0;
					for (int l = 1; l <= n; l++)
						if (mp[k][l] == 1)
							tot++;
					for (int l = 1; l <= n; l++)
						if (mp[k][l] == 1)
							f[l] += 1./tot;
				}
			}
			for (int k = 1; k <= n; k++)
				if (abs(mp[i][k]-j) <= 1)
					q[++top] = k;
			for (int k = 1; k <= n; k++) {
				double ret = 0;
				for (int l = 1; l <= top; l++)
					c[mp[k][q[l]]] = max(c[mp[k][q[l]]], f[q[l]]);
				for (int l = 1; l <= top; l++)
					ret += c[mp[k][q[l]]], c[mp[k][q[l]]] = 0;
				tmp = max(tmp, ret);
			}
			if (cnt) tmp = max(tmp, 1.);
			res += tmp/n;
		}
		ans = max(ans, res);
	}
	printf("%.12lf\n", ans);
	return 0;
}
