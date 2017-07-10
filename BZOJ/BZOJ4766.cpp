#include <bits/stdc++.h>
#include <com1>
using namespace std;
long long n, m, p;
long long mul(long long x, long long y){
	long long ans = 0;
	while(y){
		if(y&1) ans = (ans+x)%p;
		x = (x<<1)%p; y >>= 1;
	}
	return ans;
}
long long f(long long x, long long y){
	long long ans = 1;
	while(y){
		if(y&1) ans = mul(ans, x);
		x = mul(x, x); y >>= 1;
	}
	return ans;
}
int main(){
	cin >> n >> m >> p;
	cout << mul(f(n, m-1), f(m, n-1)) << endl;
}
