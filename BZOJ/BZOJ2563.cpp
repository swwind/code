#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[10020], ans;
int main(int argc, char const *argv[]){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) ans -= (a[i]=read()<<1)>>1;
	for(int i = 1; i <= m; i++){
		int x = read(), y = read(), z = read();
		a[x] += z; a[y] += z; ans -= z;
	}
	sort(a+1, a+n+1);
	for(int i = 2; i <= n; i+=2) ans += a[i];
	printf("%d\n", ans);
	return 0;
}