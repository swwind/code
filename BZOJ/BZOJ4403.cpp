#include <bits/stdc++.h>
#define N 1000003
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll frac[N];
ll inv(ll x, ll y = N-2){
	ll ans = 1;
	for(;y;y>>=1,x=x*x%N)if(y&1)ans=ans*x%N;
	return ans;
}
ll lucas(int n, int m){
	if(n < m) return 0;
	if(n < N && m < N) return frac[n]*inv(frac[m])%N*inv(frac[n-m])%N;
	return lucas(n/N, m/N)*lucas(n%N, m%N)%N;
}
int main(){
	frac[0] = 1;
	for(int i = 1; i < N; i++) frac[i] = frac[i-1]*i%N;
	int T = read();
	while(T--){
		int n = read(), l = read(), r = read();
		printf("%d\n", (lucas(n+r-l+1, r-l+1)-1+N)%N);
	}	
	return 0;
}