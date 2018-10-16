#include <bits/stdc++.h>
#define N 100020
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[N], b[N], p[N];
std::vector<int> ans;
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
		b[i] = read();
	for (int i = 1; i <= n; i++)
		p[i] = i;
	sort(p+1, p+n+1, [] (const int &a, const int &b) -> bool {
		return ::a[a]>::a[b];
	});
	ans.push_back(p[1]);
	for (int i = 2; i < n; i += 2) {
		int l = p[i], r = p[i+1];
		ans.push_back(b[l] > b[r] ? l : r);
	}
	if (~n&1)
		ans.push_back(p[n]);
	printf("%d\n", ans.size());
	for (auto i : ans)
		printf("%d ", i);
	return 0;
}