#include <bits/stdc++.h>
#define N 10000020
#define ll long long
using namespace std;
int pri[670000], mu[N], cnt, f[N];
bool mark[N];
ll n, m, ans;
int main(){
	scanf("%d", &n); m=n;
	mu[1] = 1;
	for(int i = 2; i <= n; i++){
		if(!mark[i])pri[++cnt]=i,mu[i]=-1;
		for(int j = 1; j <= cnt && pri[j]*i <= n; j++){
			mark[pri[j]*i] = 1;
			if(i%pri[j])mu[pri[j]*i] = -mu[i];
			else{mu[pri[j]*i] = 0; break;}
		}
	}
	for(int i = 1; i <= cnt; i++)
		for(int j = 1; j*pri[i] <= n; j++)
			f[pri[i]*j] += mu[j];
	for(int i = 1; i <= n; i++)
		f[i] += f[i-1];
	ans = 0;
	if(n > m) swap(n, m);
	for(ll i = 1, last; i <= n; i = last+1){
		last = min(n/(n/i), m/(m/i));
		ans += (n/i)*(m/i)*(f[last]-f[i-1]);
	}
	printf("%lld\n", ans);
}