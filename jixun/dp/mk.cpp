#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	freopen("F.in", "w", stdout);
	srand(time(0));
	int n = 1500, q = 1500;
	printf("%d %d\n", n, q);
	for (int i = 1; i <= n; i++, puts(""))
		for (int j = 1; j <= n; j++)
			putchar(rand() & 7 ? '1' : '0');
	for (int i = 1; i <= q; i++)
		printf("%d %d\n", rand() % n + 1, rand() % n + 1);
	return 0;
}