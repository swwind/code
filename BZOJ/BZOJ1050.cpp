#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int inf = 1<<30;
struct edge{
	int u, v, w;
	bool operator < (const edge &b) const{
		return w < b.w;
	}
}e[N];
int n, m, s, t, fa[N], ans1 = inf, ans2;
int x, y, cur2, cur1;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int gcd(int a, int b){return b?gcd(b, a%b):a;}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	scanf("%d%d", &s, &t);
	sort(e+1, e+m+1);
	for(int i = 1; i <= m; i++){
		cur2 = e[i].w; cur1 = -1;
		for(int j = 1; j <= n; j++) fa[j] = j;
		for(int j = i; j <= m; j++){
			x = find(e[j].u); y = find(e[j].v);
			if(x != y) fa[x] = y;
			if(find(s) == find(t)){
				cur1 = e[j].w;
				break;
			}
		}
		if(cur1 != -1 && (ans1 == inf || ans1*cur2 > cur1*ans2))
			ans1 = cur1, ans2 = cur2;
	}
	if(ans1 == inf)return puts("IMPOSSIBLE")&0;
	x = gcd(ans1, ans2);
	ans1 /= x; ans2 /= x;
	if(ans1 == 0) printf("0");
	else if(ans2 == 1) printf("%d", ans1);
	else printf("%d/%d\n", ans1, ans2);
	return 0;
}
