#include <bits/stdc++.h>
#define N 300020
#define ll long long
#define mod 1000000007
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll a[N], bin[N], b[N];
int main(int argc, char const *argv[]) {
	int n = read(); bin[0] = 1;
	for (int i = 1; i <= n; i++)
		bin[i] = bin[i-1]*2%mod;
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++)
		b[i] = (b[i-1]+a[i])%mod;
	ll ans = 0;
	// printf("%lld %lld\n", b[1], b[2]);
	for (int i = 0; i < n-1; i++) { // j-i-1
		ans = (ans+bin[i]*(b[n]-b[i+1]-b[n-i-1]+mod+mod)%mod)%mod;
	}
	printf("%lld\n", ans);
	return 0;
}