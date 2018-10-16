#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll pow(ll x, ll y, ll p) {
	ll res = 1;
	for (; y; y >>= 1, x = x * x % p)
		if (y & 1) res = res * x % p;
	return res;
}
void exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) x = 1, y = 0;
	else exgcd(b, a % b, y, x), y -= a / b * x;
}
ll inv(ll a, ll p, ll x = 0, ll y = 0) {
	exgcd(a, p, x, y);
	x = (x % p + p) % p;
	return x ? x : p;
}
ll calc(ll a, ll b, ll p) {
	if (!a) return 1;
	ll res = 1;
	for (ll i = 2; i <= p; i++)
		if (i % b) res = res * i % p;
	res = pow(res, a / p, p);
	for (ll i = 2; i <= a % p; i++)
		if (i % b) res = res * i % p;
	return res * calc(a / b, b, p) % p;
}
ll c(ll n, ll m, ll md, ll ps, ll p) {
	if (m > n) return 0;
	ll a = calc(n, ps, p), b = calc(m, ps, p), c = calc(n - m, ps, p);
	ll k = 0;
	for (ll i = n; i; i /= ps) k += i / ps;
	for (ll i = m; i; i /= ps) k -= i / ps;
	for (ll i = n - m; i; i /= ps) k -= i / ps;
	ll ans = a * inv(b, p) % p * inv(c, p) % p * pow(ps, k, p) % p;
	return ans * (md / p) % md * inv(md / p, p) % md;
}
ll exLucas(ll n, ll m, ll p) {
	ll res = 0, x = p;
	for (ll i = 2; i * i <= p; i++) {
		if (x % i == 0) {
			ll ps = 1;
			while (x % i == 0) ps *= i, x /= i;
			res = (res + c(n, m, p, i, ps)) % p;
		}
	}
	if (x > 1) res = (res + c(n, m, p, x, x)) % p;
	return res;
}
int main(int argc, char const *argv[]) {
	ll p = read(), n = read(), m = read(), w[10], sum = 0, res = 1;
	for (int i = 1; i <= m; i++)
		sum += w[i] = read();
	if (sum > n) return puts("Impossible") & 0;
	for (ll i = 1, lst = n; i <= m; i++)
		res = res * exLucas(lst, w[i], p) % p, lst -= w[i];
	printf("%lld\n", res);
	return 0;
}