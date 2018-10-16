#include <bits/stdc++.h>
#define ll long long
using namespace std;
char str[1020];
struct BigInteger {
	ll a[100], len;
	#define bit 100000000
	BigInteger add(BigInteger b) {
		BigInteger c;
		c.len = max(len, b.len);
		for (int i = 1; i <= c.len; i++)
			c.a[i] = a[i] + b.a[i];
		for (int i = 1; i <= c.len; i++) {
			if (c.a[i] >= bit) {
				c.a[i + 1] ++;
				c.a[i] -= bit;
			}
		}
		if (c.a[c.len + 1]) c.len++;
		return c;
	}
	bool odd() {
		return a[1]&1;
	}
	BigInteger(int b = 0) {
		len = 1;
		memset(a, 0, sizeof(a));
		a[1] = b;
	}
	void read() {
		scanf("%s", str + 1);
		int kkk = strlen(str + 1);
		len = (strlen(str + 1) - 1) / 8 + 1;
		for (int i = 1, j = len; i <= kkk; i++) {
			a[j] = a[j] * 10 + str[i] - '0';
			if ((kkk - i) % 8 == 0)
				j--;
		}
	}
	void print() {
		printf("%d", a[len]);
		for (int i = len-1; i; i--)
			printf("%08d", a[i]);
		puts("");
	}
	BigInteger div(int b = 2) {
		BigInteger c(*this);
		int d = 0;
		for (int i = c.len; i; i--) {
			if (d) c.a[i] += bit;
			d = c.a[i] & 1;
			c.a[i] >>= 1;
		}
		if (!c.a[c.len]) c.len--;
		return c;
	}
}a;
#define pbb pair<BigInteger, BigInteger>
pbb f(BigInteger x) {
	// x.print();
	if (x.len == 1 && x.a[1] == 1)
		return make_pair(x, 0);
	pbb res = f(x.add(1).div());
	if (x.odd()) return make_pair(res.first.add(res.second), res.second);
	else return make_pair(res.first, res.first.add(res.second));
}
int main(int argc, char const *argv[]) {
	int T; cin >> T;
	while (T--) {
		BigInteger x; x.read();
		f(x).first.print();
	}
	return 0;
}