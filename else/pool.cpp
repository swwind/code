#include <bits/stdc++.h>
#define N 100020
#define ll long long
#define mod 998244353
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll pw(ll a, ll y){
	ll ans = 0;
	for(;y;y>>=1,a=a*a%mod)if(y&1)ans=ans*a%mod;
	return ans;
}
int main(int argc, char const *argv[]){
	for(int i = 0;i<1000000000;i++);
	printf("%d\n", clock());
	return 0;
}
