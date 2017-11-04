#include <bits/stdc++.h>
#define ll long long
#define N 30
using namespace std;
inline int read() {
	int x = 0, f = 0; char ch = getchar();
	while (ch > '9' || ch < '0') {if (ch == '-')f = 1; ch = getchar();}
	while (ch <= '9' && ch >= '0') {x = (x << 3) + (x << 1) + ch - '0'; ch = getchar();}
	return f ? -x : x;
}
int n, m, mod;
char str[N];
int nxt[N], a[N];
struct Matrix {
	#ifndef MATRIX_SIZE
	#define MATRIX_SIZE 80
	#endif
	ll num[MATRIX_SIZE][MATRIX_SIZE];
	inline void clear() {
		memset(num, 0, sizeof num);
	}
	Matrix() {
		clear();
	}
	Matrix(bool flag) {
		clear();
		for (int i = 0; i < m; i++)
			num[i][i] = 1;
	}
	ll* operator [] (int x) {return num[x];}
	friend Matrix operator * (Matrix a, Matrix b) {
		Matrix c;
		for (int k = 0; k < m; k++)
			for (int i = 0; i < m; i++) if (a[i][k])
				for (int j = 0; j < m; j++) if (b[k][j])
					c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
		return c;
	}
	friend Matrix operator ^ (Matrix a, ll b) {
		Matrix c(true);
		for (; b; b >>= 1, a = a * a)
			if (b & 1) c = c * a;
		return c;
	}
} ans, res;
int main() {
	n = read(); m = read(); mod = read(); scanf("%s", str + 1);
	for (int i = 1; i <= m; i++) a[i] = str[i] - '0';
	for (int i = 2, j = 0; i <= m; i++) {
		while (j && a[j + 1] != a[i]) j = nxt[j];
		if (a[j + 1] == a[i]) j++; nxt[i] = j;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 10; j++) {
			int t = i;
			while (t && a[t + 1] != j)
				t = nxt[t];
			res[i][a[t + 1] == j ? t + 1 : 0]++;
		}
	}
	ans[0][0] = 1;
	ans = ans * (res ^ n);
	ll sum = 0;
	for (int i = 0; i < m; i++)
		sum = (sum + ans[0][i]) % mod;
	printf("%lld\n", sum);
	return 0;
}
