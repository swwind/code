#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, a[150], b[30000], tot;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a+i);
	for(int i = 0; i < n-1; i++) for(int j = i+1; j < n; j++)
	if(a[i]!=a[j])b[a[i]+a[j]]++;
	for(int i = 0; i < n; i++) tot += b[a[i]];
	printf("%d", tot);
	return 0;
}

