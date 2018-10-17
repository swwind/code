#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mp[201][201], vis[201], lk[201], n, T, x;
bool find(int x){
	for(int i = 1; i <= n; i++)
	if(!vis[i] && mp[x][i]){
		vis[i] = 1;
		if(!lk[i]||find(lk[i])){
			lk[i] = x;
			return 1;
		}
	}
	return 0;
}
bool work(){
	for(int i = 1; i <= n; i++){
		memset(vis, 0, sizeof vis);
		if(!find(i)) return 0;
	}
	return 1;
}
int main(){
	scanf("%d", &T);
	while(T--){
		memset(lk, 0, sizeof lk);
		memset(mp, 0, sizeof mp);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			scanf("%d", &mp[i][j]);
		}
		puts(work()?"Yes":"No");
	}
	return 0;
}
