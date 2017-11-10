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
int c[N], b[N], bnt, ant, a[N], ans[N], blo[N];
struct misaka {
	int p, k, id, mul;
	friend bool operator < (const misaka &a, const misaka &b) {
		return a.p < b.p;
	}
}ask[N<<1];
int r[N];
void add(int x) {
	for (;x;x^=x&-x)
		r[x] ++;
}
int asks(int x) {
	int res = 0;
	for (;x<N;x+=x&-x)
		res += r[x];
	return res;
}
int main(int argc, char const *argv[]) {
	int T = read();
	while (T --) {
		int n = read(), q = read();
		bnt = ant = 0;
		memset(r, 0, sizeof r);
		for (int i = 1; i <= n; i++) {
			int x = read();
			if (x != b[bnt]) b[++bnt] = x, c[bnt] = 1;
			else c[bnt] ++;
			blo[i] = bnt;
		}
		// printf("bnt : %d\n", bnt);
		// for (int i = 1; i <= bnt; i++)
		// 	printf("%d ", c[i]); puts("");
		for (int i = 1; i <= bnt; i++)
			a[i] = a[i - 1] + c[i];
		for (int i = 1; i <= q; i++) {
			int l = read(), r = read(), k = read();
			int bl = blo[l], br = blo[r];
			// printf("BLOCK: %d %d\n", bl, br);
			if (bl == br) ans[i] = (r - l + 1) >= k;
			else {
				ans[i] = !!(a[bl] - l + 1 >= k) + !!(r - a[br - 1] >= k);
				ask[++ant] = (misaka){bl, k, i, -1};
				ask[++ant] = (misaka){br - 1, k, i, 1};
			}
		}
		sort(ask + 1, ask + ant + 1);
		int pos = 1;
		for (int i = 1; i <= ant; i++) {
			while (pos <= bnt && pos <= ask[i].p)
				add(c[pos ++]);
			int k = asks(ask[i].k);
			// printf("ask :: %d %d %d * %d\n", ask[i].id, ask[i].p, k, ask[i].mul);
			ans[ask[i].id] += k * ask[i].mul;
		}
		for (int i = 1; i <= q; i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}