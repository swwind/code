#include <bits/stdc++.h>
#define N 300020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[N], f[2][50];
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read() / 100;
	int now = 0, pre = 1;
	memset(f, 63, sizeof f);
	f[now][0] = 0;
	for (int i = 1; i <= n; i++) {
		swap(now, pre);
		int x = a[i] / 10;
		memset(f[now], 63, sizeof f[now]);
		for (int j = 0; j < 40; j++) {
			if (j + x < 40) f[now][j + x] = f[pre][j] + a[i];
			int y = min(j, a[i]);
			if (y) f[now][j - y] = min(f[now][j - y], f[pre][j] + a[i] - y);
		}
	}
	int asuna = 1 << 30;
	for (int i = 0; i < 30; i++)
		asuna = min(asuna, f[now][i]);
	printf("%d00\n", asuna);
	return 0;
}
