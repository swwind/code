#include <cstdio>
#define ll long long
int n, m, fa[50050], rank[50050], x, y, d, ans;
int find(int x){
	if(x == fa[x])return x;
	int f = fa[x];
	fa[x] = find(fa[x]);
	rank[x] = (rank[x]+rank[f]) % 3;
	return fa[x];
}

inline int Union(int x, int y, int D){
	int a = find(x), b = find(y);
	if(a == b){
		if(D == 1 && rank[x] != rank[y])
			return 0;
		else if(D == 2)
			if(rank[x] == 2 && rank[y] != 1 || rank[x] == 1 && rank[y] != 0
				|| rank[x] == 0 && rank[y] != 2)
				return 0;
		return 1;
	}
	fa[a] = b;
	if(D == 2)
		rank[a] = (rank[y]-rank[x]+4) % 3;
	else
		rank[a] = (rank[y]-rank[x]+3) % 3;
	return 1;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &d, &x, &y);
		if(x > n || y > n || d == 2 && x == y || !Union(x, y, d))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
