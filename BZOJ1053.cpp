#include <bits/stdc++.h>
#define ll long long
#define read(a) scanf("%d", &a)
#define write(a) printf("%d\n", a);
using namespace std;
int ans = 1, num = 1, n;
int pri[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
void dfs(int k = 1, ll now = 1, int cnt = 1, int last = 20){
	if(k == 12){
		if(now > ans && cnt > num) ans = now, num = cnt;
		if(now <= ans && cnt >= num) ans = now, num = cnt;
		return;
	}
	int t = 1;
	for(int i = 0; i <= last; i++){
		dfs(k+1, now*t, cnt*(i+1), i);
		t *= pri[k];
		if(now*t > n) break;
	}
}
int main(){
	read(n);
	dfs();
	write(ans);
}