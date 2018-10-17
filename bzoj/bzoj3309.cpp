#include <bits/stdc++.h>
#define N 10000020
#define ll long long
using namespace std;
ll _a[N], _p[N], _g[N];
int pri[N], cnt;
bool mark[N];
ll calc(ll a, ll b){
	if(a > b) swap(a, b);
	ll ans = 0;
	for(int i = 1, last; i <= a; i = last+1){
		last = min(a/(a/i), b/(b/i));
		ans += (a/i)*(b/i)*(_g[last]-_g[i-1]);
	}
	return ans;
}
int main(){
	for(int i = 2; i < N; i++){
		if(!mark[i]){pri[++cnt] = _p[i] = i; _a[i] = _g[i] = 1;}
		for(int j = 1; j <= cnt && pri[j]*i < N; j++){
			mark[pri[j]*i] = 1;
			if(i%pri[j]==0){
				_a[pri[j]*i] = _a[i]+1;
				_p[pri[j]*i] = _p[i]*pri[j];
				ll tmp = i/_p[i];
				if(tmp == 1) _g[pri[j]*i] = 1;
				else _g[pri[j]*i] = (_a[tmp]==_a[pri[j]*i]?-_g[tmp]:0);
				break;
			}
			_a[pri[j]*i] = 1;
			_p[pri[j]*i] = pri[j];
			_g[pri[j]*i] = (_a[i]==1?-_g[i]:0);
		}
	}
	for(int i = 1; i < N; i++)
		_g[i] += _g[i-1];
	int T; scanf("%d", &T);
	while(T--){
		ll a, b;
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", calc(a, b));
	}
}