#include <bits/stdc++.h>
#define N 1020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int f[N][N], mp[N][N], ans;
int main(int argc, char const *argv[]){
	int n = read(), m = read();
	for(int i = 1; i <= m; i++){
		int x = read(), y = read();
		mp[x][y] = 1;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) if(!mp[i][j])
			ans = max(ans, f[i][j] = min(f[i-1][j-1], min(f[i-1][j], f[i][j-1]))+1);
	printf("%d\n", ans);
	return 0;
}