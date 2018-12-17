#pragma GCC optimize 2
#include<ctime>
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
int lbc[70020], lg2[1540];
struct bst {
	static const int BST_SIZE = 50;
	unsigned int a[BST_SIZE];
	bst(){memset(a, 0, sizeof a);}
	void set(){memset(a, -1, sizeof a);}
	bool operator [] (int x) {
		return a[x >> 5] >> (x & 31) & 1;
	}
	inline void set1(int x) {
		a[x >> 5] |= 1 << (x & 31);
	}
	void operator &= (const bst &b) {
		for (int i = 0; i < BST_SIZE; i++)
			a[i] &= b.a[i];
	}
	friend bst operator & (const bst &a, const bst &b) {
		bst c;
		for (int i = 0; i < BST_SIZE; i++)
			c.a[i] = a.a[i] & b.a[i];
		return c;
	}
	bst operator >> (int b) {
		if (b == 0) return *this;
		bst c;
		int l = b & 31, r = (b >> 5);
		for (int i = r, j = 0; i < BST_SIZE; i++, j++) {
			c.a[j] |= a[i] >> l;
			if (j && l) c.a[j - 1] |= a[i] << 32 - l;
		}
		return c;
	}
	inline int count() {
		int res = 0;
		for (int i = 0; i < BST_SIZE; i++)
			res += lbc[a[i] & ((1 << 16) - 1)] + lbc[a[i] >> 16];
		return res;
	}
};
char ch[N][N];
bst a[N][LG], b[N][LG];
// 第 x 行长度 w 。
bst res;
void aska(int x, int w) {
	int t = lg2[w];
	res &= (a[x][t]);
	res &= ((a[x][t] >> (w - (1 << t))));
}
// 第 x 行竖直长度为 w 的点集。
void askb(int x, int w,int d) {
	int t = lg2[w];
	res &= (b[x][t]);
	res &= (b[x][t] >> d);
	res &= (b[x + w - (1 << t)][t]);
	res &= (b[x + w - (1 << t)][t] >> d);
}
int n = read(), q = read();
int main(int argc, char const *argv[]) {
	for (int i = 1; i <= 70000; i++)
		lbc[i] = lbc[i ^ (i & -i)] + 1;
	lg2[1] = 0;
	for (int i = 2; i <= 1500; i++)
		lg2[i] = lg2[i >> 1] + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%s", ch[i] + 1);
		for (int j = 1; j <= n; j++)
			if (ch[i][j] == '1') {
				a[i][0].set1(j);
				b[i][0].set1(j);
			}
	}
	for (int x = 1; x <= n; x++)
		for (int i = 1; i < LG; i++)
			for (int j = 1; j <= n; j++) if (j + (1 << i - 1) <= n)
				if (a[x][i - 1][j] && a[x][i - 1][j + (1 << i - 1)])
					a[x][i].set1(j);
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
			aska(i, x);
			aska(i + y - 1, x);
			askb(i, y , x - 1);
			// puts("row");
			// print_bitset(row);
			// puts("lin");
			// print_bitset(lin);
			ans = ans + res.count();
		}
//		printf("%d\n", ans);
	}printf("%d ",clock());
	// fprintf(stdout, "%d", clock());
	return 0;
}