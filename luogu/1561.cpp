#include <bits/stdc++.h>
using namespace std;
int n, a, b, suma, sumb, mina=(1<<30), minb=(1<<30);
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &a, &b);
		mina = min(a, mina);
		minb = min(b, minb);
		suma += a;
		sumb += b;
	}
	printf("%d\n", max(suma+minb, sumb+mina));
}