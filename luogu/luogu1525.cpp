#include <bits/stdc++.h>
using namespace std;
struct node{
	int x, y, v;
	bool operator < (const node B) const {
		return v > B.v;
	}
} a[100005];
int f[40005], n, m;
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
	for(int i = 1; i <= (n << 1); i++) f[i] = i;
	sort(a, a + m);
	for(int i = 0; i < m; i++){
		int x = find(a[i].x), y = find(a[i].y);
		if(x == y)
			printf("%d", a[i].v),
			exit(0);
		else
			f[find(x+n)] = find(y),
			f[find(y+n)] = find(x);
	}
	puts("0");
	return 0;
}

