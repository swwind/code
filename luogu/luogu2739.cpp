#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, a[200], cur, cnt = 1;
int main(){
	void work(int, int);
	scanf("%d", &n);
	cur = n;
	work(1, 1);
	a[cnt++] = cur;
	for(int i = 1; i < n*(n+2);){
		for(int j = 1; j <= 20 && i < n*(n+2); i++, j++)
			printf("%d ", a[i]);
		if(i == n*(n+2))printf("%d", a[i]);
		else printf("\n");
	}
	return 0;
}
void work(int dep, int mv){
	if(dep == n){
		for(int i = 0; i < n; i++)
			a[cnt++] = cur, cur += 2*mv;
		a[cnt++] = cur, cur -= mv;
	}
	else{
		for(int i = 0; i < dep; i++)
			a[cnt++] = cur, cur += mv*2;
		a[cnt++] = cur, cur += mv;
		work(dep+1, mv/-1);
		for(int i = 0; i < dep; i++)
			a[cnt++] = cur, cur += mv*2;
		a[cnt++] = cur, cur -= mv;
	}
}
