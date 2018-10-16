#include <bits/stdc++.h>
#define N 1000020
#define ll long long
#define mod 10000
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int main(int argc, char const *argv[]) {
	int n = read(), k = read();
	double sum = 0;
	for (int i = 1; i <= n; i++)
		sum += read();
	for (ll i = 0; 1; i++, sum += k) {
		if (round(sum/(i+n)) >= k)
			return printf("%lld\n", i)&0;
	}
	return 0;
}
