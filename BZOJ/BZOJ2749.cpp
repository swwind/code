#include <bits/stdc++.h>
#define ll long long
#define N 100050
using namespace std;
int pri[N], mark[N], T, m, q, p;
ll f[N];
int main(){
	f[1] = 1;
	for(int i = 2; i <= N; i++){
		if(!mark[i]) pri[++pri[0]] = i, f[i] = f[i-1];
		for(int j = 1; pri[j]*i<=N&&j<=pri[0]; j++){
			mark[pri[j]*i] = 1;
			f[pri[j]*i] = f[i] + f[pri[j]];
			if(i%pri[j]==0) break;
		}
	}
	scanf("%d", &T);
	while(T--){
		scanf("%d", &m);
		ll flag = 1, ans = 0;
		while(m--){
			scanf("%d%d", &p, &q);
			if(p==2) flag = 0;
			ans += (ll)q*f[p];
		}
		printf("%lld\n", ans+(ll)flag);
	}
	return 0;
}

