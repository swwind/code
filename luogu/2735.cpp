#include <bits/stdc++.h>
using namespace std;
int n, m, p;
int gcd(int a, int b){
	return a%b ? gcd(b, a%b) : b;
}
int main(){
	scanf("%d%d%d", &n, &m, &p);
    printf("%d", (p*m) / 2 - (gcd(n, m) + gcd(abs(p-n), m) + p) / 2 + 1);
	return 0;
}

