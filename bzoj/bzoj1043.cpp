#include <bits/stdc++.h>
using namespace std;
int n, cnt;
double ans;
struct cc{
	double r, x, y;
}a[1020];
struct lne{
	double l, r;
	bool operator < (const lne &b) const {
		return l < b.l;
	}
}q[1020];
// return a^2
double sqr(double a){return a*a;}
// return the dist from x to y
double dis(int x, int y){return sqrt(sqr(a[x].x-a[y].x)+sqr(a[x].y-a[y].y));}
// return if x includes y
bool include(int x, int y){return a[x].r>=a[y].r+dis(x, y);}
void ins(int x, int y){
	double d = dis(x, y);
	double t = (sqr(a[x].r)-sqr(a[y].r)+sqr(d))/(2*d);
	double st = atan2(a[x].x-a[y].x, a[x].y-a[y].y);
	double l = acos(t/a[x].r);
	q[++cnt] = (lne){st-l, st+l};
}
double calc(int x){
	for(int i = x+1; i <= n; i++)
		if(include(i, x)) return 0;
	cnt = 0;
	for(int i = x+1; i <= n; i++)
		if(!include(x, i) && a[x].r+a[i].r>=dis(x, i))
			ins(x, i);
	for(int i = 1; i <= cnt; i++){
		if(q[i].l < 0) q[i].l += 2*M_PI;
		if(q[i].r < 0) q[i].r += 2*M_PI;
		if(q[i].l > q[i].r){
			q[++cnt] = (lne){0, q[i].r};
			q[i].r = 2*M_PI;
		}
	}
	sort(q+1, q+cnt+1);
	double tmp=0, last=0;
	for(int i = 1; i <= cnt; i++)
		if(q[i].l > last){
			tmp += q[i].l - last;
			last = q[i].r;
		}
		else last = max(last, q[i].r);
	return a[x].r*(tmp+2*M_PI-last);
}
int main(){
	scanf("%d\n", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lf%lf%lf", &a[i].r, &a[i].x, &a[i].y);
	for(int i = 1; i <= n; i++)
		ans += calc(i);
	printf("%.3lf\n", ans);
}