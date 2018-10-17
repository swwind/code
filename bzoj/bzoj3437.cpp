#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll a[N], b[N], sum1[N], sum2[N], f[N], qu[N];
double calc(int i, int j){
	double fz = f[i]-f[j]+sum2[i]-sum2[j];
	double fm = sum1[i]-sum1[j];
	return fz/fm;
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++){
		b[i] = read();
		sum1[i] = sum1[i-1]+b[i];
		sum2[i] = sum2[i-1]+b[i]*i;
	}
	for(int i = 1, l = 0, r = 0; i <= n; i++){
		while(l < r && calc(qu[l], qu[l+1]) < i) l++;
		f[i] = f[qu[l]]+i*(sum1[i]-sum1[qu[l]])-(sum2[i]-sum2[qu[l]])+a[i];
		while(l < r && calc(qu[r], i) < calc(qu[r-1], qu[r])) r--;
		qu[++r] = i;
	}
	printf("%lld\n", f[n]);
	return 0;
}