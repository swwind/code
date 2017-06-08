#include <bits/stdc++.h>
#define zyy 1000000007
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll dp[16][16][16][16][16][6];
int x[6];
ll f(int a, int b, int c, int d, int e, int k){
	ll &ans = dp[a][b][c][d][e][k], tmp = 0;
	if(~ans) return ans;
	if(!(a+b+c+d+e)) return ans = 1;
	if(a) tmp += (a-(k==2))*f(a-1, b, c, d, e, 1);
	if(b) tmp += (b-(k==3))*f(a+1, b-1, c, d, e, 2);
	if(c) tmp += (c-(k==4))*f(a, b+1, c-1, d, e, 3);
	if(d) tmp += (d-(k==5))*f(a, b, c+1, d-1, e, 4);
	if(e) tmp += e*f(a, b, c, d+1, e-1, 5);
	return ans = tmp%zyy;
}
int main(){
	memset(dp, -1, sizeof dp);
	for(int i = 1, k = read(); i <= k; i++) x[read()]++;
	printf("%lld\n", f(x[1], x[2], x[3], x[4], x[5], 0));
	return 0;
}