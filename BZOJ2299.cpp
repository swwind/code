#include <bits/stdc++.h>
#define int long long
#define ok(a, b) ((a)%g == 0 && (b)%g == 0)
using namespace std;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int gcd(int a, int b){return b?gcd(b, a%b):a;}
signed main(){
	int T = read();
	while(T--){
		int a = read(), b = read(), x = read(), y = read();
		int g = gcd(a<<1, b<<1);
		if(ok(x, y) || ok(x+a, y+b) || ok(x+b, y+a) || ok(x+a+b, y+a+b)) puts("Y");
		else puts("N");
	}
}