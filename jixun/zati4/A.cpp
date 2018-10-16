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
char str[N];
int main(int argc, char const *argv[]) {
	int T = read();
	while (T --) {
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		ll ans = 0, one = 0, zero = 0;
		for (int i = 1; i <= n; i++) {
			if (str[i] == '1') one ++;
			else zero ++;
			if (str[i] == '1')
				if (zero) ans += (zero + 1) * (one - 1), zero = 0;
			// printf("%d %d %d\n", one, zero, ans);
		}
		printf("%lld\n", ans + (zero ? (zero + 1) * one : 0));
	}
	return 0;
}