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
int as[N], bs[N];
int in[N], out[N], res[N], cnt;
void link(int f, int t) {
	// printf("%d -> %d\n", f, t);
	in[t]++;
	out[f]++;
}
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	int *a = as, *b = bs;
	int s = read();
	for (int i = 1; i <= s; i++)
		a[i] = read();
	for (int i = 2; i <= n; i++) {
		int s = read();
		memset(b, 0, sizeof b);
		for (int j = 1; j <= s; j++)
			b[j] = read();
		int k = 1;
		while (a[k] == b[k] && a[k]) k++;
		// printf(">>> %d %d %d\n", a[k], b[k], k);
		// if (a[k] && !b[k]) return puts("No")&0;
		if (a[k] && b[k]) link(a[k], b[k]);
		swap(a, b);
	}
	// puts("Fuck you !!!");
	for (int i = 1; i <= m; i++)
		if (in[i] && out[i]) return puts("No")&0;
	puts("Yes");
	for (int i = 1; i <= m; i++)
		if (!in[i]) res[++cnt] = i;
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++)
		printf("%d ", res[i]);
	return 0;
}