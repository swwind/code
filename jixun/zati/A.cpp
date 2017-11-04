#include <bits/stdc++.h>
#define N 320
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int cnt[N], a[N][N], ans = 1 << 30, at[N], del[N];
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read();
	for (int i = 1; i <= n; i++)
		cnt[a[i][at[i] = 1]] ++;
	for (int i = 1; i <= m; i++) {
		int * mx = max_element(cnt + 1, cnt + m + 1);
		ans = min(ans, * mx);
		// printf("%d %d %d %d %d\n", cnt[1], cnt[2], cnt[3], cnt[4], cnt[5]);
		// printf("it %d => del %d, %d\n", i, mx - cnt, *mx);
		if (i == m) break;
		del[mx - cnt] = 1;
		for (int j = 1; j <= n; j++) {
			cnt[a[j][at[j]]] --;
			while (del[a[j][at[j]]])
				++ at[j];
			cnt[a[j][at[j]]] ++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
