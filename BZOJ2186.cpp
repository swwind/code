#include <bits/stdc++.h>
#define ll long long
#define N 10000000
using namespace std;
int T, R, x, y, cnt;
int fac[10000005],ine[10000005],pri[500005],ans[10000005];
bool mark[10000005];
int main(){
	scanf("%d%d", &T, &R);
	fac[1] = 1;
	for(int i = 2; i <= N; i++)
		fac[i] = (ll) fac[i-1]*i%R;ine[1] = 1;
	for(int i = 2; i <= N; i++){
		if(!mark[i]) pri[++cnt] = i;
		for(int j = 1; pri[j]*i <= N && j <= cnt; j++){
			mark[pri[j]*i] = 1;
			if(i%pri[j]==0) break;
		}
	}
	for(int i = 2; i <= N && i < R; i++)
		ine[i] = (R-(ll)R/i*ine[R%i]%R);
		ans[1] = 1;
	for(int i = 2; i <= N; i++){
		ans[i] = ans[i-1];
		if(!mark[i]) ans[i] = (ll)ans[i]*(i-1)%R*ine[i%R]%R;
	}
	while(T--){
		scanf("%d%d", &x, &y);
		printf("%d\n", (ll)fac[x]*ans[y]%R);
	}
	return 0;
}

