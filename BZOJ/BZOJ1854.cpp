#include <bits/stdc++.h>
using namespace std;
int vis[1000010], ans, n, x, y, fa[1000010];
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n+1; ++i) fa[i] = i;
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", &x, &y);
		x = find(x), y = find(y);
		if(x == y) vis[x] = 1;
		else{
			if(x > y) swap(x, y);
			vis[x] = 1;
			fa[x] = y;
		}
	}
	for(int i = 1; i <= n+1; i++)
		if(!vis[i]) return printf("%d\n", i-1);
}
