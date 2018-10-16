#include <bits/stdc++.h>
#define N 1020
#define ll long long
#define pdd pair<int, int>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int dis(pdd a, pdd b = pdd(0, 0)) {
	return (a.first - b.first) * (a.first - b.first)
		+ (a.second - b.second) * (a.second - b.second);
}
int n, k;
pdd aa[50020];
pdd st[50020];
pdd as[50020];
int ans, top;
void dfs(int x, int now, int last) {
	// printf("%d %d\n", x, now);
	if (x == n+1) {
		if (now > ans) {
			ans = now;
			for (int i = 1; i <= n; i++)
				as[i] = st[i];
		}
		return;
	}
	if (now + 4*k*k*(n*(n-1)/2-(x-1)*(x-2)/2) <= ans)
		return;
	for (int i = last; i <= top; i++) {
		st[x] = aa[i];
		int sum = 0;
		for (int j = 1; j < x; j++)
			sum += dis(st[j], st[x]);
		dfs(x + 1, now + sum, i);
	}
}
bool cmp(const pdd &a, const pdd &b) {
	return dis(a) > dis(b);
}
int main(int argc, char const *argv[]) {
	cin >> n >> k;
	for (int i = -k; i <= k; i++)
		for (int j = -k; j <= k; j++)
			if (dis(pdd(i, j)) <= k*k)
				aa[++top] = pdd(i, j);
	sort(aa+1, aa+top+1, cmp);
	top = min(top, 18);
	dfs(1, 0, 1);
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
		printf("%d %d\n", as[i].first, as[i].second);
	return 0;
}
