#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, a[500009], c[500009], k, x, y, t, ans;
int get(int x){
	int ans = 0;
	for(int i = x; i; i -= i&-i)
		ans += c[i];
	return ans;
}
void add(int x, int d){
	for(int i = x; i <= n; i += i&-i)
		c[i] += d;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", a+i),
		add(i, a[i]);
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &k, &x, &y);
		if(k == 1) add(x, y);
		else printf("%d\n", get(y) - get(x-1));
	}
	return 0;
}
