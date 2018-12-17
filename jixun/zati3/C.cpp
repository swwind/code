#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll ans1, ans2, a[N];
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (ll i = 1, sum = 0; i <= n; i++) {
		sum += a[i];
		if (i & 1) {
			if (sum >= 0)
				ans1 += sum + 1, sum = -1;
		} else {
			if (sum <= 0)
				ans1 += - sum + 1, sum = 1;
		}
	}
	for (ll i = 1, sum = 0; i <= n; i++) {
		sum += a[i];
		if (~i & 1) {
			if (sum >= 0)
				ans2 += sum + 1, sum = -1;
		} else {
			if (sum <= 0)
				ans2 += - sum + 1, sum = 1;
		}
	}
	printf("%lld\n", min(ans1, ans2));
	return 0;
}