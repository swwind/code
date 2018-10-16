#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll f[1000020][2], a[1000020], q[1000020], l, r;
double check(ll j, ll k){
	return (f[k][1]*2-f[j][1]*2+k*k+k-j*j-j)/2./(k-j);
}
int main(int argc, char const *argv[]){
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	f[n][1] = a[n]; f[n][0] = 1ll<<60; q[l=r=1] = n;
	for(int i = n-1; i; i--){
		f[i][1] = min(f[i+1][0], f[i+1][1])+a[i];
		while(l < r && check(q[l+1], q[l]) > i) l++;
		f[i][0] = f[q[l]][1]+(q[l]-i+1)*(q[l]-i)/2;
		while(l < r && check(q[r], q[r-1]) < check(i, q[r])) r--;
		q[++r] = i;
	}
	printf("%lld\n", min(f[1][1], f[1][0]));
	return 0;
}
