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
std::map<int, bool> mp;
int a[N], ans;
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		mp[a[i] = read()] ++;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int k = - a[i] - a[j];
			if (mp[k] && k > a[j]) {
				printf("%d %d %d\n", a[i], a[j], k);
				ans = 1;
			}
		}
	}
	if (!ans) puts("No Solution");
	return 0;
}
