#include <bits/stdc++.h>
#define N 50020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int r[N], a[N], b[N];
void add(int x) {
	for (;x;x^=x&-x)
		r[x] ++;
}
int ask(int x) {
	int res = 0;
	for (;x<N;x+=x&-x)
		res += r[x];
	return res;
}
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = b[i] = read();
	sort(b + 1, b + n + 1);
	int *end = unique(b + 1, b + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = lower_bound(b + 1, end, a[i]) - b;
		ans += ask(x + 1);
		add(x);
	}
	printf("%d\n", ans);
	return 0;
}