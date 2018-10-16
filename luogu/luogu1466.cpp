#include <bits/stdc++.h>
#define ll long long
int n, s;
ll f[400];
int main(){
	scanf("%d",&n);
	s = n * (n + 1) / 2;
	if(s&1)
		return puts("0"), 0;
	s /= 2;
	f[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = s; j >= i; j--)
			f[j] += f[j-i];
	printf("%lld\n", f[s] / 2);
	return 0;
}

