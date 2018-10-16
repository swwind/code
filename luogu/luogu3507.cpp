#include <bits/stdc++.h>
using namespace std;
long long a[1000020], n, ans;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", a+i);
	sort(a+1, a+n+1);
	ans = a[1];
	for(int i = 2; i <= n; i++)
		ans = max(ans, a[i]-ans);
	printf("%lld\n", ans);
}