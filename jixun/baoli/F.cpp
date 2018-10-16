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
struct node {
	ll x, y;
	friend node operator + (const node &a, const node &b) {
		return (node){a.x+b.x, a.y+b.y};
	}
	friend node operator - (const node &a, const node &b) {
		return (node){a.x-b.x, a.y-b.y};
	}
	friend ll operator * (const node &a, const node &b) {
		return a.x*b.y-a.y*b.x;
	}
	friend ll operator ^ (const node &a, const node &b) {
		return a.x*b.x+a.y*b.y;
	}
}a[N], b[N];
int ord[1020], ok[1020], vis[1020];
int k = read(), n = read();
vector<int>path[10][1020];
bool on(const node &x, const node &y, const node &z) {
	if ((x-y)*(x-z))
		return false;
	return ((x-z)^(y-z)) > 0 && ((x-y)^(z-y)) > 0;
}
int top;
bool check(int b, int t) {
	if (top == k+1)
		return false;
	int now = ord[top++];
	for (auto i : path[now][b])
		if (ok[i] != t && !check(i, t))
			return false;
	ok[b] = t;
	return true;
}
int cnt;
bool dfs(int now, int key) {
	if (now == k+1) {
		top = 1;
		return check(key, ++cnt);
	}
	int ret = 0;
	for (int i = 1; i <= k && !ret; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			ord[now] = i;
			ret = dfs(now+1, key);
			vis[i] = 0;
		}
	}
	return ret;
}
int main(int argc, char const *argv[]) {
	for (int i = 1; i <= k; i++)
		a[i].x = read(), a[i].y = read();
	for (int i = 1; i <= n; i++)
		b[i].x = read(), b[i].y = read();
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
			for (int l = 1; l <= n; l++)
				if (on(b[l], a[i], b[j]))
					path[i][j].push_back(l);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (dfs(1, i)) ans++;
	printf("%d\n", ans);
	return 0;
}