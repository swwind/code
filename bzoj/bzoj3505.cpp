#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll c[1000020][4];
int gcd(int a, int b){return b?gcd(b, a%b):a;}
int main(){
	int n = read()+1, m = read()+1, nm = n*m;
	c[0][0] = 1;
	for(int i = 1; i <= nm; i++){
		c[i][0] = 1;
		c[i][1] = c[i-1][0]+c[i-1][1];
		c[i][2] = c[i-1][1]+c[i-1][2];
		c[i][3] = c[i-1][2]+c[i-1][3];
	}
	ll ans = c[nm][3]-n*c[m][3]-m*c[n][3];
	for(int i = 1; i < n; i++)
		for(int j = 1; j < m; j++){
			int gg = gcd(i, j);
			if(gg > 1)
				ans = ans-(gg-1)*(n-i)*(m-j)*2;
		}
	printf("%lld\n", ans);
}