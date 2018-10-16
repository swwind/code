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
int a[520][520], ans;
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			a[i][j] = max(a[i-1][j-1], a[i-1][j]) + read();
	for (int i = 1; i <= n; i++)
		ans = max(ans, a[n][i]);
	printf("%d\n", ans);
	return 0;
}
