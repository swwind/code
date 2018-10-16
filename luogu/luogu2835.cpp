#include <bits/stdc++.h>
using namespace  std;
int a[10020];
int main(){
	int n, x, ans = 0;
	scanf("%d", &n);
	while(scanf("%d", &x)!=EOF)a[x]=1;
	for(int i = 1; i <= n; i++)
		ans += !a[i];
	printf("%d\n", ans?ans:1);
}