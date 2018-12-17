// 卡特兰数第 n 项（对 p 取模
// C_n(mod p)
// Cn = (2n \choose n) / (n + 1)

#include <bits/stdc++.h>
#define ll long long
#define N (n<<1)
using namespace std;
ll ans = 1;
int n, p;
int pri[1000500], mn[2000500], num[2000500];
bool mark[2000500];
void add(int x, int val){
	while(x!=1){
		num[mn[x]] += val;
		x /= pri[mn[x]];
	}
}
int main(){
	scanf("%d%d", &n, &p);
	for(int i = 2; i <= N; i++){
		if(!mark[i]) pri[++pri[0]] = i, mn[i] = pri[0];
		for(int j = 1; pri[j]*i<=N&&j<=pri[0]; j++){
			mark[pri[j]*i] = 1;
			mn[pri[j]*i] = j;
			if(i%pri[j]==0) break;
		}
	}
	for(int i = N; i > n; i--) add(i, 1);
	for(int i = 1; i <= n+1; i++) add(i, -1);
	for(int i = 1; i <= pri[0]; i++)
		while(num[i]--) (ans*=pri[i])%=p;
	printf("%lld\n", ans);
	return 0;
}
