#include <bits/stdc++.h>
#define N 50005
#define ll long long
using namespace std;
struct node{
	int l, r, val, id;
	bool operator < (const node &b) const {
		return val == b.val ? r < b.r : val < b.val;
	}
}a[N];
int b[N], res[N], n, m, k, num[N];
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++) scanf("%d", b+i);
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &a[i].l, &a[i].r);
		a[i].id = i;
		a[i].val = (a[i].l - 1) / sqrt(n) + 1;
	}
	sort(a+1, a+m+1);
	int l = 1, r = 0, ans = 0;
	for(int i = 1; i <= m; i++){
		while(l > a[i].l) l--, num[b[l]]++, ans += 2*num[b[l]] - 1;
		while(l < a[i].l) num[b[l]]--, ans -= 2*num[b[l]] + 1, l++;
		while(r < a[i].r) r++, num[b[r]]++, ans += 2*num[b[r]] - 1;
		while(r > a[i].r) num[b[r]]--, ans -= 2*num[b[r]] + 1, r--;
		res[a[i].id] = ans;
	}
	for(int i = 1; i <= m; i++)
		printf("%d\n", res[i]);
	return 0;
}

