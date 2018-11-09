#include <bits/stdc++.h>
using namespace std;
int sum(int x){
	int ans = 0;
	for(;x;ans++)x/=2;
	return ans;
}
int sum2(int x){
	int ans = 0;
	for(;x;ans++)x^=x&-x;
	return ans;
}
int x,y,z,mx,ans;
int main(){
	scanf("%d%d%d", &x, &y, &z);
	mx = max(max(sum(x), sum(y)), sum(z));
	x = sum2(x); y = sum2(y); z = sum2(z);
	if(x < y) swap(x,y);
	if(z <= y) ans = ((1<<x)-1)+((1<<z)-1|((1<<y-z)-1<<x));
	else if(z <= x) ans = ((1<<x)-1)+((1<<y)-1<<z-y);
	else if(z <= x+y) ans = ((1<<x)-1<<z-x)+((1<<z-x)-1|((1<<x+y-z)-1<<z+z-x-y));
	else ans = -1;
	if(sum(ans) > mx) ans = -1;
	printf("%d\n", ans);
	return 0;
}