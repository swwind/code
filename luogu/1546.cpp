#include <bits/stdc++.h>
using namespace std;
struct node{
	int a, b, v;
	bool operator < (const node B) const {
		return v < B.v;
	}
} mp[100000];
int n, f[100000], ans, tot, x;
void insert(int a, int b, int c){
	mp[tot].a = a;
	mp[tot].b = b;
	mp[tot++].v = c;
}
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) f[i] = i; 
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(j < i) scanf("%d", &x), insert(i, j, x), insert(j, i, x);
			else scanf("%d", &x);
	sort(mp, mp + tot);
	for(int i = 0; i < tot; i++)
		if(find(mp[i].a) != find(mp[i].b))
			ans += mp[i].v,
			f[find(mp[i].a)] = find(mp[i].b);
	printf("%d", ans);
}

