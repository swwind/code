#include <bits/stdc++.h>
#define N 40020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct node {
	int x, y;
	friend bool operator < (const node &a, const node &b) {
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	}
}a[N], ans;
ll lbc;
bool cmp(const node &a, const node &b) {
	return a.y > b.y;
}
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++) {
		a[i].x = read();
		a[i].y = read();
		if (a[i].x < a[i].y)
			swap(a[i].x, a[i].y);
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) {
		int xx = a[i].x;
		sort(a+i, a+n+1, cmp);
		for (int j = i; j <= n; j++)
			if (1ll*a[j].y*xx*(j-i+1) > lbc)
				lbc = 1ll*a[j].y*xx*(j-i+1), ans.x = xx, ans.y = a[j].y;
		sort(a+i, a+n+1);
	}
	printf("%lld\n%d %d\n", lbc, ans.x, ans.y);
	return 0;
}