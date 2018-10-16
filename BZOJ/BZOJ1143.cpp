#include <bits/stdc++.h>
using namespace std;
bool mp[120][120];
int fa[120], q[120],n,m, cnt, ans;
void r(){
	for(int i = 2; i <= n; i++)
		swap(fa[i], fa[rand()%i+1]);
}
int main(){
	srand(23333);
	scanf("%d%d", &n, &m);
	for(int i = 1,x,y; i <= m; i++){
		scanf("%d%d", &x, &y);
		mp[x][y] = 1;
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				mp[i][j] = mp[i][j] || mp[i][k]&&mp[k][j];
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= 100000; i++){
		r(); cnt = 0;
		for(int j = 1; j <= n; j++){
			bool flag = 1;
			for(int k = 1; k <= cnt&&flag; k++)
				if(mp[q[k]][fa[j]] || mp[fa[j]][q[k]])
					flag = 0;
			if(flag) q[++cnt] = fa[j];
		}
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
}