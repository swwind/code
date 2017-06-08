#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, k, a[123], s[100011], f[100011];
int main(){
	scanf("%d%d", &k, &n);
	for(int i = 1; i <= k; i++)
		scanf("%d", &a[i]);
	f[0] = 1;
	for(int i = 1; i <= n; i++){
		m = 1LL << 60;
		for(int j = 1; j <= k; j++){
			while(a[j] * f[s[j]] <= f[i-1]) s[j]++;
			m = min(m, a[j] * f[s[j]]);
		}
		f[i] = m;
	}
	printf("%lld\n", f[n]);
	return 0;
}
