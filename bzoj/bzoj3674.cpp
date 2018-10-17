#include <bits/stdc++.h>
#include <ext/rope> 
using namespace std;
using namespace __gnu_cxx;
rope<int> *rp[200010];
int n, m, a[200100], f, x, y, lastans;
int find(int i, int x){
	int fa = rp[i] -> at(x);
	if(fa==x) return x;
	int f = find(i, fa);
	if(f==fa) return f;
	rp[i] -> replace(x, f);
	return f;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		a[i] = i;
	rp[0] = new rope<int>(a, a+n+1);
	for(int i = 1; i <= m; i++){
		rp[i] = new rope<int>(*rp[i-1]);
		scanf("%d", &f);
		if(f == 1){
			scanf("%d%d", &x, &y);
			x^=lastans, y^=lastans;
			x = find(i,x);
			y = find(i,y);
			if(x != y)
				rp[i] -> replace(y, x);
		}
		else if(f == 2){
			scanf("%d", &x); x^=lastans;
			rp[i] = rp[x];
		}
		else{
			scanf("%d%d", &x, &y);
			x^=lastans, y^=lastans;
			printf("%d\n", lastans=find(i,x)==find(i,y));
		}
	}
}