#include <bits/stdc++.h>
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define ll long long
using namespace std;
int n, m, ans, x, y;
int fa[2005], a[2005];
char ch[5];
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= 2*n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++){
		scanf("%s%d%d", ch, &x, &y);
		if(ch[0] == 'F') fa[find(x)] = find(y);
		else fa[find(x)] = find(y+n), fa[find(y)] = find(x+n);
	}
	for(int i = 1; i <= n; i++) a[i] = find(i);
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++)
		if(a[i] != a[i-1]) ans++;
	printf("%d", ans);
	return 0;
}
