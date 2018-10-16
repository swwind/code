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
int a[N], nxt[N], b[N], cnt;
int main(int argc, char const *argv[]) {
	int c = read(), n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a+1, a+n+1);
	for (int i = 1, j = 1; i <= n; i = j+1) {
		while (a[j+1] == a[i] && j < n) j++;
		b[++cnt] = j-i+1;
		a[cnt] = a[i];
	}
	for (int i = c, j = cnt; i; i--) {
		while (a[j] > i) j--;
		nxt[i] = j;
	}
	for (int i = 1; i <= c; i++) {
		int sum = c, j = cnt;
		if (i > a[cnt]) sum -= i;
		while (sum && j) {
			sum -= min(b[j], sum/a[j])*a[j];
			int nt = min(nxt[sum], j-1);
			if (a[nt] <= i && a[j] >= i && sum >= i)
				sum -= i;
			j = nt;
		}
		if (sum) return printf("%d\n", i)&0;
	}
	puts("Greed is good");
	return 0;
}
