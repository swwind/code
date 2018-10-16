#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
bool mp[120][120];
int a[120], ans, q[120];
int main(int argc, char const *argv[]) {
	srand(23333);
	int n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		mp[x][y] = 1;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				mp[i][j] |= mp[i][k] && mp[k][j];
	for (int i = 1; i <= n; i ++)
		a[i] = i;
	for (int i = 1; i <= 10000; i ++) {
		random_shuffle(a + 1, a + n + 1);
		int cnt = 0;
		for (int j = 1; j <= n; j ++) {
			int flag = 0;
			for (int k = 1; k <= cnt && !flag; k ++)
				if (mp[q[k]][a[j]] || mp[a[j]][q[k]])
					flag = 1;
			if (!flag)
				q[++cnt] = a[j];
		}
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}