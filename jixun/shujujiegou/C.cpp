#include <bits/stdc++.h>
#define N 30020
#define INF (1ll << 60)
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct Sword_Art_Online {
	ll v;
	int id;
	friend bool operator < (const Sword_Art_Online &a, const Sword_Art_Online &b) {
		return a.v < b.v;
	}
}a[N],b[N];
ll w1[N], w2[N], w3[N], f[N];
int ntr[N], posa[N], posb[N];
void calc(int x) {
	w1[x] = w2[x] = w3[x] = -INF;
	ll t1 = -INF, t2 = -INF;
	if (x >= 1 && ntr[x] != x)
		w1[x] = a[x].v * b[x].v;
	if (x >= 2 && ntr[x] != x - 1 && ntr[x - 1] != x)
		w2[x] = a[x].v * b[x - 1].v + a[x - 1].v * b[x].v;
	if (x >= 3 && ntr[x] != x - 2 && ntr[x - 1] != x && ntr[x - 2] != x - 1)
		t1 = a[x].v * b[x - 2].v + a[x - 1].v * b[x].v + a[x - 2].v * b[x - 1].v;
	if (x >= 3 && ntr[x] != x - 1 && ntr[x - 1] != x - 2 && ntr[x - 2] != x)
		t2 = a[x].v * b[x - 1].v + a[x - 1].v * b[x - 2].v + a[x - 2].v * b[x].v;
	w3[x] = max(t1, t2);
}
int main(int argc, char const *argv[]) {
	int n = read(), q = read();
	for (int i = 1; i <= n; i++)
		a[i].v = read(), a[i].id = i;
	for (int i = 1; i <= n; i++)
		b[i].v = read(), b[i].id = i;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++)
		posa[a[i].id] = posb[b[i].id] = i;
	for (int i = 1; i <= n; i++)
		ntr[i] = posb[a[i].id];
	for (int i = 1; i <= n; i++)
		calc(i);
	while (q --) {
		int x = posa[read()], y = posa[read()];
		swap(ntr[x], ntr[y]);
		for (int i = max(1, x - 5); i <= min(n, x + 5); i++) calc(i);
		for (int i = max(1, y - 5); i <= min(n, y + 5); i++) calc(i);
		f[0] = 0;
		for (int i = 1; i <= n; i++) {
			f[i] = f[i - 1] + w1[i];
			if (i >= 2) f[i] = max(f[i], f[i - 2] + w2[i]);
			if (i >= 3) f[i] = max(f[i], f[i - 3] + w3[i]);
		}
		printf("%lld\n", f[n]);
	}
	return 0;
}