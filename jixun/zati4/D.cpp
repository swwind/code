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
int a[10];
bool check(ll x) {
	int b[10];
	memset(b, 0, sizeof b);
	while (x) b[x%10]++, x/=10;
	for (int i = 0; i < 10; i++)
		if (a[i] == b[i]) return false;
	return true;
}
int main(int argc, char const *argv[]) {
	int T = read();
	while (T --) {
		ll l = read(), r = read();
		int ans = 0;
		for (int i = 0; i < 10; i++)
			a[i] = read();
		for (ll i = l; i <= r; i++)
			ans += check(i);
		printf("%d\n", ans);
	}
	return 0;
}