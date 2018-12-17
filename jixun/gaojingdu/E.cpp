#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
const int mx = 1 << 25, N = mx | 50;
bool tr[N << 1], v1[N], v2[N];
int add(bool *v, int x) {
	while (v[x]) v[x ++] = 0;
	v[x] = 1;
	return x;
}
int pre(int x) {
	for (x += mx; x; x >>= 1) {
		if (x & 1 & tr[x ^ 1]) {
			for (x ^= 1; x < mx; x = x << 1 ^ tr[x << 1 ^ 1]);
			return x - mx;
		}
	}
	return -1;
}
int main(int argc, char const *argv[]) {
	int n = read(); read(); read(); read();
	while (n --) {
		if (read() == 1) {
			int a = read(), b = read();
			if (a) {
				int l = b, r = b;
				if (a > 0) {
					for (int i = 0; i <= 30; i++)
						if (a >> i & 1)
							r = max(add(v1, b + i), r);
				} else {
					a = -a;
					for (int i = 0; i <= 30; i++)
						if (a >> i & 1)
							r = max(add(v2, b + i), r);
				}
				for (int i = l; i <= r; i++)
					tr[i + mx] = v1[i] ^ v2[i];
				for (l = l + mx >> 1, r = r + mx >> 1; l; l >>= 1, r >>= 1)
					for (int i = l; i <= r; i++)
						tr[i] = tr[i << 1] | tr[i << 1 | 1];
			}
		} else {
			int x = read(), p = pre(x);
			puts(tr[x + mx] ^ (~p && v1[p] < v2[p]) ? "1" : "0");
		}
	}
	return 0;
}