// Alone - Alan Walker
//
// If this night is not forever
// At lease we are together
// I know I'm not alone
// I know I'm not alone
// Anyway whenever
// Apart but still together
// I know I'm not alone
// I know I'm not alone
// 最美不过fa♂乐器
#include <bits/stdc++.h>
#define ll long long
#define N 200050
using namespace std;
int a[N], ans[N], mx, n, h1[N], h2[N];
map<int, int> mp;
int getHash(int bg, int ed){
	return (h1[ed]-h1[bg])*(h2[bg-1]-h2[ed-1]);

}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a+i), h1[i]=h1[i-1]+a[i]*6667;
	for(int i = n; i; i--) h2[i] = h2[i+1] + a[i]*6667;
	for(int i = 1; i*mx <= n; i++){
		int ss = 0;
		for(int j = 1; j+i-1 <= n; j += i){
			int k = getHash(j, j+i);
			if(!mp[k]) mp[k]++, ss++;
		}
		mp.clear();
		if(ss > mx) mx = ss, ans[ans[0] = 1] = i;
		else if(ss == mx) ans[++ans[0]] = i;
	}
	printf("%d %d\n", mx, ans[0]);
	for(int i = 1; i < ans[0]; i++) printf("%d ", ans[i]);
	printf("%d\n", ans[ans[0]]);
	return 0;
}
