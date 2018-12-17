#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[N], c;
double ans;
int main(int argc, char const *argv[]){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a+1, a+n+1);
	int r = lower_bound(a+1, a+n+1, m+1)-a-1;
	for(int i = 2; i <= r; i++)
		ans += min(int(lower_bound(a+1, a+n+1, m-a[i]+1)-a-1), i-1);
	printf("%.2lf\n", ans/(.5*n*(n-1)));
	return 0;
}