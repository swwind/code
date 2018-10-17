#include <bits/stdc++.h>
#define N 10000007
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int main(){
	ll p = read(), q = read();
	printf("%lld\n", p == q ? (p*q-1)/4 : (p-1)*(q-1)/4);
}