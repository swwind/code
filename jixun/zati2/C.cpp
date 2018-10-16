#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
char a[N << 1], b[N];
char rev(char c) {
	if (c == 'N') return 'S';
	if (c == 'S') return 'N';
	if (c == 'W') return 'E';
	if (c == 'E') return 'W';
}
int nxt[N << 1];
int main(int n, char const *argv[]) {
	cin >> n >> a + 1 >> b + 1;
	a[n] = ' ';
	for (int i = 1; i < n; i++) {
		a[i] = rev(a[i]);
		a[n + i] = b[i];
	}
	reverse(a + 1, a + n);
	// cout << a + 1 << endl;
	n = n * 2 - 1;
	for (int i = 2, j = 0; i <= n; i ++) {
		while (j && a[i] != a[j + 1]) j = nxt[j];
		if (a[i] == a[j + 1]) j ++; nxt[i] = j;
	}
	// printf("%d\n", nxt[n]);
	puts(!nxt[n] ? "YES" : "NO");
	return 0;
}