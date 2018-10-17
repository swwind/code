#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll a[N], b[N];
ll f[N][2];
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) b[i] = read();
	for(int i = 2; i <= n; i++)
		if(b[i-1] >= a[i] || a[i-1] <= b[i] || a[i] < a[i-1] && b[i] > b[i-1])
			return puts("-1")&0;
	f[1][0] = a[1]-b[1];
	for(int i = 2; i <= n; i++){
		if(b[i-1] >= b[i]) f[i][1] = min(f[i-1][1], f[i-1][0]+a[i-1]-b[i-1]);
		else f[i][1] = 1e16;
		if(a[i-1] <= a[i]) f[i][0] = min(f[i-1][0], f[i-1][1]+a[i-1]-b[i-1]);
		else f[i][0] = 1e16;
	}
	printf("%lld\n", min(f[n][1], f[n][0]+a[n]-b[n]));
	return 0;
}