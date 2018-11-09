#include <bits/stdc++.h>
using namespace std;
int n, t, m, a[21], ans;

int main(){
	void dfs(int, int, int, int);
	scanf("%d%d%d", &n, &t, &m);
	for(int k = 0; k < n; k++)
		scanf("%d", &a[k]);
	dfs(0, 1, t, 0);
	printf("%d", ans);
	return 0;
}

void dfs(int s, int d, int l, int e){
	if(s == n){
		if(e > ans)
			ans = e;
		return;
	}
	if(a[s] <= t)
		if(a[s] <= l)
			dfs(s+1, d, l-a[s], e+1);
		else if(d < m)
			dfs(s+1, d+1, t-a[s], e+1);
	dfs(s+1, d, l, e);
}

