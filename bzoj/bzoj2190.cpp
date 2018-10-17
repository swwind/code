#include <bits/stdc++.h>
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define ll long long
#define N 50000
using namespace std;
int prime[N/3], phi[N];
bool flag[N];
void get_prime(){
	int k = 0;
	for(int i = 2; i < N; i++){
		if(!flag[i])
			prime[k++] = i,
			phi[i] = i-1;
		for(int j = 0; j < k && i * prime[j] < N; j++){
			flag[i*prime[j]] = 1;
			if(!(i%prime[j])){
				phi[i*prime[j]] = phi[i]*prime[j]; break;
			}
			else
				phi[i*prime[j]] = phi[i]*(prime[j]-1);
		}
	}
}
int main(){
	get_prime();int n,ans=0;
	scanf("%d", &n);
	for(int i = 2; i < n; i++) ans += phi[i];
	printf("%d", (ans+2)*2-1);
	return 0;
}

