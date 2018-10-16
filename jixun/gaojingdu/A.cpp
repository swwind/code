#include <bits/stdc++.h>
#define ll long long
#define N 10020
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct BigInteger {
	ll a[3000], len;
	#define bit 100000000
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
	BigInteger(int b = 0) {
		len = 1;
		memset(a, 0, sizeof(a));
		a[1] = b;
	}
	BigInteger(const BigInteger &s) {
		len = s.len;
		memcpy(a, s.a, sizeof a);
	}
	void print() {
		printf("%d", a[len]);
		for (int i = len-1; i; i--)
			printf("%08d", a[i]);
		puts("");
	}
}ans(1);
int pri[N], pnt, num[N];
int d[N], n = read(), cnt, flag, sum;
bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}
void work(int x, int s) {
	// printf("%d\n", x);
	int k = 1;
	while (x > 1) {
		// printf("%d\n", pri[k]);
		while (x % pri[k] == 0) {
			num[k] += s;
			x /= pri[k];
		}
		k++;
	}
	// puts("s");
}
void works(int x, int s) {
	for (int i = 2; i <= x; i++)
		work(i, s);
}
int main(int argc, char const *argv[]) {
	for (int i = 2; i <= 1000; i++)
		if (isPrime(i)) pri[++pnt] = i;
	for (int i = 1; i <= n; i++) {
		d[i] = read();
		if (d[i] == 0 || d[i] > n - 1)
			flag = 1;
		if (~d[i]) {
			sum += d[i] - 1;
			cnt ++;
		}
	}
	if (n == 1)
		return puts(d[0] == 0 || d[0] == -1 ? "1" : "0") & 0;
	if (n == 2)
		return puts((d[0] == 1 || d[0] == -1) && d[1] == 1 ? "1" : "0") & 0;
	if (flag)
		return puts("0") & 0;
	works(n - 2, 1);
	works(n - 2 - sum, -1);
	for (int i = 1; i <= n; i++)
		if (~d[i]) works(d[i] - 1, -1);
	for (int i = 1; i <= pnt; i++)
		for (int j = 1; j <= num[i]; j++)
			ans = ans.mul(pri[i]);
	for (int i = 0; i < n - 2 - sum; i++)
		ans = ans.mul(n - cnt);
	ans.print();
	return 0;
}
