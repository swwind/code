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
int a[N];
int fast_pow(int x) {
	int ans = 1;
	for (int i = 1; i <= x; i++)
		ans = (ans << 1) % zyy;
	return ans;
}
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + n + 1);
	if (n & 1) {
		for (int i = 1; i <= n; i++)
			if (a[i] != ((i & 1) ? i - 1 : i))
				return puts("0")&0;
		printf("%d\n", fast_pow(n >> 1));
	} else {
		for (int i = 1; i <= n; i++)
			if (a[i] != ((i & 1) ? i : i - 1))
				return puts("0")&0;
		printf("%d\n", fast_pow(n >> 1));
	}
	return 0;
}