#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#define oo 1e8
#define MAXN 5010
using namespace std;
struct node{
	int x, y;
} p[MAXN];
double ans, dis[MAXN], ds, mins;
int vis[MAXN], n, pos;
double calc(int a, int b) {
	return sqrt((double)(p[a].x - p[b].x) * (p[a].x - p[b].x) +
				(double)(p[a].y - p[b].y) * (p[a].y - p[b].y));
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &p[i].x, &p[i].y),
		dis[i] = oo;
	dis[1] = 0;
	for(int i = 1; i <= n; ++i){
		mins = oo;
		for(int j = 1; j <= n; ++j)
			if(!vis[j] && dis[j] < mins)
				mins = dis[j], pos = j;
		ans += mins, vis[pos] = 1;
		for(int j = 1; j <= n; ++j)
			dis[j] = min(dis[j], calc(pos, j));
	}
	printf("%.2lf\n", ans);
	return 0;
}

