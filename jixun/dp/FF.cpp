#include <bits/stdc++.h>
#define N 1505
#define LG 12
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
#define bst bitset<N>
char ch[N][N];
bst a[N][LG], b[N][LG];
// 第 x 行长度 w 。
void aska(int x, int w, bst& c) {
	int t = log2(w);
	c = c & (a[x][t]);
	c = c & ((a[x][t] >> (w - (1 << t))));
}
// 第 x 行竖直长度为 w 的点集。
void askb(int x, int w, bst& c,int d) {
	int t = log2(w);
	c = c & (b[x][t]);
	c = c & (b[x][t] >> d);
	c = c & (b[x + w - (1 << t)][t]);
	c = c & (b[x + w - (1 << t)][t] >> d);
}
int n = read(), q = read();
bst res;
int main(int argc, char const *argv[]) {
	for (int i = 1; i <= n; i++) {
		scanf("%s", ch[i] + 1);
		for (int j = 1; j <= n; j++)
			if (ch[i][j] == '1') {
				a[i][0][j] = 1;
				b[i][0][j] = 1;
			}
	}
	for (int x = 1; x <= n; x++)
		for (int i = 1; i < LG; i++)
			for (int j = 1; j <= n; j++) if (j + (1 << i - 1) <= n)
				if (a[x][i - 1][j] && a[x][i - 1][j + (1 << i - 1)])
					a[x][i][j] = 1;
	for (int i = 1; i < LG; i++)
		for (int j = 1; j <= n; j++) if (j + (1 << i - 1) <= n)
			b[j][i] = b[j][i - 1] & b[j + (1 << i - 1)][i - 1];
	// print_bitset(a[1][2] >> 1);
	// bst r = askb(1, 5);
	while (q --) {
		int y = read(), x = read(), ans = 0;
		// 枚举第一行
		for (int i = 1; i + y - 1 <= n; i++) {
			res.set();
			aska(i, x, res);
			aska(i + y - 1, x, res);
			askb(i, y, res , x - 1);
			// puts("row");
			// print_bitset(row);
			// puts("lin");
			// print_bitset(lin);
			ans = ans + res.count();
		}
		printf("%d\n", ans);
	}
	return 0;
}