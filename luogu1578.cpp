#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int x, y;
	node(){}
	node(int a, int b):x(a), y(b){}
	bool operator < (const node &b) const {
		return x == b.x ? y < b.y : x < b.x;
	}
}p[5050];
int L, W, n, x, y, ans;
int main(){
	scanf("%d%d%d", &L, &W, &n);
	p[1] = node(0, 0);
	p[2] = node(0, W);
	p[3] = node(L, 0);
	p[4] = node(L, W);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &x, &y),
		p[5+i] = node(x, y);
	sort(p+1, p+n+5);
	for(int i = 1; i <= n+4; i++){
		int u = 0, d = W;
		for(int j = i+1; j <= n+4; j++){
			if(p[j].x == p[i].x || p[j].y > d || p[j].y < u) continue;
			ans = max(ans, (p[j].x - p[i].x) * (d - u));
			if(p[j].y > u && p[j].y <= p[i].y) u = p[j].y;
			if(p[j].y < d && p[j].y >= p[i].y) d = p[i].y;
			if(u >= d) break;
		}
	}
	printf("%d", ans);
	return 0;
}

