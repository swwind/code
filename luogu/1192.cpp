#include <bits/stdc++.h>
using namespace std;
int n, k, f[100020];
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; i++) f[i] = 1;
	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= k && i-j > 0; j++)
			(f[i] += f[i-j]) %= 100003;
	printf("%d\n", f[n]);
}