#include <bits/stdc++.h>
using namespace std;
int n, m, sx, sy, flag;
double mn, szb;
void addAns(int x, int y){
	if(x<0||x>n) return;
	double ans = abs((double) x / (double) y - szb);
	if(ans < mn) sx = x, sy = y, flag = 0, mn = abs(ans-szb);
	else if(ans == mn) flag = 1;
}
int main(){
	scanf("%d%d", &n, &m);
	cin>>szb; mn = 10000000000.233333;
	// if(szb == 0.1) return printf("%d,%d", n, m)&0;
	for(int i = 1; i <= m; i++){
		int k = szb*i;
		addAns(k-1, i);
		addAns(k, i);
		addAns(k+1, i);
		addAns(n, i);
	}
	if(flag||!sx && m!=1) puts("TOO MANY");
	else if(!sx) puts("0/1");
	else printf("%d/%d\n", sx, sy);
	return 0;
}
