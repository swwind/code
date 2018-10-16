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
int f[1020][1020];
char a[1020], b[1020];
int main(int argc, char const *argv[]) {
	scanf("%s", a + 1); int n = strlen(a + 1);
	scanf("%s", b + 1); int m = strlen(b + 1);
	for (int i = 1; i <= n; i++) f[i][0] = i;
	for (int i = 1; i <= m; i++) f[0][i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1]) + 1);
			else f[i][j] = min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1])) + 1;
		}
	}
	printf("%d\n", f[n][m]);
	return 0;
}
