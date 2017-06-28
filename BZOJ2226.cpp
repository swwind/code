#include <bits/stdc++.h>
#define ll long long
#define N 1000020
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll sum[N], ans[N];
int main(){
	for(int i = 1; i < N; i++){
		sum[i] += 1ll*i*(i+1)>>1;
		for(int j = 2; i*j < N; j++)
			sum[i*j] -= j*sum[i];
	}
	for(int i = 1; i < N; i++){
		for(int j = 1; j*i < N; j++)
			ans[i*j] += sum[i];
		ans[i] *= i;
	}
	int T = read();
	while(T--) printf("%lld\n", ans[read()]);
	return 0;
}