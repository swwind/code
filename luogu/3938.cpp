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
ll a[N], cnt;
ll get_father(ll x) {
	ll s = * (upper_bound(a + 1, a + cnt + 1, x - 1) - 1);
	return x - s;
}
std::vector<ll> va, vb;
int main(int argc, char const *argv[]) {
	a[cnt = 1] = 1;
	while (a[cnt ++] <= 1e12)
		a[cnt] = a[cnt - 2] + a[cnt - 1];
	cnt --;
	int T = read();
	// for (int i = 1; i <= 13; i++)
	// 	printf("(%d) => %d\n", i, get_father(i));
	while (T --) {
		ll a = read();
		va.clear();
		va.push_back(a);
		while (a != 1)
			va.push_back(a = get_father(a));
		reverse(va.begin(), va.end());

		// for (auto s : va)
		// 	printf("[%d]", s);
		// puts("");

		ll b = read();
		vb.clear();
		vb.push_back(b);
		while (b != 1)
			vb.push_back(b = get_father(b));
		reverse(vb.begin(), vb.end());

		// for (auto s : vb)
		// 	printf("[%d]", s);
		// puts("");

		int s = min(va.size(), vb.size()), flag = 0;
		for (int i = 0; i < s; i++) {
			if (va[i] != vb[i]) {
				cout << va[i - 1] << endl;
				flag = 1;
				break;
			}
		}
		if (flag) continue;
		cout << va[s - 1] << endl;
	}
	return 0;
}
