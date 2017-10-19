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
int a[N];
int main(int argc, char const *argv[]) {
	int T = read();
	while (T --) {
		int n = read();
		ll sum = 0, num = 0, ans = 0;
		for (int i = 1; i <= n; i++)
			ans += a[i] = read();
		sort(a + 1, a + n + 1);
		for (int i = n; i; i--) {
			if ((sum + a[i]) * (num + 1) > sum * num)
				sum += a[i], num ++, ans -= a[i];
			else break;
		}
		cout << ans + sum * num << endl;
	}
	return 0;
}