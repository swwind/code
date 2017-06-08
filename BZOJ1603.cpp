#include <bits/stdc++.h>
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define ll long long
using namespace std;
int n, x, y, z, ans;
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d%d%d", &x, &y, &z);
		if(z) ans++;
	}
	printf("%d", ans&1);
	return 0;
}

