#include <bits/stdc++.h>
#define N 100020
#define zyy 1000000007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int pri[N], cnt, mark[N], pnt[N];
void split(int x) {
	for (int i = 1; i <= cnt && x > 1; i++) {
		while (x % pri[i] == 0) {
			pnt[i] ++;
			x /= pri[i];
		}
	}
}
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 2; i <= n; i++) {
		if (!mark[i]) pri[++cnt] = i;
		for (int j = 1; j <= cnt && i * pri[j] <= n; j++) {
			mark[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
	for (int i = 2; i <= n; i++)
		split(i);
	ll ans = 1;
	for (int i = 1; i <= cnt; i++)
		ans = ans * (pnt[i] + 1) % zyy;
	printf("%lld\n", ans);
	return 0;
}