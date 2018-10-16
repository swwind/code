#include <bits/stdc++.h>
#define N 10020
#define ll long long
using namespace std;
const int inf = 0x3f3f3f3f;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int f[10020][N], x[N], y[N], b[N], t[N];
int main(int argc, char const *argv[]){
	int n = read(), m = read(), k = read();
	for(int i = 0; i < n; i++)
		x[i] = read(), y[i] = read();
	for(int i = 0; i <= n; i++) t[i] = m+1;
	for(int i = 1; i <= k; i++){
		int x = read();
		b[x] = read();
		t[x] = read();
	}
	int now = 0, pre = 1;
	memset(f, 63, sizeof(int)*N*10020);
	for(int i = 1; i <= m; i++) f[0][i] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int u = j-x[i-1];
			if(u > b[i-1] && u < t[i-1]) f[i][j] = min(f[i-1][u]+1, f[i][j]);
			if(u > 0) f[i][j] = min(f[i][u]+1, f[i][j]);
		}
		for(int j = m; j >= m-x[i-1] && j >= 1; j--){
			f[i][m] = min(f[i][m], f[i][j]+1);
			if(j > b[i-1] && j < t[i-1])
				f[i][m] = min(f[i-1][j]+1, f[i][m]);
		}
		for(int j = b[i]+1; j < t[i]; j++){
			int u = j+y[i-1];
			if(u > b[i-1] && u < t[i-1])
				f[i][j] = min(f[i-1][u], f[i][j]);
		}
	}
	int ans = inf;
	for(int i = b[n]+1; i < t[n]; i++) ans = min(ans, f[n][i]);
	if(ans < inf) return printf("1\n%d\n", ans)&0;
	for(int i = n-1, res = k; i >= 0; --i) if(t[i] <= m && res--)
		for(int j = b[i]+1; j < t[i]; j++) if(f[i][j]<0x3f3f3f3f)
			return printf("0\n%d\n", res+1)&0;
	printf("0\n0\n");
}