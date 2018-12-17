#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	int n, m, x, y;
	while(~scanf("%d%d%d%d", &n, &m, &x, &y)){
		if(n > m) swap(n, m), swap(x, y);
		if(n == 1) {puts("1"); continue;}
		int ans1 = min(x-1, min(y, m-y+1));
		int ans2 = min(n-x, min(y, m-y+1));
		int ans = n+1>>1;
		if(n == m && (n&1) && x == ans && y == ans) ans--;
		printf("%d\n", max(ans, max(ans1, ans2)));
	}
	return 0;
}