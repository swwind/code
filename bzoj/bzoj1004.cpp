#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int frav[202], p;
int pw(int a, int b = p-2){
	int c = 1;
	for(;b;b/=2,a=a*a%p)if(b&1)c=c*a%p;
	return c;
}
int main(){
	int r = read(), b = read(), g = read(), m = read(); p = read();
	frav[0] = 1;
	for(int i = 1; i <= 200; i++) frav[i] = frav[i-1]*i%p;
	int n = r+b+g;
	int ans = frav[n]*pw(frav[r])*pw(frav[b])*pw(frav[g])%p;
	printf("%d\n", ans*pw(m+1)%p);
}