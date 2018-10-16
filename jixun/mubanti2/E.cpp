#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll a[N], sum, ans = 1ll << 60;
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		sum += a[i] = read();
	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];
		ans = min(ans, abs(a[i] * 2 - sum));
	}
	cout << ans << endl;
	return 0;
}
