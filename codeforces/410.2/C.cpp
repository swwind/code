#include <bits/stdc++.h>
#define N 100020
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int gcd(int x, int y){if(!x)return y;if(!y)return x;return gcd(y,x%y);}
int a[N], sum, ans;
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		sum += (a[i] = read())&1;
	int gg = a[1];
	for (int i = 2; i <= n; i++)
		gg = gcd(gg, a[i]);
	if (gg > 1) return puts("YES\n0")&0;
	for (int i = 1; i <= n-1; i++)
		if ((a[i]&1) && (a[i+1]&1)) {
			a[i]^=1;a[i+1]^=1;
			sum -= 2, ans++;
		}
	printf("YES\n%d\n", ans+sum*2);
	return 0;
}