#include <bits/stdc++.h>
using namespace std;
int n, x, y, mp[60][60], vis[60], a[60];
int sum, ans;
int main(){
	scanf("%d", &n); srand(2333);
	while(scanf("%d%d", &x, &y) != EOF && x && y)
		mp[x][y] = mp[y][x] = 1;
	for(int i = 1; i <= n; ++i) a[i] = i;
	for(int k = 1; k <= 10000; ++k, ans = 0){
		for(int i = 1; i <= n; ++i)
			swap(a[i], a[rand()%i+1]);
		memset(vis, 0, sizeof vis);
		for(int i = 1; i <= n; ++i)
			if(!vis[i]){
				++ans;
				for(int j = i+1; j <= n; ++j)
					if(!mp[a[i]][a[j]])
						vis[j] = 1;
			}
		sum = max(sum, ans);
	}
	printf("%d\n", sum);
}