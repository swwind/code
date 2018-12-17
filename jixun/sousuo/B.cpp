#include <bits/stdc++.h>
#define N 1000020
#define ll long long
#define mod 100000007
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll bin[N];
struct node {
	ll sz, num0, num1;
	int ls, rs, tg;
	void reset() {
		ls = rs = -1;
		num1 = tg = 0;
		sz = num0 = 1;
	}
	void update(int x) {
		tg += x;
		sz = (sz + 2 * (bin[x] - 1) * num0 + (bin[x] - 1) * num1) % mod;
		sz = (sz + mod) % mod;
		num0 = (num1 * bin[x - 1] + num0 * bin[x]) % mod;
		num1 = 0;
	}
}tr[N*2];
string str;
int cnt;
void pushdown(node &rt) {
	if (!rt.tg)
		return;
	if (rt.ls == -1) {
		tr[rt.ls = cnt++].reset();
		if (rt.tg > 1)
			tr[rt.ls].update(rt.tg - 1);
	} else {
		tr[rt.ls].update(rt.tg);
	}
	if (rt.rs == -1) {
		tr[rt.rs = cnt++].reset();
		if (rt.tg > 1)
			tr[rt.rs].update(rt.tg - 1);
	} else {
		tr[rt.rs].update(rt.tg);
	}
	rt.tg = 0;
}
void update(node &rt, int x) {
	pushdown(rt);
	if (x+1 == str.length())
		if (str[x] == 'L') rt.ls = -1;
		else rt.rs = -1;
	else
		if (str[x] == 'L') update(tr[rt.ls], x+1);
		else update(tr[rt.rs], x+1);
	rt.sz = 1;
	rt.num0 = rt.num1 = 0;
	if (rt.ls == -1)
		++rt.num1;
	else {
		rt.sz += tr[rt.ls].sz;
		rt.num0 += tr[rt.ls].num0;
		rt.num1 += tr[rt.ls].num1;
	}
	if (rt.rs == -1)
		++rt.num1;
	else {
		rt.sz += tr[rt.rs].sz;
		rt.num0 += tr[rt.rs].num0;
		rt.num1 += tr[rt.rs].num1;
	}
	if (rt.ls == -1 && rt.rs == -1)
		rt.num0 = 1, rt.num1 = 0;
	rt.sz = rt.sz%mod;
	rt.num0 = rt.num0%mod;
	rt.num1 = rt.num1%mod;
}
int main(int argc, char const *argv[]) {
	bin[0] = 1;
	for (int i = 1; i <= 1000000; i++)
		bin[i] = bin[i-1]*2%mod;
	for (int t = read(); t; t--, cnt = 0) {
		tr[cnt++].reset();
		for (int q = read(); q; q--) {
			if (read() == 1) {
				tr[0].update(read());
			} else {
				cin >> str;
				update(tr[0], 0);
			}
			printf("%lld\n", tr[0].sz);
		}
	}
	return 0;
}