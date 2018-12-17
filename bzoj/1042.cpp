#include <iostream>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h> 
#include <queue>
#include <cmath>
#include <math.h>
#include <vector>
#include <iostream>
#include <cstdio>
#include <fstream>
#define ll long long

using namespace std;

int n, s, c[5], d[5], tot;
ll ans, f[100005];
void dfs(int x, int k, int s){
	if(s < 0) return;
	if(x == 5){
		if(k % 2 == 0) ans += f[s];
		else ans -= f[s];
		return;
	}
	dfs(x+1, k, s);
	dfs(x+1, k+1, s-(d[x]+1)*c[x]);
}

int main(){
	scanf("%d%d%d%d%d", &c[1], &c[2], &c[3], &c[4], &tot);
	f[0] = 1;
	for(int i = 1; i <= 4; i++)
		for(int j = 0; j <= 100000 - c[i]; j++)
			f[j + c[i]] = f[j + c[i]] + f[j];
	for(int i = 0; i < tot; i++){
		scanf("%d%d%d%d%d", &d[1], &d[2], &d[3], &d[4], &s);
		ans = 0, dfs(1, 0, s);
		printf("%lld\n", ans);
	}
	return 0;
} 
