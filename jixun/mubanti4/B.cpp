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
int a[N], q[N], cnt;
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++) {
		int x = read();
		int pos = upper_bound(q + 1, q + cnt + 1, x) - q;
		if (pos > cnt) q[++cnt] = x;
		else q[pos] = min(q[pos], x);
	}
	printf("%d\n", cnt);
	return 0;
}