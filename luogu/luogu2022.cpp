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
ll k = read(), m = read(), number, n, i;
int main () {
	for (i = 1; i <= k; i *= 10)
		number += k/i-i+1;
	number--;
	if (number >= m || k-(i/10) == 0 && number < m-1)
		return puts("0")&0;
	for (i = k-(i/10), n = k; number < m-1; n *= 10)
		number += i *= 10;
	printf("%lld\n", max(n-number+m-2,k));
	return 0;
}