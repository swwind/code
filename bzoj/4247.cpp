#include <bits/stdc++.h>
#define N 2020
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct node{
	int x, y;
}e[N];
int dp[N][N];
bool operator < (const node &a, const node &b){
	return a.x == b.x ? a.y > b.y : a.x > b.x;
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++){
		e[i].x = read(); e[i].y = read();
	}
	for(int i = 0; i <= n; i++)
		dp[0][i] = dp[i][n+1] = -(1<<30);
	sort(e+1, e+n+1); dp[0][1] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= n; j++)
			dp[i][j] = max(dp[i-1][max(j-e[i].x, 0)+1]+e[i].y, dp[i-1][j]);
	int ans = 0;
	for(int i = 0; i <= n; i++)
		ans = max(ans, dp[n][i]);
	printf("%d\n", ans);
}