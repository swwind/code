#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[N];
int main(int argc, char const *argv[]) {
	int n = read(), k = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + n + 1);
	int * end = unique(a + 1, a + n + 1);
	if (end - a - 1 < k) puts("NO RESULT");
	else printf("%d\n", a[k]);
	return 0;
}