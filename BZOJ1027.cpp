#include <bits/stdc++.h>
#define N 505
#define esp 1e-10
#define inf (1<<30)
using namespace std;
struct node{
	double x, y;
	double operator * (const node B) const {
		return x * B.y - y * B.x;
	}
	node operator - (const node B) const {
		return (node){x-B.x, y-B.y};
	}
} a[N], b[N];
int dis[N][N], mp[N][N], n, m;
int col(node x, node y){
	if(x.x > y.x) swap(x, y);
	for(int i = 1; i <= m; i++)
		if(b[i].x < x.x || b[i].x > y.x)
			return 0;
	if(x.y > y.y) swap(x, y);
	for(int i = 1; i <= m; i++)
		if(b[i].y < x.y || b[i].y > y.y)
			return 0;
	return 1;
}
int jud(node x, node y){
	int c1 = 0, c2 = 0;
	for(int i = 1; i <= m; i++){
		double t = (y-x)*(b[i]-x);
		if(t > esp) c1++;
		if(t < -esp) c2++;
		if(c1*c2) return 0;
	}
	if(!c1&&!c2&&col(x, y)) return puts("2"), -1;
	if(c1) return 1;
	if(c2) return 2;
	return 3;
}
void solve(){
	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++){
			int flag = jud(a[i], a[j]);
			if(flag == -1) return;
			if(flag == 1) dis[i][j] = 1;
			else if(flag == 2) dis[j][i] = 1;
			else if(flag == 3) dis[i][j] = dis[j][i] = 1;
		}
	int ans = inf;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(dis[j][i] < inf)
				for(int k = 1; k <= n; k++)
					dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
	for(int i = 1; i <= n; i++) ans = min(ans, dis[i][i]);
	if(ans == inf || ans <= 2) puts("-1");
	else printf("%d", ans);
}
bool spj(){
	for(int i = 1; i <= n; i++)
		if(fabs(a[i].x - a[1].x) > esp || fabs(a[i].y - a[1].y) > esp) return 0;
	for(int i = 1; i <= m; i++)
		if(fabs(b[i].x - a[1].x) > esp || fabs(b[i].y - a[1].y) > esp) return 0;
	return puts("1"), 1;
}
int main(){
	memset(dis, 127/3, sizeof dis);
	scanf("%d%d", &n, &m);
	double K;
	for(int i = 1; i <= n; i++)
		scanf("%lf%lf%lf", &a[i].x, &a[i].y, &K);
	for(int i = 1; i <= m; i++)
		scanf("%lf%lf%lf", &b[i].x, &b[i].y, &K);
	if(spj()) return 0;
	solve();
	return 0;
}
