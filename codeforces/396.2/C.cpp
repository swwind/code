#include <bits/stdc++.h>
#define N 1020
#define ll long long
#define mod 1000000007
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int f[N], g[N], r[N], cnt[30];
char str[N];
int main(int argc, char const *argv[]) {
	int n = read();
	scanf("%s", str + 1);
	for (int i = 0; i < 26; i++)
		cnt[i] = read();
	f[1] = 1;
	for (int i = 2, len; i <= n + 1; i++) {
		len  =   1 << 30;
		g[i] = - 1 << 30;
		r[i] =   1 << 30;
		for (int j = i - 1; j; j--) {
			len = min(len, cnt[str[j] - 'a']);
			if (len < i - j)
				break;
			f[i] = (f[i] + f[j]) % mod;
			g[i] = max(g[i], max(i - j, g[j]));
			r[i] = min(r[i], r[j] + 1);
		}
	}
	printf("%d\n%d\n%d\n", f[n + 1], g[n + 1], r[n + 1]);
	return 0;
}
