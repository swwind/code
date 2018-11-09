#include <bits/stdc++.h>
#define N 1505
#define ll long long
using namespace std;
inline int read(){
	int x; scanf("%d", &x); return x;
	// int x=0,f=0;char ch=getchar();
	// while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	// while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	// return f?-x:x;
}
int sum[N][N], tr[N][N], a[N][N], b[N][N], c[N][N], d[N][N], h[N], l[N], ans;
int max(int a, int b, int c){return max(max(a, b), c);}
int main(){
	int n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			sum[i][j] = read()+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
	for(int i = k; i <= n; i++)
		for(int j = k; j <= m; j++){
			tr[i][j] = sum[i][j]-sum[i][j-k]-sum[i-k][j]+sum[i-k][j-k];
			h[i] = max(h[i], tr[i][j]); l[j] = max(l[j], tr[i][j]);
		}
	for(int i = k; i <= n; i++)
		for(int j = k; j <= m; j++)
			a[i][j] = max(a[i-1][j], a[i][j-1], tr[i][j]);
	for(int i = k; i <= n; i++)
		for(int j = m-k+1; j; j--)
			b[i][j] = max(b[i-1][j], b[i][j+1], tr[i][j+k-1]);
	for(int i = n-k+1; i; i--)
		for(int j = k; j <= m; j++)
			c[i][j] = max(c[i+1][j], c[i][j-1], tr[i+k-1][j]);
	for(int i = n-k+1; i; i--)
		for(int j = m-k+1; j; j--)
			d[i][j] = max(d[i+1][j], d[i][j+1], tr[i+k-1][j+k-1]);
	for(int i = k; i <= n-k; i++)
		for(int j = k; j <= m-k; j++){
			ans = max(ans, a[i][m]+c[i+1][j]+d[i+1][j+1]);
			ans = max(ans, c[i+1][m]+b[i][j+1]+a[i][j]);
			ans = max(ans, a[n][j]+b[i][j+1]+d[i+1][j+1]);
			ans = max(ans, b[n][j+1]+a[i][j]+c[i+1][j]);
		}
	for(int i = k; i <= n-k*2; i++)
		for(int j = i+k; j <= n-k; j++)
			ans = max(ans, b[i][1]+h[j]+d[j+1][1]);
	for(int i = k; i <= m-k*2; i++)
		for(int j = i+k; j <= m-k; j++)
			ans = max(ans, c[1][i]+l[j]+d[1][j+1]);
	printf("%d\n", ans);
	return 0;
}
//卧槽，垃圾题目降我AC率