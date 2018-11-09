#include <bits/stdc++.h>
#define N 100020
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int gcd(int a, int b){return b?gcd(b, a%b):a;}
int lcm(int a, int b){return a*b/gcd(a, b);}
void exgcd(int a, int b, int &x, int &y){
	if(!b){x=1,y=0;return;}
	exgcd(b, a%b, x, y);
	int t = x; x = y;
	y = t-a/b*y;
}
int inv(int a, int b){
	int x, y;
	exgcd(a, b, x, y);
	return (x%b+b)%b;
}
int a[N], b[N], c[N], m[N], ans, LCM = 1;
int calc(int x){
	if(x < ans) return 0;
	return (x-ans)/LCM+1;
}
signed main(){
	int n = read(), A = read(), B = read();
	for(int i = 1; i <= n; i++) m[i] = read(), a[i] = read();
	for(int i = 1; i <= n; i++){
		if(gcd(LCM, m[i]) > 1) return puts("0\n0\n")&0;
		LCM *= m[i];
	}
	for(int i = 1; i <= n; i++){
		b[i] = LCM/m[i];
		c[i] = inv(b[i], m[i]);
		ans = (ans+a[i]*b[i]%LCM*c[i])%LCM;
	}
	ans = (ans+LCM)%LCM;
	int num = calc(B)-calc(A-1);
	printf("%lld\n", num);
	printf("%lld\n", num ? calc(A-1)*LCM+ans : 0);
	return 0;
}