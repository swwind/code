#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10050], n, ans;
int main(){
	scanf("%lld", &n);
	for(int i = 0; i < n; i++) scanf("%lld", a+i);
	sort(a, a+n);
	for(int i = 1; i < n; i++)
		ans += (a[i] - a[i-1]) * i * (n - i) * 2;
	printf("%lld", ans);
	return 0;
}

