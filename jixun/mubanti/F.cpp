#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll pw[30];
ll calc(ll x, int i) {
	ll n = 0, tmp = 1, res = 0, b = 0, xx = x;
	while (x) {
		int d = x % 10;
		x /= 10; ++ n;
		if (d > i) res += tmp + d * pw[n - 1];
		else if (d == i) res += b + 1 + d * pw[n - 1];
		else res += d * pw[n - 1];
		b += d * tmp;
		tmp *= 10;
	}
	if (!i) {
		ll tmp = 1;
		while (xx) {
			res -= tmp;
			tmp *= 10;
			xx /= 10;
		}
	}
	return res;
}
int main(int argc, char const *argv[]) {
	for (int i = 1; i < 20; i++) pw[i] = i * pow(10, i - 1);
	ll x = read(), y = read();
	for (int i = 0; i < 10; i++)
		cout << calc(y, i) - calc(x - 1, i) << endl;
	return 0;
}
