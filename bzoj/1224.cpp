#include <bits/stdc++.h>
#define esp 1e-10
using namespace std;
int n, m, ans, x, y;
double target, sum[60];
void dfs(int pos, int cnt, double now){
	double _max = now + sum[pos+(n-cnt)-1] - sum[pos-1], _min = now + sum[m] - sum[m-n+cnt];
	if(_min - target > esp || _max - target < -esp) return;
	if(cnt == n){
		ans++;
		return;
	}
	if(pos == m + 1) return;
	dfs(pos+1, cnt, now);
	dfs(pos+1, cnt+1, now + 1.0 / pos);
}
int main(){
	scanf("%d%d%d%d", &n, &m, &x, &y);
	target = (double) x / (double) y;
	for(int i = 1; i <= m; i++)
		sum[i] = sum[i-1] + 1.0 / i;
	dfs(1, 0, 0.0);
	return printf("%d", ans), 0;
}
