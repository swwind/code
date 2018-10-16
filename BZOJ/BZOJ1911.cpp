#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a, b, c;
ll sum[N], f[N], q[N];
double calc(int i, int j){
	double fz = f[i]-f[j]+a*(sum[i]*sum[i]-sum[j]*sum[j])+b*(sum[j]-sum[i]);
	double fm = 2*a*(sum[i]-sum[j]);
	return fz/fm;
}
int main(){
	int n = read();
	a = read(); b = read(); c = read();
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1]+read();
	for(int i = 1, l = 0, r = 0; i <= n; i++){
		while(l < r && calc(q[l], q[l+1]) < sum[i]) l++;
		ll tmp = sum[i]-sum[q[l]];
		f[i] = f[q[l]]+a*tmp*tmp+b*tmp+c;
		while(l < r && calc(q[r-1], q[r]) > calc(q[r], i)) r--;
		q[++r] = i;
	}
	printf("%lld\n", f[n]);
	return 0;
}