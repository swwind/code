#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll dp[120][20];
ll f[120][120][20];
ll s1[120], s2[120];
int main(){
	int n = read(), m = read(), k = read();
	if(m == 1){
		for(int i = 1; i <= n; i++)
			s1[i] = s1[i-1]+read();
		for(int i = 1; i <= n; i++)
			for(int k_ = 1; k_ <= k; k_++){
				dp[i][k_] = dp[i-1][k_];
				for(int j = 0; j < i; j++)
					dp[i][k_] = max(dp[i][k_], dp[j][k_-1]+s1[i]-s1[j]);
			}
		printf("%lld\n", dp[n][k]);
	}
	else{
		for(int i = 1; i <= n; i++){
			s1[i] = s1[i-1]+read();
			s2[i] = s2[i-1]+read();
		}
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
		for(int k_ = 1; k_ <= k; k_++){
			f[i][j][k_] = max(f[i-1][j][k_], f[i][j-1][k_]);
			for(int _k = 0; _k < i; _k++)
				f[i][j][k_] = max(f[i][j][k_], f[_k][j][k_-1]+s1[i]-s1[_k]);
			for(int _k = 0; _k < i; _k++)
				f[i][j][k_] = max(f[i][j][k_], f[i][_k][k_-1]+s2[j]-s2[_k]);
			if(i == j) for(int _k = 0; _k < i; _k++)
				f[i][j][k_] = max(f[i][j][k_], f[_k][_k][k_-1]+s1[i]-s1[_k]+s2[j]-s2[_k]);
		}
		printf("%lld\n", f[n][n][k]);
	}
	return 0;
}
