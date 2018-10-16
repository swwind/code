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
map<ll, bool> mp;
ll a[N], flag;
int main(int argc, char const *argv[]) {
	int k = read(), n = read();
	for (int i = 1; i <= n; i++)
		mp[a[i] = read()] = 1;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (mp[k - a[i]] && a[i] < k - a[i]) {
			flag = 1;
			printf("%lld %lld\n", a[i], k - a[i]);
		}
	}
	if (!flag) puts("No Solution");
	return 0;
}