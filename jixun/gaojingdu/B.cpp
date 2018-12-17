#include <bits/stdc++.h>
#define ll long long
using namespace std;

char str[30020];
struct BigInteger {
	ll a[3000], len;
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
	BigInteger del(int b = 1) {
		BigInteger c(*this);
		c.a[1] -= b;
		int k = 1;
		while (k < c.len && c.a[k] < 0) {
			c.a[k] += bit;
			c.a[++ k] --;
		}
		if (c.len > 1 && !c.a[c.len])
			c.len --;
		return c;
	}
	BigInteger mul(BigInteger b) {
		BigInteger c;
		for (int i = 1; i <= len; i++)
			for (int j = 1; j <= b.len; j++)
				c.a[i + j - 1] += a[i] * b.a[j];
		c.len = len + b.len;
		for (int i = 1; i < c.len; i++) {
			c.a[i + 1] += c.a[i] / bit;
			c.a[i] %= bit;
		}
		while (c.len > 1 && !c.a[c.len])
			c.len --;
		return c;
	}
	friend bool operator < (const BigInteger &a, const BigInteger &b) {
		if (a.len < b.len) return true;
		if (b.len < a.len) return false;
		for (int i = a.len; i; i--) {
			if (a.a[i] < b.a[i]) return true;
			if (b.a[i] < a.a[i]) return false;
		}
		return false;
	}
	friend bool operator == (const BigInteger &a, const BigInteger &b) {
		if (a.len != b.len) return false;
		for (int i = a.len; i; i--)
			if (a.a[i] != b.a[i]) return false;
		return true;
	}
	friend bool operator <= (const BigInteger &a, const BigInteger &b) {
		return a < b || a == b;
	}
	BigInteger div(int b = 2) {
		BigInteger c(*this);
		ll last = 0;
		for (int i = len; i; i--) {
			last = last * bit + a[i];
			c.a[i] = last / b;
			last %= b;
		}
		if (!c.a[c.len])c.len--;
		return c;
	}
	BigInteger(int b = 0) {
		len = 1;
		memset(a, 0, sizeof(a));
		a[1] = b;
	}
	BigInteger(const BigInteger &s) {
		len = s.len;
		memcpy(a, s.a, sizeof a);
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
};
BigInteger pows(BigInteger a, int b) {
	BigInteger c(1);
	for (int i = 1; i <= b; i++)
		c = c.mul(a);
	// printf("mid ^ %d = \n", b);
	// c.print();
	return c;
}
int main(int argc, char const *argv[]) {
	int a;
	cin >> a;
	BigInteger b;
	b.read();
	// printf("%d\n", a);
	BigInteger l(0), r(1);
	while (pows(r, a) <= b) {
		l = r;
		r = r.mul(2);
	}
	while (l < r) {
		BigInteger mid = l.add(r).div();
		if (pows(mid, a) <= b) l = mid.add(1);
		else r = mid;
	}
	l.del(1).print();
	return 0;
}
