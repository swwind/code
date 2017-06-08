#include <bits/stdc++.h>
using namespace std;
int get(int x){
	int ans = 0;
	for(int i = 1; i <= x; i++)
		if(x/i*i==x) ans += i;
	return ans;
}
int main(){
	int a, b;
	while(scanf("%d%d", &a, &b)!=EOF){
	a = pow(a, b);
	printf("%d\n", get(a));}
}