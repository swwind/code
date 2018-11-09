#include <bits/stdc++.h>
#define mod 9973
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int power(int x, int y){
	int ans = 1;
	for(;y;y>>=1,x=x*x%mod)if(y&1)ans=ans*x%mod;
	return ans;
}
int main(int argc, char const *argv[]){
	int t = read();
	while(t--){
		int a = read(), b = read()%mod;
		printf("%d\n", a*power(b, mod-2)%mod);
	}
	return 0;
}