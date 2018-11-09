#include <bits/stdc++.h>
#define N 5020
#define ll long long
#define pii pair<int, int>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
pii a[N], b[N];
int main(int argc, char const *argv[]) {
	int n = read(), m = 0;
	for (int i = 1; i <= n; i++) {
		int x = read(), y = read();
		a[i] = pii(x, y);
	}
	sort(a+1, a+n+1);
	b[0].second = -1<<30;
	for (int i = 1; i <= n; i++)
		if (a[i].first > b[m].second) b[++m] = a[i];
		else b[m].second = max(b[m].second, a[i].second);
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= m; i++){
		ans1 = max(ans1, b[i].second-b[i].first);
		if (i > 1) ans2 = max(ans2, b[i].first-b[i-1].second);
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}