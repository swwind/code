#include <bits/stdc++.h>
#define ll long long
#define inf (1LL<<60)
using namespace std;
struct SZB{
	int x, y, p;
	bool operator < (const SZB &b) const {
		return x == b.x ? y < b.y : x < b.x;
	}
} a[200050];
int pos[1050], n, m;
ll f[1050];
ll sqr(ll a){
	return a*a;
}
int main(){
	scanf("%d%d", &n, &m);
	n += 2;
	a[1].x = a[1].y = 1;
	a[2].x = a[2].y = m;
	for(int i = 3; i <= n; i++)
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].p);
	sort(a+2, a+n+1);
	pos[1] = 1;
	for(int i = 2; i <= n; i++){
		ll tmp = -inf;
		for(int j = 1; j <= a[i].y; j++) if(pos[j])
			tmp = max(tmp, f[j]-sqr(a[i].y-j)-sqr(a[i].x-pos[j]));
		pos[a[i].y] = a[i].x;
		f[a[i].y] = tmp + a[i].p;
	}
	printf("%d\n", f[m]);
	return 0;
}

