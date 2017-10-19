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
map<int, int> mp;
int main(int argc, char const *argv[]) {
	int n = read(), ans = 0, sum1 = 0, sum0 = 0;
	mp[0] = 1;
	for (int i = 1, x; i <= n; i++) {
		scanf("%1d", &x);
		if (x) sum1 ++;
		else   sum0 ++;
		if (mp[sum1 - sum0])
			ans = max(ans, i - mp[sum1 - sum0] + 1);
		else
			mp[sum1 - sum0] = i + 1;
	}
	printf("%d\n", ans);
	return 0;
}