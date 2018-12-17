#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int n, m, n2;
struct mat{
	ll num[33][33];
	void clear(){memset(num, 0, sizeof num);}
	mat(){clear();}
	mat(bool flag){clear();for(int i = 0; i < n2; i++)num[i][i]=1;}
}mp;
mat operator *(const mat &a, const mat &b){
	mat c;
	for(int k = 0; k < n2; k++)
		for(int i = 0; i < n2; i++) if(a.num[i][k])
			for(int j = 0; j < n2; j++) if(b.num[k][j])
				c.num[i][j] = (c.num[i][j]+a.num[i][k]*b.num[k][j])%mod;
	return c;
}
mat operator ^(mat a, int b){
	mat c(true);
	for(;b;b/=2,a=a*a)if(b&1)c=c*a;
	return c;
}
void dfs(int dep, int pre, int now){
	if(dep > n) return;
	if(dep == n){
		mp.num[pre][now]++;
		return;
	}
	dfs(dep+1, pre<<1|1, now<<1);
	dfs(dep+1, pre<<1, now<<1|1);
	dfs(dep+2, pre<<2, now<<2);
}
int main(){
	scanf("%d%d", &m, &n);
	n2 = 1 << n;
	dfs(0, 0, 0);
	mp = mp^(m+1);
	printf("%lld\n", mp.num[0][n2-1]);
	return 0;
}