#include <bits/stdc++.h>
using namespace std;
int a[100], n, x, k, ans;
int main(){
	for(int i = 1; i < 100; i++)
		a[i] = a[i-1]+i;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++,k=0){
		scanf("%d", &x);
		while(x>=a[k])k++;
		ans ^= k-1;
	}
	puts(ans?"NO":"YES");
}
