#include <bits/stdc++.h>
#define N 310
#define ST 0
#define ED n+1
using namespace std;
inline int read(){
	int x = 0, f = 0; char ch = getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int inf = 1<<30;
int n, ans;
namespace Min_Cost_Max_Flow{
	struct abcd{
		int to, flow, cost, next;
	}e[1001001];
	int head[N], tot=1;
	int q[65540], f[N], cost[N], from[N];
	unsigned short r, h;
	bool v[N];
	void Add(int x, int y, int f, int c){
		e[++tot].to = y;
		e[tot].flow = f;
		e[tot].cost = c;
		e[tot].next = head[x];
		head[x] = tot;
	}
	void Link(int x, int y, int f, int c){
		Add(x, y, f, c);
		Add(y, x, 0, -c);
	}
	int Edmonds_Karp(){
		memset(cost, 127/3, sizeof cost);
		cost[ST] = f[ED] = 0;
		q[++r] = ST; f[ST] = inf;
		while(r != h){
			int x = q[++h]; v[x] = 0;
			for(int i = head[x]; i; i = e[i].next)
				if(e[i].flow && cost[x]+e[i].cost < cost[e[i].to]){
					cost[e[i].to] = cost[x]+e[i].cost;
					f[e[i].to] = min(f[x], e[i].flow);
					from[e[i].to] = i;
					if(!v[e[i].to]) v[e[i].to] = 1, q[++r] = e[i].to;
				}
		}
		if(!f[ED]) return 0;
		ans += f[ED]*cost[ED];
		for(int i = from[ED]; i; i = from[e[i^1].to])
			e[i].flow -= f[ED], e[i^1].flow += f[ED];
		return 1;
	}
}
using namespace Min_Cost_Max_Flow;
int main(){
	n = read();
	for(int i = 1, m; i <= n; i++){
		m = read();
		for(int j = 1, x, y; j <= m; j++){
			x = read(); y = read();
			Link(i, x, inf, y);
			Link(ST, x, 1, y);
		}
		Link(i, ED, m, 0);
		if(i > 1) Link(i, 1, inf, 0);
	}
	while(Edmonds_Karp());
	printf("%d\n", ans);
	return 0;
}