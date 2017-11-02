#include <bits/stdc++.h>
#define N 100020
#define ll long long
#define x first
#define y second
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
pair<int, int> a[N];
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i].x = read(), a[i].y = read();
	sort(a + 1, a + n + 1);
	int mr = a[1].y, ans = 0;
	for (int i = 2; i <= n; i++) {
		ans = max(ans, min(mr, a[i].y) - a[i].x);
		mr = max(mr, a[i].y);
	}
	printf("%d\n", ans);
	return 0;
}
