#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, x, y, now = (1LL<<60), ans;
int main(){
	scanf("%lld%lld", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%lld%lld", &x, &y);
		now += m;
		now = min(now, x);
		ans += now * y;
	}
	printf("%lld", ans);
	return 0;
}
