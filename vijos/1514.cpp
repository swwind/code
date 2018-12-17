#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int f[N][20], lg[N];
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		f[i][0] = read();
	lg[1] = 0;
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i >> 1] + 1;
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++) if (j + (1 << i - 1) <= n)
			f[j][i] = max(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
	int m = read();
	while (m --) {
		int l = read()+1, r = read()+1;
		int t = lg[r - l + 1];
		printf("%d\n", max(f[l][t], f[r - (1 << t) + 1][t]));
	}
	return 0;
}