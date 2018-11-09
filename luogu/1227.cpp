#include <bits/stdc++.h>
#define N 200020
using namespace std;
int n, u=-N, d=N, l=N, r=-N, x[N], y[N], vis[N];
map<int, map<int, int> > mp;
inline int max(int a, int b){return a < b ? b : a;}
inline int min(int a, int b){return a < b ? a : b;}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d%d", x+i, y+i);
		u = max(u, y[i]);
		d = min(d, y[i]);
		l = min(l, x[i]);
		r = max(r, x[i]);
		mp[x[i]][y[i]] = i;
	}
	int sx = l+r, sy = u+d; // 最后再除以二
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		if(!mp[int(sx-x[i])][int(sy-y[i])])
			return puts("This is a dangerous situation!")&0;
		vis[mp[int(sx-x[i])][int(sy-y[i])]] = vis[i] = 1;
	}
	printf("V.I.P. should stay at (%.1f,%.1f).\n", sx/2.0, sy/2.0);
	return 0;
}
