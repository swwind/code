#include <bits/stdc++.h>

using namespace std;

const int oo = 1e8;
int f[10005], n, NaN, ans, t;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &NaN, &t);
		while(scanf("%d", &NaN) && NaN)
			f[i] = max(f[NaN-1], f[i]);
		f[i] += t;
		ans = max(ans, f[i]);
	}
	printf("%d", ans);
}

