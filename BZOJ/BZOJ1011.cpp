#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
double A;
ll a[N];
double solve(int l, int r, int x){
	double ans = 0;
	if(r-l <= 200) for(;l<=r;l++)
		ans += 1.0*(a[l]-a[l-1])/(x-l);
	else while(l <= r){
		int _r = min(r, l+200);
		ans += 1.0*(a[_r]-a[l-1])/(x-(l+_r)/2);
		l = _r+1;
	}
	return ans*(a[x]-a[x-1]);
}
int main(){
	int n = read();
	scanf("%lf", &A);
	for(int i = 1; i <= n; i++)
		a[i] = read()+a[i-1];
	for(int i = 1; i <= n; i++)
		printf("%.7lf\n", solve(1, floor(A*i), i));
}
// Fallen Angels (Original Mix)