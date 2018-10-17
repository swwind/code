#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, f[1050][1050], sw[1050], vis[1050], a, b, ans;
int find(int x){
	for(int i = 0; i < n; i++)
		if(!vis[i] && f[x][i]){
			vis[i] = 1;
			if(!sw[i] || find(sw[i])){
				sw[i] = x;
				return 1;
			}
		}
	return 0;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
		scanf("%d%d", &a, &b),
		f[i][a] = f[i][b] = 1;
	for(int i = 1; i <= m; i++, memset(vis, 0, sizeof vis))
		if(find(i)) ans++;
		else break;
	return printf("%d", ans), 0;
}

