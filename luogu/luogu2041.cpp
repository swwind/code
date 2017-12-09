#include <bits/stdc++.h>
#define N 1020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int mp[N][N], n = read();
void dfs(int x, int y) {
	if (mp[x + 1][y]) dfs(x + 1, y);
	if (mp[x][y + 1]) dfs(x, y + 1);
	printf("%d %d\n", x, y);
	mp[x][y] = 0;
	mp[x + 1][y] = mp[x][y + 1] = 1;
	// for (int i = 1; i <= 10; i++, puts(""))
	// 	for (int j = 1; j <= 10; j++)
	// 	putchar(mp[i][j] ? '1' : ' ');
	// puts("");
	if (x + y <= n)
		dfs(x + 1, y), dfs(x, y + 1);
}
int main(int argc, char const *argv[]) {
	mp[1][1] = 1;
	if (n > 2) return puts("-1")&0;
	if (n == 1) puts("1");
	else puts("4");
	dfs(1, 1);
	return 0;
}