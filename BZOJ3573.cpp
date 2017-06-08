#include <bits/stdc++.h>
#define N 500050
#define ll long long
using namespace std;
double a[N], s[N], val[N];
int d[N], last[N], tmp = 1, ans, n, cnt, x, y;
struct node{
	int to, nxt;
	node(){}
	node(int x, int y):to(x), nxt(y){}
}e[N<<1];
void insert(int x, int y){
	e[++cnt] = node(y, last[x]); last[x] = cnt;
	e[++cnt] = node(x, last[y]); last[y] = cnt;
}
void dfs(int x, int fa){
	for(int i = last[x]; i; i = e[i].nxt)
		if(e[i].to != fa)
			s[e[i].to] = s[x] + log(d[x]),
			dfs(e[i].to, x);
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", a+i);
	for(int i = 1; i < n; i++)
		scanf("%d%d", &x, &y),
		insert(x, y),
		d[x]++, d[y]++;
	for(int i = 2; i <= n; i++) d[i]--;
	s[1] = log(1);
	dfs(1, 0);
	for(int i = 1; i <= n; i++)
		val[i] = s[i] + log(a[i]);
	sort(val+1, val+n+1);
	for(int i = 2; i <= n; i++)
		if(val[i]-val[i-1] < 1e-5) tmp++;
		else ans = max(ans, tmp), tmp = 1;
	ans = max(ans, tmp);
	printf("%d\n", n-ans);
	return 0;
}
























































//Copy from hzwer.com
