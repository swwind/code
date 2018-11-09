#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000050], n;
int main(){
	scanf("%lld", &n);
	a[1] = 1;
	for(int i = 2; i <= n; i++)
		(a[i] = (i&1) ? a[i-1] : (a[i-1] + a[i>>1])) %= 1000000000;
	printf("%d", a[n]);
	return 0;
}

