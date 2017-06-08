#include <bits/stdc++.h>
#define ll long long
#define N 100050
using namespace std;
struct node{
	int x, y, val;
	inline bool operator < (const node &b) const {
		return x == b.x ? y < b.y : x < b.x;
	}
}a[1050];
int n, m, r, f[N], ans;
int main(){
	scanf("%d%d%d", &n, &m, &r);
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].val);
	sort(a+1, a+m+1);
	for(int i = 1; i <= m; i++) f[i] = a[i].val;
	for(int i = 2; i <= m; i++) for(int j = 1; j < i; j++)
	if(a[j].y + r <= a[i].x) f[i] = max(f[i], f[j] + a[i].val);
	for(int i = 1; i <= m; i++) ans = max(ans, f[i]);
	return printf("%d\n", ans)&0;
}

