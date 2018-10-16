#include <bits/stdc++.h>
#define N 100020
#define ll long long
#define mod 10000
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll a[N], sum;
int main(int argc, char const *argv[]) {
	int n = read(), f = read();
	for (int i = 1; i <= n; i++) {
		int k = read(), l = read();
		sum += min(l, k);
		a[i] = min(l, 2*k)-min(l, k);
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= f; i++)
		sum += a[n-i+1];
	printf("%lld\n", sum);
	return 0;
}