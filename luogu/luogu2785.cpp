#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
double x[N], y[N], b, ans;
int main(int argc, char const *argv[]) {
	int n = read();
	cin >> b;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	ans = x[n] * y[1] - x[1] * y[n];
	for (int i = 1; i < n; i++) 
		ans += x[i] * y[i + 1] - x[i + 1] * y[i];
	printf("%.4lf\n", fabs(ans / 2 * b));
	return 0;
}