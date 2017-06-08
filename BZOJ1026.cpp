#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[15][10], a, b;
int as[20], tot;
ll get(ll x){
	if(!x)return 1;
	memset(as,0,sizeof as);
	while(x)as[++as[0]]=x%10,x/=10;
	as[as[0]+1]=-2333;
	ll ans = 1;
	for(int i = 1; i < as[0]; i++)
		for(int j = 1; j <= 9; j++)
			ans += f[i][j];
	for(int i = 1; i < as[as[0]]; i++)
		ans += f[as[0]][i];
	for(int i = as[0] - 1; i; i--)
		if(abs(as[i+1] - as[i+2]) <= 1) return ans;
		else for(int j = 0; j < as[i]; j++) if(abs(j-as[i+1]) > 1) ans += f[i][j];
	if(abs(as[1] - as[2]) > 1) return ans+1;
	else return ans;
}
int main(){
	scanf("%lld%lld", &a, &b);
	for(int i = 0; i < 10; i++) f[1][i] = 1;
	for(int i = 2; i < 15; i++) for(int j = 0; j < 10; j++) for(int k = 0; k < 10; k++)
	if(abs(j-k) > 1) f[i][j] += f[i-1][k];
	printf("%lld", get(b)-get(a-1));
	return 0;
}

