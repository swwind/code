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
int a[N], b[N], ans = -1, n, m;
int main(int argc, char const *argv[]) {
	int n = read(), k = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		if (k <= ++ b[a[i] % m])
			ans = a[i] % m;
	}
	if (ans == -1)
		return puts("No") & 0;
	puts("Yes");
	for (int i = 1; i <= n && k; i++) {
		if (a[i] % m == ans) {
			printf("%d ", a[i]);
			k --;
		}
	}
	puts("");
	return 0;
}