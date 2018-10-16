#include <bits/stdc++.h>

#define ll unsigned long long

ll n;
int a[10], b[10];

int dec(int &k){
	return k = (k - 2 + a[0]) % a[0] + 1;
}

int f(ll val){
	//printf("\n%u :\n", val);
	a[0] = 0;
	memset(b, 0, sizeof b);
	while(val) a[++a[0]] = val % 10, val /= 10;
	for(int i = 1; i <= a[0]; i++) if(b[a[i]] || !a[i]) return 0; else b[a[i]]++;
	int k = a[0];
	while(b[a[k]]++ != 2){
		//printf("%d ", a[k]);
		int s = a[k];
		for(int i = 0; i < s; i++) dec(k)/*, printf("%d ", a[k])*/;
		//printf(" -> %d\n", a[k]);
	}
	if(k != a[0]) return 0;
	for(int i = 1; i < 10; i++) if(b[i] == 1) return 0;
	return 1;
}

int main(){
	scanf("%u", &n);
//	printf("%d", f(81362));
	while(++n)
		if(f(n)) return printf("%u", n), 0;
	return 0;
}

