#include <bits/stdc++.h>
#define ll long long
#define N 10000000
using namespace std;
int fac[N], ine[N], pri[N], ans[N];
bool mark[N]; int T, r, n, m;
void exgcd(int a, int b, int &x, int &y){
	if(!b){x=1;y=0;return;}
	exgcd(b, a%b, x, y);
	int t = x; x = y; y = t-a/b*y;
}
int getIne(int x){
	int a, b;
	exgcd(x, r, a, b);
	return (a%r+r)%r;
}
int main(){
	scanf("%d%d", &T, &r);
	fac[1] = ine[1] = ans[1] = 1;
	for(int i = 2; i <= N; i++)
		fac[i] = (ll)fac[i-1]*i%r;
	for(int i = 2; i <= N; i++){
		if(!mark[i])
			pri[++pri[0]] = i,
			ine[i] = getIne(i);
		for(int j = 1; pri[j]*i<=N && j<=pri[0]; j++){
			mark[pri[j]*i] = 1;
			if(i%pri[j] == 0) break;
		}
	}
	for(int i = 2; i <= N; i++){
		ans[i] = ans[i-1];
		if(!mark[i]) ans[i] = (ll)ans[i]*(i-1)%r*ine[i]%r;
	}
	while(T--){
		scanf("%d%d", &n, &m);
		printf("%d\n", (ll)fac[n]*ans[m]%r);
	}
	return 0;
}

