#include <bits/stdc++.h>
#define INF 100000000

using namespace std;

struct fuck{
	int a, b;
	double val;
	bool operator < (const fuck f) const {
		return val < f.val;
	}
}a[20000];
int tot, n;

int gcd(int a, int b){
	if(a == 0) return b;
	else return a%b ? gcd(b, a%b) : b;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i <= n; i++) for(int j = i; j <= n; j++)
		if(gcd(i, j) == 1) a[tot].a = i, a[tot].b = j, a[tot++].val = (double)i / (double)j;
	sort(a, a+tot);
	for(int i = 0; i < tot; i++) printf("%d/%d\n", a[i].a, a[i].b);
	return 0;
}

