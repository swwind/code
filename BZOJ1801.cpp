#include <bits/stdc++.h>
#define ll long long
#define N 105
#define MOD 9999973
using namespace std;
ll n, m, f[N][N][N];
int main(){
	f[0][0][0] = 1;
	scanf("%lld%lld", &n, &m);
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j <= m; j++){
			for(ll k = 0; k <= m - j; k++){
				f[i][j][k] = f[i-1][j][k];
				if(j) (f[i][j][k] += f[i-1][j-1][k]*(m-j+1-k)) %= MOD;
				if(k && j < m) (f[i][j][k] += f[i-1][j+1][k-1]*(j+1)) %= MOD;
				if(j >= 2) (f[i][j][k] += f[i-1][j-2][k]*(m-j+2-k)*(m-j+1-k)/2) %= MOD;
				if(k >= 2 && j + 1 < m) (f[i][j][k] += f[i-1][j+2][k-2]*(j+2)*(j+1ll)/2) %= MOD;
				if(j && k) (f[i][j][k] += f[i-1][j][k-1]*j*(m-j-k+1)) %= MOD;
				if(i == n) (ans += f[i][j][k]) %= MOD;
			}
		}
	}
	return printf("%lld\n", ans)*0;
} 
