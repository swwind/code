#include <bits/stdc++.h>
#define MOD 100003
#define ll long long
using namespace std;
ll x;
int fuck(ll x){
	int ans = 0;
	while(x > (1LL << ans)) ans++;
	return ans;
}
int main(){
	scanf("%lld", &x);
	printf("%d", fuck(x));
	return 0;
}
