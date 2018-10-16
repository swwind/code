#include <bits/stdc++.h>
#define N 6000007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll a[N], b[N], sum, ans;
int main(){
	int n = read();
	for(int i = 1; i <= n; i++)
		sum += a[i] = read();
	sum /= n;
	for(int i = 1; i <= n; i++)
		b[i] = b[i-1]+a[i]-sum;
	sort(b+1, b+n+1);
	for(int i = 1; i <= n; i++)
		ans += abs(b[i+1>>1]-b[i]);
	printf("%lld\n", ans);
	return 0;
}