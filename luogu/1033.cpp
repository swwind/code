#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-4;
double h, s, v, l, k;
int n, ans;
int main(int argc, char const *argv[]) {
	scanf("%lf%lf%lf%lf%lf%d", &h, &s, &v, &l, &k, &n);
	for (int i = 0; i < n; i++)
		ans += i < eps+(s-sqrt((h-k)/5)*v)+l && i > (s-sqrt(h/5)*v)-eps;
	printf("%d\n", ans);
	return 0;
}