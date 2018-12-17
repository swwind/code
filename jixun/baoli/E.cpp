#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct node {
	int x, y, z;
	friend bool operator < (const node &a, const node &b) {
		return a.x < b.x;
	}
}b[N];
ll a[N], cnt, ans[N], lst[N], lbc[N];
int main(int argc, char const *argv[]) {
	int n = read(), k = read();
	for (int i = 1; i <= n; i++) {
		int x = read(), y = read();
		a[++cnt] = y; b[cnt] = (node){x, y, 1};
		a[++cnt] = y+k; b[cnt] = (node){x+k, y, -1};
	}
	sort(b+1, b+cnt+1);
	sort(a+1, a+cnt+1);
	int tot = unique(a+1, a+cnt+1)-a-1;
	for (int i = 1; i <= cnt; i++) {
		int st = lower_bound(a+1, a+tot+1, b[i].y)-a, ed = lower_bound(a+1, a+tot+1, b[i].y+k)-a;
		for (int j = st; j < ed; j++) {
			ans[lbc[j]] += (a[j+1]-a[j])*(b[i].x-lst[j]);
			lbc[j] += b[i].z;
			lst[j] = b[i].x;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%lld ", ans[i]);
	return 0;
}