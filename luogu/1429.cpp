#include <bits/stdc++.h>
#define N 1000020
#define ll long long
#define pdd pair<double, double>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
pdd p[N]; int v[N];
const double INF = 1e60;
double dis(int x, int y) {
	return
		sqrt((p[x].first  - p[y].first)  * (p[x].first  - p[y].first)
			+(p[x].second - p[y].second) * (p[x].second - p[y].second));
}
bool cmp(const int &x, const int &y) {
	return p[x].second < p[y].second;
}
double work(int l, int r) {
	if (l == r) return INF;
	if (l+1 == r) return dis(l, r);
	int mid = l + r >> 1, k = 0;
	double ls = work(l, mid);
	double rs = work(mid+1, r);
	double ret = min(ls, rs);
	for (int i = l; i <= r; i++)
		if (fabs(p[i].first-p[mid].first) <= ret)
			v[++k] = i;
	sort(v+1, v+k+1, cmp);
	for (int i = 1; i <= k; i++)
		for (int j = i+1; j <= k && p[v[j]].second-p[v[i]].second < ret; j++)
			ret = min(ret, dis(v[i], v[j]));
	return ret;
}
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &p[i].first, &p[i].second);
	sort(p+1, p+n+1);
	printf("%.4lf\n", work(1, n));
	return 0;
}
