#include <bits/stdc++.h>
#define ll long long
#define N 1000050
using namespace std;
int fa[N], l[N], r[N], d[N], v[N], n, m, x, y, die[N];
char ch[10];
int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
int merge(int x, int y){
	if(!x) return y;
	if(!y) return x;
	if(v[x] > v[y]) swap(x, y);
	r[x] = merge(r[x], y);
	if(d[r[x]] > d[l[x]]) swap(r[x], l[x]);
	d[x] = d[r[x]]+1;
	return x;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", v+i), fa[i] = i;
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		scanf("%s%d", ch, &x);
		if(ch[0] == 'M'){
			scanf("%d", &y);
			if(die[x] || die[y]) continue;
			int a = find(x), b = find(y);
			if(a != b)
				fa[a] = fa[b] = merge(a, b);
		}
		else{
			if(die[x]) puts("0");
			else{
				int a = find(x);
				die[a] = 1;
				printf("%d\n", v[a]);
				fa[a] = merge(l[a], r[a]);
				fa[fa[a]] = fa[a];
			}
		}
	}
	return 0;
}

