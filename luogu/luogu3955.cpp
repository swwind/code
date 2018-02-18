#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
bool check(int a, int b, int c) {
	int x = pow(10, c);
	return a % x == b;
}
int a[N];
int main(int argc, char const *argv[]) {
	int n = read(), q = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + n + 1);
	while (q --) {
		int len = read();
		int s = read();
		bool flag = 1;
		for (int i = 1; i <= n && flag; i++) {
			if (a[i] >= s && check(a[i], s, len)) {
				printf("%d\n", a[i]);
				flag = 0;
			}
		}
		flag && puts("-1");
	}
	return 0;
}