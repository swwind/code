#include <bits/stdc++.h>
#define N 1000020
#define ll long long
#define mod 10000
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int f[1020][1020];
int main(int argc, char const *argv[]) {
	int q = read(), p = read(), n = read(), t = read();
	for (int i = 1; i <= n*(n-1)/2; i++) {
		int x = read(), y = read();
		f[x][y] = f[y][x] = read();
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
	if (f[q][p] > t) {
		puts("0");
	} else {
		printf("1\n%d\n", f[q][p]);
	}
	return 0;
}
