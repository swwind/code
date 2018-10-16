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
int a[N], ans = 1<<30;
int min(int a, int b){return a < b ? a : b;}
int main(int argc, char const *argv[]){
	int n = read(), k = read(), b = read();
	for(int i = 1; i <= b; ++i) a[read()] = 1;
	for(int i = 1; i <= n; ++i) a[i] += a[i-1];
	for(int i = k; i <= n; ++i) ans = min(ans, a[i]-a[i-k]);
	printf("%d\n", ans);
	return 0;
}