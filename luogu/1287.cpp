#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll f[12][12];
ll jc(int x) {
	return x == 1 ? 1 : x*jc(x-1);
}
int main(int argc, char const *argv[]) {
	int n = read(), k = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= min(i, k); j++)
			if (i == j || j == 1) f[i][j] = 1;
			else f[i][j] = f[i-1][j-1]+j*f[i-1][j];
	printf("%lld\n", f[n][k]*jc(k));
	return 0;
}